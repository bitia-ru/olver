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


#include "util/string/wstr_agent.h"
#include <wchar.h>
#include <errno.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict wcpcpy_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* dest;
    wchar_t* src;
    wchar_t* res;

    // Prepare
    dest = (wchar_t*)readPointer(&stream);
    src = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcpcpy(dest, src);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcpncpy_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* dest;
    wchar_t* src;
    size_t n;
    wchar_t* res;

    // Prepare
    dest = (wchar_t*)readPointer(&stream);
    src = (wchar_t*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcpncpy(dest, src, n);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcscat_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    wchar_t* res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcscat(ws1, ws2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcschr_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws;
    int   wc;
    wchar_t* res;

    // Prepare
    ws = (wchar_t*)readPointer(&stream);
    wc = readWChar(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcschr(ws, wc);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;}


void print_wstring(wchar_t* ws)
{
	int i=0, length=0;
	int tmp;
	char* bytes=ws;

	ta_debug_printf("WString: ");
	
	while(ws[i]!=0)
	{
		tmp=ws[i];
		ta_debug_printf("%d ", tmp);
		i++;
	}
	length=i;
	ta_debug_printf("\nWString length %d\nWString bytes: ", length);
	for(i=0;i<length*sizeof(wchar_t);i+=4)
	{
		ta_debug_printf("'%c' ", bytes[i+3]);
		ta_debug_printf("'%c' ", bytes[i+2]);
		ta_debug_printf("'%c' ", bytes[i+1]);
		ta_debug_printf("'%c' ", bytes[i]);
	}
	ta_debug_printf("\n");
	ta_debug_printf("\n");
}

static TACommandVerdict wcscmp_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    int res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);


    START_TARGET_OPERATION(thread);
	print_wstring(ws1);
	print_wstring(ws2);

    // Execute
    res = wcscmp(ws1, ws2);
	ta_debug_printf("res %d\n", res);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcscpy_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    wchar_t* res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcscpy(ws1, ws2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcscspn_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    size_t res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcscspn(ws1, ws2);

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcsdup_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = wcsdup(ws1);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcslen_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t* ws;
    size_t res;

    // Prepare
    ws = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcslen(ws);

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcsncat_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    size_t n;
    wchar_t* res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcsncat(ws1, ws2, n);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcsncmp_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    size_t n;
    int res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcsncmp(ws1, ws2, n);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcsncpy_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    size_t n;
    wchar_t* res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcsncpy(ws1, ws2, n);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcsnlen_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t* ws;
    size_t n;
    size_t res;

    // Prepare
    ws = (wchar_t*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcsnlen(ws, n);

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcspbrk_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    wchar_t* res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcspbrk(ws1, ws2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcsrchr_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws;
    int   wc;
    wchar_t* res;

    // Prepare
    ws = (wchar_t*)readPointer(&stream);
    wc = readWChar(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcsrchr(ws, wc);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcsspn_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    size_t res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcsspn(ws1, ws2);

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcsstr_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    wchar_t* res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcsstr(ws1, ws2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcswcs_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    wchar_t* res;

    // Prepare
    ws1 = (wchar_t*)readPointer(&stream);
    ws2 = (wchar_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wcswcs(ws1, ws2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_string_wstr_commands(void)
{
    ta_register_command("wcpcpy",wcpcpy_cmd);
    ta_register_command("wcpncpy",wcpncpy_cmd);
    ta_register_command("wcscat",wcscat_cmd);
    ta_register_command("wcschr",wcschr_cmd);
    ta_register_command("wcscmp",wcscmp_cmd);
    ta_register_command("wcscpy",wcscpy_cmd);
    ta_register_command("wcscspn",wcscspn_cmd);
    ta_register_command("wcsdup",wcsdup_cmd);
    ta_register_command("wcslen",wcslen_cmd);
    ta_register_command("wcsncat",wcsncat_cmd);
    ta_register_command("wcsncmp",wcsncmp_cmd);
    ta_register_command("wcsncpy",wcsncpy_cmd);
    ta_register_command("wcsnlen",wcsnlen_cmd);
    ta_register_command("wcspbrk",wcspbrk_cmd);
    ta_register_command("wcsrchr",wcsrchr_cmd);
    ta_register_command("wcsspn",wcsspn_cmd);
    ta_register_command("wcsstr",wcsstr_cmd);
    ta_register_command("wcswcs",wcswcs_cmd);
}

