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


#include "system/stat/stat_agent.h"
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <sys/times.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict acct_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int isNotZero;
    char *filename = NULL;

    // Prepare
    isNotZero = readInt(&stream);
    if (isNotZero)
    {
        filename = readString(&stream);
    }

    START_TARGET_OPERATION(thread);
    res = acct(filename);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clock_cmd(TAThread thread,TAInputStream stream)
{
    clock_t res;

    // Prepare

    START_TARGET_OPERATION(thread);
    res = clock();
    END_TARGET_OPERATION(thread);

    // Response
    writeLong(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getloadavg_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int nelem;
    double* loadavg;
    int i=0;

    // Prepare
    nelem = readInt(&stream);
    loadavg = ta_alloc_memory(nelem*sizeof(double)+5);

    START_TARGET_OPERATION(thread);
    res = getloadavg(loadavg, nelem);
    END_TARGET_OPERATION(thread);

    // Response
    for (i=0;i<nelem;i++)
    {
        writeDouble(thread, loadavg[i]);
    }

    writeInt(thread, res);

    sendResponse(thread);

    ta_dealloc_memory(loadavg);
    return taDefaultVerdict;
}

static TACommandVerdict times_cmd(TAThread thread,TAInputStream stream)
{
    clock_t res;
    struct tms buffer;


    START_TARGET_OPERATION(thread);
    res = times(&buffer);
    END_TARGET_OPERATION(thread);

    // Response
    writeLong( thread, buffer.tms_utime  );
    writeLong( thread, buffer.tms_stime  );
    writeLong( thread, buffer.tms_cutime );
    writeLong( thread, buffer.tms_cstime );
    writeLong( thread, res               );
    writeInt ( thread, errno             );

    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_system_stat_commands(void)
{
    ta_register_command("acct",acct_cmd);
    ta_register_command("clock",clock_cmd);
    ta_register_command("getloadavg",getloadavg_cmd);
    ta_register_command("times",times_cmd);
}
