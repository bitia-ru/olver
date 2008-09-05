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


#include "util/conversion/wstrreal_agent.h"
#include <errno.h>

#include <wchar.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __wcstod_internal_cmd(TAThread thread,TAInputStream stream)
{

    wchar_t* st, *endptr;

    size_t size;

    double res;



    size = readInt(&stream);

    st = (wchar_t*)ta_alloc_memory(size * sizeof(wchar_t) + 1);



    readWCharArray(&stream, st, &size);



    st[size] = '\0';



    START_TARGET_OPERATION(thread);


    errno = 0;
    res = __wcstod_internal(st, &endptr, 0);

    END_TARGET_OPERATION(thread);


    writeDouble(thread, res);

    writeInt(thread, (int)( endptr - st));

    writeInt(thread, errno);


    ta_dealloc_memory(st);



    sendResponse(thread);


    return taDefaultVerdict;
}

static TACommandVerdict __wcstof_internal_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* st, *endptr;

    size_t size;

    float res;



    size = readInt(&stream);

    st = (wchar_t*)ta_alloc_memory(size * sizeof(wchar_t) + 1);



    readWCharArray(&stream, st, &size);



    st[size] = '\0';



    START_TARGET_OPERATION(thread);



    errno = 0;

    res = __wcstof_internal(st, &endptr, 0);



    END_TARGET_OPERATION(thread);



    writeFloat(thread, res);

    writeInt(thread, (int)( endptr - st));

    writeInt(thread, errno);



    ta_dealloc_memory(st);



    sendResponse(thread);



    return taDefaultVerdict;


}

static TACommandVerdict __wcstold_internal_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* st, *endptr;

    size_t size;

    long double res;



    size = readInt(&stream);

    st = (wchar_t*)ta_alloc_memory(size * sizeof(wchar_t) + 1);



    readWCharArray(&stream, st, &size);



    st[size] = '\0';



    START_TARGET_OPERATION(thread);



    errno = 0;

    res = __wcstold_internal(st, &endptr, 0);



    END_TARGET_OPERATION(thread);



    writeLongDouble(thread, res);

    writeInt(thread, (int)( endptr - st));

    writeInt(thread, errno);



    ta_dealloc_memory(st);



    sendResponse(thread);



    return taDefaultVerdict;


}

static TACommandVerdict wcstod_cmd(TAThread thread,TAInputStream stream)
{

    wchar_t* st, *endptr;

    size_t size;

    double res;



    size = readInt(&stream);

    st = (wchar_t*)ta_alloc_memory(size * sizeof(wchar_t) + 1);



    readWCharArray(&stream, st, &size);



    st[size] = '\0';


    START_TARGET_OPERATION(thread);



    errno = 0;

    res = wcstod(st, &endptr);



    END_TARGET_OPERATION(thread);



    writeDouble(thread, res);

    writeInt(thread, (int)( endptr - st));

    writeInt(thread, errno);



    ta_dealloc_memory(st);



    sendResponse(thread);



    return taDefaultVerdict;

}

static TACommandVerdict wcstof_cmd(TAThread thread,TAInputStream stream)
{
    int showData = 1;

    wchar_t* st, *endptr;

    size_t size;

    float res;



    size = readInt(&stream);

    st = (wchar_t*)ta_alloc_memory(size * sizeof(wchar_t) + 1);



    readWCharArray(&stream, st, &size);



    st[size] = '\0';


    if ( showData ) { ta_debug_printf( "wcstof_cmd : st is [%ls]\n", st ); }

    START_TARGET_OPERATION(thread);



    errno = 0;

    res = wcstof(st, &endptr);



    END_TARGET_OPERATION(thread);

    if ( showData ) {
        ta_debug_printf( "wcstof_cmd : res    is [%g]\n" , res    );
        ta_debug_printf( "wcstof_cmd : endptr is [%ls]\n", endptr );
        ta_debug_printf( "wcstof_cmd : errno  is [%i]\n" , errno  );
    }


    writeFloat(thread, res);

    writeInt(thread, (int)( endptr - st));

    writeInt(thread, errno);



    ta_dealloc_memory(st);



    sendResponse(thread);



    return taDefaultVerdict;
}

static TACommandVerdict wcstold_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* st, *endptr;

    size_t size;

    long double res;



    size = readInt(&stream);

    st = (wchar_t*)ta_alloc_memory(size * sizeof(wchar_t) + 1);



    readWCharArray(&stream, st, &size);



    st[size] = '\0';



    START_TARGET_OPERATION(thread);



    errno = 0;

    res = wcstold(st, &endptr);



    END_TARGET_OPERATION(thread);



    writeLongDouble(thread, res);

    writeInt(thread, (int)( endptr - st));

    writeInt(thread, errno);



    ta_dealloc_memory(st);



    sendResponse(thread);



    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_conversion_wstrreal_commands(void)
{
    ta_register_command("__wcstod_internal",__wcstod_internal_cmd);
    ta_register_command("__wcstof_internal",__wcstof_internal_cmd);
    ta_register_command("__wcstold_internal",__wcstold_internal_cmd);
    ta_register_command("wcstod",wcstod_cmd);
    ta_register_command("wcstof",wcstof_cmd);
    ta_register_command("wcstold",wcstold_cmd);
}

