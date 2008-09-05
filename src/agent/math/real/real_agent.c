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


#include "math/real/real_agent.h"
#include <errno.h>
#include <math.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict ceil_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = ceil(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ceilf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = ceilf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ceill_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = ceill(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict copysign_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;
   
    x = readDouble(&stream);
    y = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = copysign(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict copysignf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
   
    x = readFloat(&stream);
    y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = copysignf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict copysignl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;
   
    x = readLongDouble(&stream);
    y = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = copysignl(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict dremf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
   
    x = readFloat(&stream);
    y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = dremf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict dreml_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;

    x = readLongDouble(&stream);
    y = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = dreml(x, y);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fabs_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = fabs(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fabsf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = fabsf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;}

static TACommandVerdict fabsl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = fabsl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fdim_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;
   
    x = readDouble(&stream);
    y = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = fdim(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fdimf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
   
    x = readFloat(&stream);
    y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = fdimf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fdiml_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;
   
    x = readLongDouble(&stream);
    y = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = fdiml(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict floor_cmd(TAThread thread,TAInputStream stream)
{
    double arg;
    double res;
   
    arg = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = floor(arg);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict floorf_cmd(TAThread thread,TAInputStream stream)
{   
    float arg;
    float res;
   
    arg = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = floorf(arg);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict floorl_cmd(TAThread thread,TAInputStream stream)
{
    long double arg;
    long double res;
   
    arg = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = floorl(arg);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fma_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, z, res;

    x = readDouble(&stream);
    y = readDouble(&stream);
    z = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = fma(x, y, z);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fmaf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, z, res;
   
    x = readFloat(&stream);
    y = readFloat(&stream);
    z = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = fmaf(x, y, z);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fmal_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, z, res;

    x = readLongDouble(&stream);
    y = readLongDouble(&stream);
    z = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = fmal(x, y, z);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fmax_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;

    x = readDouble(&stream);
    y = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    res = fmax(x, y);

    END_TARGET_OPERATION(thread);

    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fmaxf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
   
    x = readFloat(&stream);
    y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = fmaxf(x, y);
    
    END_TARGET_OPERATION(thread);

    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fmaxl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;

    x = readLongDouble(&stream);
    y = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    res = fmaxl(x, y);

    END_TARGET_OPERATION(thread);
 
    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fmin_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;

    x = readDouble(&stream);
    y = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    res = fmin(x, y);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fminf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
   
    x = readFloat(&stream);
    y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);

    res = fminf(x, y);
    
    END_TARGET_OPERATION(thread);

    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fminl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;

    x = readLongDouble(&stream);
    y = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    res = fminl(x, y);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fmod_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;

    x = readDouble(&stream);
    y = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = fmod(x, y);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fmodf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
   
    x = readFloat(&stream);
    y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = fmodf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fmodl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;

    x = readLongDouble(&stream);
    y = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = fmodl(x, y);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict llrint_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    long long res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = llrint(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict llrintf_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    long long res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = llrintf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict llrintl_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    long long res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = llrintl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict llround_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    long long res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = llround(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict llroundf_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    long long res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = llroundf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict llroundl_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    long long res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = llroundl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lrint_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    long res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = lrint(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lrintf_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    long res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = lrintf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lrintl_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    long res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = lrintl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lround_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    long res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = lround(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lroundf_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    long res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = lroundf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lroundl_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    long res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = lroundl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict modf_cmd(TAThread thread,TAInputStream stream)
{
    double x, iptr, res;

    x = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    res = modf(x, &iptr);

    END_TARGET_OPERATION(thread);

    writeDouble(thread, res);
    writeDouble(thread, iptr);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict modff_cmd(TAThread thread,TAInputStream stream)
{
    float x, iptr, res;

    x = readFloat(&stream);

    START_TARGET_OPERATION(thread);

    res = modff(x, &iptr);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, res);
    writeFloat(thread, iptr);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict modfl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, iptr, res;

    x = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    res = modfl(x, &iptr);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, res);
    writeLongDouble(thread, iptr);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict nan_cmd(TAThread thread,TAInputStream stream)
{
    double res;
    char* tagp;

    tagp = readString(&stream);

    START_TARGET_OPERATION(thread);

    res = nan(tagp);

    END_TARGET_OPERATION(thread);

    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict nanf_cmd(TAThread thread,TAInputStream stream)
{
    float res;
    char* tagp;

    tagp = readString(&stream);

    START_TARGET_OPERATION(thread);

    res = nanf(tagp);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict nanl_cmd(TAThread thread,TAInputStream stream)
{
    long double res;
    char* tagp;

    tagp = readString(&stream);

    START_TARGET_OPERATION(thread);

    res = nan(tagp);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict nearbyint_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = nearbyint(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict nearbyintf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = nearbyintf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict nearbyintl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = nearbyintl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict remainder_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;

    x = readDouble(&stream);
    y = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = remainder(x, y);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict remainderf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
   
    x = readFloat(&stream);
    y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = remainderf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict remainderl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;

    x = readLongDouble(&stream);
    y = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = remainderl(x, y);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict remquo_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;
    int quo;
    x = readDouble(&stream);
    y = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = remquo(x, y, &quo);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeDouble(thread, res);
    writeInt(thread, quo);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict remquof_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
    int quo;
    x = readFloat(&stream);
    y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = remquof(x, y, &quo);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeFloat(thread, res);
    writeInt(thread, quo);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict remquol_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;
    int quo;
    x = readLongDouble(&stream);
    y = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = remquol(x, y, &quo);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    writeInt(thread, quo);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict rint_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = rint(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict rintf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = rintf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict rintl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = rintl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict round_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = round(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict roundf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = roundf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict roundl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = roundl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict trunc_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = trunc(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict truncf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = truncf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict truncl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = truncl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_real_commands(void)
{
    ta_register_command("ceil",ceil_cmd);
    ta_register_command("ceilf",ceilf_cmd);
    ta_register_command("ceill",ceill_cmd);
    ta_register_command("copysign",copysign_cmd);
    ta_register_command("copysignf",copysignf_cmd);
    ta_register_command("copysignl",copysignl_cmd);
    ta_register_command("dremf",dremf_cmd);
    ta_register_command("dreml",dreml_cmd);
    ta_register_command("fabs",fabs_cmd);
    ta_register_command("fabsf",fabsf_cmd);
    ta_register_command("fabsl",fabsl_cmd);
    ta_register_command("fdim",fdim_cmd);
    ta_register_command("fdimf",fdimf_cmd);
    ta_register_command("fdiml",fdiml_cmd);
    ta_register_command("floor",floor_cmd);
    ta_register_command("floorf",floorf_cmd);
    ta_register_command("floorl",floorl_cmd);
    ta_register_command("fma",fma_cmd);
    ta_register_command("fmaf",fmaf_cmd);
    ta_register_command("fmal",fmal_cmd);
    ta_register_command("fmax",fmax_cmd);
    ta_register_command("fmaxf",fmaxf_cmd);
    ta_register_command("fmaxl",fmaxl_cmd);
    ta_register_command("fmin",fmin_cmd);
    ta_register_command("fminf",fminf_cmd);
    ta_register_command("fminl",fminl_cmd);
    ta_register_command("fmod",fmod_cmd);
    ta_register_command("fmodf",fmodf_cmd);
    ta_register_command("fmodl",fmodl_cmd);
    ta_register_command("llrint",llrint_cmd);
    ta_register_command("llrintf",llrintf_cmd);
    ta_register_command("llrintl",llrintl_cmd);
    ta_register_command("llround",llround_cmd);
    ta_register_command("llroundf",llroundf_cmd);
    ta_register_command("llroundl",llroundl_cmd);
    ta_register_command("lrint",lrint_cmd);
    ta_register_command("lrintf",lrintf_cmd);
    ta_register_command("lrintl",lrintl_cmd);
    ta_register_command("lround",lround_cmd);
    ta_register_command("lroundf",lroundf_cmd);
    ta_register_command("lroundl",lroundl_cmd);
    ta_register_command("modf",modf_cmd);
    ta_register_command("modff",modff_cmd);
    ta_register_command("modfl",modfl_cmd);
    ta_register_command("nan",nan_cmd);
    ta_register_command("nanf",nanf_cmd);
    ta_register_command("nanl",nanl_cmd);
    ta_register_command("nearbyint",nearbyint_cmd);
    ta_register_command("nearbyintf",nearbyintf_cmd);
    ta_register_command("nearbyintl",nearbyintl_cmd);
    ta_register_command("remainder",remainder_cmd);
    ta_register_command("remainderf",remainderf_cmd);
    ta_register_command("remainderl",remainderl_cmd);
    ta_register_command("remquo",remquo_cmd);
    ta_register_command("remquof",remquof_cmd);
    ta_register_command("remquol",remquol_cmd);
    ta_register_command("rint",rint_cmd);
    ta_register_command("rintf",rintf_cmd);
    ta_register_command("rintl",rintl_cmd);
    ta_register_command("round",round_cmd);
    ta_register_command("roundf",roundf_cmd);
    ta_register_command("roundl",roundl_cmd);
    ta_register_command("trunc",trunc_cmd);
    ta_register_command("truncf",truncf_cmd);
    ta_register_command("truncl",truncl_cmd);
}

