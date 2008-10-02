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


#include "common/agent.h"
#include "common/ta_hash.h"
#include "common/ta_assertion.h"
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

/********************************************************************/
/**                     Test Agent Debug Printf                    **/
/********************************************************************/
const char* ta_agent_log = "/tmp/olver-log/agent.log";

static int dumpverbose_enabled = 1;
static int debug_enabled = 0;

int is_ta_debug(void)
{
    return debug_enabled;
}

void ta_debug_on(void)
{
    debug_enabled = 1;
}

void ta_debug_off(void)
{
    debug_enabled = 0;
}

int is_ta_verbose(void)
{
    return dumpverbose_enabled;
}

void ta_verbose_on(void)
{
    dumpverbose_enabled = 1;
}

void ta_verbose_off(void)
{
    FILE* out = fopen(ta_agent_log, "a");
    fclose(out);

    dumpverbose_enabled = 0;
}

int ta_debug_printf(char* format, ...)
{
    int cancelstate;
    va_list arg_list;
    int res = 0;

    if (dumpverbose_enabled)
    {
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&cancelstate);

        va_start(arg_list, format);

        res = vprintf(format, arg_list);

        va_end(arg_list);

        pthread_setcancelstate(cancelstate,&cancelstate);
    }
    else
    {
        FILE* out;
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&cancelstate);
        va_start(arg_list, format);

        out = fopen(ta_agent_log, "a+b");
        if (out)
        {
            res = vfprintf(out, format, arg_list);
            fclose(out);
        }
        else
        {
            res = vprintf(format, arg_list);
        }

        va_end(arg_list);
        pthread_setcancelstate(cancelstate,&cancelstate);
    }
    return res;
}


/********************************************************************/
/**                       Exception Handling                       **/
/********************************************************************/

static int ta_exception_handling_enabled = 1;

int ta_exception_handling_enable( int enable )
{
    int old_value = ta_exception_handling_enabled;
    ta_exception_handling_enabled = enable;
    return old_value;
}


/* ===================================== *
 * POSIX Exception Handling
 * ===================================== */
#if defined(__GNUC__)

#include <signal.h>

typedef void (*PosixExceptionHandler)(siginfo_t* info, void* context);

void start_exception_protected_section(PosixExceptionHandler exception_handler);
void end_exception_protected_section(void);


#define START_EXCEPTION_PROTECTED_SECTION(handler)  start_exception_protected_section(handler);
#define END_EXCEPTION_PROTECTED_SECTION()           end_exception_protected_section();


/* ===================================== *
 * Absence of Exception Handling
 * ===================================== */
#else

#define START_EXCEPTION_PROTECTED_SECTION(handler)
#define END_EXCEPTION_PROTECTED_SECTION()


#endif


/* ===================================== *
 * POSIX Exception Handling Implementation
 * ===================================== */
#if defined(__GNUC__)

static struct sigaction ta_previous_sigsegv_sigaction;
static PosixExceptionHandler ta_posix_exception_handler;
const char* ta_program_name = "!Program name unknown!";


static void ta_exception_handler(int signo, siginfo_t* info, void* context)
{
    struct sigaction action;
    struct sigaction* previous_action;
    sigset_t sigset, oldset;

    if( is_ta_debug() )
    {
        int gdb_pid;
        char spid[20];
        snprintf(spid, 19, "%i", getpid());
        spid[19] = 0;
        ta_debug_printf("Forking...\n");
        gdb_pid = fork();
        ta_debug_printf("Forked...\n");

        if (gdb_pid == 0) { // We are the child
            char spath[256];
            ta_debug_printf("Spath is:");

            snprintf(spath, sizeof(spath)-1, "%s.gdb", ta_program_name);
            ta_debug_printf("spath:%s.gdb", ta_program_name);

            if (execl("/usr/bin/gdb", "gdb", "--command", spath, ta_program_name, spid, NULL) == -1)

            {
                ta_debug_printf("Couldn't start gdb\n");

            }

            exit(0);
        } else if (gdb_pid < 0) {
            ta_debug_printf("Couldn't fork\n");
        } else {
            // Wait for any signal from GDB
            sigset_t wsig;
            int ressig=0;
            sigfillset( &wsig );
            sigwait(&wsig, &ressig);
        }

        return;
    }

    ta_posix_exception_handler(info,context);

    switch (signo)
    {
    case SIGSEGV :
        previous_action = &ta_previous_sigsegv_sigaction;
        break;
    default :
        return;
    }
    sigaction(signo, previous_action, &action);

    sigemptyset(&sigset);
    sigaddset(&sigset, signo);
    sigprocmask(SIG_UNBLOCK, &sigset, &oldset);
    kill(getpid(), signo);
    sigprocmask(SIG_SETMASK, &oldset, NULL);
    sigaction(signo, &action, NULL);
}

static void test_agent_exception_handler(siginfo_t* info, void* context);

void start_exception_protected_section(PosixExceptionHandler exception_handler)
{
    struct sigaction action;

    if (!ta_exception_handling_enabled)
        return;

    ta_posix_exception_handler = exception_handler;

    memset(&action, sizeof(sigaction), 0);
    action.sa_sigaction = ta_exception_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &action, &ta_previous_sigsegv_sigaction);
}

void end_exception_protected_section(void)
{
    sigaction(SIGSEGV, &ta_previous_sigsegv_sigaction, NULL);
}

#endif

static void test_agent_exception_handler(siginfo_t* info, void* context)
{
    TAThread thread;
    char buff[256];

    thread = ta_current_thread();
    switch (info->si_signo)
    {
    case SIGSEGV :
        if (info->si_code == SEGV_MAPERR)
            sprintf( buff, "Segmentation fault: Invalid memory address '%p'", info->si_addr );
        else if (info->si_code == SEGV_ACCERR)
            sprintf( buff, "Segmentation fault: Invalid permissions for memory at '%p'", info->si_addr );
        else
            sprintf( buff, "Segmentation fault: Unknown memory access violation at '%p'", info->si_addr );
        break;
    default :
        sprintf( buff, "Unexpected signal '%d'", info->si_signo );
        break;
    }

    sendException(thread,buff);
    ta_debug_printf("  %s\n",buff);
    test_agent_recovery_thread(thread);
}


/********************************************************************/
/**                       Test Agent Recovery                      **/
/********************************************************************/
void test_agent_recovery(void)
{
    test_agent_recovery_thread(ta_current_thread());
}

void test_agent_recovery_thread(TAThread thread)
{
    if (thread->level > 0)
    {
        siglongjmp(thread->start_point,1);
        assertion(0,"test_agent_recovery_thread: jump failed");
    }
    // otherwise thread->start_point has not set up yet
    assertion(0,"test_agent_recovery_thread: recovery is impossible");
}


/********************************************************************/
/**                     Test Agent Memory Pool                     **/
/********************************************************************/
#define TA_STATIC_MEMMODE    1
#define TA_BSTARTED_MEMMODE  1L<<8

#ifndef TA_MEMPOOL_DEBUG
    #define TA_MEMBLOCK_NUM     4096
    #define TA_MEMBLOCK_SIZE    128
#else
    #define TA_MEMBLOCK_NUM     32768
    #define TA_MEMBLOCK_SIZE    1024

    static int ta_memuse;
    static int ta_memmax;
#endif

struct TAMemBlockInfo
{
    char bUsed;
    int allocsize;
};

static unsigned char ta_memory_blocks[TA_MEMBLOCK_NUM][TA_MEMBLOCK_SIZE];
static struct TAMemBlockInfo ta_memory_blinfo[TA_MEMBLOCK_NUM];
static int ta_memory_mode = 0;

void* ta_static_alloc_memory(size_t size)
{
    int needblocks, i, j, n;

    if(!(ta_memory_mode & TA_BSTARTED_MEMMODE))
        ta_init_mempool();

    if(size == 0) return NULL;

    needblocks = (size/TA_MEMBLOCK_SIZE) +
        (size % TA_MEMBLOCK_SIZE ? 1 : 0);

    for(i = 0, n = 0; i < TA_MEMBLOCK_NUM; i++)
    {
        if(!ta_memory_blinfo[i].bUsed) ++n;
        else n = 0;

        if(n == needblocks) {
            for(j = i-n+1; j < i+1; j++)
                ta_memory_blinfo[j].bUsed = TRUE;

            ta_memory_blinfo[i-n+1].allocsize = needblocks;

            return (void*)(ta_memory_blocks[i-n+1]);
        }
    }

    errno = ENOMEM;
    ta_debug_printf("ERROR: out of static memory.\n");

    return NULL;
}

void* ta_static_realloc_memory(void* ptr, size_t newsize)
{
    int needblocks, i, j;

    needblocks = (newsize/TA_MEMBLOCK_SIZE) +
    (newsize % TA_MEMBLOCK_SIZE ? 1 : 0);

    if(ptr == NULL) return ta_alloc_memory(newsize);
    if(newsize == 0)
    {
        ta_dealloc_memory(ptr);
        return NULL;
    }

    i = (int)ptr - (int)ta_memory_blocks;

    if(!((i%TA_MEMBLOCK_SIZE == 0) &&
       (i/TA_MEMBLOCK_SIZE < TA_MEMBLOCK_NUM))) return NULL;

    i /= TA_MEMBLOCK_SIZE;

    for(j = i; j < TA_MEMBLOCK_NUM && j-i < needblocks; j++)
        if(ta_memory_blinfo[j].bUsed) break;

    if(j-i < needblocks)
    {
        void* newptr = ta_alloc_memory(newsize);

        if(newptr == NULL) return NULL;

        memcpy(newptr, ptr, ta_memory_blinfo[i].allocsize*TA_MEMBLOCK_SIZE);

        ta_dealloc_memory(ptr);

        return newptr;
    }

    for(j = i + ta_memory_blinfo[i].allocsize; j-i < needblocks; j++)
        ta_memory_blinfo[j].bUsed = TRUE;

    ta_memory_blinfo[i].allocsize = needblocks;

    return ptr;
}

void ta_static_dealloc_memory(void* ptr)
{
    int i, j;

    if(ptr == NULL) return;

    i = (int)ptr - (int)ta_memory_blocks;

    if(!((i%TA_MEMBLOCK_SIZE == 0) &&
        (i/TA_MEMBLOCK_SIZE) < TA_MEMBLOCK_NUM)) return;

    i /= TA_MEMBLOCK_SIZE;

    if(ta_memory_blinfo[i].allocsize != -1)
    {
        for(j = 0; j < ta_memory_blinfo[i].allocsize; j++)
            ta_memory_blinfo[i+j].bUsed = FALSE;

        ta_memory_blinfo[i].allocsize = -1;
    }
}

void ta_init_mempool(void)
{
    int i;

    for(i = 0; i < TA_MEMBLOCK_NUM; i++)
    {
        ta_memory_blinfo[i].bUsed = FALSE;
        ta_memory_blinfo[i].allocsize = -1;
    }

    ta_memory_mode |= TA_BSTARTED_MEMMODE;

    ta_debug_printf("Static memory allocator started.\n");

#ifdef TA_MEMPOOL_DEBUG
    ta_debug_printf("STATIC MEMORY ALLOCATOR IS IN DEBUG MODE!!!\n");
    ta_memuse = ta_memmax = 0;
#endif
}

void* ta_alloc_memory(size_t size)
{
    void* res;

    if(ta_memory_mode & TA_STATIC_MEMMODE)
        res = ta_static_alloc_memory(size);
    else res = malloc(size);

#ifdef TA_MEMPOOL_DEBUG
    if(errno != ENOMEM) ta_memuse += size;
#endif

    return res;
}

void* ta_realloc_memory(void* ptr, size_t newsize)
{
    void* res;

#ifdef TA_MEMPOOL_DEBUG
    size_t sz = ta_pointer_getsize(ptr);
#endif

    if(ta_memory_mode & TA_STATIC_MEMMODE)
        res = ta_static_realloc_memory(ptr, newsize);
    else res = realloc(ptr, newsize);

#ifdef TA_MEMPOOL_DEBUG
    if(errno != ENOMEM) ta_memuse += newsize - sz;
#endif

    return res;
}

void ta_dealloc_memory(void* ptr)
{
#ifdef TA_MEMPOOL_DEBUG
    size_t sz = ta_pointer_getsize(ptr);
#endif

    if(ta_memory_mode & TA_STATIC_MEMMODE)
        ta_static_dealloc_memory(ptr);
    else free(ptr);

#ifdef TA_MEMPOOL_DEBUG
    if(ta_memuse > ta_memmax) ta_memmax = ta_memuse;
    ta_debug_printf("memmax: %d\n", ta_memmax);
    ta_memuse -= sz;
#endif
}

int ta_is_standard_memode(void)
{
    return !(ta_memory_mode & TA_STATIC_MEMMODE);
}

// For static allocation mode only!!!
size_t ta_pointer_getsize(void* ptr)
{
    int i;

    if(ptr == NULL) return 0;

    i = (int)ptr - (int)ta_memory_blocks;

    if(!((i%TA_MEMBLOCK_SIZE == 0) &&
       (i/TA_MEMBLOCK_SIZE < TA_MEMBLOCK_NUM)))
    {
        ta_debug_printf("ta_pointer_getsize[%d, %d]: ptr not found!\n", ptr, i);
        return -1;
    }

    i /= TA_MEMBLOCK_SIZE;

    return ta_memory_blinfo[i].allocsize;
}

/********************************************************************/
/**                     Test Agent Socket Pool                     **/
/********************************************************************/
int ta_create_socket(void)
{
    struct linger optvalue;
    int flag;
    int sockid;

    sockid = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (sockid == -1)
    {

        perror("ta_create_socket");
        assertion(0,"Cannot create socket");
        return -1;
    }

    // setsockopt
    optvalue.l_onoff = 1;
    optvalue.l_linger = 100;
    if (setsockopt(sockid,SOL_SOCKET,SO_LINGER,(const char*)&optvalue,sizeof(optvalue)) != 0)
    {

        perror("init_ta_thread");
        assertion(0,"Cannot setsockopt");
        return -1;
    }

    // setsockopt for optimization
    flag = 1;
    if (setsockopt(sockid,IPPROTO_TCP,TCP_NODELAY,(const char*)&flag,sizeof(int)) != 0)
    {

        perror("init_ta_thread");
        assertion(0,"Cannot setsockopt");
        return -1;
    }

    return sockid;
}

int ta_recv_socket(int sockid, char* data, size_t size)
{
    int res2;

    for(;;)
    {
        res2 = recv(sockid,data,size,MSG_WAITALL);
        if ((res2 == -1) && (errno == EINTR))
        {
            continue;
        }
        return res2;
    }
}

void ta_close_socket(int sockid)
{
    ta_debug_printf("ta_close_socket[%d]\n",sockid);
    shutdown(sockid,SHUT_RDWR);
    close(sockid);
}

void ta_gethostaddress(struct sockaddr_in* addr,const char* host,int port)
{
    struct hostent* hp;

    // Family
    addr->sin_family = AF_INET;
    // Host
    hp = gethostbyname(host);
    if (hp == NULL)
    {
        assertion(0,"Can not find host by name [%s]",host);
        return;
    }
    memcpy((char*)&addr->sin_addr,(char*)hp->h_addr,hp->h_length);
    // Port
    addr->sin_port = htons(port);
}


/********************************************************************/
/**                    Test Agent TCP Communicator                 **/
/********************************************************************/
#define TEST_SYSTEM_DEFAULT_HOST    "127.0.0.1"
#define TEST_SYSTEM_DEFAULT_PORT    2795

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX  _SC_HOST_NAME_MAX
#endif

char test_system_host[HOST_NAME_MAX] = TEST_SYSTEM_DEFAULT_HOST;
int test_system_port = TEST_SYSTEM_DEFAULT_PORT;
struct sockaddr_in tsControlCenter;

int init_tcp_communicator(TAThread thread);
int receive_command_tcp_communicator(TAThread thread,char** buffer_ptr,int buffer_size);
void send_message_tcp_communicator(TAThread thread,const char* buffer,int length);
void destroy_tcp_communicator(TAThread thread);

void ta_setup_tcp_communicator(int argc,const char** argv)
{
    const char* value;

    // read test system address
    value = getenv("TEST_SYSTEM_HOST");
    if (value != NULL)
    {
        strcpy(test_system_host,value);
    }
    value = getenv("TEST_SYSTEM_PORT");
    if (value != NULL)
    {
        sscanf(value,"%d",&test_system_port);
    }

    // init test system descriptor
    ta_gethostaddress(&tsControlCenter,test_system_host,test_system_port);

    // setup tcp communicator
    ta_setup_communicator( init_tcp_communicator );
}

#define COMMUNICATOR_DATA(thread) thread->communicator.data.tcp

int init_tcp_communicator(TAThread thread)
{
    // setup virtual table
    thread->communicator.receive_command = receive_command_tcp_communicator;
    thread->communicator.send_message = send_message_tcp_communicator;
    thread->communicator.destructor = destroy_tcp_communicator;

    // socket
    COMMUNICATOR_DATA(thread).sockid = ta_create_socket();

    // connect
    if (connect(COMMUNICATOR_DATA(thread).sockid,(struct sockaddr*)&tsControlCenter,sizeof(tsControlCenter)) == -1)
    {

        perror("init_ta_thread");
        assertion(0,"Cannot connect to server [%s:%d]",test_system_host,test_system_port);
        return 0;
    }
    return 1;
}

int receive_command_tcp_communicator(TAThread thread,char** buffer_ptr,int buffer_size)
{
int32_t len;
int cancelstate,res2;

    // Receive command
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&cancelstate);

    res2 = ta_recv_socket(COMMUNICATOR_DATA(thread).sockid,(char*)&len,sizeof(len));
    if (res2 != sizeof(len))
    {
        if ((res2 == 0) || ((res2 == -1) && (errno == ECONNRESET)))
        {
            ta_debug_printf( "[%d,%lu] connection closed\n", getpid(), (unsigned long)pthread_self() );
            return -1;
        }
        perror("recv");
        assertion(0,"recv failed");
    }
    len = ntohl(len);

    if (len > buffer_size)
        *buffer_ptr = (char*)ta_alloc_memory(len+1);

    if (ta_recv_socket(COMMUNICATOR_DATA(thread).sockid,*buffer_ptr,len) != len)
    {
        perror("recv");
        assertion(0,"recv of message failed");
    }

    pthread_setcancelstate(cancelstate,&cancelstate);

    return len;
}

void send_message_tcp_communicator(TAThread thread,const char* buffer,int length)
{
    int cancelstate;
    int i;

    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&cancelstate);

//    for (i=0;i<length;i++)
//    {
//        ta_debug_printf("%c", buffer[i]);
 //   }
 //   ta_debug_printf("\n");

    if (send(COMMUNICATOR_DATA(thread).sockid,(char*)buffer,length,0) != length)
        assertion(0,"Send of message failed");

    pthread_setcancelstate(cancelstate,&cancelstate);
}

void destroy_tcp_communicator(TAThread thread)
{
    ta_close_socket( COMMUNICATOR_DATA(thread).sockid );
}

#undef COMMUNICATOR_DATA


/********************************************************************/
/**                  Test Agent Message Communicator               **/
/********************************************************************/
int message_communicator_port = 1859;

int init_message_communicator(TAThread thread);
int  receive_command_message_communicator(TAThread thread,char** buffer_ptr,int buffer_size);
void send_message_message_communicator(TAThread thread,const char* buffer,int length);
void destroy_message_communicator(TAThread thread);

void ta_setup_message_communicator(int well_known_port)
{
    // setup message communicator port
    message_communicator_port = well_known_port;
    // disable auto registration
    ta_auto_registration_enable( 0 );
    // setup message communicator
    ta_setup_communicator( init_message_communicator );
}

#define COMMUNICATOR_DATA(thread) thread->communicator.data.message

//
// Current restriction of the message communicator is the only port (one per system)
//
int init_message_communicator(TAThread thread)
{
    struct sockaddr_in addr;

    // setup virtual table
    thread->communicator.receive_command = receive_command_message_communicator;
    thread->communicator.send_message = send_message_message_communicator;
    thread->communicator.destructor = destroy_message_communicator;

    // socket
    COMMUNICATOR_DATA(thread).sockid = ta_create_socket();

    // set reuse address option
    {
        int optval = 1;
        setsockopt(COMMUNICATOR_DATA(thread).sockid,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int));
    }

    // binding
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(message_communicator_port);

    if (bind(COMMUNICATOR_DATA(thread).sockid,(struct sockaddr*) &addr,sizeof(addr)) == -1)
    {
        perror("init_message_communicator");
        close(COMMUNICATOR_DATA(thread).sockid);
        COMMUNICATOR_DATA(thread).sockid = -1;
        assertion(0,"Cannot bind socket");
        return 0;
    }

    // command socket
    COMMUNICATOR_DATA(thread).cmdsockid = -1;

    return 1;
}

int receive_command_message_communicator(TAThread thread,char** buffer_ptr,int buffer_size)
{
    struct sockaddr_in addr;
    socklen_t addrlen;
    int new_sockid;
    int32_t len;
    int cancelstate,res2;

    // save state
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&cancelstate);

    // close old socket
    if (COMMUNICATOR_DATA(thread).cmdsockid != -1)
    {
        ta_close_socket( COMMUNICATOR_DATA(thread).cmdsockid );
        COMMUNICATOR_DATA(thread).cmdsockid = -1;
    }

    // listen
    if (listen(COMMUNICATOR_DATA(thread).sockid,10) == -1)
    {
        perror("receive_command");
        close(COMMUNICATOR_DATA(thread).sockid);
        assertion(0,"Cannot listen socket");
        return -1;
    }

    // accept new connection
    addrlen = sizeof(addr);
    new_sockid = accept(COMMUNICATOR_DATA(thread).sockid,(struct sockaddr *) &addr, &addrlen);
    memcpy( &COMMUNICATOR_DATA(thread).peer_addr, &addr, sizeof(addr) );

    // receive command
    res2 = ta_recv_socket(new_sockid,(char*)&len,sizeof(len));
    if (res2 != sizeof(len))
    {
        ta_debug_printf( "[%d,%lu] connection closed\n", getpid(), (unsigned long)pthread_self() );
        if (res2 == -1)
        {
            perror("recv");
        }
        return -1;
    }
    len = ntohl(len);

    if (len > buffer_size)
        *buffer_ptr = (char*)ta_alloc_memory(len+1);

    if (ta_recv_socket(new_sockid,*buffer_ptr,len) != len)
    {
        perror("recv");
        assertion(0,"recv of message failed");
    }

    // save command socket
    COMMUNICATOR_DATA(thread).cmdsockid = new_sockid;

    // restore state
    pthread_setcancelstate(cancelstate,&cancelstate);

    return len;
}

void send_message_message_communicator(TAThread thread,const char* buffer,int length)
{
int cancelstate;

    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&cancelstate);

    if (send(COMMUNICATOR_DATA(thread).cmdsockid,(char*)buffer,length,0) != length)
        assertion(0,"Send of message failed");

    pthread_setcancelstate(cancelstate,&cancelstate);
}

void destroy_message_communicator(TAThread thread)
{
    ta_close_socket( COMMUNICATOR_DATA(thread).sockid );
    if (COMMUNICATOR_DATA(thread).cmdsockid != -1)
    {
        ta_close_socket( COMMUNICATOR_DATA(thread).cmdsockid );
    }
}

#undef COMMUNICATOR_DATA


/********************************************************************/
/**                      Test Agent Communicator                   **/
/********************************************************************/
static TestAgentCommunicatorInit ta_communicator_init = NULL;

void ta_setup_communicator(TestAgentCommunicatorInit init_communicator)
{
    ta_communicator_init = init_communicator;
}


/********************************************************************/
/**                       Test Agent Command                       **/
/********************************************************************/
int ta_receive_command(TAThread thread,char** buffer_ptr,int buffer_size)
{
    // TODO: Implement alignment of parameters in sync with the test system side
    return thread->communicator.receive_command( thread, buffer_ptr, buffer_size );
}


/********************************************************************/
/**                       Test Agent Timemarks                     **/
/********************************************************************/
void clear_timemark(struct timespec* timemark)
{
    timemark->tv_nsec = -1;
}

#define CLOCK_MONOTONIC         1
#define CLOCK_PROCESS_CPUTIME_ID    2
#define CLOCK_THREAD_CPUTIME_ID     3
void start_target_operation(TAThread thread)
{
    clock_gettime( CLOCK_REALTIME, &thread->start_time );
    /*
    ta_debug_printf("start_target_operation: %ld, %ld\n",
    (long int)thread->start_time.tv_sec,
    (long int)thread->start_time.tv_nsec);
    */
}

void end_target_operation(TAThread thread)
{
    clock_gettime( CLOCK_REALTIME, &thread->end_time );
    /*
    ta_debug_printf("end_target_operation: %ld, %ld\n",
    (long int)thread->end_time.tv_sec,
    (long int)thread->end_time.tv_nsec);
    */
}

static void ta_insert_timemarks(TAThread thread)
{
    char timemarks_buffer[170];
    int cursor = 0;

    /*
    ta_debug_printf("%ld, %ld, %ld, %ld\n",
    (long int)thread->start_time.tv_sec,
    (long int)thread->start_time.tv_nsec,
    (long int)thread->end_time.tv_sec,
    (long int)thread->end_time.tv_nsec);
    */
    if (thread->start_time.tv_nsec != -1)
    {
        cursor = sprintf( timemarks_buffer, "$tms:long:%ld%clong:%ld",
            (long int)thread->start_time.tv_sec,
            (int)0,
            (long int)thread->start_time.tv_nsec
            );
        cursor++;
        thread->start_time.tv_nsec = -1;
    }
    if (thread->end_time.tv_nsec != -1)
    {
        cursor += sprintf( timemarks_buffer + cursor,
            "$tme:long:%ld%clong:%ld",
            (long int)thread->end_time.tv_sec,
            (int)0,
            (long int)thread->end_time.tv_nsec
            );
        cursor++;
        thread->end_time.tv_nsec = -1;
    }
    if (cursor > 0)
    {
        // Save alignment of the stream
        //while ( cursor % sizeof( long ) != 0 )
        //{
        //    timemarks_buffer[cursor] = 0;
        //    cursor++;
        //}

        insertCharArray_TAOuputStream(thread->stream, timemarks_buffer, cursor );
    }
}


/********************************************************************/
/**                      Test Agent Response                       **/
/********************************************************************/
void ta_send_message(TAThread thread,const char* buffer,int length)
{
    thread->communicator.send_message(thread,buffer,length);
}

void sendResponse(TAThread thread)
{
    int32_t netint;
    int cursor;

    // Insert timemarks
    ta_insert_timemarks( thread );

    // Insert TSMessage Header
    netint = htonl(thread->stream->cursor);
    insertCharArray_TAOuputStream(thread->stream, (char*)&netint, 4);

    // Clear TAThread Output Stream
    cursor = thread->stream->cursor;
    thread->stream->cursor = 0;

    // Send TSMessage
    ta_send_message(thread, thread->stream->buffer, cursor);
}

void sendException(TAThread thread,const char* buff)
{
    thread->stream->cursor = 0;
    writeType_TAStream(thread,"$excp");
    writeString(thread,buff);
    sendResponse(thread);
}

void sendExceptionFromCurrentThread(const char* buff)
{
    TAThread thread = ta_current_thread();
    sendException(thread, buff);
}

/********************************************************************/
/**                  Test Agent Auto Registration                  **/
/********************************************************************/
static int ta_auto_registration = 1;

int ta_auto_registration_enable(int enable)
{
    int old_value = ta_auto_registration;
    ta_auto_registration = enable;
    return old_value;
}

void register_ta_thread(TAThread thread,TAThreadParam* par)
{
    int i;
    pid_t     pid;
    pthread_t self;

    if (!ta_auto_registration)
        return;
    pid  = getpid();
    self = pthread_self();
    writeInt(thread,pid);
    writeULong(thread,self);
    if (par->kind == TANewThread)
    {
        writeString(thread,"NEW_THREAD");
        writePointer(thread,par->arg.pthread_arg);
        sendResponse(thread);
    }
    else if (par->kind == TANewProcess)
    {
        writeString(thread,"NEW_PROCESS");
        writeInt(thread,par->arg.process_arg.argc);
        for( i = 0; i < par->arg.process_arg.argc; i++ )
        {
            writeString(thread,par->arg.process_arg.argv[i]);
        }
#define environ __environ
        for( i = 0; environ[i] != NULL; i++ );
        writeInt(thread,i);
        for( i = 0; environ[i] != NULL; i++ )
        {
            writeString(thread,environ[i]);
        }
#undef environ
        sendResponse(thread);
        if (par->arg.process_arg.argv[par->arg.process_arg.argc] != NULL)
        {
            sendException(thread,"Invariant failed: argv[argc] != NULL");
        }
    }
    else
    {
        writeString(thread,"EXISTING");
        sendResponse(thread);
    }
}


/********************************************************************/
/**                        Test Agent Thread                       **/
/********************************************************************/
pthread_key_t ta_thread_key;

void ta_common_init(void)
{
    // create ta_thread_key
    if (pthread_key_create( &ta_thread_key, NULL ) != 0)
        assertion(0,"Cannot create pthread key");
}

TAThread init_ta_thread(TAThreadParam* par)
{
    TAThread thread;

    // allocate memory
    thread = ta_alloc_memory(sizeof(struct TAThread));
    assertion(thread != 0,"init_ta_thread: not enought memory");

    // connection specific initialization
    ta_communicator_init(thread);

    // output stream
    thread->stream = createTAOuputStream();

    // timemarks
    clear_timemark(&thread->start_time);
    clear_timemark(&thread->end_time);
    thread->level = 0;

    // register in test system
    register_ta_thread(thread,par);

    if (pthread_setspecific( ta_thread_key, thread ) != 0)
    {
        perror("init_ta_thread");
        assertion(0,"Cannot set pthread key value");
        return thread;
    }

    return thread;
}

/* ta_thread_reinit shall be called after fork in a newly-created process */
void ta_thread_reinit(TAThread thread)
{
    pid_t     pid;
    pthread_t self;

    // partially destroy old agent descriptor
    destroyTAInputStream(thread->stream);
    if (thread->communicator.destructor != NULL)
    {
        thread->communicator.destructor(thread);
    }

    // init communicator
    ta_communicator_init(thread);

    // output stream
    thread->stream = createTAOuputStream();

    // timemarks (use old values)
    // clear_timemark(&thread->start_time);
    // clear_timemark(&thread->end_time);

    // register in test system
    pid  = getpid();
    self = pthread_self();
    writeInt(thread,pid);
    writeULong(thread,self);
    writeString(thread,"FORKED_PROCESS");
    sendResponse(thread);
}

TAThread ta_current_thread(void)
{
    static TAThreadParam threadParam = { TARequest };
    TAThread thread;

    thread = (TAThread)pthread_getspecific(ta_thread_key);
    if (thread != NULL)
        return thread;
    return init_ta_thread(&threadParam);
}

void destroy_ta_thread(TAThread thread)
{
    thread->level--;
    if (thread->level > 0)
        return;
    destroyTAInputStream(thread->stream);
    if (thread->communicator.destructor != NULL)
    {
        thread->communicator.destructor(thread);
    }
    ta_dealloc_memory(thread);
}


/********************************************************************/
/**                     Test Agent Main Functions                  **/
/********************************************************************/
void cleanup_ta_thread(void* thread)
{
    destroy_ta_thread((TAThread)thread);
}

#define TA_STATIC_BUFFER_SIZE (128*1024)
void* ta_main_routine(TAThreadParam* par)
{
    TAThread thread;
    TACommandVerdict verdict;
    CommandProcessorRoutine routine;
    char static_buffer[TA_STATIC_BUFFER_SIZE+1];
    char *buffer,*arguments;
    int len,arguments_length;

    if (par != NULL)
    {
        // The first call
        thread = init_ta_thread(par);
        sigsetjmp(thread->start_point,1);
        thread->level = 1;
    }
    else
    {
        // Recursive call
        thread = ta_current_thread();
        thread->level++;
    }
    pthread_cleanup_push(cleanup_ta_thread,thread);

    START_EXCEPTION_PROTECTED_SECTION(test_agent_exception_handler);

    buffer = static_buffer;
    // Main cycle
    for(;;)
    {
        // Receive command
        len = ta_receive_command( thread, &buffer, TA_STATIC_BUFFER_SIZE );
        if (len < 0)
            break;

        // Parse command
        arguments = memchr(buffer,':',len);
        if (arguments != NULL)
        {
            *arguments = '\0';
            arguments++;
            arguments_length = &(buffer[len]) - arguments;
        }
        else
        {
            buffer[len] = '\0';
            arguments_length = 0;
        }

        {
            /*
            struct timespec currtime;
            // Dump operation start time
            //clock_gettime( CLOCK_REALTIME, &currtime );
            ta_debug_printf("search timemark: %ld, %ld\n",
            (long int)currtime.tv_sec,
            (long int)currtime.tv_nsec);*/
        }

        // Call command processor
        ta_debug_printf( "search for %s (%lu)...\n", buffer, (unsigned long)pthread_self() );

        routine = ta_get_command_processor(buffer);

        if (routine == NULL)
        {
            char* err_msg = ta_alloc_memory( strlen(buffer) + 48 );
            sprintf( err_msg, "Unsupported test agent command: %s", buffer );

            sendException(thread,err_msg);

            ta_debug_printf("Unsupported command: %s\n",buffer);
            ta_dealloc_memory(err_msg);
        }
        else
        {

            verdict = routine(thread,createTAInputStream(arguments,arguments_length));
        }

        // Deallocate resources
        if (buffer != static_buffer)
        {
            ta_dealloc_memory(buffer);
            buffer = static_buffer;
        }
        // Break condition
        if (verdict.finish)
            break;
    }

    END_EXCEPTION_PROTECTED_SECTION();
    // Destroy thread
    //destroy_ta_thread(thread);
    pthread_cleanup_pop(1);

    return verdict.status;
}

void* ta_thread_main_routine(void* arg)
{
    TAThreadParam threadParam;

    threadParam.kind = TANewThread;
    threadParam.arg.pthread_arg = arg;
    ta_debug_printf("STARTING THREAD WITH PARAMETER: %ld\n", ((long)arg));

    return ta_main_routine(&threadParam);
}

void ta_process_main_init(void)
{
#ifndef TA_MEMPOOL_DEBUG
    const char* smemmode = NULL;

    if((smemmode = getenv("TA_MEMORY_MODE")) != NULL)
    {
        if(strcmp(smemmode, "static") == 0)
            ta_memory_mode = TA_STATIC_MEMMODE;
    }
#else
    ta_memory_mode = TA_STATIC_MEMMODE;
#endif
}

int ta_process_main_routine(int argc,const char** argv)
{
    TAThreadParam threadParam;

    // init common part of test agents
    ta_common_init();
    // start main activity
    threadParam.kind = TANewProcess;
    threadParam.arg.process_arg.argc = argc;
    threadParam.arg.process_arg.argv = argv;
    return (int)ta_main_routine(&threadParam);
}


/********************************************************************/
/**                Test Agent Command Default Verdict              **/
/********************************************************************/
TACommandVerdict taDefaultVerdict = { 0, NULL};


/********************************************************************/
/**                    Test Agent Command Processor                **/
/********************************************************************/
String2PtrHashMap ta_command_dictionary;

void ta_register_command(const char* command,CommandProcessorRoutine routine)
{
    ta_s2p_hash_map_put( &ta_command_dictionary, command, routine );
}

CommandProcessorRoutine ta_get_command_processor(const char* command)
{
    return (CommandProcessorRoutine)ta_s2p_hash_map_get(&ta_command_dictionary,command);
}


/********************************************************************/
/**             Test Agent Cancellation Point Detection            **/
/********************************************************************/
void cancelpoint_detector(void* par)
{
TAThread thread = (TAThread)par;

    ta_debug_printf("ENDED in DETECTOR (%u)...\n", (unsigned long)pthread_self());
    END_TARGET_OPERATION(thread);

    writeInt(thread,1);
    sendResponse(thread);
}

void dr_cancelpoint_detector(void* par)
{
    struct CancelPointDetectorParam* param=(struct CancelPointDetectorParam*)par;
    TAThread thread = (TAThread)param->thread;

    ta_debug_printf("ENDED in CP DR DETECTOR (%u)...\n", (unsigned long)pthread_self());
    END_TARGET_OPERATION(thread);
    writeDeferredReaction(thread, param->defferedReactionName);
    writeInt(thread,1);
    sendResponse(thread);
    ta_debug_printf("in CP DR DONE (%u)....\n", (unsigned long)pthread_self());
}

/********************************************************************/
/**                        Test Agent Sandbox                      **/
/********************************************************************/
const char* ta_test_directory = "/tmp/olver/agent";

const char* ta_get_test_file_path(const char* path)
{
    char* full_path;
    if(path != NULL && strlen(path) != 0)
    {
        full_path = ta_alloc_memory(strlen(ta_test_directory) + strlen(path) + 2);
        if(full_path != NULL)
        {
            sprintf(full_path, "%s/%s", ta_test_directory, path);
        }
    }
    
    return full_path;
}
