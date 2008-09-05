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


#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "common/verbose.h"

/*
 *  Redirect output to this file
 */
FILE* verbose_output = NULL;

/*
 * Verbose control flag
 */
int verbose_enabled = 1;

/*
 * Verbose function implementation
 */
int verbose(const char *format, ...)
{
    if (verbose_enabled == 1 && verbose_output != NULL)
    {
        va_list args;
        va_start(args, format);
        vfprintf(verbose_output, format, args);
        va_end(args);       
    }
    return 0;
}
