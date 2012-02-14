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

#include "io/fstream/fstream_agent.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "fs/fs/fs_agent.h"
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/uio.h>

/* typedef struct FILE _IO_FILE; */

/* since these are binary-only, we need prototypes here */
int _IO_feof(struct _IO_FILE *);
int _IO_putc(int, struct _IO_FILE *);
int _IO_getc(struct _IO_FILE *);
int _IO_puts(const char *);

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

static TACommandVerdict a_fileno_cmd( TAThread thread, TAInputStream stream ) {
    int res;
    FILE * file = (FILE *)readPointer( & stream );
    START_TARGET_OPERATION( thread );
    res = fileno( file );
    END_TARGET_OPERATION( thread );
    writeInt( thread, res   );
    writeInt( thread, errno );
    sendResponse( thread );
    return taDefaultVerdict;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict _IO_feof_cmd(TAThread thread,TAInputStream stream)
{
    struct _IO_FILE * file;
    int res;

    file=(struct _IO_FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res =  _IO_feof(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict _IO_getc_cmd(TAThread thread,TAInputStream stream)
{
    struct _IO_FILE * file;
    int res;

    file=(struct _IO_FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res =  _IO_getc(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict _IO_putc_cmd(TAThread thread,TAInputStream stream)
{
    struct _IO_FILE * file;
    int res;
    int __c;

    __c=readInt(&stream);
    file=(struct _IO_FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res =  _IO_putc(__c, file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict _IO_puts_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char* __c;

    __c=readString(&stream);

    START_TARGET_OPERATION(thread);
    res =  _IO_puts(__c);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __fpending_cmd(TAThread thread,TAInputStream stream)
{
    size_t res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = __fpending(file);
    END_TARGET_OPERATION(thread);

    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clearerr_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  file ;

    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    clearerr(file);
    END_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fclose_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fclose(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fdopen_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  res;
    char*  mode;
    int    fildes;

    fildes=readInt(&stream);
    mode=readString(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fdopen(fildes, mode); ;
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict feof_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = feof(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ferror_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = ferror(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fflush_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fflush(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fflush_unlocked_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fflush_unlocked(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fgetc_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fgetc(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fgetpos_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;
    fpos_t * pos;

    file=(FILE*)readPointer(&stream);
    pos=(fpos_t*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fgetpos(file, pos);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fgetpos64_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;
    fpos64_t * pos;

    file=(FILE*)readPointer(&stream);
    pos=(fpos64_t*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fgetpos64(file, pos);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fgets_cmd(TAThread thread,TAInputStream stream)
{
    char*  res;
    FILE*  file;
    char*  s;
    int    n;

    file=(FILE*)readPointer(&stream);
    n=readInt(&stream);
    s=(char*)ta_alloc_memory(n);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res= fgets(s, n, file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res!=NULL);
    if (res!=NULL)
    {
        writeString(thread, s);
    }
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fileno_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fileno(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fgetwc_unlocked_cmd(TAThread thread,TAInputStream stream)
{
    wint_t    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fgetwc_unlocked(file);
    END_TARGET_OPERATION(thread);

    writeUInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;

    return taDefaultVerdict;
}

static TACommandVerdict fopen_cmd(TAThread thread,TAInputStream stream)
{
    char*  filename;
    char*  mode;
    FILE* res;

    filename=readString(&stream);
    mode=readString(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fopen(filename, mode);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fopen64_cmd(TAThread thread,TAInputStream stream)
{
    char*  filename;
    char*  mode;
    FILE* res;

    filename=readString(&stream);
    mode=readString(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fopen64(filename, mode);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fputc_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int    c;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    c=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fputc(c, file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fputs_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    char*  s;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    s=readString(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fputs(s, file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fread_cmd(TAThread thread,TAInputStream stream)
{
    size_t    res;
    void*     ptr;
    size_t    size;
    size_t    nitems;
    FILE*     file;

    file=(FILE*)readPointer(&stream);
    ptr=readPointer(&stream);
    size=readSize(&stream);
    nitems=readSize(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fread(ptr, size, nitems, file);
    END_TARGET_OPERATION(thread);

    writeSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict freopen_cmd(TAThread thread,TAInputStream stream)
{
    char*  filename;
    char*  mode;
    FILE*  res;
    FILE*  file;

    filename=readString(&stream);
    mode=readString(&stream);
    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = freopen(filename, mode,file);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict freopen64_cmd(TAThread thread,TAInputStream stream)
{
    char*  filename;
    char*  mode;
    FILE*  res;
    FILE*  file;

    filename=readString(&stream);
    mode=readString(&stream);
    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = freopen64(filename, mode,file);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fseek_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;
    long   offset;
    int    whence;

    file=(FILE*)readPointer(&stream);
    offset=(long)readLLong(&stream);
    whence=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  fseek(file, offset, whence);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fseeko_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;
    off_t  offset;
    int    whence;

    file=(FILE*)readPointer(&stream);
    offset=(off_t)readLLong(&stream);
    whence=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  fseeko(file, offset, whence);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fseeko64_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;
    loff_t offset;
    int    whence;

    file=(FILE*)readPointer(&stream);
    offset=(loff_t)readLLong(&stream);
    whence=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  fseeko64(file, offset, whence);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fsetpos_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;
    fpos_t *pos;

    file=(FILE*)readPointer(&stream);
    pos=(fpos_t *)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  fsetpos(file, pos);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fsetpos64_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;
    fpos64_t *pos;

    file=(FILE*)readPointer(&stream);
    pos=(fpos64_t *)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  fsetpos64(file, pos);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ftell_cmd(TAThread thread,TAInputStream stream)
{
    long    res;
    FILE*   file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  ftell(file);
    END_TARGET_OPERATION(thread);

    writeLLong(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ftello_cmd(TAThread thread,TAInputStream stream)
{
    off_t    res;
    FILE*   file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  ftello(file);
    END_TARGET_OPERATION(thread);

    writeLLong(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ftello64_cmd(TAThread thread,TAInputStream stream)
{
    off_t    res;
    FILE*    file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  ftello64(file);
    END_TARGET_OPERATION(thread);

    writeLLong(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fwrite_cmd(TAThread thread,TAInputStream stream)
{
    size_t    res;
    void*     ptr;
    size_t    size;
    size_t    nitems;
    FILE*     file;

    file=(FILE*)readPointer(&stream);
    ptr=readPointer(&stream);
    size=readSize(&stream);
    nitems=readSize(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = fwrite(ptr, size, nitems, file);
    END_TARGET_OPERATION(thread);

    writeSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getc_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = getc(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getc_unlocked_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = getc_unlocked(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getchar_cmd(TAThread thread,TAInputStream stream)
{
    char * input          ;
    char * stdinAsFileName;
    int res       ;
    int savedErrno;
    FILE * stdinAsFile;
    FILE * oldStdin   ;

    input           = readString( & stream );
    stdinAsFileName = readString( & stream );
    //printf( "getchar_cmd : input           is %s\n", input           );
    //printf( "getchar_cmd : stdinAsFileName is %s\n", stdinAsFileName );
    stdinAsFile = fopen( stdinAsFileName, "w" );
    //printf( "getchar_cmd : stdinAsFile is %sNULL\n", stdinAsFile == NULL ? "" : "not " );
    fputs( input, stdinAsFile );
    fclose( stdinAsFile );
    stdinAsFile = freopen( stdinAsFileName, "r", stdin );
    //printf( "getchar_cmd : stdinAsFile is %sNULL\n", stdinAsFile == NULL ? "" : "not " );
    //oldStdin = stdin;
    //stdin = stdinAsFile;
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = getchar();
    END_TARGET_OPERATION(thread);

    savedErrno = errno;
    //stdin = oldStdin;
    fclose( stdinAsFile );

    writeInt( thread, res       );
    writeInt( thread, savedErrno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict getchar_unlocked_cmd(TAThread thread,TAInputStream stream)
{
    char * input          ;
    char * stdinAsFileName;
    int res       ;
    int savedErrno;
    FILE * stdinAsFile;

    input           = readString( & stream );
    stdinAsFileName = readString( & stream );
    stdinAsFile = fopen( stdinAsFileName, "w" );
    fputs( input, stdinAsFile );
    fclose( stdinAsFile );
    stdinAsFile = freopen( stdinAsFileName, "r", stdin );
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = getchar_unlocked();
    END_TARGET_OPERATION(thread);

    savedErrno = errno;
    fclose( stdinAsFile );

    writeInt( thread, res       );
    writeInt( thread, savedErrno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict getw_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = getw(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict putc_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int    c;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    c=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = putc(c, file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict putc_unlocked_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int    c;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    c=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = putc_unlocked(c, file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict putchar_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int c;

    c=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = putchar(c);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict putchar_unlocked_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int c;

    c=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = putchar_unlocked(c);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict puts_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    char*  s;

    s=readString(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = puts(s);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict putw_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int    c;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    c=readInt(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = putw(c, file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict rewind_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    rewind(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ungetc_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int    c;
    int    to_stdin;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);
    c=readInt(&stream);
    to_stdin=readInt(&stream);

    if (!to_stdin)
    {
        START_TARGET_OPERATION(thread);
        res = ungetc(c, file);
        END_TARGET_OPERATION(thread);
    }
    else
    {
        START_TARGET_OPERATION(thread);
        res = ungetc(c, stdin);
        END_TARGET_OPERATION(thread);
    }
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_io_fstream_fstream_commands(void)
{
    ta_register_command( "a_fileno", a_fileno_cmd );

    ta_register_command("_IO_feof",_IO_feof_cmd);
    ta_register_command("_IO_getc",_IO_getc_cmd);
    ta_register_command("_IO_putc",_IO_putc_cmd);
    ta_register_command("_IO_puts",_IO_puts_cmd);
    ta_register_command("__fpending",__fpending_cmd);
    ta_register_command("clearerr",clearerr_cmd);
    ta_register_command("fclose",fclose_cmd);
    ta_register_command("fdopen",fdopen_cmd);
    ta_register_command("feof",feof_cmd);
    ta_register_command("ferror",ferror_cmd);
    ta_register_command("fflush",fflush_cmd);
    ta_register_command("fflush_unlocked",fflush_unlocked_cmd);
    ta_register_command("fgetc",fgetc_cmd);
    ta_register_command("fgetpos",fgetpos_cmd);
    ta_register_command("fgetpos64",fgetpos64_cmd);
    ta_register_command("fgets",fgets_cmd);
    ta_register_command("fgetwc_unlocked",fgetwc_unlocked_cmd);
    ta_register_command("fileno",fileno_cmd);
    ta_register_command("fopen",fopen_cmd);
    ta_register_command("fopen64",fopen64_cmd);
    ta_register_command("fputc",fputc_cmd);
    ta_register_command("fputs",fputs_cmd);
    ta_register_command("fread",fread_cmd);
    ta_register_command("freopen",freopen_cmd);
    ta_register_command("freopen64",freopen64_cmd);
    ta_register_command("fseek",fseek_cmd);
    ta_register_command("fseeko",fseeko_cmd);
    ta_register_command("fseeko64",fseeko64_cmd);
    ta_register_command("fsetpos",fsetpos_cmd);
    ta_register_command("fsetpos64",fsetpos64_cmd);
    ta_register_command("ftell",ftell_cmd);
    ta_register_command("ftello",ftello_cmd);
    ta_register_command("ftello64",ftello64_cmd);
    ta_register_command("fwrite",fwrite_cmd);
    ta_register_command("getc",getc_cmd);
    ta_register_command("getc_unlocked",getc_unlocked_cmd);
    ta_register_command("getchar",getchar_cmd);
    ta_register_command("getchar_unlocked",getchar_unlocked_cmd);
    ta_register_command("getw",getw_cmd);
    ta_register_command("putc",putc_cmd);
    ta_register_command("putc_unlocked",putc_unlocked_cmd);
    ta_register_command("putchar",putchar_cmd);
    ta_register_command("putchar_unlocked",putchar_unlocked_cmd);
    ta_register_command("puts",puts_cmd);
    ta_register_command("putw",putw_cmd);
    ta_register_command("rewind",rewind_cmd);
    ta_register_command("ungetc",ungetc_cmd);
}
