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


#ifndef COMMON_EXPLICIT_FSM_H
#define COMMON_EXPLICIT_FSM_H

extern int fiber_execution_finished;

#define EXECUTE_EXPLICIT_FSM(func) \
    initFibers(func); \
    iterate(int i=0; !fiber_execution_finished; i++;) \
    { \
        doActions(); \
    }


/*
 * To be called from the scenario function to let all active fibers execute one
 * step. The scenario may look like:
    scenario
    bool sc_forever_scen()
    {
        EXECUTE_EXPLICIT_FSM(scenario_function);
        return true;
    }
 */

void doActions(void);

typedef void(*fiberFunc)(void);

/*
 * To be called from implementation function (fiberFunc) to signal end of 
 * current step
 */
void serialize(void);

/*
 * To be called from scenario _init function. The parameter is a pointer to 
 * the implementation function
 */
void initFibers(fiberFunc func);

/*
 * To be called from scenario _finish function
 */
void finishFibers();

#endif
