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


#include "util/conversion/wchar_agent.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

mbstate_t readMbstate(TAInputStream* stream)
{
    mbstate_t res;

    verifyType_TAInputStream(stream,"mbstate");

    res.count = readInt(stream);
    res.value = readLong(stream);
    
    return res;
}
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict btowc_cmd(TAThread thread,TAInputStream stream)
{
    long res;
    int c;

    // Prepare
    c=readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = btowc(c);    
    END_TARGET_OPERATION(thread);    
    // Response
    writeUInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mblen_cmd(TAThread thread,TAInputStream stream)
{
    char* s=0;
    size_t n;
    int res, ind;

   
    // Prepare
    s=(char*)readPointer(&stream);
    n=readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = mblen(s, n);    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mbrlen_cmd(TAThread thread,TAInputStream stream)
{
    char* s=0;
    size_t n;
    int res, ind;
    mbstate_t ps;

    // Prepare
    s=(char*)readPointer(&stream);
    n=readInt(&stream);
    ps=readMbstate(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(ps.value==-1)
        res = mbrlen(s, n, 0);
    else
        res = mbrlen(s, n, &ps);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mbrtowc_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* pwc;
    char* s=0;
    size_t n;
    int res, ind;
    mbstate_t ps;

   
    // Prepare
    ind=readInt(&stream);
    pwc=(wchar_t*)readPointer(&stream);
    s=(char*)readPointer(&stream);
    n=readInt(&stream);
    ps=readMbstate(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(ind)
    {
        if(ps.value==-1)
            res = mbrtowc(pwc, s, n, 0);
        else
            res = mbrtowc(pwc, s, n, &ps);
    }
    else
        if(ps.value==-1)
            res = mbrtowc(0, s, n, 0);
        else
            res = mbrtowc(0, s, n, &ps);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    if(ind)
        writePointer(thread, pwc);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mbsinit_cmd(TAThread thread,TAInputStream stream)
{
    mbstate_t ps;
    int res;

    // Prepare
    ps=readMbstate(&stream);

    START_TARGET_OPERATION(thread);
    if(ps.value==-1)
        res = mbsinit(0);
    else
        res = mbsinit(&ps);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mbsnrtowcs_cmd(TAThread thread,TAInputStream stream)
{
    char* src;
    wchar_t* dst;
    size_t len;
    int res, ind1, ind2, nms;
    mbstate_t ps;

   
    // Prepare
    ind1=readInt(&stream);
    ind2=readInt(&stream);
    dst=(wchar_t*)readPointer(&stream);
    src=(char*)readPointer(&stream);
    nms=readInt(&stream);
    len=readInt(&stream);
    ps=readMbstate(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(ps.value==-1)
        res = mbsnrtowcs(dst, &src, nms, len, 0);
    else
        res = mbsnrtowcs(dst, &src, nms, len, &ps);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    if(ind1)
        writePointer(thread, dst);
    if(ind2)
        writePointer(thread, src);

    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mbsrtowcs_cmd(TAThread thread,TAInputStream stream)
{
    char* src;
    wchar_t* dst;
    size_t len;
    int res, ind1, ind2;
    mbstate_t ps;

   
    // Prepare
    ind1=readInt(&stream);
    ind2=readInt(&stream);
    dst=(wchar_t*)readPointer(&stream);
    src=(char*)readPointer(&stream);
    len=readInt(&stream);
    ps=readMbstate(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(ps.value==-1)
        res = mbsrtowcs(dst, &src, len, 0);
    else
        res = mbsrtowcs(dst, &src, len, &ps);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    if(ind1)
        writePointer(thread, dst);
    if(ind2)
        writePointer(thread, src);

    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mbstowcs_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* pwcs;
    char* s=0;
    size_t n;
    int res, ind;

   
    // Prepare
    pwcs=(wchar_t*)readPointer(&stream);
    s=(char*)readPointer(&stream);
    n=readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = mbstowcs(pwcs, s, n);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    if(pwcs!=0)
        writePointer(thread, pwcs);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mbtowc_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* pwc;
    char* s=0;
    size_t n;
    int res, ind;

   
    // Prepare
    ind=readInt(&stream);
    pwc=(wchar_t*)readPointer(&stream);
    s=(char*)readPointer(&stream);
    n=readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(ind)
        res = mbtowc(pwc, s, n);    
    else
        res = mbtowc(0, s, n);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writePointer(thread, pwc);

    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcrtomb_cmd(TAThread thread,TAInputStream stream)
{
    char* s=0;
    wchar_t wc;
    int res, ind;
    mbstate_t ps;

    // Prepare
    s=(char*)readPointer(&stream);
    wc=readWChar(&stream);
    ps=readMbstate(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(ps.value==-1)
        res = wcrtomb(s, wc, 0);
    else
        res = wcrtomb(s, wc, &ps);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    if(s!=0)
        writePointer(thread, s);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcsnrtombs_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* src;
    char* dst=0;
    size_t len;
    int res, ind, nws;
    mbstate_t ps;

   
    // Prepare
    dst=(char*)readPointer(&stream);
    src=(wchar_t*)readPointer(&stream);
    nws=readInt(&stream);
    len=readInt(&stream);
    ps=readMbstate(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(ps.value==-1)
        res = wcsnrtombs(dst, &src, nws, len, 0);
    else
        res = wcsnrtombs(dst, &src, nws, len, &ps);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writePointer(thread, dst);
    writePointer(thread, src);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcsrtombs_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* src;
    char* dst=0;
    size_t len;
    int res, ind;
    mbstate_t ps;

   
    // Prepare
    dst=(char*)readPointer(&stream);
    src=(wchar_t*)readPointer(&stream);
    len=readInt(&stream);
    ps=readMbstate(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(ps.value==-1)
        res = wcsrtombs(dst, &src, len, 0);
    else
        res = wcsrtombs(dst, &src, len, &ps);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writePointer(thread, dst);
    writePointer(thread, src);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcstombs_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* pwcs;
    char* s=0;
    size_t n;
    int res, ind;

   
    // Prepare
    s=(char*)readPointer(&stream);
    pwcs=(wchar_t*)readPointer(&stream);
    n=readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = wcstombs(s, pwcs, n);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    if(s!=0)
        writePointer(thread, s);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wctob_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    long c;

    // Prepare
    c=readUInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wctob(c);    
    END_TARGET_OPERATION(thread);    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wctomb_cmd(TAThread thread,TAInputStream stream)
{

    wchar_t wchar;
    char* s=0;
    int res, ind;

   
    // Prepare
    s=(char*)readPointer(&stream);
    wchar=readWChar(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = wctomb(s, wchar);    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writePointer(thread, s);
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_conversion_wchar_commands(void)
{
    ta_register_command("btowc",btowc_cmd);
    ta_register_command("mblen",mblen_cmd);
    ta_register_command("mbrlen",mbrlen_cmd);
    ta_register_command("mbrtowc",mbrtowc_cmd);
    ta_register_command("mbsinit",mbsinit_cmd);
    ta_register_command("mbsnrtowcs",mbsnrtowcs_cmd);
    ta_register_command("mbsrtowcs",mbsrtowcs_cmd);
    ta_register_command("mbstowcs",mbstowcs_cmd);
    ta_register_command("mbtowc",mbtowc_cmd);
    ta_register_command("wcrtomb",wcrtomb_cmd);
    ta_register_command("wcsnrtombs",wcsnrtombs_cmd);
    ta_register_command("wcsrtombs",wcsrtombs_cmd);
    ta_register_command("wcstombs",wcstombs_cmd);
    ta_register_command("wctob",wctob_cmd);
    ta_register_command("wctomb",wctomb_cmd);
}

