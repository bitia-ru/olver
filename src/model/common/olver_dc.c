/*
 * Copyright (c) 2005-2006 Institute for System Programming
 * Russian Academy of Sciences
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "atl/char.h"
#include "atl/integer.h"
#include "atl/long.h"
#include "atl/void_ast.h"
#include "atl/map.h"

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/stat.h>

#include "../../dc_sock.c"

static struct sockaddr_in peer_addr;

/********************************************************************/
/**                  Exact-Width Integer Types                     **/
/********************************************************************/


int command_stop(void)
{
    dc_bf_putstr("stop_master");
    if(ta_send_command_to_master_agent())
    {
        close(dc_socket);
        // nothing to receive here
        return 0;
    } else return DC_COMMAND_FAILED;
}

int command_exec(char* remotePath, char* opts, char* stream_out, char* stream_err)
{
    char buff[1024*128];
    dc_printf("executing command_exec: remote_path:%s opts:\"%s\"\n", remotePath, opts);
    sprintf(buff, "exec:str:%s", remotePath);

    dc_bf_putstr("exec:");
    dc_bf_addstr(remotePath);
    dc_bf_addstr(opts);

    if(ta_send_command_to_master_agent())
    {
        // res
        if(dc_receive_message())
        {
            int status;
            dc_parse_int();
            status = dc_pr_int;
            dc_printf("status:%d\n", status);
            dc_parse_bytearray();
            dc_save_bytearray(stream_out);
            dc_parse_bytearray();
            dc_save_bytearray(stream_err);
        }
        return DC_COMMAND_PASSED;
    }
    return DC_COMMAND_FAILED;
}

int command_put(char* localPath, char* remotePath)
{
    dc_bf_putstr("put:");
    dc_bf_addstr(remotePath);

    dc_bf_addfile(localPath);

    ta_send_command_to_master_agent();

    return DC_COMMAND_PASSED;
}

int command_get(char* localPath, char* remotePath)
{
    dc_printf("executing command_get_file: local:%s remote:%s\n", localPath, remotePath);

    dc_bf_putstr("get:");
    dc_bf_addstr(remotePath);

    ta_send_command_to_master_agent();

    if( dc_receive_message() && dc_parse_bytearray() && dc_save_bytearray(localPath)==DC_COMMAND_PASSED )
    {
        return DC_COMMAND_PASSED;
    } else {
        perror("command_get_file: failed");
    }

    return DC_COMMAND_FAILED;
}

int command_rm(char* remotePath)
{
    dc_printf("executing command_get_file remotePath:%s\n", remotePath);

    dc_bf_putstr("rm:");
    dc_bf_addstr(remotePath);

    ta_send_command_to_master_agent();

    return DC_COMMAND_PASSED;
}

void print_usage(void)
{
    printf(
        "Usage: olver_dc command [options]\n"
        "Supported commands are:\n"
        "\t'stop':\n\t\tstop olver daemon and exit\n"
        "\t'exec remote_path opts out err':\n\t\texecute remote file 'remote_path'\n\t\tpass 'opts' as an argument\n\t\tput stdout to 'out' and stderr to 'err'\n"
        "\t'put local_path remote_path':\n\t\tput file referenced by 'local_path' into\n\t\tremote 'remote_path'\n"
        "\t'get local_path remote_path':\n\t\tget into file referenced by 'local_path'\n\t\tcontents of remote file 'remote_path'\n"
        "\t'rm remote_path':\n\t\tremove remote file 'remote_path'\n"
    );
}

int main(int argc,char** argv)
{
    int dc_res = 0;
    init_dc();
    debug_enabled = DC_VERBOSE;

    if(argc>1)
    {
        char *command = argv[1];
        if (strcmp(command,"help") == 0 || strcmp(command,"-help") == 0 || strcmp(command,"--help") == 0)
        {
            print_usage();
        } else if (strcmp(command,"stop") == 0)
        {
            dc_res = command_stop();
        } else if(strcmp(command, "exec") == 0) {
            if(argc!=6)
            {
                fprintf(stderr, "Invalid number of arguments for 'exec'.\n");
                dc_res = -1;
            } else {
                char *remote = argv[2];
                char *opts = argv[3];
                char *stream_out = argv[4];
                char *stream_err = argv[5];
                dc_res = command_exec(remote, opts, stream_out, stream_err);
            }
        } else if(strcmp(command, "put") == 0) {
            if(argc!=4)
            {
                fprintf(stderr, "Invalid number of arguments for 'put'.\n");
                dc_res = -1;
            } else {
                char *local = argv[2];
                char *remote = argv[3];
                dc_res = command_put(local, remote);
            }
        } else if(strcmp(command, "get") == 0) {
            if(argc!=4)
            {
                fprintf(stderr, "Invalid number of arguments for 'get'.\n");
                dc_res = -1;
            } else {
                char *local = argv[2];
                char *remote = argv[3];
                dc_res = command_get(local, remote);
            }
        } else if(strcmp(command, "rm") == 0) {
            if(argc!=3)
            {
                fprintf(stderr, "Invalid number of arguments for 'rm'.\n");
                dc_res = -1;
            } else {
                char *remote = argv[2];
                dc_res = command_rm(remote);
            }
        } else {
                fprintf(stderr, "Unknown command '%s'. Type '%s --help' for usage details.\n", command, argv[0]);
                dc_res = -1;
        }
    } else print_usage();

    finish_dc();
    return 0;
}


