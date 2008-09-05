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
#include <stdlib.h>
#include <security/pam_appl.h>
#include "util/pam/pam_agent.h"

#define PAM_MAX_RESP_SIZE 256

int su_conv( int, const struct pam_message **, struct pam_response **, void * );

void writeListStr( TAThread thread, char ** res ) {
    int size = 0, i;
    if ( res == 0 ) {
        writeInt( thread, -1 );
        return;
    }
    while ( res[ size ] != 0 ) { size++; }
    writeInt( thread, size );
    for ( i = 0; i < size; i++ ) { writeString( thread, res[ i ] ); }
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pam_acct_mgmt_cmd( TAThread thread, TAInputStream stream ) {
    pam_handle_t * pamh  = (pam_handle_t *)readPointer( & stream );
    int            flags =                 readInt    ( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_acct_mgmt( pamh, flags );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_acct_mgmt_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_authenticate_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh  = (pam_handle_t *)readPointer( & stream );
    int            flags =                 readInt    ( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_authenticate( pamh, flags );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_authenticate_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_chauthtok_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh  = (pam_handle_t *)readPointer( & stream );
    int            flags =                 readInt    ( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_chauthtok( pamh, flags );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_chauthtok_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_close_session_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh  = (pam_handle_t *)readPointer( & stream );
    int            flags =                 readInt    ( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_close_session( pamh, flags );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_close_session_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_end_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh       = (pam_handle_t *)readPointer( & stream );
    int            pam_status =                 readInt    ( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_end( pamh, pam_status );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_end_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_fail_delay_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh      = (pam_handle_t *)readPointer( & stream );
    unsigned int   micro_sec =                 readUInt   ( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_fail_delay( pamh, micro_sec );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_fail_delay_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_get_item_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh      = (pam_handle_t *)readPointer( & stream );
    int            item_type =                 readInt    ( & stream );
    void         * item      =                 readPointer( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_get_item( pamh, item_type, & item );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_get_item_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt    ( thread, res  );
    writePointer( thread, item );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_getenvlist_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh = (pam_handle_t *)readPointer( & stream );
    char ** res;
    START_TARGET_OPERATION( thread );
    res = pam_getenvlist( pamh );
    END_TARGET_OPERATION( thread );
    writeListStr( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_open_session_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh  = (pam_handle_t *)readPointer( & stream );
    int            flags =                 readInt    ( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_open_session( pamh, flags );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_open_session_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_set_item_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh      = (pam_handle_t *)readPointer( & stream );
    int            item_type =                 readInt    ( & stream );
    void         * item      =                 readPointer( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_set_item( pamh, item_type, item );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_set_item_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_setcred_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh  = (pam_handle_t *)readPointer( & stream );
    int            flags =                 readInt    ( & stream );
    int res;
    START_TARGET_OPERATION( thread );
    res = pam_setcred( pamh, flags );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_setcred_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writeInt( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict pam_start_cmd( TAThread thread,TAInputStream stream ) {
    char * service_name = readString( & stream );
    char * username     = readString( & stream );
    int    pam_conv     = readInt   ( & stream );
    struct pam_conv conv = { su_conv, NULL };
    int res;
    pam_handle_t * pamh;
    START_TARGET_OPERATION( thread );
    res = pam_start( service_name, username, & conv, & pamh );
    END_TARGET_OPERATION( thread );
    if ( res != PAM_SUCCESS ) { ta_debug_printf( "pam_start_cmd : %s\n", pam_strerror( pamh, res ) ); }
    writePointer( thread, (void *)pamh );
    writeInt    ( thread, res          );
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pam_strerror_cmd( TAThread thread,TAInputStream stream ) {
    pam_handle_t * pamh   = (pam_handle_t *)readPointer( & stream );
    int            errnum =                 readInt    ( & stream );
    char * res;
    START_TARGET_OPERATION( thread );
    res = pam_strerror( pamh, errnum );
    END_TARGET_OPERATION( thread );
    writeString( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_util_pam_commands(void)
{
    ta_register_command( "pam_acct_mgmt"    , pam_acct_mgmt_cmd     );
    ta_register_command( "pam_authenticate" , pam_authenticate_cmd  );
    ta_register_command( "pam_chauthtok"    , pam_chauthtok_cmd     );
    ta_register_command( "pam_close_session", pam_close_session_cmd );
    ta_register_command( "pam_end"          , pam_end_cmd           );
    ta_register_command( "pam_fail_delay"   , pam_fail_delay_cmd    );
    ta_register_command( "pam_get_item"     , pam_get_item_cmd      );
    ta_register_command( "pam_getenvlist"   , pam_getenvlist_cmd    );
    ta_register_command( "pam_open_session" , pam_open_session_cmd  );
    ta_register_command( "pam_set_item"     , pam_set_item_cmd      );
    ta_register_command( "pam_setcred"      , pam_setcred_cmd       );
    ta_register_command( "pam_start"        , pam_start_cmd         );
    ta_register_command( "pam_strerror"     , pam_strerror_cmd      );
}

int su_conv( int num_msg, const struct pam_message ** msg, struct pam_response ** resp, void * appdata ) {
    return PAM_SUCCESS;
}
