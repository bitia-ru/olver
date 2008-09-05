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


#include "system/host/host_agent.h"
#include "errno.h"
#include <unistd.h>
#include "sys/utsname.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict gethostid_cmd(TAThread thread,TAInputStream stream)
{
    long res;
    
    START_TARGET_OPERATION(thread);
    
    res = gethostid();
    
    END_TARGET_OPERATION(thread);
    
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict gethostname_cmd(TAThread thread,TAInputStream stream)
{
    char * name;
    size_t namelen;
    int res;
    
    name = (char*)readPointer(&stream); 
    namelen = readSize(&stream); 
        
    START_TARGET_OPERATION(thread);
    
    res = gethostname(name,namelen);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
    
    return taDefaultVerdict;
}

static TACommandVerdict sethostname_cmd(TAThread thread,TAInputStream stream)
{
    char * name;
    size_t namelen;
    int res;
    
    name = (char*)readPointer(&stream); 
    namelen = readSize(&stream); 
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = sethostname(name,namelen);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread); 
    
    return taDefaultVerdict;
}

static TACommandVerdict uname_cmd(TAThread thread,TAInputStream stream)
{
    struct utsname * name;
    int res;
    
    name = (struct utsname*)readPointer(&stream); 
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = uname(name);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    if(name!=NULL)
    {
        writePointer(thread, name->sysname);
        writePointer(thread, name->nodename);
        writePointer(thread, name->release);
        writePointer(thread, name->version);
        writePointer(thread, name->machine);
        writePointer(thread, name->domainname);
    }
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict read_HOSTNAMEMAX_cmd(TAThread thread,TAInputStream stream)
{
    long res;
    
    START_TARGET_OPERATION(thread);
    
    /* {sethostname.03} If the symbol HOST_NAME_MAX is defined, or if sysconf(_SC_HOST_NAME_MAX)() returns 
     * a value greater than 0, this value shall represent the maximum length of the new hostname. Otherwise,
     * if the symbol MAXHOSTLEN is defined, this value shall represent the maximum length for the new hostname. 
     * If none of these values are defined, the maximum length shall be the size of the nodename field of the 
     * utsname structure.
     */
    #ifdef HOST_NAME_MAX
     res = HOST_NAME_MAX;
    #else
     res = sysconf(_SC_HOST_NAME_MAX);
     if(res<=0)
     {
       #ifdef MAXHOSTLEN
         res = MAXHOSTLEN;       
       #else
         {
        struct utsname uts;
       res = sizeof( uts.nodename);  
     }
       #endif         
     }
    #endif
    
    END_TARGET_OPERATION(thread);
    
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_system_host_commands(void)
{
    ta_register_command("gethostid",gethostid_cmd);
    ta_register_command("gethostname",gethostname_cmd);
    ta_register_command("sethostname",sethostname_cmd);
    ta_register_command("uname",uname_cmd);
    ta_register_command("read_HOSTNAMEMAX",read_HOSTNAMEMAX_cmd);    
}

