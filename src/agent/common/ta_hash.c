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
#include "common/ta_hash.h"
#include "common/ta_assertion.h"
#include <string.h>
#include <stdlib.h>

void* ta_alloc_memory(size_t size);

static int ta_string_hash_code(const char* str)
{
int i,res;

  res = 0;
  for(i=0;str[i]!=0;i++)
    res = res ^ str[i];
  return (res & (TA_STRING_HASH_SIZE-1));
}


/********************************************************************/
/**                      String2Ptr Hash Map                      **/
/********************************************************************/
void* ta_s2p_hash_map_get( String2PtrHashMap* map, const char* key)
{
  String2PtrHashMapElement tmp;
  
  tmp = map->data[ta_string_hash_code(key)];
  if (tmp.key == NULL)
    return NULL;
  
  if (strcmp(tmp.key,key) == 0)
      return tmp.value;
  
  while(tmp.next!=NULL)
  {      
    tmp=*(tmp.next);
  
    if (strcmp(tmp.key,key) == 0)
      return tmp.value;
  }
  return NULL;
}

void  ta_s2p_hash_map_put( String2PtrHashMap* map, const char* key, void* value )
{
  String2PtrHashMapElement* base, *tempPtr;
  
  base = (&(map->data[ta_string_hash_code(key)]));
  if (base->key == NULL)
   {base->key   = key;
    base->value = value;
    return;
   }
  tempPtr = ((String2PtrHashMapElement*)ta_alloc_memory(sizeof(String2PtrHashMapElement)));
  assertion( tempPtr != NULL, "ta_s2p_hash_map_put: not enough memory" );
  
  tempPtr->key   = key;
  tempPtr->value = value;
  tempPtr->next  = base->next;
  base->next = tempPtr;
}

