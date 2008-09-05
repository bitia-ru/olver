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


#include "locale/locale/locale_agent.h"
#include <langinfo.h>
#include <locale.h>

void writeLConv(TAThread thread, const struct lconv* plc)
{
    writeString(thread, plc->decimal_point);
    writeString(thread, plc->thousands_sep);
    writeString(thread, plc->grouping);
    writeString(thread, plc->int_curr_symbol);
    writeString(thread, plc->currency_symbol);
    writeString(thread, plc->mon_decimal_point);
    writeString(thread, plc->mon_thousands_sep);
    writeString(thread, plc->mon_grouping);
    writeString(thread, plc->positive_sign);
    writeString(thread, plc->negative_sign);

    writeChar(thread, plc->int_frac_digits);
    writeChar(thread, plc->frac_digits);
    writeChar(thread, plc->p_cs_precedes);
    writeChar(thread, plc->p_sep_by_space);
    writeChar(thread, plc->n_cs_precedes);
    writeChar(thread, plc->n_sep_by_space);
    writeChar(thread, plc->p_sign_posn);
    writeChar(thread, plc->n_sign_posn);
    writeChar(thread, plc->int_p_cs_precedes);
    writeChar(thread, plc->int_n_cs_precedes);
    writeChar(thread, plc->int_p_sep_by_space);
    writeChar(thread, plc->int_n_sep_by_space);
    writeChar(thread, plc->int_p_sign_posn);
    writeChar(thread, plc->int_n_sign_posn);
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict setlocale_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    char* res;
    int category = readInt(&stream);
    char* locale = readString(&stream);
    
    START_TARGET_OPERATION(thread);

    // Execute
    res = setlocale(category, locale);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict nl_langinfo_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    char* res;
    nl_item item = readInt(&stream);
    
    START_TARGET_OPERATION(thread);

    // Execute
    res = nl_langinfo(item);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict localeconv_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    struct lconv* res;
    
    START_TARGET_OPERATION(thread);

    // Execute
    res = localeconv();

    END_TARGET_OPERATION(thread);

    // Response
    writeLConv(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict newlocale_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    locale_t res;
    int category_mask = readInt(&stream);
    char* locale = readString(&stream);
    locale_t base = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);

    // Execute
    res = newlocale(category_mask, locale, base);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict freelocale_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare    
    locale_t locale;
    
    locale = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);

    // Execute
    freelocale(locale);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict duplocale_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare    
    locale_t locale, res;
    
    locale = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);

    // Execute
    res = duplocale(locale);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict uselocale_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    locale_t res;
    locale_t newloc = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);

    // Execute
    res = uselocale(newloc);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_locale_commands(void)
{
    ta_register_command("setlocale",   setlocale_cmd);
    ta_register_command("nl_langinfo", nl_langinfo_cmd);
    ta_register_command("localeconv",  localeconv_cmd);
    ta_register_command("newlocale",   newlocale_cmd);
    ta_register_command("freelocale",  freelocale_cmd);
    ta_register_command("duplocale",   duplocale_cmd);
    ta_register_command("uselocale",   uselocale_cmd);
}
