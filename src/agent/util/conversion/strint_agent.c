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


#include "util/conversion/strint_agent.h"
#include <errno.h>
#include <inttypes.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
#define mytype long
#define internal_cmd __strtol_internal_cmd
#define internal_func __strtol_internal
#define writeFunc writeLong 
#include "strint_internal.h"
#undef mytype
#undef internal_cmd
#undef internal_func
#undef writeFunc

#define mytype long long
#define internal_cmd __strtoll_internal_cmd
#define internal_func __strtoll_internal
#define writeFunc writeLLong 
#include "strint_internal.h"
#undef mytype
#undef internal_cmd
#undef internal_func
#undef writeFunc


#define mytype unsigned long
#define internal_cmd __strtoul_internal_cmd
#define internal_func __strtoul_internal
#define writeFunc writeULong 
#include "strint_internal.h"
#undef mytype
#undef internal_cmd
#undef internal_func
#undef writeFunc

#define mytype unsigned long long
#define internal_cmd __strtoull_internal_cmd
#define internal_func __strtoull_internal
#define writeFunc writeULLong 
#include "strint_internal.h"
#undef mytype
#undef internal_cmd
#undef internal_func
#undef writeFunc


#define mytype long
#define ato_cmd a64l_cmd
#define ato_func a64l
#define writeFunc writeLong
#include "strint_ato.h"
#undef mytype
#undef ato_cmd
#undef ato_func
#undef writeFunc

#define mytype int
#define ato_cmd atoi_cmd
#define ato_func atoi
#define writeFunc writeInt
#include "strint_ato.h"
#undef mytype
#undef ato_cmd
#undef ato_func
#undef writeFunc

#define mytype long
#define ato_cmd atol_cmd
#define ato_func atol
#define writeFunc writeLong
#include "strint_ato.h"
#undef mytype
#undef ato_cmd
#undef ato_func
#undef writeFunc

#define mytype long long
#define ato_cmd atoll_cmd
#define ato_func atoll
#define writeFunc writeLLong
#include "strint_ato.h"
#undef mytype
#undef ato_cmd
#undef ato_func
#undef writeFunc

static TACommandVerdict l64a_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    long value;
    // Prepare       
    value=readLong(&stream);
    // Execute    
    START_TARGET_OPERATION(thread);
    res = l64a(value);
    END_TARGET_OPERATION(thread);

    // Response    
    writeString(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

#define mytype long long
#define usual_cmd strtoimax_cmd
#define usual_func strtoimax
#define writeFunc writeLLong 
#include "strint_usual.h"
#undef mytype
#undef usual_cmd
#undef usual_func
#undef writeFunc

#define mytype long
#define usual_cmd strtol_cmd
#define usual_func strtol
#define writeFunc writeLong 
#include "strint_usual.h"
#undef mytype
#undef usual_cmd
#undef usual_func
#undef writeFunc

#define mytype long long
#define usual_cmd strtoll_cmd
#define usual_func strtoll
#define writeFunc writeLLong 
#include "strint_usual.h"
#undef mytype
#undef usual_cmd
#undef usual_func
#undef writeFunc

#define mytype long long
#define usual_cmd strtoq_cmd
#define usual_func strtoq
#define writeFunc writeLLong 
#include "strint_usual.h"
#undef mytype
#undef usual_cmd
#undef usual_func
#undef writeFunc

#define mytype unsigned long
#define usual_cmd strtoul_cmd
#define usual_func strtoul
#define writeFunc writeULong 
#include "strint_usual.h"
#undef mytype
#undef usual_cmd
#undef usual_func
#undef writeFunc

#define mytype unsigned long long
#define usual_cmd strtoull_cmd
#define usual_func strtoull
#define writeFunc writeULLong 
#include "strint_usual.h"
#undef mytype
#undef usual_cmd
#undef usual_func
#undef writeFunc

#define mytype unsigned long long
#define usual_cmd strtoumax_cmd
#define usual_func strtoumax
#define writeFunc writeULLong 
#include "strint_usual.h"
#undef mytype
#undef usual_cmd
#undef usual_func
#undef writeFunc


#define mytype unsigned long long
#define usual_cmd strtouq_cmd
#define usual_func strtouq
#define writeFunc writeULLong 
#include "strint_usual.h"
#undef mytype
#undef usual_cmd
#undef usual_func
#undef writeFunc

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_conversion_strint_commands(void)
{
    ta_register_command("__strtol_internal",__strtol_internal_cmd);
    ta_register_command("__strtoll_internal",__strtoll_internal_cmd);
    ta_register_command("__strtoul_internal",__strtoul_internal_cmd);
    ta_register_command("__strtoull_internal",__strtoull_internal_cmd);
    ta_register_command("a64l",a64l_cmd);
    ta_register_command("atoi",atoi_cmd);
    ta_register_command("atol",atol_cmd);
    ta_register_command("atoll",atoll_cmd);
    ta_register_command("l64a",l64a_cmd);
    ta_register_command("strtoimax",strtoimax_cmd);
    ta_register_command("strtol",strtol_cmd);
    ta_register_command("strtoll",strtoll_cmd);
    ta_register_command("strtoq",strtoq_cmd);
    ta_register_command("strtoul",strtoul_cmd);
    ta_register_command("strtoull",strtoull_cmd);
    ta_register_command("strtoumax",strtoumax_cmd);
    ta_register_command("strtouq",strtouq_cmd);
}

