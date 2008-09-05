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
 * Dump function is able to dump specification objects.
 *
 * format = "[$(obj)|str]*[general format acceptable by printf]"
 */
int dump(const char * format, ...);

int dumpv(const char * format, va_list args);

/*
 * Use this macro definitions instead of direct references to
 * the functions and variables.
 */
#define VERBOSE_OUTPUT(file)   verbose_output = file;
#define VERBOSE         verbose
#define VERBOSE_ON()    verbose_enabled = 1;
#define VERBOSE_OFF()   verbose_enabled = 0;
#define DUMP dump
#define DUMPV dumpv


/*
   DUMP example:

   void print_specification_objects()
   {
        String *s = NULL;
        List* l = NULL;

        s = create_String("test string");

        l = create_List(&type_String);
        append_List(l, create_String("s1"));
        append_List(l, create_String("s2"));
        append_List(l, create_String("s3"));
        append_List(l, create_String("s4"));
        append_List(l, create_String("s5"));


        VERBOSE_OUTPUT(stdout);                     // optional, stdout by default
        VERBOSE_ON();                               // switch  verbose on, turned on by default
        
        VERBOSE("Print objects using DUMP:\n");     // print general string

        DUMP("List: $(obj)\n", NULL);               // dump NULL pointer
        DUMP("String: $(obj)\n", s);                // dump String
        DUMP("List: $(obj);\nString = $(obj); number = %d;\n", l, s, 10);   // dump List, String, int

        VERBOSE_OFF();
   }


*/

/* calls dump(), use for debug purposes */
int dump_req(const char *fmt,...);

void set_assertion_exit_callback(void);

void breakHere(void);
