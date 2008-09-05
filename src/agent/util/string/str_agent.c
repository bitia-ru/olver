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


#include "util/string/str_agent.h"
#include <string.h>
#include <strings.h>
#include <errno.h>

/*
 * These function declarations represents binary interface definition of
 *   Linux Standard Base Core Specification 3.1
 *   Copyright (c) 2004, 2005 Free Standards Group
 *
 *   See section 'Data Definitions for libc'.
 *   
 *   Why is it absent in 'string.h'?
 */
char * __strdup(const char* string);


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __stpcpy_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = __stpcpy(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __strdup_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = __strdup(s1);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writeInt(thread, errno); 
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict rindex_cmd(TAThread thread,TAInputStream stream)
{
    char* s;
    int   c;
    char* res;

    // Prepare
    s = (char*)readPointer(&stream);
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = rindex(s, c);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict stpcpy_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = stpcpy(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict stpncpy_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    size_t n;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = stpncpy(s1, s2, n);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strcat_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strcat(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict index_cmd(TAThread thread,TAInputStream stream)
{
    char* s;
    int   c;
    char* res;

    // Prepare
    s = (char*)readPointer(&stream);
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = index(s, c);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strchr_cmd(TAThread thread,TAInputStream stream)
{
    char* s;
    int   c;
    char* res;

    // Prepare
    s = (char*)readPointer(&stream);
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strchr(s, c);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strcmp_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    int res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strcmp(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strcpy_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strcpy(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strcspn_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    size_t res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strcspn(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strdup_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = strdup(s1);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strlen_cmd(TAThread thread, TAInputStream stream)
{
    char* s;
    size_t res;

    // Prepare
    s = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strlen(s);

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strncat_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    size_t n;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strncat(s1, s2, n);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strncmp_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    size_t n;
    int res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strncmp(s1, s2, n);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strncpy_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    size_t n;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strncpy(s1, s2, n);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strndup_cmd(TAThread thread, TAInputStream stream)
{
    char* s;
    size_t n;
    char* res;

    // Prepare
    s = (char*)readPointer(&stream);
    n = readSize(&stream);
    
   START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = strndup(s,n);

    END_TARGET_OPERATION(thread);
    // Execute

    // Response
    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strnlen_cmd(TAThread thread, TAInputStream stream)
{
    char* s;
    size_t n;
    size_t res;

    // Prepare
    s = (char*)readPointer(&stream);
    n = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strnlen(s,n);

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strpbrk_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strpbrk(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strrchr_cmd(TAThread thread, TAInputStream stream)
{
    char* s;
    int   c;
    char* res;

    // Prepare
    s = (char*)readPointer(&stream);
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strrchr(s, c);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strspn_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    size_t res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strspn(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strstr_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    char* res;

    // Prepare
    s1 = (char*)readPointer(&stream);
    s2 = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = strstr(s1, s2);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_string_str_commands(void)
{
    ta_register_command("__stpcpy",__stpcpy_cmd);
    ta_register_command("__strdup",__strdup_cmd);
    ta_register_command("rindex",rindex_cmd);
    ta_register_command("stpcpy",stpcpy_cmd);
    ta_register_command("stpncpy",stpncpy_cmd);
    ta_register_command("strcat",strcat_cmd);
    ta_register_command("index",index_cmd);
    ta_register_command("strchr",strchr_cmd);
    ta_register_command("strcmp",strcmp_cmd);
    ta_register_command("strcpy",strcpy_cmd);
    ta_register_command("strcspn",strcspn_cmd);
    ta_register_command("strdup",strdup_cmd);
    ta_register_command("strlen",strlen_cmd);
    ta_register_command("strncat",strncat_cmd);
    ta_register_command("strncmp",strncmp_cmd);
    ta_register_command("strncpy",strncpy_cmd);
    ta_register_command("strndup",strndup_cmd);
    ta_register_command("strnlen",strnlen_cmd);
    ta_register_command("strpbrk",strpbrk_cmd);
    ta_register_command("strrchr",strrchr_cmd);
    ta_register_command("strspn",strspn_cmd);
    ta_register_command("strstr",strstr_cmd);
}

