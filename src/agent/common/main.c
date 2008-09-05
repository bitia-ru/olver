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


#include "common/command.h"
#include "common/agent.h"
#include <string.h>

/********************************************************************/
/**                         Test Agent Main                        **/
/********************************************************************/

int main(int argc,const char** argv)
{
    int argi;
    // set verbose output stream
    verbose_output = stdout;

    for(argi=1;argi<argc;argi++)
    {
        // process options
        if ( strcmp(argv[argi],"-silent") == 0 )
        {
            ta_verbose_off();
            verbose_enabled = 0;
        }
        else if ( strcmp(argv[argi],"-debug") == 0 )
        {
            ta_debug_on();
            verbose_enabled = 0;
            ta_program_name = argv[0];
        }
        else if ( strcmp(argv[argi],"-log") == 0 )
        {
            argi++;
            if (argv[argi] != NULL)
             {
                ta_agent_log = argv[argi];
             }
        }
    }

    // init test agent
    ta_process_main_init();

    // register commands
    ta_register_commands();

    // setup tcp communicator
    ta_setup_tcp_communicator(argc, argv);

    // startup test agent main function
    return ta_process_main_routine(argc,argv);
}
