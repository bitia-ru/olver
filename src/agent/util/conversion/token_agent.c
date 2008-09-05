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


#include "util/conversion/token_agent.h"
#include <string.h>
#include <stdio.h>
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
extern char *strsep(char **, const char *);

static TACommandVerdict strsep_cmd(TAThread thread,TAInputStream stream)
{
    char* stringp;
    char *delim, *res;

    // Prepare       
    stringp=(char*)readPointer(&stream);
    delim=(char*)readPointer(&stream);

    ta_debug_printf("stringp==%s\n", stringp);  
    ta_debug_printf("delim==%s\n", delim);

    // Execute    
    START_TARGET_OPERATION(thread);
    res = strsep(&stringp, delim);
    END_TARGET_OPERATION(thread);

    ta_debug_printf("After...\n");
    ta_debug_printf("stringp==%s\n", stringp);
    ta_debug_printf("delim==%s\n", delim);

    // Response    
    writePointer(thread, res);
    writePointer(thread, stringp);    

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strtok_cmd(TAThread thread,TAInputStream stream)
{
    char* stringp;
    char *delim, *res;

    // Prepare       
    stringp=(char*)readPointer(&stream);
    delim=(char*)readPointer(&stream);

    ta_debug_printf("stringp==%s\n", stringp);  
    ta_debug_printf("delim==%s\n", delim);

    // Execute    
    START_TARGET_OPERATION(thread);
    res = strtok(stringp, delim);
    END_TARGET_OPERATION(thread);

    ta_debug_printf("After...\n");
    ta_debug_printf("stringp==%s\n", stringp);
    ta_debug_printf("delim==%s\n", delim);

    // Response    
    writePointer(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strtok_r_cmd(TAThread thread,TAInputStream stream)
{
    char* stringp, *buff;
    char *delim, *res;

    // Prepare       
    stringp=(char*)readPointer(&stream);
    delim=(char*)readPointer(&stream);
    buff=(char*)readPointer(&stream);    

    ta_debug_printf("strtok_r...\n");
    ta_debug_printf("stringp==%s\n", stringp);  
    ta_debug_printf("delim==%s\n", delim);
    
    // Execute    
    START_TARGET_OPERATION(thread);
    res = strtok_r(stringp, delim, &buff);
    END_TARGET_OPERATION(thread);

    ta_debug_printf("After...\n");
    ta_debug_printf("stringp==%s\n", stringp);
    ta_debug_printf("delim==%s\n", delim);
    ta_debug_printf("buff==%s\n", buff);

    // Response    
    writePointer(thread, res);
    writePointer(thread, buff);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __strtok_r_cmd(TAThread thread,TAInputStream stream)
{
    char* stringp, *buff;
    char *delim, *res;

    // Prepare       
    stringp=(char*)readPointer(&stream);
    delim=(char*)readPointer(&stream);
    buff=(char*)readPointer(&stream);    

    ta_debug_printf("strtok_r...\n");
    ta_debug_printf("stringp==%s\n", stringp);  
    ta_debug_printf("delim==%s\n", delim);

    // Execute
    START_TARGET_OPERATION(thread);
    res = __strtok_r(stringp, delim, &buff);
    END_TARGET_OPERATION(thread);

    ta_debug_printf("After...\n");
    ta_debug_printf("stringp==%s\n", stringp);
    ta_debug_printf("delim==%s\n", delim);
    ta_debug_printf("buff==%s\n", buff);

    // Response    
    writePointer(thread, res);
    writePointer(thread, buff);

    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_conversion_token_commands(void)
{
    ta_register_command("strsep",strsep_cmd);
    ta_register_command("strtok",strtok_cmd);
    ta_register_command("strtok_r",strtok_r_cmd);
    ta_register_command("__strtok_r",__strtok_r_cmd);
}

