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


#include "socket/rpc/secure_agent.h"
#include <rpc/auth.h>

/********************************************************************/
/**                 Data Types Readers And Writers                 **/
/********************************************************************/

void readDesBlock(TAInputStream * stream, union des_block * block)
{
    verifyType_TAInputStream(stream, "desblock");
    
   
    block->key.high = readUInt32(stream);
    block->key.low = readUInt32(stream);
}
 

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict key_decryptsession_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    char *remotename;
    union des_block deskey;
    
    // Prepare
    remotename = readString(&stream);
    readDesBlock(&stream, &deskey);
    
    START_TARGET_OPERATION(thread);
    
    res = key_decryptsession(remotename, &deskey);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_rpc_secure_commands(void)
{
    ta_register_command("key_decryptsession",key_decryptsession_cmd);
}

