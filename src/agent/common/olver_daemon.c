
#include "common/agent.h"
#include <string.h>

#include <sys/stat.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>


#include "../../dc_sock.c"

int agent_daemon_port = MASTER_AGENT_DEFAULT_PORT;
int agent_daemon_socket = -1;
struct sockaddr_in peer_addr;

int dc_reply(int sock, char *buff, int32_t length)
{
    int32_t netint = htonl(length);
    if (send(sock,&netint,sizeof(netint),0) != sizeof(netint))
    {
        perror("dc_reply:send1");
        return 0;
    }
    if (send(sock,buff,length,0) != length)
    {
        perror("dc_reply:error sending data");
        return 0;
    }
    return 1;
}

void dc_command_exec()
{
    int status = 0;
    char cmd[65536];
    char *remote_path, *opts;

    dc_parse_string();
    remote_path = dc_pr_string;

    dc_parse_string();
    opts = dc_pr_string;

    dc_printf("dc_command_exec remote_path:%s opts:%s\n", remote_path, opts);
    sprintf(cmd, "%s %s >execout  2>execerr", remote_path, opts);
    status = system(cmd);
    dc_bf_addint(status);
    dc_bf_addfileifexists("execout");
    dc_bf_addfileifexists("execerr");
    dc_bf_send();
//    remove("execout");
//    remove("execerr");
}

void dc_command_put_file()
{
    char *remote_path;
    char *file_contents;
    dc_parse_string();
    remote_path = dc_pr_string;
    dc_parse_bytearray();
    file_contents = dc_pr_string;
    dc_save_bytearray(remote_path);

    dc_printf("dc_command_put_file:%s contents:%s\n", remote_path, file_contents);
}

void dc_command_get_file()
{
    char *remote_path;
    dc_parse_string();
    remote_path = dc_pr_string;

    dc_bf_reset();
    if(!dc_bf_addfileifexists(remote_path))
        dc_printf("dc_command_get_file: File not found:%s\n", remote_path);

    dc_bf_send();
}

void dc_command_rm_file()
{
    char *remote_path;
    dc_parse_string();
    remote_path = dc_pr_string;

    remove(remote_path);
}

int ad_main_routine(int argc,const char** argv)
{
    TAThread  master_thread;
    TACommandVerdict verdict = taDefaultVerdict;
    struct sockaddr_in master_addr;
    const char* value;

    init_dc();

    ta_debug_off();
    value = getenv("AGENT_DAEMON_PORT");
    if (value != NULL)
    {
        sscanf(value,"%d",&agent_daemon_port);
    }

    // Init master thread
    master_thread = ta_alloc_memory(sizeof(struct TAThread));
    master_thread->communicator.data.tcp.sockid = -1;
    master_thread->stream = createTAOuputStream();
    clear_timemark(&master_thread->start_time);
    clear_timemark(&master_thread->end_time);

    // Say to system not to create zombie processes on child death
    {
        struct sigaction act;
        sigaction( SIGCHLD, NULL, &act );
        act.sa_flags = SA_NOCLDWAIT;
        sigaction( SIGCHLD, &act, NULL );
    }

    // Create master agent socket
    agent_daemon_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (agent_daemon_socket == -1)
    {perror("ad_main_routine");
    assertion(0,"Cannot create socket");
    return 1;
    }

    // Set reuse address option
    {
        int optval = 1;
        setsockopt(agent_daemon_socket,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int));
    }

    // Bind
    master_addr.sin_family = AF_INET;
    master_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    master_addr.sin_port = htons(agent_daemon_port);
    if (bind(agent_daemon_socket,(struct sockaddr*) &master_addr,sizeof(master_addr)) == -1)
    {
        perror("ad_main_routine");
        close(agent_daemon_socket);
        assertion(0,"Cannot bind socket");
        return 1;
    }
    if (listen(agent_daemon_socket,10) == -1)
    {
        perror("ad_main_routine");
        close(agent_daemon_socket);
        assertion(0,"Cannot listen socket");
        return 1;
    }
    for(;;)
    {
        struct sockaddr_in addr;
        socklen_t length;
        int new_sockid;
        int32_t cmd_length;
        char* command;
        char* arguments;
        int arguments_length;
        int res2;

        // Accept new connection
        length = sizeof(addr);
        new_sockid = accept(agent_daemon_socket,(struct sockaddr *) &addr, &length);
        memcpy( &peer_addr, &addr, sizeof(addr) );

        // Receive command
        res2 = recv(new_sockid,(char*)&cmd_length,sizeof(cmd_length),MSG_WAITALL);
        if (res2 == sizeof(cmd_length))
        {
            cmd_length = ntohl(cmd_length);
            command = (char*)ta_alloc_memory(cmd_length);
            if (command == NULL)
            {
                assertion(0,"Not enought memory");
                return 2;
            }
            if (recv(new_sockid,command,cmd_length,MSG_WAITALL) == cmd_length)
            {
                master_thread->communicator.data.tcp.sockid = new_sockid;
                // Parse command
                arguments = memchr(command,':',cmd_length);
                if (arguments != NULL)
                {
                    *arguments = '\0';
                    arguments++;
                    arguments_length = &(command[cmd_length]) - arguments;
                    dc_printf("arguments:%s arguments_length:%d cmd_length:%d\n", arguments, arguments_length, cmd_length);
                }
                else
                {
                    command[cmd_length] = '\0';
                    arguments_length = 0;
                }

                dc_memory_available = arguments_length;
                dc_rec_data = arguments;
                dc_socket = new_sockid;
                dc_parse_start();

                if (strcmp(command,"exec") == 0)
                {
                    dc_command_exec();
                } else if (strcmp(command,"put") == 0)
                {
                    dc_command_put_file();
                } else if (strcmp(command,"get") == 0)
                {
                    dc_command_get_file();
                } else if (strcmp(command,"rm") == 0)
                {
                    dc_command_rm_file();
                }
                else if (strcmp(command,"stop_master") == 0)
                    verdict.finish = 1;
            }
            else
            {
                perror("recv failed");
            }
            ta_dealloc_memory(command);
        }

        // Close socket
        shutdown(new_sockid,2);
        close(new_sockid);

        // Break condition
        if (verdict.finish)
            break;
    }

    shutdown(agent_daemon_socket,2);
    close(agent_daemon_socket);
    finish_dc();
    return 0;
}

/********************************************************************/
/**                         Test Agent Main                        **/
/********************************************************************/
int main(int argc,const char** argv)
{
    debug_enabled = DC_VERBOSE;
    // process options
    if ((argc == 2) && (strcmp(argv[1],"-silent") == 0))
    {
        debug_enabled = 0;
    }

    ta_debug_printf("Starting OLVER Daemon v.1.2...\n");

    // setup tcp communicator
    ta_setup_tcp_communicator(argc,argv);

    ta_debug_printf("Started.\n\n");
    // startup test agent main function
    return ad_main_routine(argc,argv);
}

