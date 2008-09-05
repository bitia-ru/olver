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


#include "util/bit/bit_agent.h"
#include <ctype.h>
#include <strings.h>

/*
 * According to POSIX 2004 ffs shall be in 'strings.h',
 * but LSB Environment conatins it in the 'string.h' only.
 */
#include <string.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict ffs_cmd(TAThread thread,TAInputStream stream)
{
    int i;
    int res;
    
    /* Prepare */
    i = readInt(&stream);

    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = ffs(i);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict toascii_cmd(TAThread thread,TAInputStream stream)
{

    int c;
    int res;
    
    /* Prepare */
    c = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = toascii(c);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_bit_commands(void)
{
    ta_register_command("ffs",ffs_cmd);
    ta_register_command("toascii",toascii_cmd);
}

