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
static TACommandVerdict ato_cmd(TAThread thread,TAInputStream stream)
{
    char* nptr, *endptr;
    mytype res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=readString(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    res=ato_func(nptr);
    END_TARGET_OPERATION(thread);

    // Response    
    writeFunc(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

