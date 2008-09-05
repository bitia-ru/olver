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


#include "util/format/money_agent.h"
#include <errno.h>
#include <monetary.h>

double* readDoubleList(TAInputStream* stream, int* list_size)
{
    double* ret=ta_alloc_memory(10*sizeof(double));
    int i=0;
    
    memset(ret, 0, 10*sizeof(double));

    verifyType_TAInputStream(stream,"double_list");
    *list_size=readInt(stream);

    for(i=0;i<*list_size;i++)    
        ret[i]=readDouble(stream);

    return ret;
}
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict strfmon_cmd(TAThread thread,TAInputStream stream)
{
    char* s;
    int maxsize, list_size, res;
    char* format;
    double* pars;

   
    // Prepare
    s=(char*)readPointer(&stream);
    maxsize=readInt(&stream);
    format=(char*)readPointer(&stream);
    pars=readDoubleList(&stream, &list_size);

    START_TARGET_OPERATION(thread);
    errno=0;
    switch(list_size)
    {
    case 0:
        res=strfmon(s, maxsize, format);
    break;
    case 1:
        res=strfmon(s, maxsize, format, pars[0]);
    break;
    case 2:
        res=strfmon(s, maxsize, format, pars[0], pars[1]);
    break;
    case 3:
        res=strfmon(s, maxsize, format, pars[0], pars[1], pars[2]);
    break;
    case 4:
        res=strfmon(s, maxsize, format, pars[0], pars[1], pars[2], pars[3]);
    break;
    case 5:
        res=strfmon(s, maxsize, format, pars[0], pars[1], pars[2], pars[3], 
            pars[4]);
    break;
    case 6:
        res=strfmon(s, maxsize, format, pars[0], pars[1], pars[2], pars[3],
            pars[4], pars[5]);
    break;
    case 7:
        res=strfmon(s, maxsize, format, pars[0], pars[1], pars[2], pars[3],
            pars[4], pars[5], pars[6]);
    break;
    case 8:
        res=strfmon(s, maxsize, format, pars[0], pars[1], pars[2], pars[3],
            pars[4], pars[5], pars[6], pars[7]);
    break;
    case 9:
        res=strfmon(s, maxsize, format, pars[0], pars[1], pars[2], pars[3],
            pars[4], pars[5], pars[6], pars[7], pars[8]);
    break;
    case 10:
        res=strfmon(s, maxsize, format, pars[0], pars[1], pars[2], pars[3],
            pars[4], pars[5], pars[6], pars[7], pars[8], pars[9]);
    break;
    default:
        ta_debug_printf("Error: number of parameters is bigger than 10\n");
    }
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writePointer(thread, s);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_format_money_commands(void)
{
    ta_register_command("strfmon",strfmon_cmd);
}

