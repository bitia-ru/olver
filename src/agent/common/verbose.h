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

/*
*  Redirect output to this file
*/
extern FILE* verbose_output;

/*
 * Verbose control flag
 */
extern int verbose_enabled;
/*
 * Verbose function declaration
 */
int verbose(const char *format, ...);
/*
 * Use this macro definitions instead of direct references to
 * the functions and variables.
 */
#define VERBOSE_OUTPUT(file)   verbose_output = file;
#define VERBOSE         verbose
#define VERBOSE_ON()    verbose_enabled = 1;
#define VERBOSE_OFF()   verbose_enabled = 0;

