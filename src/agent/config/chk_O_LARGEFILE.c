#define _GNU_SOURCE

#include <sys/file.h>
#include <zlib.h>

#include <stdio.h>


int main(int argc, char**argv)
{
    printf("O_LARGEFILE=0x%X\n", (int)O_LARGEFILE);
    
    //zlib.h defines, required for util.compress
    printf("Z_NULL=0x%X\n", (int)Z_NULL);
    printf("MAX_WBITS=0x%X\n", (int)MAX_WBITS);
    printf("MAX_MEM_LEVEL=0x%X\n", (int)MAX_MEM_LEVEL);
    printf("Z_NO_FLUSH=0x%X\n", (int)Z_NO_FLUSH);
    printf("Z_PARTIAL_FLUSH=0x%X\n", (int)Z_PARTIAL_FLUSH);
    printf("Z_SYNC_FLUSH=0x%X\n", (int)Z_SYNC_FLUSH);
    printf("Z_FULL_FLUSH=0x%X\n", (int)Z_FULL_FLUSH);
    printf("Z_FINISH=0x%X\n", (int)Z_FINISH);
    printf("Z_ERRNO=0x%X\n", (int)Z_ERRNO);
    printf("Z_STREAM_ERROR=0x%X\n", (int)Z_STREAM_ERROR);
    printf("Z_DATA_ERROR=0x%X\n", (int)Z_DATA_ERROR);
    printf("Z_MEM_ERROR=0x%X\n", (int)Z_MEM_ERROR);
    printf("Z_BUF_ERROR=0x%X\n", (int)Z_BUF_ERROR); 
    printf("Z_VERSION_ERROR=0x%X\n", (int)Z_VERSION_ERROR);
    printf("Z_OK=0x%X\n", (int)Z_OK);
    printf("Z_STREAM_END=0x%X\n", (int)Z_STREAM_END);
    printf("Z_NEED_DICT=0x%X\n", (int)Z_NEED_DICT);
    printf("Z_DEFAULT_COMPRESSION=0x%X\n", (int)Z_DEFAULT_COMPRESSION);
    printf("Z_NO_COMPRESSION=0x%X\n", (int)Z_NO_COMPRESSION);
    printf("Z_BEST_SPEED=0x%X\n", (int)Z_BEST_SPEED);
    printf("Z_BEST_COMPRESSION=0x%X\n", (int)Z_BEST_COMPRESSION);
    printf("Z_DEFAULT_STRATEGY=0x%X\n", (int)Z_DEFAULT_STRATEGY);
    printf("Z_FILTERED=0x%X\n", (int)Z_FILTERED);
    printf("Z_HUFFMAN_ONLY=0x%X\n", (int)Z_HUFFMAN_ONLY);
    printf("Z_BINARY=0x%X\n", (int)Z_BINARY);
    printf("Z_ASCII=0x%X\n", (int)Z_BINARY);
    printf("Z_UNKNOWN=0x%X\n", (int)Z_UNKNOWN);
    printf("Z_DEFLATED=0x%X\n", (int)Z_DEFLATED);
    printf("ZLIB_VERSION=0x%X\n", (int)ZLIB_VERSION);
    printf("ZSTREAM_SIZE=0x%X\n", (int)sizeof(z_stream));
    
    return 0;
}
