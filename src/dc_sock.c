#define SOCKET_ERROR (-1)
#define DC_COMMAND_FAILED (-1)
#define DC_COMMAND_PASSED (0)
#define MASTER_AGENT_DEFAULT_PORT    1859

#define DC_VERBOSE 0

static int master_agent_port = MASTER_AGENT_DEFAULT_PORT;
static int debug_enabled = 1;

/********************************************************************/
/**                          Local data                            **/
/********************************************************************/
//input buffer
static int      dc_memory_available;
static char*    dc_rec_data;
static int      dc_socket;

//input buffer parse results (after dc_parse_...)
static int32_t  dc_pr_int;
static char*    dc_pr_string;
static int      dc_pr_length;
static char*    dc_pr_start;

static char*    dc_send_buffer;
static int      dc_send_buffer_length;
static int      dc_send_buffer_position;

int dc_printf(char* format, ...);

void dc_dmp(char *bf, int sz)
{
    if(DC_VERBOSE)
    {
        int i, j;
        printf("\n");
        if(sz>32) sz = 32;
        for(i=0;i<sz;)
        {
            for(j=0;j<16&&i<sz;j++,i++)
            {
                printf("%02X ", (char)bf[i], (char)bf[i]);
            }
            printf(" : ");
            for(;j>0;j--)
            {
                char c = (char)bf[i-j];
                if(c>30)
                    printf("%c", c);
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
}


static int dc_parse_start()
{
    dc_pr_int = 0;
    dc_pr_length = 0;
    dc_pr_start = dc_rec_data;
}

static int dc_avail(int size)
{
    int diff = dc_pr_start - dc_rec_data;
    if(dc_memory_available - diff >=size)
        return 1;

    perror("no buffer space available");
    return 0;
}

static int dc_parse_int()
{
    dc_printf("dc_parse_int\n");
    if( dc_avail(sizeof(int32_t)) )
    {
        int netint = *((int32_t*)dc_pr_start);
        dc_pr_int = ntohl(netint);
        dc_printf("netint:%d dc_pr_int:%d\n", netint, dc_pr_int);
        dc_pr_start += 4;
        return 1;
    }

    dc_pr_int = 0xCCCCCCCC;
    return 0;
}

static int dc_parse_string()
{
    if( dc_avail(4*sizeof(char)) ) // "str:"
    {
        if( 0 == memcmp(dc_pr_start, "str:", 4) )
        {
            dc_pr_start += 4;
            dc_pr_string = dc_pr_start;
            dc_pr_length = strlen(dc_pr_start);
            dc_pr_start += dc_pr_length+1;
            return 1;
        }
    }
    return 0;
}

static int dc_parse_bytearray()
{
    if( dc_avail(3*sizeof(char) + sizeof(int32_t)) ) // "ba:<int>"
    {
        dc_printf("one:%s\n", dc_pr_start);

        if( 0 == memcmp(dc_pr_start, "ba:", 3) )
        {
            dc_printf("two\n");
            dc_pr_start += 3;
            dc_parse_int();
            dc_printf("int:%d\n", dc_pr_int);
            dc_pr_length = dc_pr_int;
            dc_pr_string = dc_pr_start;
            if(dc_avail(dc_pr_int))
            {
                dc_pr_start += dc_pr_length;
                return 1;
            }
            else
                return 0;
        }
    }
    perror("error in dc_parse_bytearray\n");
    return 0;
}

int dc_printf(char* format, ...)
{
    int cancelstate;
    va_list arg_list;
    int res = 0;


    if (debug_enabled)
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
        out = fopen("agent.log", "a+b");
        res = vfprintf(out, format, arg_list);
        fclose(out);
        va_end(arg_list);

        pthread_setcancelstate(cancelstate,&cancelstate);
    }
    return res;
}

int dc_save_bytearray(char* localPath)
{
    FILE *f;
    char *fbuff=NULL;
    dc_printf("dc_save_bytearray: localPath:%s\n", localPath);

    remove(localPath);
    f = fopen(localPath, "wb");
    if(!f)
    {
        perror("dc_save_bytearray: Could not create file: localPath");
        return DC_COMMAND_FAILED;
    }

    if( dc_pr_length!=fwrite(dc_pr_string, 1, dc_pr_length, f) )
    {
        perror("dc_save_bytearray: Error saving file");
        fclose(f);
        return DC_COMMAND_FAILED;
    }

    fclose(f);

    return DC_COMMAND_PASSED;
}

static inline void dc_bf_mem(int size)
{
    if( (dc_send_buffer_position+size) >=dc_send_buffer_length)
    {
        int newsize = dc_send_buffer_length*2;
        char* newbuff;
        if(!newsize) newsize = 1024*1024;
        while( newsize<=(dc_send_buffer_position+size) )
        {
            newsize*=2;
        }

        newbuff = (char*)malloc(newsize);
        if(newbuff)
        {
            memcpy(newbuff, dc_send_buffer, dc_send_buffer_position);
            free(dc_send_buffer);
            dc_send_buffer = newbuff;
            dc_send_buffer_length = newsize;
        }
    }
}

// NULL-terminate buffer
void dc_bf_term()
{
    dc_bf_mem(sizeof(char));
    dc_send_buffer[dc_send_buffer_position] = '\0';
}

void dc_bf_reset()
{
    dc_send_buffer_position = 0;
}

static inline void dc_bf_addch(char c)
{
    dc_bf_mem(1);
    dc_send_buffer[dc_send_buffer_position++] = c;

    if(DC_VERBOSE)
    {
        dc_printf("dc_bf_addch:");
        dc_dmp(dc_send_buffer, dc_send_buffer_position);
    }
}

// add some string without leading 0
void dc_bf_putstr(char* str)
{
    int len = strlen(str);
    dc_bf_mem(len);
    memcpy( &dc_send_buffer[dc_send_buffer_position], str, len);
    dc_send_buffer_position+=len;

    if(DC_VERBOSE)
    {
        dc_printf("dc_bf_putstr:%s", str);
        dc_dmp(dc_send_buffer, dc_send_buffer_position);
    }
}

// add some string with "str:" prefix and leading 0
void dc_bf_addstr(char* str)
{
    int len = strlen(str)+1;
    int ind;
    dc_bf_putstr("str:");
    dc_bf_mem(len);
    memcpy( &dc_send_buffer[dc_send_buffer_position], str, len);
    dc_send_buffer_position+=len;

    if(DC_VERBOSE)
    {
        dc_printf("dc_bf_addstr:%s", str);
        dc_dmp(dc_send_buffer, dc_send_buffer_position);
    }

}

// add integer in network order
void dc_bf_addint(int num)
{
    int netint = htonl(num);
    dc_bf_mem(sizeof(int32_t));
    *((int32_t*)&dc_send_buffer[dc_send_buffer_position])=netint;
    dc_send_buffer_position+=sizeof(int32_t);

    if(DC_VERBOSE)
    {
        dc_printf("dc_bf_addint:%d", num);
        dc_dmp(dc_send_buffer, dc_send_buffer_position);
    }

}

void dc_bf_addbytearray(char *bytes, int size)
{
    dc_bf_putstr("ba:");
    dc_bf_addint(size);
    dc_bf_mem(size);
    memcpy( &dc_send_buffer[dc_send_buffer_position], bytes, size);
    dc_send_buffer_position+=size;
}

int dc_bf_addfile(char* localPath)
{
    FILE *f;
    char *fbuff=NULL;
    int fsize;
    struct stat flenstat;
    dc_printf("dc_bf_addfile: localPath:%s\n", localPath);

    f = fopen(localPath, "rb");
    if(!f)
    {
        perror("dc_bf_addfile: File not found: localPath");
        return DC_COMMAND_FAILED;
    }

    if(0==fstat(fileno(f), &flenstat))
    {
        fsize = (int)flenstat.st_size;
        fbuff = malloc(fsize);
        if(!fbuff)
        {
            perror("dc_bf_addfile: not enough memory to read file");
            fclose(f);
            return DC_COMMAND_FAILED;
        }

        if(fsize!=fread(fbuff, 1, fsize, f))
        {
            perror("dc_bf_addfile: error reading file localPath");
            free(fbuff);
            fclose(f);
            return DC_COMMAND_FAILED;
        }
    } else {
        perror("dc_bf_addfile: fstat failed for localPath");
        fclose(f);
        return DC_COMMAND_FAILED;
    }

    if(fbuff)
    {
        dc_bf_addbytearray(fbuff, fsize);
        free(fbuff);
    }
    fclose(f);

    return DC_COMMAND_PASSED;
}

int dc_bf_addfileifexists(char* localPath)
{
    FILE* f = fopen(localPath, "rb");
    if(!f)
    {
        char fakebuff[1];
        dc_bf_addbytearray(fakebuff, 0);
        return DC_COMMAND_FAILED;
    } else {
        fclose(f);
        dc_bf_addfile(localPath);
        return DC_COMMAND_PASSED;
    }
}

int dc_bf_send()
{
    int32_t netint = htonl(dc_send_buffer_position);
    if (send(dc_socket,&netint,sizeof(netint),0) != sizeof(netint))
    {
        dc_bf_reset();
        perror("dc_bf_send:send1");
        return 0;
    }
    if(DC_VERBOSE)
    {
        dc_printf("sending data", dc_send_buffer);
        dc_dmp(dc_send_buffer, dc_send_buffer_position);
    }

    if (send(dc_socket,dc_send_buffer,dc_send_buffer_position,0) != dc_send_buffer_position)
    {
        dc_bf_reset();
        perror("dc_bf_send:error sending data");
        return 0;
    }
    dc_bf_reset();
    return 1;
}


static int ts_recv(int dc_socket, char* buffer, int dc_length, int flags)
{
    int was_received,to_be_received,res2;

    was_received = 0;
    to_be_received = dc_length;
    for(;;)
    {
        res2 = recv( dc_socket, buffer+was_received, to_be_received, 0 );
        if ((res2 == SOCKET_ERROR) || (res2 == 0))
            return res2;
        if (res2 == to_be_received)
            return dc_length;
        was_received = was_received + res2;
        to_be_received = to_be_received - res2;
    }
}

void init_dc()
{
    dc_memory_available = 0;
    dc_rec_data = NULL;

    dc_send_buffer = NULL;
    dc_send_buffer_length = 0;
    dc_send_buffer_position = 0;

    dc_socket = 0;
}

void finish_dc()
{
    if( dc_socket )
        close(dc_socket);
    if(dc_rec_data)
        free(dc_rec_data);

    if(dc_send_buffer)
        free(dc_send_buffer);
}

int dc_receive_message()
{
    int res2;

    res2 = ts_recv(dc_socket,(char*)&dc_memory_available,sizeof(dc_memory_available),0);
    if (res2 != sizeof(dc_memory_available))
    {
        if (res2 == SOCKET_ERROR)
            perror("dc_receive_message");
        dc_rec_data = NULL;
        dc_memory_available = 0;
        return (res2 == 0) ? 1 : 0;
    }
    dc_memory_available = ntohl(dc_memory_available);

    dc_rec_data = (char*)malloc(dc_memory_available+1);
    res2 = ts_recv(dc_socket,dc_rec_data,dc_memory_available,0);
    dc_rec_data[dc_memory_available]='\0';

    if (res2 != dc_memory_available)
    {
        if (res2 == SOCKET_ERROR)
            perror("ts_recv");
        free(dc_rec_data);
        dc_rec_data = NULL;
        return 0;
    }

    dc_printf("dc_receive_message(%d):%s\n", dc_memory_available, dc_rec_data);
    if(DC_VERBOSE)
    {
        dc_dmp(dc_rec_data, dc_memory_available);
    }

    dc_parse_start();
    return 1;
}

int ta_send_command_to_master_agent()
{
    struct sockaddr_in addr;
    struct hostent* hp;
    int32_t netint;

    dc_bf_term();
    dc_printf("sending command: %s\n", dc_send_buffer);
    dc_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (dc_socket == -1)
    {
        perror("dc_socket");
        return 0;
    }
    addr.sin_family = AF_INET;
    hp = gethostbyname("localhost");
    if (hp == NULL)
    {
        perror("gethostbyname");
        close(dc_socket);
        return 0;
    }
    memcpy((char*)&addr.sin_addr,(char*)hp->h_addr,hp->h_length);
    addr.sin_port = htons(master_agent_port);

    if (connect(dc_socket,(struct sockaddr*) &addr,sizeof(addr)) == -1)
    {
        perror("connect");
        close(dc_socket);
        return 0;
    }

    netint = htonl(dc_send_buffer_position);
    dc_printf("size:%d netint:%d\n", dc_send_buffer_position, netint);
    if (send(dc_socket,&netint,sizeof(netint),0) != sizeof(netint))
    {
        perror("ta_send_command_to_master_agent:send1");
        close(dc_socket);
        return 0;
    }
    if (send(dc_socket,dc_send_buffer,dc_send_buffer_position,0) != dc_send_buffer_position)
    {
        perror("ta_send_command_to_master_agent:send2");
        close(dc_socket);
        return 0;
    }

    sleep(1);
    //close(dc_socket);
    return 1;
}
