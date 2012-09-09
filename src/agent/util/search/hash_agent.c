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


#include "util/search/hash_agent.h"
#include <search.h>
#include <string.h>

#include <stdlib.h>
#include <errno.h>

/********************************************************************/
/**                     String Table Manipulation                  **/
/********************************************************************/

struct string_table_entry;

typedef struct string_table_entry
{
    char *str;
    struct string_table_entry* next;
} string_table_entry;

static string_table_entry *string_table = NULL;

string_table_entry *create_string_table_entry()
{
    string_table = ta_alloc_memory(sizeof(string_table_entry));
    string_table->str = NULL;
    string_table->next = NULL;

    return string_table; 	
}

void create_string_table()
{
    string_table = create_string_table_entry();
}

void delete_string_table()
{
    string_table_entry *it;
    string_table_entry *curr;

    it = string_table;
    while(it)
    {
        if(it->str)
            ta_dealloc_memory(it->str);
        curr = it;
        it = it->next;
        ta_dealloc_memory(curr);
    }
    string_table = NULL;
}

char* remember_string(char* str)
{
    string_table_entry *it;
    string_table_entry *curr;

    it = string_table;
    while(it)
    {
        if(!it->str)
        {
            it->str = (char*)ta_alloc_memory(strlen(str)+1);
            strcpy(it->str, str);
            return it->str;
        }

        if(!it->next)
        {
            it->next = create_string_table_entry();
            if(str)
            {
                it->next->str = (char*)ta_alloc_memory(strlen(str)+1);
                strcpy(it->next->str, str);
                return it->next->str;
            }
            return NULL;
        }
        it = it->next;
    }
    return NULL;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict init_string_table_cmd(TAThread thread,TAInputStream stream)
{
    // Execute
    START_TARGET_OPERATION(thread);
    create_string_table( );
    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict finish_string_table_cmd(TAThread thread,TAInputStream stream)
{
    // Execute
    START_TARGET_OPERATION(thread);
    delete_string_table( );
    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict hcreate_cmd(TAThread thread,TAInputStream stream)
{
    size_t n;
    int res;

    // Prepare
    n = readSize(&stream);
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = hcreate( n );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict hdestroy_cmd(TAThread thread,TAInputStream stream)
{
    // Execute
    START_TARGET_OPERATION(thread);
    hdestroy( );
    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    return taDefaultVerdict;
}



static TACommandVerdict hsearch_cmd(TAThread thread,TAInputStream stream)
{
    // HashEntryT* hsearch_spec (CallContext context, HashEntryT* item, HashActionT action)
    // ====
    // VoidTPtr resEntry, String* resKey, VoidTPtr resData hsearch_spec (CallContext context, String* key, VoidTPtr* data, HashActionT action)

    ENTRY *resEntry;
    char *resKey;
    void *resData;

    char *inKey;
    void *inData;
    ACTION  inAction;
    ENTRY   inEntry;


    inKey =     readString(&stream);
    inData =    readPointer(&stream);
    inAction =  readInt(&stream);

    if(inKey)
    {
        inKey = remember_string(inKey);
    }

    inEntry.key =  inKey;
    inEntry.data = inData;
    errno = 0;

    START_TARGET_OPERATION(thread);

    resEntry = hsearch(inEntry, inAction);

    END_TARGET_OPERATION(thread);

    writePointer(thread,(void*)resEntry);

    if(resEntry)
    {
        writeString(thread, resEntry->key);
        writePointer(thread, resEntry->data);
    } else {
        writeString(thread,(char*)NULL);
        writePointer(thread,(void*)NULL);
    }
    writeInt(thread,errno);
    sendResponse(thread);


    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_util_search_hash_commands(void)
{
    ta_register_command("init_string_table",init_string_table_cmd);
    ta_register_command("finish_string_table",finish_string_table_cmd);
    ta_register_command("hcreate",hcreate_cmd);
    ta_register_command("hdestroy",hdestroy_cmd);
    ta_register_command("hsearch",hsearch_cmd);
}

