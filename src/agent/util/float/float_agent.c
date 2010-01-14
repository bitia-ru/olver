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


#include "util/float/float_agent.h"
#include <errno.h>
#include <math.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __finite_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    int res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    res = __finite(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __finitef_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    int res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __finitef(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __finitel_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    int res;
    x = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __finitel(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __fpclassify_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    int res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __fpclassify(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __fpclassifyf_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    int res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __fpclassifyf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __isinf_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    int res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __isinf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __isinff_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    int res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __isinff(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __isinfl_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    int res;
    x = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __isinfl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __isnan_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    int res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __isnan(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __isnanf_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    int res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __isnanf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __isnanl_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    int res;
    x = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __isnanl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __signbit_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    int res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __signbit(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict __signbitf_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    int res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = __signbitf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict finite_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    int res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = finite(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict finitef_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    int res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = finitef(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict finitel_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    int res;
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = finitel(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict frexp_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int exp;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = frexp(x, &exp);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, exp);
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict frexpf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
    int exp;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = frexpf(x, &exp);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, exp);
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict frexpl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
    int exp;
    x = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = frexpl(x, &exp);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, exp);
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict ilogb_cmd(TAThread thread,TAInputStream stream)
{
    double x;
    int res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = ilogb(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict ilogbf_cmd(TAThread thread,TAInputStream stream)
{
    float x;
    int res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = ilogbf(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict ilogbl_cmd(TAThread thread,TAInputStream stream)
{
    long double x;
    int res;
    x = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = ilogbl(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict ldexp_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int exp;

    // Prepare

    x = readDouble(&stream);
    exp = readInt(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = ldexp(x, exp);
    
    END_TARGET_OPERATION(thread);
    
    // Response

    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ldexpf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
    int exp;

    // Prepare

    x = readFloat(&stream);
    exp = readInt(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    
    res = ldexpf(x, exp);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ldexpl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
    int exp;

    // Prepare

    x = readLongDouble(&stream);
    exp = readInt(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    
    res = ldexpl(x, exp);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict logb_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = logb(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict logbf_cmd(TAThread thread,TAInputStream stream)
{ 
    float x, res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = logbf(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict logbl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
    x = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = logbl(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict nextafter_cmd(TAThread thread,TAInputStream stream)
{  
    double x,y,res;
    x = readDouble(&stream);
    y = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = nextafter(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict nextafterf_cmd(TAThread thread,TAInputStream stream)
{
    float x,y,res;
    int* p;
    x = readFloat(&stream);
    y = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = nextafterf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict nextafterl_cmd(TAThread thread,TAInputStream stream)
{
    long double x,y,res;
    x = readLongDouble(&stream);
    y = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = nextafterl(x, y);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}
static TACommandVerdict nexttoward_cmd(TAThread thread,TAInputStream stream)
{
    double x,res;
    long double y;
    x = readDouble(&stream);
    y = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;

    res = nexttoward(x, y);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict nexttowardf_cmd(TAThread thread,TAInputStream stream)
{
    float x,res;
    long double y;
    x = readFloat(&stream);
    y = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = nexttowardf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict nexttowardl_cmd(TAThread thread,TAInputStream stream)
{
    long double x,y,res;
    x = readLongDouble(&stream);
    y = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = nexttowardl(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict scalb_cmd(TAThread thread,TAInputStream stream)
{
    double x,n,res;
    x = readDouble(&stream);
    n = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalb(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static Ái@ €kS•ÆS•Æd	aƒ2'§ S?€ýœaP  
šÝ÷  ÷TLS_SOURCES = tls_agent.c


SOURCES += $(TLS_SOURCES:%.c=pthread/tls/%.c)

¨(üFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalbf(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict scalbl_cmd(TAThread thread,TAInputStream stream)
{
    long double x,n,res;
    x = readLongDouble(&stream);
    n = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalbl(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict scalbln_cmd(TAThread thread,TAInputStream stream)
{
    double x,res;
    long n;
    x = readDouble(&stream);
    n = readLong(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalbln(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict scalblnf_cmd(TAThread thread,TAInputStream stream)
{
    float x,res;
    long n;
    x = readFloat(&stream);
    n = readLong(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalblnf(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict scalblnl_cmd(TAThread thread,TAInputStream stream)
{
    long double x,res;
    long n;
    x = readLongDouble(&stream);
    n = readLong(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalblnl(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict scalbn_cmd(TAThread thread,TAInputStream stream)
{
    double x,res;
    int n;
    x = readDouble(&stream);
    n = readInt(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalbn(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict scalbnf_cmd(TAThread thread,TAInputStream stream)
{
    float x,res;
    int n;
    x = readFloat(&stream);
    n = readInt(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalbnf(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict scalbnl_cmd(TAThread thread,TAInputStream stream)
{
    long double x,res;
    int n;
    x = readLongDouble(&stream);
    n = readInt(&stream);
 
    START_TARGET_OPERATION(thread);
    
    errno=0;
    res = scalbnl(x, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno);
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict significand_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    x = readDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = significand(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict significandf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
    x = readFloat(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = significandf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}

static TACommandVerdict significandl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
    x = readLongDouble(&stream);
 
    START_TARGET_OPERATION(thread);
    
    res = significandl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;    
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_float_commands(void)
{
    ta_register_command("__finite",__finite_cmd);
    ta_register_command("__finitef",__finitef_cmd);
    ta_register_command("__finitel",__finitel_cmd);
    ta_register_command("__fpclassify",__fpclassify_cmd);
    ta_register_command("__fpclassifyf",__fpclassifyf_cmd);
    ta_register_command("__isinf",__isinf_cmd);
    ta_register_command("__isinff",__isinff_cmd);
    ta_register_command("__isinfl",__isinfl_cmd);
    ta_register_command("__isnan",__isnan_cmd);
    ta_register_command("__isnanf",__isnanf_cmd);
    ta_register_command("__isnanl",__isnanl_cmd);
    ta_register_command("__signbit",__signbit_cmd);
    ta_register_command("__signbitf",__signbitf_cmd);
    ta_register_command("finite",finite_cmd);
    ta_register_command("finitef",finitef_cmd);
    ta_register_command("finitel",finitel_cmd);
    ta_register_command("frexp",frexp_cmd);
    ta_register_command("frexpf",frexpf_cmd);
    ta_register_command("frexpl",frexpl_cmd);
    ta_register_command("ilogb",ilogb_cmd);
    ta_register_command("ilogbf",ilogbf_cmd);
    ta_register_command("ilogbl",ilogbl_cmd);
    ta_register_command("ldexp",ldexp_cmd);
    ta_register_command("ldexpf",ldexpf_cmd);
    ta_register_command("ldexpl",ldexpl_cmd);
    ta_register_command("logb",logb_cmd);
    ta_register_command("logbf",logbf_cmd);
    ta_register_command("logbl",logbl_cmd);
    ta_register_command("nextafter",nextafter_cmd);
    ta_register_command("nextafterf",nextafterf_cmd);
    ta_register_command("nextafterl",nextafterl_cmd);
    ta_register_command("nexttoward",nexttoward_cmd);
    ta_register_command("nexttowardf",nexttowardf_cmd);
    ta_register_command("nexttowardl",nexttowardl_cmd);
    ta_register_command("scalb",scalb_cmd);
    ta_register_command("scalbf",scalbf_cmd);
    ta_register_command("scalbl",scalbl_cmd);
    ta_register_command("scalbln",scalbln_cmd);
    ta_register_command("scalblnf",scalblnf_cmd);
    ta_register_command("scalblnl",scalblnl_cmd);
    ta_register_command("scalbn",scalbn_cmd);
    ta_register_command("scalbnf",scalbnf_cmd);
    ta_register_command("scalbnl",scalbnl_cmd);
    ta_register_command("significand",significand_cmd);
    ta_register_command("significandf",significandf_cmd);
    ta_register_command("significandl",significandl_cmd);
}

