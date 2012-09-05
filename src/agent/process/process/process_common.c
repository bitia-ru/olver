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

#include <curses.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <pty.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include "common/ta_stream.h"
#include "io/file/file_agent.h"
#include "ncurses/string/printf_agent.h"
#include "ncurses/string/scanf_agent.h"
#include "process/process/process_agent.h"
#include "process/process/process_common.h"
#include "process/process/functionTypedValuesCall.h"
#include "util/assert/assert_agent.h"
#include "util/format/printf_agent.h"
#include "util/format/scanf_agent.h"
#include "util/format/wprintf_agent.h"
#include "util/format/wscanf_agent.h"

void error(int exitstatus, int errnum, const char * format, ...);

int functionLongValuesCall( int a, long * b ); // !!! no function body here !!!

/********************************************************************/
/**                        read text file                          **/
/********************************************************************/

static char * getFileContents( const char * fileName ) {
    FILE * file     ;
    int    resultLen;
    char * result   ;
    if ( ( file = fopen( fileName, "r" ) ) == NULL ) { return NULL; }
    resultLen = 0;
    while ( fgetc( file ) != EOF ) { resultLen++; }
    fseek( file, 0, SEEK_SET );
    if ( ( result = (char *)ta_alloc_memory( ( resultLen + 1 ) * sizeof( char ) ) ) != NULL ) { // + 1 - for final 0
        fread( result, resultLen, sizeof( char ), file );
        result[ resultLen ] = 0;
    }
    fclose( file );
    return result;
}

static char * freadFile( FILE ** file, const char * fileName, char * fileMode ) {
    long   oldOffset;
    char * result   ;
    int    i        ;
    if ( * file == NULL || fileName == NULL || fileMode == NULL ) { return NULL; }
    // save old file state
    oldOffset = ftell( * file );
    fclose( * file );
    // read file contents
    result = getFileContents( fileName );
    // restore old file state
    // fileMode = [analog replace_CString for char *]( fileMode, 'w', 'a' );
    for ( i = 0; i < strlen( fileMode ); i++ ) { if ( fileMode[ i ] == 'w' ) { fileMode[ i ] = 'a'; } }
    * file = fopen( fileName, fileMode );
    fseek( * file, oldOffset, SEEK_SET );
    return result;
}

static char * readFile( int * fd, const char * fileName, int fileOflag ) {
    char  * result   ;
    off_t   oldOffset;
    FILE  * file     ;
    int     resultLen;
    int     i        ;
    if ( * fd == NULL || fileName == NULL ) { return NULL; }
    // save old file state
    oldOffset = lseek( * fd, 0, SEEK_CUR );
    close( * fd );
    // read file contents
    result = getFileContents( fileName );
    // restore old file state
    fileOflag &= ~ O_CREAT ;
    fileOflag &= ~ O_TRUNC ;
    fileOflag |=   O_APPEND;
    * fd = open( fileName, fileOflag );
    lseek( * fd, oldOffset, SEEK_SET );
    return result;
}

static wchar_t * fwreadFile( FILE ** file, const char * fileName, char * fileMode ) {
    wchar_t * result   ;
    long      oldOffset;
    int       resultLen;
    int       i        ;
    if ( * file == NULL || fileName == NULL || fileMode == NULL ) { return NULL; }
    // save old file state
    oldOffset = ftell( * file );
    fclose( * file );
    // read file contents
    if ( ( * file = fopen( fileName, "r" ) ) == NULL ) { return NULL; }
    //fwide( * file, 1 );
    resultLen = 0;
    while ( fgetwc( * file ) != WEOF ) { resultLen++; }
    // ta_debug_printf( "fwreadFile : resultLen is %d\n", resultLen );
    fseek( * file, 0, SEEK_SET );
    if ( ( result = (wchar_t *)ta_alloc_memory( ( resultLen + 1 ) * sizeof( wchar_t ) ) ) != NULL ) { // + 1 - for final 0
        // fread( result, resultLen, sizeof( wchar_t ), * file );
        int i;
        for ( i = 0; i < resultLen; i++ ) { result[ i ] = fgetwc( * file ); }
        result[ resultLen ] = 0;
    }
    fclose( * file );
    // ta_debug_printf( "fwreadFile : result is [%s|%ls]\n", result, result );
    // restore old file state
    // fileMode = [analog replace_CString for char *]( fileMode, 'w', 'a' );
    for ( i = 0; i < strlen( fileMode ); i++ ) { if ( fileMode[ i ] == 'w' ) { fileMode[ i ] = 'a'; } }
    * file = fopen( fileName, fileMode );
    fwide( * file, 1 );
    fseek( * file, oldOffset, SEEK_SET );
    return result;
}

TACommandVerdict getFileContents_cmd( TAThread thread, TAInputStream stream ) {
    char * fileName = readString( & stream );
    char * result = getFileContents( fileName );
    writeInt( thread, result == NULL ? 1 : 0 );
    if ( result != NULL ) { writeString( thread, result ); }
    sendResponse( thread );
    if ( result != NULL ) { ta_dealloc_memory( result ); }
    return taDefaultVerdict;
}

TACommandVerdict freadFile_cmd( TAThread thread, TAInputStream stream ) {
    FILE * file     = (FILE *)readPointer( & stream );
    char * fileName =         readString ( & stream );
    char * fileMode =         readString ( & stream );
    char * result = freadFile( & file, fileName, fileMode );
    writeString ( thread, result );
    writePointer( thread, file   );
    sendResponse( thread );
    if ( result != NULL ) { ta_dealloc_memory( result ); }
    return taDefaultVerdict;
}

TACommandVerdict readFile_cmd( TAThread thread, TAInputStream stream ) {
    int    fd        = readInt      ( & stream );
    char * fileName  = readString   ( & stream );
    int    fileOflag = readOpenFlags( & stream );
    char * result = readFile( & fd, fileName, fileOflag );
    writeString( thread, result );
    writeInt   ( thread, fd     );
    sendResponse( thread );
    if ( result != NULL ) { ta_dealloc_memory( result ); }
    return taDefaultVerdict;
}

TACommandVerdict fwreadFile_cmd( TAThread thread, TAInputStream stream ) {
    FILE * file     = (FILE *)readPointer( & stream );
    char * fileName =         readString ( & stream );
    char * fileMode =         readString ( & stream );
    wchar_t * result = fwreadFile( & file, fileName, fileMode );
    writeWString( thread, result );
    writePointer( thread, file   );
    sendResponse( thread );
    if ( result != NULL ) { ta_dealloc_memory( result ); }
    return taDefaultVerdict;
}

/********************************************************************/
/**                     trace function call                        **/
/********************************************************************/

static int appendIfFileExists( const char * fileName, const char * data, int erasePrevious ) {
    FILE * file = fopen( fileName, "r" );
    if ( file == NULL ) { return 0; }
    fclose( file );
    file = fopen( fileName, erasePrevious == 1 ? "w" : "a" );
    fprintf( file, "%s", data );
    fclose( file );
    return 1;
}

TACommandVerdict appendIfFileExists_cmd( TAThread thread, TAInputStream stream ) {
    char * fileName      = readString( & stream );
    char * data          = readString( & stream );
    int    erasePrevious = readInt   ( & stream );
    int result = appendIfFileExists( fileName, data, erasePrevious );
    writeInt( thread, result );
    sendResponse( thread );
    return taDefaultVerdict;
}

/********************************************************************/
/**                  execute function with ...                     **/
/********************************************************************/

TACommandVerdict executeFunctionWithDots_cmd( TAThread thread, TAInputStream stream ) {/**/
    char * funcText = readString( & stream );
    int    returnedValue;
    int    storedErrno  ;
    int    outputSize   ;
    char * output       ;
    FILE * file = fopen( "functionWithDots.c", "w" );
    fprintf( file, "%s", funcText );
    fclose( file );
    system( "gcc -o functionWithDots.exe functionWithDots.c" );
    system( "./functionWithDots.exe > functionWithDots.output" );
    file = fopen( "functionWithDots.result_errno", "r" );
    fscanf( file, "functionWithDotsResult : %d\n", & returnedValue );
    fscanf( file, "functionWithDotsErrno  : %d\n", & storedErrno   );
    fclose( file );
    file = fopen( "functionWithDots.output", "r" );
    outputSize = 0;
    while ( fgetc( file ) != EOF ) { outputSize++; }
    outputSize++; // for final 0
    fclose( file );
    file = fopen( "functionWithDots.output", "r" ); // set file pointer to begin of file
    output = (char *)ta_alloc_memory( outputSize * sizeof( char ) );
    fread( output, outputSize - 1, sizeof( char ), file );
    fclose( file );
    output[ outputSize - 1 ] = 0;
    ta_debug_printf( "executeFunctionWithDots_cmd : returned value is [%d]\n", returnedValue );
    ta_debug_printf( "executeFunctionWithDots_cmd : output         is [%s]\n", output        );
    ta_debug_printf( "executeFunctionWithDots_cmd : errno          is [%d]\n", storedErrno   );
    writeInt   ( thread, returnedValue );
    writeString( thread, output        );
    writeInt   ( thread, storedErrno   );
    sendResponse( thread );
    ta_dealloc_memory( output );
    return taDefaultVerdict;
}

static long getFunctionAsLongByName( const char * name ) {
    static char * nameToFunction[][ 2 ] = {
                      { "asprintf" , (char *)asprintf  }, { "vasprintf", (char *)vasprintfDotsShell },
                                                          { "vdprintf" , (char *)vdprintfDotsShell  },
                      { "err"      , (char *)err       },
                      { "error"    , (char *)error     },
                      { "errx"     , (char *)errx      }, { "verrx"    , (char *)verrxDotsShell     },
                      { "fprintf"  , (char *)fprintf   }, { "vfprintf" , (char *)vfprintfDotsShell  },
                      { "fscanf"   , (char *)fscanf    }, { "vfscanf"  , (char *)vfscanfDotsShell   },
                      { "fwprintf" , (char *)fwprintf  }, { "vfwprintf", (char *)vfwprintfDotsShell },
                      { "fwscanf"  , (char *)fwscanf   }, { "vfwscanf" , (char *)vfwscanfDotsShell  },
                      { "mvprintw" , (char *)mvprintw  },
                      { "mvscanw"  , (char *)mvscanw   },
                      { "mvwprintw", (char *)mvwprintw },
                      { "mvwscanw" , (char *)mvwscanw  },
                      { "printf"   , (char *)printf    }, { "vprintf"  , (char *)vprintfDotsShell   },
                      { "printw"   , (char *)printw    },
                      { "scanf"    , (char *)scanf     }, { "vscanf"   , (char *)vscanfDotsShell    },
                      { "scanw"    , (char *)scanw     },
                      { "snprintf" , (char *)snprintf  }, { "vsnprintf", (char *)vsnprintfDotsShell },
                      { "sprintf"  , (char *)sprintf   }, { "vsprintf" , (char *)vsprintfDotsShell  },
                      { "sscanf"   , (char *)sscanf    }, { "vsscanf"  , (char *)vsscanfDotsShell   },
                      { "swprintf" , (char *)swprintf  }, { "vswprintf", (char *)vswprintfDotsShell },
                      { "swscanf"  , (char *)swscanf   }, { "vswscanf" , (char *)vswscanfDotsShell  },
                      { "warn"     , (char *)warn      },
                      { "warnx"    , (char *)warnx     },
                      { "wprintf"  , (char *)wprintf   }, { "vwprintf" , (char *)vwprintfDotsShell  },
                      { "wprintw"  , (char *)wprintw   }, { "vw_printw", (char *)vw_printwDotsShell },
                                                          { "vwprintw" , (char *)vwprintwDotsShell  },
                      { "wscanf"   , (char *)wscanf    }, { "vwscanf"  , (char *)vwscanfDotsShell   },
                      { "wscanw"   , (char *)wscanw    }, { "vw_scanw" , (char *)vw_scanwDotsShell  },
                                                          { "vwscanw"  , (char *)vwscanwDotsShell   }
                  };
    static int nameToFunctionLen = sizeof( nameToFunction ) / sizeof( nameToFunction[ 0 ] );
    int i;
    for ( i = 0; i < nameToFunctionLen; i++ ) {
        if ( strcmp( name, nameToFunction[ i ][ 0 ] ) == 0 ) { return (long)nameToFunction[ i ][ 1 ]; }
    }
    return (long)NULL;
} // getFunctionAsLongByName

static int useInputOrWInputTypedValues( TAThread thread, long functionAsLong, TypedList * arguments,
                                        const char * input, const wchar_t * wInput, int * savedErrnoPtr
                                      ) {
    // Временная заглушка - использование input при помощи вызова sscanf или swscanf.
    // Когда Хорошилов сделает подмену ввода с терминала, будем пользоваться его функциями.
    long newFunctionAsLong;
    TypedList argumentsPlus;
    char    * inputCopy  = NULL; // for 64 bit
    wchar_t * wInputCopy = NULL; // for 64 bit
    int i;
    int result;
    argumentsPlus.size = arguments->size + 1;
    argumentsPlus.elements = (TypedListElement *)ta_alloc_memory( argumentsPlus.size * sizeof( TypedListElement ) );
    if ( functionAsLong == (long)scanf || functionAsLong == (long)vscanfDotsShell ) {
        inputCopy = (char *)ta_alloc_memory( ( strlen( input ) + 1 ) * sizeof( char ) );
        strcpy( inputCopy, input );
        newFunctionAsLong = (long)sscanf;
        argumentsPlus.elements[ 0 ].type         = CStringCode;
        argumentsPlus.elements[ 0 ].data.CString = inputCopy  ;
    } else if ( functionAsLong == (long)wscanf || functionAsLong == (long)vwscanfDotsShell ) {
        wInputCopy = ta_wcsalign(wInput);
        newFunctionAsLong = (long)swscanf;
        argumentsPlus.elements[ 0 ].type         = WStringCode;
        argumentsPlus.elements[ 0 ].data.WString = wInputCopy ;
    } else {
        newFunctionAsLong = (long)NULL;
    }
    for ( i = 0; i < arguments->size; i++ ) {
        argumentsPlus.elements[ i + 1 ].type = arguments->elements[ i ].type;
        argumentsPlus.elements[ i + 1 ].data = arguments->elements[ i ].data;
    }
    errno = 0;
    START_TARGET_OPERATION( thread );
    result = functionTypedValuesCall( newFunctionAsLong, & argumentsPlus );
    END_TARGET_OPERATION( thread );
    * savedErrnoPtr = errno;
    for ( i = 0; i < arguments->size; i++ ) { arguments->elements[ i ].data = argumentsPlus.elements[ i + 1 ].data; }
    ta_dealloc_memory( argumentsPlus.elements );
    if ( inputCopy  != NULL ) { ta_dealloc_memory( inputCopy  ); }
    if ( wInputCopy != NULL ) { ta_dealloc_memory( wInputCopy ); }
    return result;
} // useInputOrWInputTypedValues

static void readOutputAndWOutputTypedValues( long functionAsLong, const TypedList * arguments,
                                             int result, char ** outputPtr, wchar_t ** wOutputPtr
                                           ) {
    // Когда Хорошилов сделает перехват вывода на терминал, будем пользоваться его функциями.
    int i;
    if ( result < 0 ) { return; }
    if ( functionAsLong == (long)printf || functionAsLong == (long)vprintfDotsShell ) {
        // Временная заглушка - получение output при помощи вызова sprintf.
        TypedList argumentsPlus;
        argumentsPlus.size = arguments->size + 1;
        argumentsPlus.elements = (TypedListElement *)ta_alloc_memory( argumentsPlus.size * sizeof( TypedListElement ) );
        * outputPtr = (char *)ta_alloc_memory( ( result + 1 ) * sizeof( char ) );
        argumentsPlus.elements[ 0 ].type         = CStringCode;
        argumentsPlus.elements[ 0 ].data.CString = * outputPtr;
        for ( i = 0; i < arguments->size; i++ ) {
            argumentsPlus.elements[ i + 1 ].type = arguments->elements[ i ].type;
            argumentsPlus.elements[ i + 1 ].data = arguments->elements[ i ].data;
        }
        functionTypedValuesCall( (long)sprintf, & argumentsPlus );
        ta_dealloc_memory( argumentsPlus.elements );
    } else if ( functionAsLong == (long)wprintf || functionAsLong == (long)vwprintfDotsShell ) {
        // Временная заглушка - получение wOutput при помощи вызова swprintf.
        TypedList argumentsPlus;
        argumentsPlus.size = arguments->size + 2;
        argumentsPlus.elements = (TypedListElement *)ta_alloc_memory( argumentsPlus.size * sizeof( TypedListElement ) );
        * wOutputPtr = (wchar_t *)ta_alloc_memory( ( result + 1 ) * sizeof( wchar_t ) );
        argumentsPlus.elements[ 0 ].type         = WStringCode ;
        argumentsPlus.elements[ 0 ].data.WString = * wOutputPtr;
        argumentsPlus.elements[ 1 ].type          = SizeTObjCode;
        argumentsPlus.elements[ 1 ].data.SizeTObj = result + 1  ;
        for ( i = 0; i < arguments->size; i++ ) {
            argumentsPlus.elements[ i + 2 ].type = arguments->elements[ i ].type;
            argumentsPlus.elements[ i + 2 ].data = arguments->elements[ i ].data;
        }
        functionTypedValuesCall( (long)swprintf, & argumentsPlus );
        ta_dealloc_memory( argumentsPlus.elements );
    }
} // readOutputAndWOutputTypedValues

static void readErrputTypedValues( long functionAsLong, TypedList * arguments, char ** errputPtr ) {
    // Когда Хорошилов сделает перехват вывода на терминал, будем пользоваться его функциями.
    if ( functionAsLong == (long)warn || functionAsLong == (long)warnx ) {
        // Временная заглушка - получение errput при помощи подмены stderr.
        TypedListElement * lastElem = & arguments->elements[ arguments->size - 1 ];
        assertion( lastElem->type == CStringCode, "readErrputTypedValues : lastElem->type is %d", lastElem->type );
        FILE * stderrAsFile = fopen( lastElem->data.CString, "w" );
        FILE * oldStderr = stderr;
        stderr = stderrAsFile;
        functionTypedValuesCall( functionAsLong, arguments ); // хотя последний элемент из arguments не важен
        stderr = oldStderr;
        fclose( stderrAsFile );
        * errputPtr = getFileContents( lastElem->data.CString );
    }
} // readErrputTypedValues

static int functionWithDotsTypedValuesCall( TAThread thread, long functionAsLong, TypedList * arguments,
                                            const char * input, const wchar_t * wInput, int * savedErrnoPtr,
                                            char ** outputPtr, wchar_t ** wOutputPtr, char ** errputPtr
                                          ) {
    int result;
    if ( strlen( input ) != 0 || ta_wcslen( wInput ) != 0 ) {
        result = useInputOrWInputTypedValues( thread, functionAsLong, arguments, input, wInput, savedErrnoPtr );
    } else {
        // Когда Хорошилов сделает подмену ввода с терминала, останется только этот блок.
        errno = 0;
        START_TARGET_OPERATION( thread );
        result = functionTypedValuesCall( functionAsLong, arguments );
        END_TARGET_OPERATION( thread );
        * savedErrnoPtr = errno;
    }
    readOutputAndWOutputTypedValues( functionAsLong, arguments, result, outputPtr, wOutputPtr );
    readErrputTypedValues( functionAsLong, arguments, errputPtr );
    return result;
} // functionWithDotsTypedValuesCall

static int useInputOrWInputLongValues( TAThread thread, const long * arguments, int argumentsSize,
                                       const char * input, const wchar_t * wInput, int * savedErrnoPtr
                                     ) {
    // Временная заглушка - использование input при помощи вызова sscanf или swscanf.
    // Когда Хорошилов сделает подмену ввода с терминала, будем пользоваться его функциями.
    long * argumentsPlus = (long *)ta_alloc_memory( ( argumentsSize + 1 ) * sizeof( long ) );
    char    * inputCopy  = NULL; // for 64 bit
    wchar_t * wInputCopy = NULL; // for 64 bit
    int i;
    int result;
    if ( arguments[ 0 ] == (long)scanf || arguments[ 0 ] == (long)vscanfDotsShell ) {
        inputCopy = (char *)ta_alloc_memory( ( strlen( input ) + 1 ) * sizeof( char ) );
        strcpy( inputCopy, input );
        argumentsPlus[ 0 ] = (long)sscanf;
        argumentsPlus[ 1 ] = (long)inputCopy;
    } else if ( arguments[ 0 ] == (long)wscanf || arguments[ 0 ] == (long)vwscanfDotsShell ) {
        wInputCopy = ta_wcsalign(wInput);
        argumentsPlus[ 0 ] = (long)swscanf;
        argumentsPlus[ 1 ] = (long)wInputCopy;
    } else {
        argumentsPlus[ 0 ] = (long)NULL;
    }
    for ( i = 1; i < argumentsSize; i++ ) { argumentsPlus[ i + 1 ] = arguments[ i ]; }
    errno = 0;
    START_TARGET_OPERATION( thread );
    result = functionLongValuesCall( argumentsSize + 1, argumentsPlus );
    END_TARGET_OPERATION( thread );
    * savedErrnoPtr = errno;
    ta_dealloc_memory( argumentsPlus );
    if ( inputCopy  != NULL ) { ta_dealloc_memory( inputCopy  ); }
    if ( wInputCopy != NULL ) { ta_dealloc_memory( wInputCopy ); }
    return result;
} // useInputOrWInputLongValues

static void readOutputAndWOutputLongValues
                ( const long * arguments, int argumentsSize, int result, char ** outputPtr, wchar_t ** wOutputPtr ) {
    // Когда Хорошилов сделает перехват вывода на терминал, будем пользоваться его функциями.
    int i;
    if ( result < 0 ) { return; }
    if ( arguments[ 0 ] == (long)printf || arguments[ 0 ] == (long)vprintfDotsShell ) {
        // Временная заглушка - получение output при помощи вызова sprintf.
        long * argumentsPlus = (long *)ta_alloc_memory( ( argumentsSize + 1 ) * sizeof( long ) );
        argumentsPlus[ 0 ] = (long)sprintf;
        * outputPtr = (char *)ta_alloc_memory( ( result + 1 ) * sizeof( char ) );
        argumentsPlus[ 1 ] = (long)* outputPtr;
        for ( i = 1; i < argumentsSize; i++ ) { argumentsPlus[ i + 1 ] = arguments[ i ]; }
        functionLongValuesCall( argumentsSize + 1, argumentsPlus );
        ta_dealloc_memory( argumentsPlus );
    } else if ( arguments[ 0 ] == (long)wprintf || arguments[ 0 ] == (long)vwprintfDotsShell ) {
        // Временная заглушка - получение wOutput при помощи вызова swprintf.
        long * argumentsPlus = (long *)ta_alloc_memory( ( argumentsSize + 2 ) * sizeof( long ) );
        argumentsPlus[ 0 ] = (long)swprintf;
        * wOutputPtr = (wchar_t *)ta_alloc_memory( ( result + 1 ) * sizeof( wchar_t ) );
        argumentsPlus[ 1 ] = (long)* wOutputPtr;
        argumentsPlus[ 2 ] = result + 1;
        for ( i = 1; i < argumentsSize; i++ ) { argumentsPlus[ i + 2 ] = arguments[ i ]; }
        functionLongValuesCall( argumentsSize + 2, argumentsPlus );
        ta_dealloc_memory( argumentsPlus );
    }
} // readOutputAndWOutputLongValues

static void readErrputLongValues( long * arguments, int argumentsSize, char ** errputPtr ) {
    // Когда Хорошилов сделает перехват вывода на терминал, будем пользоваться его функциями.
    if ( arguments[ 0 ] == (long)warn || arguments[ 0 ] == (long)warnx ) {
        // Временная заглушка - получение errput при помощи подмены stderr.
        FILE * stderrAsFile = fopen( (char *)arguments[ argumentsSize - 1 ], "w" );
        FILE * oldStderr = stderr;
        stderr = stderrAsFile;
        functionLongValuesCall( argumentsSize, arguments ); // хотя достаточно argumentsSize - 1
        stderr = oldStderr;
        fclose( stderrAsFile );
        * errputPtr = getFileContents( (char *)arguments[ argumentsSize - 1 ] );
    }
} // readErrputLongValues

static int functionWithDotsLongValuesCall( TAThread thread, long * arguments, int argumentsSize,
                                           const char * input, const wchar_t * wInput, int * savedErrnoPtr,
                                           char ** outputPtr, wchar_t ** wOutputPtr, char ** errputPtr
                                         ) {
    int result;
    //ta_debug_printf( "functionWithDotsCall : enter\n" );
    //ta_debug_printf( "functionWithDotsCall : input  is [%s]\n" , input  == NULL ? "NULL"  : input  );
    //ta_debug_printf( "functionWithDotsCall : wInput is [%ls]\n", wInput == NULL ? L"NULL" : wInput );
    if ( strlen( input ) != 0 || ta_wcslen( wInput ) != 0 ) {
        result = useInputOrWInputLongValues( thread, arguments, argumentsSize, input, wInput, savedErrnoPtr );
    } else {
        if ( 0 ) {
            int i;
            for ( i = 0; i < argumentsSize; i++ ) {
                ta_debug_printf( "functionWithDotsLongValuesCall : arguments[ %i ] is [%016lX]\n", i, arguments[ i ] );
            }
            ta_debug_printf( "functionWithDotsLongValuesCall : 12.7777777 is [%016lX]\n", 12.7777777 );
            ta_debug_printf( "functionWithDotsLongValuesCall : 12.7777778 is [%016lX]\n", 12.7777778 );
            ta_debug_printf( "functionWithDotsLongValuesCall : sizeof( long   ) is [%d]\n", sizeof( long   ) );
            ta_debug_printf( "functionWithDotsLongValuesCall : sizeof( float  ) is [%d]\n", sizeof( float  ) );
            ta_debug_printf( "functionWithDotsLongValuesCall : sizeof( double ) is [%d]\n", sizeof( double ) );
            ta_debug_printf( "functionWithDotsLongValuesCall : arguments[ 0 ] is %swarn\n",
                             arguments[ 0 ] == (long)warn ? "" : "not "
                           );
            if ( arguments[ 0 ] == (long)warn ) {
                ta_debug_printf
                    ( "functionWithDotsLongValuesCall : (char *)arguments[ 1 ] is [%s]\n", (char *)arguments[ 1 ] );
                ta_debug_printf( "functionWithDotsLongValuesCall : arguments[ 2 ] is [%f]\n", arguments[ 2 ] );
                ta_debug_printf
                    ( "functionWithDotsLongValuesCall : (char *)arguments[ 3 ] is [%s]\n", (char *)arguments[ 3 ] );
            }
        } // if
        // Когда Хорошилов сделает подмену ввода с терминала, останется только этот блок.
        errno = 0;
        START_TARGET_OPERATION( thread );
        result = functionLongValuesCall( argumentsSize, arguments );
        if ( 0 ) {
            if ( arguments[ 0 ] == (long)warn ) {
                result = functionLongValuesCall( argumentsSize - 1, arguments );
                result = ((int (*)())arguments[ 0 ])( arguments[ 1 ], arguments[ 2 ] );
                ((void (*)())arguments[ 0 ])( arguments[ 1 ], arguments[ 2 ] );
                warn( "%f", 12.7777777 );
                warn( arguments[ 1 ], arguments[ 2 ] );
                warn( arguments[ 1 ], arguments[ 2 ], arguments[ 3 ] );
            }
        } // if
        //ta_debug_printf( "functionWithDotsLongValuesCall : before END_TARGET_OPERATION\n" );
        END_TARGET_OPERATION( thread );
        * savedErrnoPtr = errno;
    }
    readOutputAndWOutputLongValues( arguments, argumentsSize, result, outputPtr, wOutputPtr );
    readErrputLongValues( arguments, argumentsSize, errputPtr );
    return result;
} // functionWithDotsLongValuesCall

TACommandVerdict functionWithDotsCall_cmd( TAThread thread, TAInputStream stream ) {
    char             * callDataType  ;
    bool               useTypedCall  ;
    char             * funcName      ;
    long               functionAsLong;
    TypedList          typedArguments;
    long             * longArguments ;
    int                argumentsSize ;
    char             * input         ;
    wchar_t          * wInput        ;
    int                result        ;
    int                savedErrno    ;
    char             * output  = NULL;
    wchar_t          * wOutput = NULL;
    char             * errput  = NULL;
    char    * emptyString    = ""   ;
    wchar_t   emptyWString[] = { 0 }; // L"" not work with LSB headers
    callDataType = readString( & stream );
    if      ( strcmp( callDataType, "TypedValues" ) == 0 ) { useTypedCall = 1; }
    else if ( strcmp( callDataType, "LongValues"  ) == 0 ) { useTypedCall = 0; }
    else { assertion( 0, "functionWithDotsCall_cmd : unsupported call type" ); }
    funcName = readString( & stream );
    if ( useTypedCall ) {                 readTypedList    ( & stream, & typedArguments ); }
                   else { argumentsSize = readDotsArguments( & stream, & longArguments  ); }
    input  = readString ( & stream );
    wInput = readWString( & stream );
    functionAsLong = getFunctionAsLongByName( funcName );
    ta_debug_printf( "search for %s (%u)...\n", funcName, (unsigned long)pthread_self() );
    if ( useTypedCall ) {
        // align WString aruments
        for ( int i = 0; i < typedArguments.size; ++i )
            if (typedArguments.elements[i].type == WStringCode)
                typedArguments.elements[i].data.WString = ta_wcsalign(typedArguments.elements[i].data.WString);
        
        result = functionWithDotsTypedValuesCall( thread, functionAsLong, & typedArguments,
                                                  input, wInput, & savedErrno, & output, & wOutput, & errput
                                                );
        writeTypedList( thread, & typedArguments );
        for ( int i = 0; i < typedArguments.size; ++i )
            if (typedArguments.elements[i].type == WStringCode)
                ta_dealloc_memory(typedArguments.elements[i].data.WString);
    } else {
        longArguments[ 0 ] = functionAsLong;
        result = functionWithDotsLongValuesCall
                     ( thread, longArguments, argumentsSize, input, wInput, & savedErrno, & output, & wOutput, & errput );
    }
    writeInt    ( thread, result                                   );
    writeInt    ( thread, savedErrno                               );
    writeString ( thread, output  == NULL ? emptyString  : output  );
    writeWString( thread, wOutput == NULL ? emptyWString : wOutput );
    writeString ( thread, errput  == NULL ? emptyString  : errput  );
    sendResponse( thread );
    if ( ! useTypedCall ) { ta_dealloc_memory( longArguments ); }
    if ( output  != NULL ) { ta_dealloc_memory( output  ); }
    if ( wOutput != NULL ) { ta_dealloc_memory( wOutput ); }
    if ( errput  != NULL ) { ta_dealloc_memory( errput  ); }
    return taDefaultVerdict;
} // functionWithDotsCall_cmd

/********************************************************************/
/**                     byte chain with id                         **/
/********************************************************************/

/* $(markedbytechain) */
void readMarkedByteChain( TAInputStream * stream, int * id, void * value, size_t valueSize ) {
    int charsReceived;
    char * charList;
    verifyType_TAInputStream( stream, "markedbytechain" );
    * id = readInt( stream );
    charsReceived = readByteList( stream, & charList );
    assertion( valueSize == charsReceived, "readMarkedByteChain : valueSize is %d, charsReceived is %d\n",
                                           (int)valueSize, charsReceived
             );
    memcpy( value, charList, valueSize );
    ta_dealloc_memory( charList );
}

void writeMarkedByteChain( TAThread thread, int id, const void * value, size_t valueSize ) {
    writeInt( thread, id );
    writeByteList( thread, valueSize, (char *)value, 0 );
}

/********************************************************************/
/**                  write-read for int array                      **/
/********************************************************************/

/*
 * any data may be sended or received as int array
 * DANGER : byte and int order
 */
void readIntArray( TAInputStream * stream, int * array, int size ) {
    int sended, i;
    verifyType_TAInputStream( stream, "intarray" );
    sended = readInt( stream );
    assertion( sended == size, "readIntArray : sended is %d, but size is %d", sended, size );
    for ( i = 0; i < size; i++ ) { array[ i ] = readInt( stream ); }
}

void writeIntArray( TAThread thread, const int * array, int size ) {
    int i;
    writeInt( thread, size );
    for ( i = 0; i < size; i++ ) { writeInt( thread, array[ i ] ); }
}

/********************************************************************/
/**                  write-read for user types                     **/
/********************************************************************/

/* $(strnullterminatedlist) */
int readStringNullTerminatedList( TAInputStream * stream, char *** list_ptr ) {
    int size, i;
    verifyType_TAInputStream( stream, "strnullterminatedlist" );
    size = readInt( stream );
    if ( size == -1 ) {
        * list_ptr = NULL;
    } else if ( size >= 0 ) {
        * list_ptr = (char **)ta_alloc_memory( ( size + 1 ) * sizeof( char * ) );
        assertion( * list_ptr != NULL, "Can't alloc %d bytes for list", ( size + 1 ) * sizeof( char * ) );
        for ( i = 0; i < size; i++ ) { (* list_ptr)[ i ] = readString( stream ); }
        (* list_ptr)[ size ] = NULL;
    }
    return size;
}

void writeStringNullTerminatedList( TAThread thread, int size, char ** list ) {
    writeInt( thread, size );
    if ( size >= 0 ) {
        int i;
        for ( i = 0; i < size; i++ ) { writeString( thread, list[ i ] ); }
        ta_dealloc_memory( list );
    }
}

/* $(uintlist) */
int readUintList( TAInputStream * stream, unsigned int ** list_ptr ) {
    int size, i;
    verifyType_TAInputStream( stream, "uintlist" );
    size = readInt( stream );
    if ( size == -1 ) {
        * list_ptr = NULL;
    } else if ( size >= 0 ) {
        * list_ptr = (unsigned int *)ta_alloc_memory( size * sizeof( unsigned int ) );
        assertion( * list_ptr != NULL, "Can't alloc %d bytes for list", size * sizeof( unsigned int ) );
        for ( i = 0; i < size; i++ ) { (* list_ptr)[ i ] = readUInt( stream ); }
    }
    return size;
}

void writeUintList( TAThread thread, int size, unsigned int * list ) {
    writeInt( thread, size );
    if ( size >= 0 ) {
        int i;
        for ( i = 0; i < size; i++ ) { writeUInt( thread, list[ i ] ); }
        ta_dealloc_memory( list );
    }
}

/* $(charlist) */
int readCharList( TAInputStream * stream, char ** list_ptr ) {
    int size, i;
    verifyType_TAInputStream( stream, "charlist" );
    size = readInt( stream );
    if ( size == -1 ) {
        * list_ptr = NULL;
    } else if ( size >= 0 ) {
        * list_ptr = (char *)ta_alloc_memory( size * sizeof( char ) );
        assertion( * list_ptr != NULL, "Can't alloc %d bytes for list", size * sizeof( char ) );
        for ( i = 0; i < size; i++ ) { (* list_ptr)[ i ] = readChar( stream ); }
    }
    return size;
}

void writeCharList( TAThread thread, int size, char * list, int needDealloc ) {
    writeInt( thread, size );
    if ( size >= 0 ) {
        int i;
        for ( i = 0; i < size; i++ ) { writeChar( thread, list[ i ] ); }
        if ( needDealloc != 0 ) { ta_dealloc_memory( list ); }
    }
}

/* $(bytelist) */
int readByteList( TAInputStream * stream, unsigned char ** list_ptr ) {
    int size, i;
    verifyType_TAInputStream( stream, "bytelist" );
    size = readInt( stream );
    if ( size == -1 ) {
        * list_ptr = NULL;
    } else if ( size >= 0 ) {
        * list_ptr = (unsigned char *)ta_alloc_memory( size * sizeof( unsigned char ) );
        assertion( * list_ptr != NULL, "Can't alloc %d bytes for list", size * sizeof( unsigned char ) );
        for ( i = 0; i < size; i++ ) { (* list_ptr)[ i ] = readUChar( stream ); }
    }
    return size;
}

void writeByteList( TAThread thread, int size, unsigned char * list, int needDealloc ) {
    writeInt( thread, size );
    if ( size >= 0 ) {
        int i;
        for ( i = 0; i < size; i++ ) { writeUChar( thread, list[ i ] ); }
        if ( needDealloc != 0 ) { ta_dealloc_memory( list ); }
    }
}

/* $(timeval) */
int readTimeVal( TAInputStream * stream, struct timeval * value )
{
    if(startsWith_TAInputStream(stream, "null:"))
    {
        shift_TAInputStream(stream, 5);

        return 0;
    }

    verifyType_TAInputStream( stream, "timeval" );
    value->tv_sec  = readLong( stream );
    value->tv_usec = readLong( stream );

    return 1;
}

void writeTimeVal( TAThread thread, const struct timeval * value ) {
    writeLong( thread, value->tv_sec  );
    writeLong( thread, value->tv_usec );
}

/* $(itimerval) */
void readITimerVal( TAInputStream * stream, struct itimerval * value ) {
    verifyType_TAInputStream( stream, "itimerval" );
    readTimeVal( stream, & value->it_value    );
    readTimeVal( stream, & value->it_interval );
}

void writeITimerVal( TAThread thread, const struct itimerval * value ) {
    writeTimeVal( thread, & value->it_value    );
    writeTimeVal( thread, & value->it_interval );
}

/* $(itimerspec) */
void readITimerSpec( TAInputStream * stream, struct itimerspec * value ) {
    verifyType_TAInputStream( stream, "itimerspec" );
    value->it_value   .tv_sec  = readLong( stream );
    value->it_value   .tv_nsec = readLong( stream );
    value->it_interval.tv_sec  = readLong( stream );
    value->it_interval.tv_nsec = readLong( stream );
}

void writeITimerSpec( TAThread thread, const struct itimerspec * value ) {
    writeLong( thread, value->it_value   .tv_sec  );
    writeLong( thread, value->it_value   .tv_nsec );
    writeLong( thread, value->it_interval.tv_sec  );
    writeLong( thread, value->it_interval.tv_nsec );
}

/* $(errorcode) - write only */
//use writeInt

/* $(argumentdescriptor) - read only */
void readArgumentDescriptor( TAInputStream * stream, ArgumentDescriptor * value ) {
    verifyType_TAInputStream( stream, "argumentdescriptor" );
    if ( readInt( stream ) ) { value->declaration = readString( stream ); }
                        else { value->declaration = NULL                ; }
    if ( readInt( stream ) ) { value->initialization = readString( stream ); }
                        else { value->initialization = NULL                ; }
    value->parameter = readString( stream );
}

/* $(argumentdescriptorlist) - read only */
int readArgumentDescriptorList( TAInputStream * stream, ArgumentDescriptorList * listPtr ) {
    int size, i;
    verifyType_TAInputStream( stream, "argumentdescriptorlist" );
    size = readInt( stream );
    if ( size == -1 ) {
        * listPtr = NULL;
    } else if ( size >= 0 ) {
        * listPtr = (ArgumentDescriptorList)ta_alloc_memory( size * sizeof( ArgumentDescriptor ) );
        assertion( * listPtr != NULL, "Can't alloc %d bytes for list", size * sizeof( ArgumentDescriptor ) );
        for ( i = 0; i < size; i++ ) { readArgumentDescriptor( stream, & (* listPtr)[ i ] ); }
    }
    return size;
}

/* $(dotsarguments) - read only */
int readDotsArguments( TAInputStream * stream, long ** listPtr ) {
    int size, i;
    verifyType_TAInputStream( stream, "dotsarguments" );
    size = readInt( stream );
    assertion( size >= 0, "readDotsArguments : size (%d) < 0", size );
    size++; // !
    * listPtr = (long *)ta_alloc_memory( size * sizeof( long ) );
    assertion( * listPtr != NULL, "Can't alloc %d bytes for list", size * sizeof( long ) );
    for ( i = 1; i < size; i++ ) { (* listPtr)[ i ] = readLong( stream ); } // (* listPtr)[ 0 ] - for ptr to function
    return size;
}

/* $(typedlistelement) */
#define TypedListElementSimpleCase( TypeCode, Func ) ( strcmp( typeCode, #TypeCode ) == 0 ) \
{ value->type = TypeCode##Code; value->data.TypeCode = read##Func( stream ); }

// TypedListElementStringCase == TypedListElementSimpleCase

void readTypedListElement( TAInputStream * stream, TypedListElement * value ) {
    char * typeCode;
    verifyType_TAInputStream( stream, "typedlistelement" );
    typeCode = readString( stream );
    if      TypedListElementSimpleCase( IntTObj    , Int    )
    else if TypedListElementSimpleCase( CharTObj   , Char   )
    else if TypedListElementSimpleCase( ShortTObj  , Short  )
    else if TypedListElementSimpleCase( LongTObj   , Long   )
    else if TypedListElementSimpleCase( LLongTObj  , LLong  )
    else if TypedListElementSimpleCase( IntMaxTObj , IntMax )
    else if TypedListElementSimpleCase( SizeTObj   , Size   )
    else if TypedListElementSimpleCase( PtrDiffTObj, Long   )
    else if TypedListElementSimpleCase( WIntTObj   , WChar  )
    else if ( strcmp( typeCode, "FloatTObj" ) == 0 ) {
        int * start = (int *)& value->data.FloatTObj;
        value->type = FloatTObjCode;
        readIntArray( stream, start, sizeof( float ) / sizeof( int ) );
    }
    else if ( strcmp( typeCode, "DoubleTObj" ) == 0 ) {
        int * start = (int *)& value->data.DoubleTObj;
        value->type = DoubleTObjCode;
        readIntArray( stream, start, sizeof( double ) / sizeof( int ) );
    }
    else if ( strcmp( typeCode, "LongDoubleTObj" ) == 0 ) {
        int * start = (int *)& value->data.LongDoubleTObj;
        value->type = LongDoubleTObjCode;
        readIntArray( stream, start, sizeof( long double ) / sizeof( int ) );
    }
    else if TypedListElementSimpleCase( CString, String  )
    else if TypedListElementSimpleCase( WString, WString )
    else if TypedListElementSimpleCase( VoidTPtrObj, Pointer )
    else { assertion( 0, "readTypedListElement : unsupported type" ); }
} // readTypedListElement

#undef TypedListElementSimpleCase

void writeTypedListElement( TAThread thread, const TypedListElement * value ) {
    const int * start;
    switch ( value->type ) {
        case IntTObjCode    : writeString( thread, "IntTObj"     ); writeInt   ( thread, value->data.IntTObj     ); break;
        case CharTObjCode   : writeString( thread, "CharTObj"    ); writeChar  ( thread, value->data.CharTObj    ); break;
        case ShortTObjCode  : writeString( thread, "ShortTObj"   ); writeShort ( thread, value->data.ShortTObj   ); break;
        case LongTObjCode   : writeString( thread, "LongTObj"    ); writeLong  ( thread, value->data.LongTObj    ); break;
        case LLongTObjCode  : writeString( thread, "LLongTObj"   ); writeLLong ( thread, value->data.LLongTObj   ); break;
        case IntMaxTObjCode : writeString( thread, "IntMaxTObj"  ); writeIntMax( thread, value->data.IntMaxTObj  ); break;
        case SizeTObjCode   : writeString( thread, "SizeTObj"    ); writeSize  ( thread, value->data.SizeTObj    ); break;
        case PtrDiffTObjCode: writeString( thread, "PtrDiffTObj" ); writeLong  ( thread, value->data.PtrDiffTObj ); break;
        case WIntTObjCode   : writeString( thread, "WIntTObj"    ); writeWChar ( thread, value->data.WIntTObj    ); break;
        case FloatTObjCode:
            start = (int *)& value->data.FloatTObj;
            writeString( thread, "FloatTObj" );
            writeIntArray( thread, start, sizeof( float ) / sizeof( int ) );
            break;
        case DoubleTObjCode:
            start = (int *)& value->data.DoubleTObj;
            writeString( thread, "DoubleTObj" );
            writeIntArray( thread, start, sizeof( double ) / sizeof( int ) );
            break;
        case LongDoubleTObjCode:
            start = (int *)& value->data.LongDoubleTObj;
            writeString( thread, "LongDoubleTObj" );
            writeIntArray( thread, start, sizeof( long double ) / sizeof( int ) );
            break;
        case CStringCode    : writeString( thread, "CString"     ); writeString ( thread, value->data.CString     ); break;
        case WStringCode    : writeString( thread, "WString"     ); writeWString( thread, value->data.WString     ); break;
        case VoidTPtrObjCode: writeString( thread, "VoidTPtrObj" ); writePointer( thread, value->data.VoidTPtrObj ); break;
        default: assertion( 0, "writeTypedListElement : unsupported type" ); break;
    }
} // writeTypedListElement

/* $(typedlist) */
void readTypedList( TAInputStream * stream, TypedList * list ) {
    int i;
    verifyType_TAInputStream( stream, "typedlist" );
    list->size = readInt( stream );
    if ( list->size == -1 ) {
        list->elements = NULL;
    } else if ( list->size >= 0 ) {
        list->elements = (TypedListElement *)ta_alloc_memory( list->size * sizeof( TypedListElement ) );
        assertion( list->elements != NULL, "Can't alloc %d bytes for list", list->size * sizeof( TypedListElement ) );
        for ( i = 0; i < list->size; i++ ) { readTypedListElement( stream, & list->elements[ i ] ); }
    }
}

void writeTypedList( TAThread thread, const TypedList * list ) {
    writeInt( thread, list->size );
    if ( list->size >= 0 ) {
        int i;
        for ( i = 0; i < list->size; i++ ) { writeTypedListElement( thread, & list->elements[ i ] ); }
        ta_dealloc_memory( list->elements );
    }
}

void printTypedList( const TypedList * list ) {
    int i;
    ta_debug_printf( "printTypedList : list->size is %d\n", list->size );
    for ( i = 0; i < list->size; i++ ) {
        ta_debug_printf( "printTypedList : list->elements[ %d ].type is %d\n", i, list->elements[ i ].type );
        ta_debug_printf( "printTypedList : list->elements[ %d ].data is ", i );
        switch ( list->elements[ i ].type ) {
            case IntTObjCode       : ta_debug_printf( "%d\n"     , list->elements[ i ].data ); break;
            case CharTObjCode      : ta_debug_printf( "%hhd\n"   , list->elements[ i ].data ); break;
            case ShortTObjCode     : ta_debug_printf( "%hd\n"    , list->elements[ i ].data ); break;
            case LongTObjCode      : ta_debug_printf( "%ld\n"    , list->elements[ i ].data ); break;
            case LLongTObjCode     : ta_debug_printf( "%lld\n"   , list->elements[ i ].data ); break;
            case IntMaxTObjCode    : ta_debug_printf( "%jd\n"    , list->elements[ i ].data ); break;
            case SizeTObjCode      : ta_debug_printf( "%zd\n"    , list->elements[ i ].data ); break;
            case PtrDiffTObjCode   : ta_debug_printf( "%td\n"    , list->elements[ i ].data ); break;
            case WIntTObjCode      : ta_debug_printf( "%lc\n"    , list->elements[ i ].data ); break;
            case FloatTObjCode     : ta_debug_printf( "%f\n"     , list->elements[ i ].data ); break;
            case DoubleTObjCode    : ta_debug_printf( "%f\n"     , list->elements[ i ].data ); break;
            case LongDoubleTObjCode: ta_debug_printf( "%Lf\n"    , list->elements[ i ].data ); break;
            case CStringCode       : ta_debug_printf( "\"%s\"\n" , list->elements[ i ].data ); break;
            case WStringCode       : ta_debug_printf( "\"%ls\"\n", list->elements[ i ].data ); break;
            case VoidTPtrObjCode   : ta_debug_printf( "%p\n"     , list->elements[ i ].data ); break;
            default: assertion( 0, "printTypedList : unsupported type" ); break;
        }
    }
} // printTypedList

/* $(tm) */
void readTm( TAInputStream * stream, struct tm * value ) {
    verifyType_TAInputStream( stream, "tm" );
    value->tm_sec   = readInt( stream );
    value->tm_min   = readInt( stream );
    value->tm_hour  = readInt( stream );
    value->tm_mday  = readInt( stream );
    value->tm_mon   = readInt( stream );
    value->tm_year  = readInt( stream );
    value->tm_wday  = readInt( stream );
    value->tm_yday  = readInt( stream );
    value->tm_isdst = readInt( stream );
}

void writeTm( TAThread thread, const struct tm * value ) {
    writeInt( thread, value == NULL );
    if ( value != NULL ) {
        writeInt( thread, value->tm_sec   );
        writeInt( thread, value->tm_min   );
        writeInt( thread, value->tm_hour  );
        writeInt( thread, value->tm_mday  );
        writeInt( thread, value->tm_mon   );
        writeInt( thread, value->tm_year  );
        writeInt( thread, value->tm_wday  );
        writeInt( thread, value->tm_yday  );
        writeInt( thread, value->tm_isdst );
    }
}
