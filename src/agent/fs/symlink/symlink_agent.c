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


#include "fs/symlink/symlink_agent.h"
#include <errno.h>
#include <string.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict readlink_cmd(TAThread thread,TAInputStream stream)
{
  ssize_t res;
  char* path;
  char* buf;
  char* oldBuf;
  size_t bufsize;

  path=readString(&stream);
  bufsize=readSize(&stream);
  buf=ta_alloc_memory(bufsize);
  oldBuf=ta_alloc_memory(bufsize);

  assertion( buf != NULL || oldBuf!=NULL, "readlink_cmd: not enough memory" );
  memcpy(oldBuf, buf, bufsize);
  errno = 0;

  START_TARGET_OPERATION(thread);
  res=readlink(path, buf, bufsize);
  END_TARGET_OPERATION(thread);

  writeSSize(thread, res);
  writeByteArray(thread, buf, bufsize);
  writeInt(thread, memcmp(buf, oldBuf, bufsize));
  writeInt(thread,errno);

  sendResponse(thread);
  return taDefaultVerdict;
}

static TACommandVerdict symlink_cmd(TAThread thread,TAInputStream stream)
{
  int res;
  char* path1;
  char* path2;

  path1=readString(&stream);
  path2=readString(&stream);
  errno = 0;

  START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
  res=symlink(path1, path2);
  END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

  writeInt(thread, res);
  writeInt(thread, errno);

  sendResponse(thread);
  return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_symlink_commands(void)
{
    ta_register_command("readlink",readlink_cmd);
    ta_register_command("symlink",symlink_cmd);
}

