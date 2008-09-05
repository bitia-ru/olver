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

#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "util/getopt/getopt_agent.h"

char** readListStr(TAInputStream* stream)
{
    char** ret;
    int size, i;
    
    verifyType_TAInputStream(stream,"list_str");
    size=readInt(stream);
    ret=ta_alloc_memory(size*sizeof(char*));
    memset(ret, 0, size*sizeof(char*));

    for(i=0;i<size;i++)    
        ret[i]=readString(stream);

    return ret;
}
struct option readOption(TAInputStream* stream)
{
    struct option ret;
    int size, i;
    int* ptr=NULL;
    
    verifyType_TAInputStream(stream,"option");

    ret.name=readString(stream);
    ret.has_arg=readInt(stream);
    i=readInt(stream);

    if(i==0)
    {
        ptr = ta_alloc_memory(sizeof(int));
        *ptr = 0;
        *ptr = readInt(stream);
    }

    ret.flag=ptr;

    ret.val=readInt(stream);

    return ret;
}

struct option* readListOpt(TAInputStream* stream, int* size)
{
    struct option* ret;
    int i;
    
    verifyType_TAInputStream(stream,"list_opt");
    *size=readInt(stream);
    ta_debug_printf("size==%d\n", *size);
    ret=ta_alloc_memory((*size+1)*sizeof(struct option));
    memset(ret, 0, (*size+1)*sizeof(struct option));

    for(i=0;i<*size;i++)    
        ret[i]=readOption(stream);    
    
    return ret;
}

void writeGetoptRet(TAThread thread) 
{
    writeString(thread, optarg);
    writeInt(thread, opterr);
    writeInt(thread, optind);
    writeInt(thread, optopt);
}
void writeListOpt(TAThread thread, struct option* longopts, int size) 
{
    int i, tmp;
    writeInt(thread, size);
    for(i=0;i<size;i++)
    {
        writeInt(thread, tmp = (longopts[i].flag==NULL ? 1 :0));
        if(!tmp)
            writeInt(thread, *(longopts[i].flag));
    }    
}

void readKeyList(TAInputStream* stream, char*** keylistp, int* size)
{
    int i;
    
    verifyType_TAInputStream(stream,"list_str");
    *size=readInt(stream);
    *keylistp=ta_alloc_memory(((*size)+1)*sizeof(char*));
    memset(*keylistp, 0, ((*size)+1)*sizeof(char*));

    for(i=0;i<*size;i++)    
        (*keylistp)[i]=readString(stream);
    (*keylistp)[i]=NULL;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getopt_cmd(TAThread thread,TAInputStream stream)
{
    int argc, res;
    char** argv;
    char* optstring;
   
    // Prepare
    argc=readInt(&stream);
    argv=readListStr(&stream);
    optstring=readString(&stream);

    START_TARGET_OPERATION(thread);
    res=getopt(argc, argv, optstring);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeGetoptRet(thread);   
    writeInt(thread, res);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getopt_long_cmd(TAThread thread,TAInputStream stream)
{
    int argc, res;
    char** argv;
    char* optstring;
    struct option* longopts;
    int longindex, size;

    // Prepare
    argc=readInt(&stream);
    argv=readListStr(&stream);
    optstring=readString(&stream);
    longopts=readListOpt(&stream, &size);
    longindex=readInt(&stream);

    START_TARGET_OPERATION(thread);
    res=getopt_long(argc, argv, optstring, longopts, &longindex);
    END_TARGET_OPERATION(thread);

    ta_debug_printf("optarg==%s, optind==%d, opterr==%d, optopt==%c, ret==%d\n", optarg, optind, opterr, optopt, res);
    
    // Response
    writeInt(thread, res);
    writeGetoptRet(thread);
    writeListOpt(thread, longopts, size);
    writeInt(thread, longindex);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getopt_long_only_cmd(TAThread thread,TAInputStream stream)
{
    int argc, res;
    char** argv;
    char* optstring;
    struct option* longopts;
    int longindex, size;

    // Prepare
    argc=readInt(&stream);
    argv=readListStr(&stream);
    optstring=readString(&stream);
    longopts=readListOpt(&stream, &size);
    longindex=readInt(&stream);

    START_TARGET_OPERATION(thread);
    res=getopt_long_only(argc, argv, optstring, longopts, &longindex);
    END_TARGET_OPERATION(thread);

    ta_debug_printf("optarg==%s, optind==%d, opterr==%d, optopt==%c, ret==%d\n", optarg, optind, opterr, optopt, res);
    
    // Response
    writeInt(thread, res);
    writeGetoptRet(thread);
    writeListOpt(thread, longopts, size);
    writeInt(thread, longindex);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getsubopt_cmd(TAThread thread,TAInputStream stream)
{
    char* optionp, *valuep;
    char** keylistp;
    int size, res;
   
    // Prepare
    optionp=(char*)readPointer(&stream);
    readKeyList(&stream, &keylistp, &size);
    valuep=(char*)readPointer(&stream);
  
    START_TARGET_OPERATION(thread);
    res=getsubopt(&optionp, keylistp, &valuep);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writePointer(thread, optionp);
    writePointer(thread, valuep);

    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict getoptind_cmd(TAThread thread,TAInputStream stream)
{
    int opt;

    START_TARGET_OPERATION(thread);
    opt=optind;
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, opt);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}
static TACommandVerdict getopterr_cmd(TAThread thread,TAInputStream stream)
{
    int err;
    
    err=readInt(&stream);

    START_TARGET_OPERATION(thread);
    opterr=err;
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}
static TACommandVerdict setoptind_cmd(TAThread thread,TAInputStream stream)
{
    int ind;
    
    ind=readInt(&stream);

    START_TARGET_OPERATION(thread);
    optind=ind;
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_getopt_commands(void)
{
    ta_register_command("getopt",getopt_cmd);
    ta_register_command("getopt_long",getopt_long_cmd);
    ta_register_command("getopt_long_only",getopt_long_only_cmd);
    ta_register_command("getsubopt",getsubopt_cmd);

    //Utility cmds 
    ta_register_command("getoptind",getoptind_cmd);
    ta_register_command("getopterr",getopterr_cmd);
    ta_register_command("setoptind",setoptind_cmd);
}

