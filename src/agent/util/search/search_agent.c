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


#include "util/search/search_agent.h"
#include "common/ta_stream.h"
#include <stdlib.h>
#include <string.h>
#include <search.h>

#define ERR_WRONG_KEY        1
#define ERR_WRONG_PARAM1     2
#define ERR_WRONG_PARAM2     4
#define ERR_CALLED_WHEN_ZERO 8

static void* key;
static size_t key_sz;
static void* base;
static size_t base_sz;
static size_t nel;
static size_t width;

static unsigned int err_code;

int bsearch_compar(const void* ckey, const void* celem2)
{
    int res;

    /* If the nel argument has the value zero, the comparison function pointed to by compar shall not be called. */
    if (nel == 0)
        err_code |= ERR_CALLED_WHEN_ZERO;

    /* The first argument is always a pointer to the key. */
    if (ckey != key)
        err_code |= ERR_WRONG_KEY;

    /* The second argument is an array element. */
    if ((celem2 < base) || ((celem2 - base) % width != 0) || ((celem2 - base) / width >= nel))
        err_code |= ERR_WRONG_PARAM2;

    res = memcmp(ckey, celem2, width);
    
    return res;
}

int lfind_compar(const void* celem1, const void* celem2)
{
    return memcmp(celem1, celem2, width);
}

int lsearch_compar(const void* celem1, const void* celem2)
{
    return memcmp(celem1, celem2, width);
}

int qsort_compar(const void* celem1, const void* celem2)
{
    int res;

    /* If the nel argument has the value zero, the comparison function pointed to by compar shall not be called. */
    if (nel == 0)
        err_code |= ERR_CALLED_WHEN_ZERO;

    /* The first argument is an array element. */
    if ((celem1 < base) || ((celem1 - base) % width != 0) || ((celem1 - base) / width >= nel))
        err_code |= ERR_WRONG_PARAM1;

    /* The second argument is an array element. */
    if ((celem2 < base) || ((celem2 - base) % width != 0) || ((celem2 - base) / width >= nel))
        err_code |= ERR_WRONG_PARAM2;

    res = memcmp(celem1, celem2, width);
    
    return res;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict bsearch_cmd(TAThread thread, TAInputStream stream)
{
    void* res;
    size_t idx;

    // Prepare
    readByteArray(&stream, (char**)&key, &key_sz);
    readByteArray(&stream, (char**)&base, &base_sz);
    nel = readSize(&stream);
    width = readSize(&stream);
    err_code = 0;

    START_TARGET_OPERATION(thread);

    // Execute
    res = bsearch(key, base, nel, width, bsearch_compar);

    END_TARGET_OPERATION(thread);

    if (err_code & ERR_WRONG_KEY)
    {
        sendException(thread, "The first argument of compar() is not key!");
        return taDefaultVerdict;
    }
    else if (err_code & ERR_WRONG_PARAM2)
    {
        sendException(thread, "The second argument of compar() is not the array element!");
        return taDefaultVerdict;
    }
    else if (err_code & ERR_CALLED_WHEN_ZERO)
    {
        sendException(thread, "The compar() function was called when nel is zero!");
        return taDefaultVerdict;
    }

    if (res != NULL)
        if ((res < base) || ((res - base) % width != 0) || ((res - base) / width >= nel))
        {
            sendException(thread, "The result is not the array element!");
            return taDefaultVerdict;
        }

    // Response
    idx = (res == NULL) ? 0 : (res - base) / width + 1;
    writeSize(thread, idx);
    writeByteArray(thread, base, base_sz);
    writeByteArray(thread, key, key_sz);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lfind_cmd(TAThread thread, TAInputStream stream)
{
    void* res;
    size_t idx;
    int mediator_res;

    // Prepare
    readByteArray(&stream, (char**)&key, &key_sz);
    readByteArray(&stream, (char**)&base, &base_sz);
    nel = readSize(&stream);
    width = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = lfind(key, base, &nel, width, lfind_compar);

    END_TARGET_OPERATION(thread);

    if (res)
        mediator_res = 1;
    else
        mediator_res = 0;


    if (res != NULL)
        if ((res < base) || ((res - base) % width != 0) || ((res - base) / width >= nel))
        {
            sendException(thread, "The result is not the array element!");
            return taDefaultVerdict;
        }

    // Response
    idx = (res == NULL) ? 0 : (res - base) / width ;
    writeSize(thread, idx);
    writeSize(thread, nel);
    writeInt(thread, mediator_res);
    writeByteArray(thread, base, base_sz);
    writeByteArray(thread, key, key_sz);
   
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lsearch_cmd(TAThread thread, TAInputStream stream)
{
    void* res;
    size_t idx;
    int mediator_res;

    // Prepare
    readByteArray(&stream, (char**)&key, &key_sz);
    readByteArray(&stream, (char**)&base, &base_sz);
    nel = readSize(&stream);
    width = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = lsearch(key, base, &nel, width, lsearch_compar);

    END_TARGET_OPERATION(thread);

    if (res)
        mediator_res = 1;
    else
        mediator_res = 0;


    if (res != NULL)
        if ((res < base) || ((res - base) % width != 0) || ((res - base) / width >= nel))
        {
            sendException(thread, "The result is not the array element!");
            return taDefaultVerdict;
        }

    // Response
    idx = (res == NULL) ? 0 : (res - base) / width ;
    
    base_sz = (base_sz>=(idx+1)*width) ? base_sz : (idx+1)*width;
    
    writeSize(thread, idx);
    writeSize(thread, nel);
    writeInt(thread, mediator_res);
    writeByteArray(thread, base, base_sz);
    writeByteArray(thread, key, key_sz);
   
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict qsort_cmd(TAThread thread, TAInputStream stream)
{
    size_t idx;

    // Prepare
    readByteArray(&stream, (char**)&base, &base_sz);
    nel = readSize(&stream);
    width = readSize(&stream);
    err_code = 0;

    START_TARGET_OPERATION(thread);

    // Execute
    qsort(base, nel, width, qsort_compar);

    END_TARGET_OPERATION(thread);

    if (err_code & ERR_WRONG_PARAM1)
    {
        sendException(thread, "The first argument of compar() is not the array element!");
        return taDefaultVerdict;
    }
    else if (err_code & ERR_WRONG_PARAM2)
    {
        sendException(thread, "The second argument of compar() is not the array element!");
        return taDefaultVerdict;
    }
    else if (err_code & ERR_CALLED_WHEN_ZERO)
    {
        sendException(thread, "The compar() function was called when nel is zero!");
        return taDefaultVerdict;
    }

    // Response
    writeByteArray(thread, base, base_sz);
    sendResponse(thread);
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_search_search_commands(void)
{
    ta_register_command("bsearch", bsearch_cmd);
    ta_register_command("lfind", lfind_cmd);
    ta_register_command("lsearch", lsearch_cmd);
    ta_register_command("qsort", qsort_cmd);
}

/********************************************************************/
/**                      Helper Functions                          **/
/********************************************************************/

/*useful only if elem_size is less than sizeof(int)*/
/*
void print_array(void *array, int elem_size, int array_size)
{
    int i;
    void *current;
    unsigned char tmp;
    for(i=0;i<array_size;i++) 
    {
        current = array + i*elem_size;
        tmp = *((unsigned char*)current);
        ta_debug_printf("%d ", (int)tmp);
        ta_debug_printf("A ");
    }
}*/
