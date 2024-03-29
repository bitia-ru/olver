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
static TACommandVerdict usual_cmd(TAThread thread,TAInputStream stream)
{
    char* nptr, *endptr;
    mytype res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(char*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);


    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = usual_func(nptr, (char**)NULL, base);
    else
        res = usual_func(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

    // Response    
    writeFunc(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

