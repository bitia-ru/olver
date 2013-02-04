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
#include <stdio.h>
#include <fcntl.h>
#include "util/format/fmtmsg_agent.h"
#define MM_PRINT 0x100
#define MM_CONSOLE 0x200
#include <fmtmsg.h>
#include <stdlib.h>
#include <unistd.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict fmtmsg_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    long classification;
    char *label;
    int severity;
    char *text;
    char *action;
    char *tag;
    int fd;

    void *buf;
    size_t nbyte;
    size_t read_res;

        
    // Prepare
    classification = readInt(&stream);
    classification = classification | readInt(&stream);
    classification = classification | readInt(&stream);
    classification = classification | MM_PRINT | MM_CONSOLE;
    
    severity = readInt(&stream);

    label = readString(&stream);
    text = readString(&stream);
    action = readString(&stream);
    tag = readString(&stream);

    nbyte = readSize(&stream);
    buf = ta_alloc_memory(nbyte);

    remove(ta_get_test_file_path("xxx.txt"));
    fd = open(ta_get_test_file_path("xxx.txt"), O_RDWR  | O_CREAT | O_TRUNC, 0);
    dup2 ( fd, 2);
    close( fd );

    START_TARGET_OPERATION(thread);
    res = fmtmsg(classification, label, severity, text, action, tag); 
    END_TARGET_OPERATION(thread);

    lseek(2, 0, SEEK_SET);
    
    read_res = read(2, buf, nbyte);
    ((char*)buf)[read_res]='\0';
        
    
    // Response
    writeInt(thread, res);
    writeString(thread, (char*)buf);
    
    sendResponse(thread);
    
    ta_dealloc_memory(buf);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_format_fmtmsg_commands(void)
{
    ta_register_command("fmtmsg",fmtmsg_cmd);
}

