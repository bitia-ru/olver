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


#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "fs/fs/fs_agent.h"


/********************************************************************/
/**                        Format Functions                        **/
/********************************************************************/

/* FilePermissions */
mode_t readFilePermissions(TAInputStream* stream)
{
char* code;
mode_t res;

  verifyType_TAInputStream(stream,"perms");
  code = readString(stream);
  res = 0;
  if (code[0] == 'r') res = res | S_IRUSR;
  if (code[1] == 'w') res = res | S_IWUSR;
  if (code[2] == 'x') res = res | S_IXUSR;
  if (code[3] == 'r') res = res | S_IRGRP;
  if (code[4] == 'w') res = res | S_IWGRP;
  if (code[5] == 'x') res = res | S_IXGRP;
  if (code[6] == 'r') res = res | S_IROTH;
  if (code[7] == 'w') res = res | S_IWOTH;
  if (code[8] == 'x') res = res | S_IXOTH;
  return res;
}

/* FileKind */

mode_t readFileKind(TAInputStream *stream)
{
    char *name;

    verifyType_TAInputStream(stream, "filekind");
    name = readString(stream);


#define trans(code, mode) if(!strcmp(name, #code)) return mode;

    trans(FIFOFile, S_IFIFO)
      trans(RegularFile, S_IFREG)
      trans(BlockFile, S_IFBLK)
      trans(CharacterFile, S_IFCHR)
      trans(DirectoryFile, S_IFDIR)
    
    return (mode_t)0;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __xmknod_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    
    int ver;
    const char *path;
    mode_t mode;
    dev_t dev;
    int retval;

    ver = readInt(&stream);
    path = readString(&stream);
    mode = readFileKind(&stream);
    mode |= readFilePermissions(&stream);
    dev = readULLong(&stream);
    

    START_TARGET_OPERATION(thread);
    
    // Execute
    errno = 0;
#if ( __i386__ || __powerpc__ || (__s390__ && !__s390x__) ) 
    retval = __xmknod( ver, path, mode, &dev );
#else
    retval = __xmknod( 0, path, mode, &dev );
#endif        
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, retval);
    writeInt(thread, errno); 
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict link_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    const char *path1 = readString(&stream);
    const char *path2 = readString(&stream);
    int retval;
        
    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    // Execute
    errno = 0;
    retval = link(path1, path2);
    
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    // Response
    writeInt(thread, retval);
    writeInt(thread, errno); 
    sendResponse(thread);
   
  
    return taDefaultVerdict;
}

static TACommandVerdict remove_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    const char *path = readString(&stream);
    int retval;
    
    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    // Execute
    errno = 0;
    retval = remove(path);
    
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    // Response
    writeInt(thread, retval);
    writeInt(thread, errno); 
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict rename_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    const char *pathOld;
    const char *pathNew;
    
    pathOld = readString(&stream);
    pathNew = readString(&stream);
    int retval;
    
    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    // Execute
    errno = 0;
    retval = rename(pathOld, pathNew);
    
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
   // Response
    writeInt(thread, retval);
    writeInt(thread, errno); 
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict unlink_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    const char *path = readString(&stream);
    int retval;
    
    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    // Execute
    errno = 0;
    retval = unlink(path);
    
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    // Response
    writeInt(thread, retval);
    writeInt(thread, errno); 
    sendResponse(thread);    
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_fs_commands(void)
{
    ta_register_command("__xmknod",__xmknod_cmd);
    ta_register_command("link",link_cmd);
    ta_register_command("remove",remove_cmd);
    ta_register_command("rename",rename_cmd);
    ta_register_command("unlink",unlink_cmd);
}

