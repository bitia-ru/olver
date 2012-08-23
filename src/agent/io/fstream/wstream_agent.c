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

#include "io/fstream/wstream_agent.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "fs/fs/fs_agent.h"
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/uio.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict fgetwc_cmd(TAThread thread,TAInputStream stream)
{
    wint_t    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = fgetwc(file);
    END_TARGET_OPERATION(thread);

    writeUInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fgetws_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t * res ;
    FILE    * file;
    int       n   ;
    wchar_t * ws  ;

    file = (FILE *)readPointer( & stream );
    n    = readInt( & stream );
    ws   = (wchar_t *)ta_alloc_memory( n * sizeof( wchar_t ) );

    START_TARGET_OPERATION(thread);
    res= fgetws(ws, n, file);
    END_TARGET_OPERATION(thread);

    writeInt( thread, res != NULL );
    if ( res != NULL ) { writeWString( thread, ws ); }
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict fputwc_cmd(TAThread thread,TAInputStream stream)
{
    wint_t    res;
    wchar_t    wc;
    FILE*  file ;

    wc=readInt(&stream);
    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = fputwc(wc, file);
    END_TARGET_OPERATION(thread);

    writeUInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fputws_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    wchar_t * ws;
    FILE*  file ;

    ws = ta_wcsalign(readWString( & stream )); //align on copy
    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = fputws(ws, file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    ta_dealloc_memory(ws);

    return taDefaultVerdict;
}

static TACommandVerdict fwide_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    FILE*  file ;
    int mode;

    file=(FILE*)readPointer(&stream);
    mode=readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = fwide(file, mode);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getwc_cmd(TAThread thread,TAInputStream stream)
{
    wint_t    res;
    FILE*  file ;

    file=(FILE*)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = getwc(file);
    END_TARGET_OPERATION(thread);

    writeUInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getwchar_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t * input          ;
    char    * stdinAsFileName;
    wint_t res       ;
    int    savedErrno;
    FILE * stdinAsFile;

    input           = ta_wcsalign(readWString( & stream )); //align on copy
    stdinAsFileName = readString ( & stream );
    stdinAsFile = fopen( stdinAsFileName, "w" );
    fputws( input, stdinAsFile );
    fclose( stdinAsFile );
    stdinAsFile = freopen( stdinAsFileName, "r", stdin );
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = getwchar();
    END_TARGET_OPERATION(thread);

    writeUInt( thread, res        );
    writeInt ( thread, savedErrno );
    sendResponse( thread );
    
    ta_dealloc_memory(input);

    return taDefaultVerdict;
}

static TACommandVerdict putwc_cmd(TAThread thread,TAInputStream stream)
{
    wint_t    res;
    wchar_t    wc;
    FILE*  file ;

    wc=readInt(&stream);
    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = putwc(wc, file);
    END_TARGET_OPERATION(thread);

    writeUInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict putwchar_cmd(TAThread thread,TAInputStream stream)
{
    wint_t    res;
    wchar_t    wc;

    wc=readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = putwchar(wc);
    END_TARGET_OPERATION(thread);

    writeUInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ungetwc_cmd(TAThread thread,TAInputStream stream)
{
    wint_t    res;
    wint_t    wc;
    int       to_stdin;
    FILE*  file ;

    to_stdin=readInt(&stream);
    wc=readInt(&stream);
    file=(FILE*)readPointer(&stream);

    if (!to_stdin)
    {
        START_TARGET_OPERATION(thread);
        res = ungetwc(wc, file);
        END_TARGET_OPERATION(thread);
    }
    else
    {
        START_TARGET_OPERATION(thread);
        res = ungetwc(wc, stdin);
        END_TARGET_OPERATION(thread);
    }
    writeUInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_io_fstream_wstream_commands(void)
{
    ta_register_command("fgetwc",fgetwc_cmd);
    ta_register_command("fgetws",fgetws_cmd);
    ta_register_command("fputwc",fputwc_cmd);
    ta_register_command("fputws",fputws_cmd);
    ta_register_command("fwide",fwide_cmd);
    ta_register_command("getwc",getwc_cmd);
    ta_register_command("getwchar",getwchar_cmd);
    ta_register_command("putwc",putwc_cmd);
    ta_register_command("putwchar",putwchar_cmd);
    ta_register_command("ungetwc",ungetwc_cmd);
}

