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


#include "common/explicit_fsm.h"

int fiber_execution_finished = 0;

#ifdef WIN32

#define _WIN32_WINNT 0x0500
#include <windows.h>

static LPVOID scenFiber = NULL;
static LPVOID mainFiber = NULL;

void doActions(void)
{
    if(!fiber_execution_finished)
        SwitchToFiber(scenFiber);
    if(fiber_execution_finished)
        finishFibers();
}

void serialize(void)
{
    SwitchToFiber(mainFiber);
}

VOID CALLBACK scenarioRunFiber(PVOID pParam)
{
    fiberFunc f = (fiberFunc)pParam;
    fiber_execution_finished = 0;
    (*f)();
    fiber_execution_finished = 1;
    SwitchToFiber(mainFiber);
}

void initFibers(fiberFunc func)
{
    if (mainFiber == NULL&&fiber_execution_finished==0)
    {
        mainFiber = ConvertThreadToFiber(NULL);
        scenFiber = (LPVOID)CreateFiber(0, scenarioRunFiber, func);
    }
}

void finishFibers()
{
    mainFiber = NULL;
    scenFiber = NULL;
}

/************************************************************************/
/*  New code                                                            */
/************************************************************************/
#else

//#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static pthread_t scen_thread = -1;
static int initialized = 0;
static int main_run = 1;

void finishFibers()
{
    //printf("finished\n");
    sleep(0);
    
    pthread_cancel(scen_thread);
    scen_thread = -1;
    initialized = 0;
}

void doActions(void)
{
    //printf("do! finished == %d\n", fiber_execution_finished);
    sleep(0);

    if(!fiber_execution_finished)
    {
        main_run = 0;
        while(!main_run);
        
        if(fiber_execution_finished)
            finishFibers();
    }
    else
    {
        finishFibers();
    }
}

void serialize(void)
{
    //printf("serialize\n");
    sleep(0);    
    
    main_run = 1;
    while(main_run);
}

void* scenarioRunFiber(void* pParam)
{
    fiberFunc f = (fiberFunc) pParam;
    
    while(main_run);
    //printf("run...\n");
        
    fiber_execution_finished = 0;
    
    (*f)();
    
    fiber_execution_finished = 1;
    serialize();
    
    return 0;
}

void initFibers(fiberFunc func)
{
    if(!initialized)
    {
        //printf("init\n");
        sleep(0);
        initialized = 1;
        main_run = 1;
                
        pthread_create(&scen_thread, 0, scenarioRunFiber, func);
    }
}

#endif
