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
#include "util/crypt/crypt_agent.h"
#include <unistd.h>

#include <stdlib.h>

#include <errno.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict crypt_cmd(TAThread thread,TAInputStream stream)
{
    char* key;

    char* salt;

    char* res;

   

    // Prepare

    key=readString(&stream);

    salt=readString(&stream);



    START_TARGET_OPERATION(thread);

    errno=0;

    res=crypt(key, salt);

    END_TARGET_OPERATION(thread);

    

    // Response

    writeString(thread, res);

    writeInt(thread, errno);



    sendResponse(thread);

    

    return taDefaultVerdict;
}

static TACommandVerdict encrypt_cmd(TAThread thread,TAInputStream stream)

{

    char* block;

    int edflag;

   

    // Prepare

    block=(char*)readPointer(&stream);

    edflag=readInt(&stream);



    START_TARGET_OPERATION(thread);

    errno=0;

    encrypt(block, edflag);

    END_TARGET_OPERATION(thread);



    // Response

    writePointer(thread, block);

    writeInt(thread, errno);



    sendResponse(thread);

    

    return taDefaultVerdict;

}

static TACommandVerdict setkey_cmd(TAThread thread,TAInputStream stream)

{

    char* key;

    int i;

   

    // Prepare

    key=(char*)readPointer(&stream);



    ta_debug_printf("setkey:\n");

    for(i=0;i<64;i++)

        ta_debug_printf("%d ", key[i]);

    ta_debug_printf("\n");



    START_TARGET_OPERATION(thread);

    errno=0;

    setkey(key);

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread, errno);



    sendResponse(thread);

    

    return taDefaultVerdict;

}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_crypt_commands(void)
{
    ta_register_command("crypt",crypt_cmd);
    ta_register_command("encrypt",encrypt_cmd);
    ta_register_command("setkey",setkey_cmd);
}

