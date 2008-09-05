/*
 * File: TraceXMLFormatter.c
 * Description:
 *       This file contains an implementation of TraceXMLFormatter.
 *
 * Copyright (c) 2002-2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <malloc.h>
#include "TracerStringBuffer.h"
#include "TraceXMLFormatter.h"
#include "TraceBool.h"
#include "TraceList.h"



/*
 * Encode attribute values
 */
static char * encodeAttValue(const char *value)
{
unsigned i, last, len;
char *ptr;
StringBuffer * buff;

  len = strlen(value);
  buff = StringBuffer_create(2 * len);

  if(buff == NULL) return NULL;

  last = 0;
  for(i=0;i<len;i++)
   {switch (value[i])
     {case '<':
        StringBuffer_append(buff, value+last, i-last);
        StringBuffer_append_s(buff, "&lt;");
        last = i+1;
        break;
      case '&':
        StringBuffer_append(buff, value+last, i-last );
        StringBuffer_append_s(buff, "&amp;" );
        last = i+1;
        break;
      case '"':
        StringBuffer_append(buff, value+last, i-last );
        StringBuffer_append_s(buff, "&quot;" );
        last = i+1;
        break;
     }
   }
  StringBuffer_append(buff, value+last, len-last );
  ptr = StringBuffer_toString(buff);
  StringBuffer_delete(buff);
  return ptr;
}

/*
 * Encode CDATA values
 */
static char * encodeCdataValue(const char *value)
{
unsigned i, last, len;
char *ptr;
StringBuffer * buff;
char buff2[8];

  len = strlen(value);
  buff = StringBuffer_create(2 * len);

  if(buff == NULL) return NULL;

  last = 0;
  for(i=0;i<len;i++) {
/*	if (value[i] == '>') {
      StringBuffer_append(buff, value+last, i-last);
      StringBuffer_append_s(buff, "&#x3E;");
      last = i+1;
	} else
*/
	if (value[i] == ']') {
      StringBuffer_append(buff, value+last, i-last);
      StringBuffer_append_s(buff, "&#x5D;");
      last = i+1;
	} else if (value[i] == '&') {
      StringBuffer_append(buff, value+last, i-last);
      StringBuffer_append_s(buff, "&#x26;");
      last = i+1;
	} else if (value[i] != '\n' && (signed char)value[i] < 32) {
      StringBuffer_append(buff, value+last, i-last);
	  sprintf(buff2, "&#x%02X;", value[i]);
      StringBuffer_append_s(buff, buff2);
      last = i+1;
	}
  }
  StringBuffer_append(buff, value+last, len-last );
  ptr = StringBuffer_toString(buff);
  StringBuffer_delete(buff);
  return ptr;
}

/*
 * Encode boolean value
 */
static char * encodeBoolValue(TraceBool value)
{
  return (value == tr_true) ? "true" : "false";
}

/*
 * Indent methods
 */

char * Indent_print(Indent ind) {
  char *buf = (char *)malloc(ind.cur_indent + 1);
  if(buf != NULL) {
    memset(buf,ind.indent_char,ind.cur_indent);
    buf[ind.cur_indent] = '\0';
  }
  return buf;
}


/*
 * TraceXMLFormatter methods definition
 */
TraceXMLFormatter_state * TraceXMLFormatter_state_create(int indent_size, char indent_char)
{
TraceXMLFormatter_state * tfs;

  tfs = (TraceXMLFormatter_state *)malloc(sizeof(*tfs));
  if(tfs != NULL) {
    tfs->indent_size = indent_size;
    tfs->indent_char = indent_char;
    tfs->cur_indent = 0;
    tfs->indent.indent_size = indent_size;
    tfs->indent.indent_char = indent_char;
    tfs->indent.cur_indent = 0;
  }
  return tfs;
}
///////////////////////////////////
void TraceXMLFormatter_state_delete(void * tfs) {
  if(tfs != NULL) free(tfs);
}
///////////////////////////////////
TraceFormatter * TraceXMLFormatter_default_create() {
    return TraceXMLFormatter_create(2, ' ');
}
///////////////////////////////////
TraceBool TraceXMLFormatter_valid(TraceFormatter *tf)
{
  if( (NULL == tf->state) ||
      (NULL == tf->delete_state) ||
      (NULL == tf->startTrace) ||
      (NULL == tf->endTrace) ||
      (NULL == tf->traceScenarioStart) ||
      (NULL == tf->traceEnvironmentProperties) ||
      (NULL == tf->traceScenarioParameters) ||
      (NULL == tf->traceTestEngineProperty) ||
      (NULL == tf->traceScenarioEnd) ||
      (NULL == tf->traceScenarioValue) ||
      (NULL == tf->traceState) ||
      (NULL == tf->traceTransitionStart) ||
      (NULL == tf->traceTransitionEnd) ||
      (NULL == tf->traceModelOperationStart) ||
      (NULL == tf->traceModelOperationArgument) ||
      (NULL == tf->traceModelOperationResult) ||
      (NULL == tf->traceModelOperationChannel) ||
      (NULL == tf->traceModelOperationTimestamp) ||
      (NULL == tf->traceOracleStart) ||
      (NULL == tf->tracePreconditionEnd) ||
      (NULL == tf->traceOracleEnd) ||
      (NULL == tf->traceModelOperationEnd) ||
      (NULL == tf->traceSeriesStart) ||
      (NULL == tf->traceSeriesEnd) ||
      (NULL == tf->tracePrimeFormula) ||
      (NULL == tf->traceCoverageElement) ||
      (NULL == tf->traceMark) ||
      (NULL == tf->traceCoverageStructureStart) ||
      (NULL == tf->traceFormulaeStart) ||
      (NULL == tf->traceFormula) ||
      (NULL == tf->traceFormulaeEnd) ||
      (NULL == tf->traceCoverageStart) ||
      (NULL == tf->traceElement) ||
      (NULL == tf->traceCoverageEnd) ||
      (NULL == tf->traceCoverageStructureEnd) ||
      (NULL == tf->traceException) ||
      (NULL == tf->traceInterimException) ||
      (NULL == tf->traceInternalError) ||
      (NULL == tf->traceSystemInfo) ||
      (NULL == tf->traceUserInfo) )
    return tr_false;
  return tr_true;
}



/*
 * Trace level methods
 */

const char * TraceXMLFormatter_startTrace(void *state, const char *encoding) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

  // Reinitialize indent
  st->indent.indent_size = st->indent_size;
  st->indent.indent_char = st->indent_char;
  st->indent.cur_indent = st->cur_indent;

  if (strcmp(encoding,""))
   {
    StringBuffer_append_s(ss,"<?xml version=\"1.0\" encoding=\"");
    StringBuffer_append_s(ss,encoding);
    StringBuffer_append_s(ss,"\"?>\n");
   }

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<trace ");
  StringBuffer_append_s(ss, "version=\"");
  StringBuffer_append_s(ss, TRACE_VERSION);
  StringBuffer_append_s(ss, "\"");
  StringBuffer_append_s(ss, ">\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_endTrace(void *state, TraceBool original) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "</trace>\n");
  if (!original) st->indent.cur_indent += st->indent.indent_size;

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}


/*
 * Scenario level methods
 */
char * TraceXMLFormatter_traceScenarioValue(void *state, int traceId, const char *kind, const char *type, const char *name, const char *value);

const char * TraceXMLFormatter_traceScenarioStart(void *state, int traceId, const char *name, time_t now, const char *host, const char *os)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;


//  ss << indent++ << "<scenario_start" << " trace=\"" << traceId << "\""
//     << " name=\"" << encodeAttValue(name) << "\"" << " time=\"" << now << "000\""
//     << " host=\"" << encodeAttValue(host) << "\"" << " os=\"" << encodeAttValue(os)
//     << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<scenario_start trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" name=\"");
  ptr = encodeAttValue(name);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\" time=\"");
  StringBuffer_append_l(ss, now);
  StringBuffer_append_s(ss, "000\" host=\"");
  ptr = encodeAttValue(host);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\" os=\"");
  ptr = encodeAttValue(os);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceEnvironmentProperties(void *state, int traceId, TraceList *properties) //  map<char *,char *>
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer *ss;
  TracePair *prop;
  TraceListitem *item;

  if(properties == NULL) return NULL;
  ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;


  for(item = properties->head;(item != NULL); item = item->next)
  {
//    ss << indent << "<environment" << " trace=\"" << traceId << "\""
//       << " name=\"" << encodeAttValue(it->first) << "\"" << " value=\""
//       << encodeAttValue(it->second) << "\"" << "/>" << endl;
    prop = (TracePair *)item->data;
    if(!prop) continue;
    ptr = Indent_print(st->indent);
    StringBuffer_append_s(ss, ptr);
    if(ptr) free(ptr);
    StringBuffer_append_s(ss, "<environment trace=\"");
    StringBuffer_append_l(ss, traceId);
    StringBuffer_append_s(ss, "\" name=\"");
    ptr = encodeAttValue(prop->first);
    StringBuffer_append_s(ss, ptr);
    if(ptr) free(ptr);
    StringBuffer_append_s(ss, "\" value=\"");
    ptr = encodeAttValue(prop->second);
    StringBuffer_append_s(ss, ptr);
    if(ptr) free(ptr);
    StringBuffer_append_s(ss, "\"/>\n");
  }

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceScenarioParameters(void *state, int traceId, int argc, const char** argv)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  int i;
  char name[10];
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

  for(i = 0; i<argc; i++)
   {
    sprintf(name,"arg%d\0",i);
    ptr = TraceXMLFormatter_traceScenarioValue(state, traceId, "parameter", "String", name, argv[i]);
    StringBuffer_append_s(ss, ptr);
    if(ptr) free(ptr);
   }

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceTestEngineProperty(void *state, int traceId, const char *name, const char *value)
{
  return TraceXMLFormatter_traceScenarioValue(state, traceId, "test engine property", "String", name, value );
}
///////////////////////////////////
const char * TraceXMLFormatter_traceScenarioEnd(void *state, int traceId, time_t now)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;


//  ss << --indent << "<scenario_end" << " trace=\"" << traceId << "\"" << " time=\"" << now << "000\"" << "/>" << endl;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<scenario_end trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" time=\"");
  StringBuffer_append_l(ss, now);
  StringBuffer_append_s(ss, "000\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}


/*
 * Transition level methods
 */

// TODO: encode 'value'
char * TraceXMLFormatter_traceScenarioValue(void *state, int traceId, const char *kind, const char *type, const char *name, const char *value)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;


//  ss << indent << "<scenario_value" << " trace=\"" << traceId << "\"" << " kind=\"" << encodeAttValue(kind)
//     << "\"" << " type=\"" << encodeAttValue(type) << "\"" << " name=\"" << encodeAttValue(name) << "\""
//     << ">" << "<![CDATA[" << value << "]]>" << "</scenario_value>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<scenario_value trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" kind=\"");
  ptr = encodeAttValue(kind);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\" type=\"");
  ptr = encodeAttValue(type);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\" name=\"");
  ptr = encodeAttValue(name);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"><![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(value));
  StringBuffer_append_s(ss, "]]></scenario_value>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}

///////////////////////////////////
// TODO: type = ?
const char * TraceXMLFormatter_traceState(void *state, int traceId, const char *id) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<state" << " trace=\"" << traceId << "\""
//     << " id=\"" << encodeAttValue(id) << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<state trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" id=\"");
  ptr = encodeAttValue(id);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
// TODO: type = ?
// TODO: "scenario method" or "scenario function"?
// TODO: "iteration variable" or something else?
// TODO: name and type of "iteration variable" are unknown
const char * TraceXMLFormatter_traceTransitionStart (void *state, int traceId, const char *id) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<transition_start" << " trace=\"" << traceId << "\""
//     << " id=\"" << encodeAttValue(id) << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<transition_start trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" id=\"");
  ptr = encodeAttValue(id);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceTransitionEnd (void *state, int traceId) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << --indent << "<transition_end" << " trace=\"" << traceId << "\"" << "/>" << endl;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<transition_end trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}



/*
 * Oracle level methods
 */
const char * TraceXMLFormatter_traceModelOperationStart(void *state, int traceId, const char *kind, const char *subsystem, const char *signature, unsigned refid)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<model_operation_start" << " trace=\"" << traceId << "\"" << " kind=\"" << encodeAttValue(kind) << "\"";
//  ss << " package=\"" << encodeAttValue(subsystem) << "\"";
//  ss << " signature=\"" << encodeAttValue(signature) << "\"" << " refid=\"" << refid << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<model_operation_start trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" kind=\"");
  ptr = encodeAttValue(kind);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"");

  if (strlen(subsystem) > 0) {
    StringBuffer_append_s(ss, " package=\"");
    ptr = encodeAttValue(subsystem);
    StringBuffer_append_s(ss, ptr);
    if(ptr) free(ptr);
    StringBuffer_append_s(ss, "\"");
  }

  StringBuffer_append_s(ss, " signature=\"");
  ptr = encodeAttValue(signature);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\" refid=\"");
  StringBuffer_append_l(ss, refid);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
// TODO: encode 'value'
const char * TraceXMLFormatter_traceModelOperationArgument(void *state, int traceId, const char *type, const char *name, const char *value)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<model_value" << " trace=\"" << traceId << "\"" << " kind=\"argument\""
//     << " type=\"" << encodeAttValue(type) << "\"" << " name=\"" << encodeAttValue(name) << "\""
//     << ">" << "<![CDATA[" << value << "]]>" << "</model_value>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<model_value trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" kind=\"argument\" type=\"");
  ptr = encodeAttValue(type);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\" name=\"");
  ptr = encodeAttValue(name);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"><![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(value));
  StringBuffer_append_s(ss, "]]></model_value>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
// TODO: encode 'value'
const char * TraceXMLFormatter_traceModelOperationResult(void *state, int traceId, const char *type, const char *value)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<model_value" << " trace=\"" << traceId << "\"" << " kind=\"result\""
//     << " type=\"" << encodeAttValue(type) << "\"" << "><![CDATA[" << value << "]]>" << "</model_value>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<model_value trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" kind=\"result\" type=\"");
  ptr = encodeAttValue(type);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"><![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(value));
  StringBuffer_append_s(ss, "]]></model_value>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceModelOperationChannel(void *state, int traceId, const char *channel)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<model_value" << " trace=\"" << traceId << "\"" << " kind=\"channel\""
//     << " type=\"ChannelID\"" << "><![CDATA[" << channel << "]]>" << "</model_value>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<model_value trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" kind=\"channel\" type=\"ChannelID\"><![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(channel));
  StringBuffer_append_s(ss, "]]></model_value>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceModelOperationTimestamp(void *state, int traceId, const char *timestamp)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<model_value" << " trace=\"" << traceId << "\"" << " kind=\"timestamp\""
//     << " type=\"TimeInterval\"" << "><![CDATA[" << timestamp << "]]>" << "</model_value>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<model_value trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" kind=\"timestamp\" type=\"TimeInterval\"><![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(timestamp));
  StringBuffer_append_s(ss, "]]></model_value>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceOracleStart(void *state, int traceId, const char *subsystem, const char *signature, unsigned ref)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<oracle_start" << " trace=\"" << traceId << "\""
//     << " package=\"" << encodeAttValue(subsystem) << "\"";
//     << " signature=\"" << encodeAttValue(signature) << "\"";
//     << " ref=\"" << ref << "\"" << "/>"<< endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<oracle_start trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"");

  if (strlen(subsystem) > 0) {
    StringBuffer_append_s(ss, " package=\"");
    ptr = encodeAttValue(subsystem);
    StringBuffer_append_s(ss, ptr);
    if(ptr) free(ptr);
    StringBuffer_append_s(ss, "\"");
  }
  StringBuffer_append_s(ss, " signature=\"");
  ptr = encodeAttValue(signature);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"");

  if (ref > 0) {
    StringBuffer_append_s(ss, " ref=\"");
    StringBuffer_append_l(ss, ref);
    StringBuffer_append_s(ss, "\"");
  }
  StringBuffer_append_s(ss, "/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_tracePreconditionEnd(void *state, int traceId)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<precondition_end" << " trace=\"" << traceId << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<precondition_end trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceOracleEnd(void *state, int traceId)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << --indent << "<oracle_end" << " trace=\"" << traceId << "\"" << "/>" << endl;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<oracle_end trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceModelOperationEnd(void *state, int traceId)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << --indent << "<model_operation_end" << " trace=\"" << traceId << "\"" << "/>" << endl;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<model_operation_end trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceSeriesStart(void *state, int traceId)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<serialization_start" << " trace=\"" << traceId << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<serialization_start trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceSeriesEnd(void *state, int traceId)
{
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << --indent << "<serialization_end" << " trace=\"" << traceId << "\"" << "/>" << endl;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<serialization_end trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}



/*
 * Coverage level methods
 */

const char * TraceXMLFormatter_tracePrimeFormula(void *state, int traceId, int id, TraceBool value) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<prime_formula" << " trace=\"" << traceId << "\""
//  << " id=\"" << id << "\"" << " value=\"" << encodeBoolValue(value) << "\""<< "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<prime_formula trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" id=\"");
  StringBuffer_append_l(ss, id);
  StringBuffer_append_s(ss, "\" value=\"");
  ptr = encodeBoolValue(value);
  StringBuffer_append_s(ss, ptr);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceCoverageElement(void *state, int traceId, const char *structureId, const char *coverageId, int branchId) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<coverage_element" << " trace=\"" << traceId << "\""
//     << " coverage=\"" << encodeAttValue(coverageId) << "\"" << " id=\"" << branchId << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<coverage_element trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"");
  if( strlen( structureId ) != 0 )
  {
    StringBuffer_append_s(ss, " structure=\"");
    ptr = encodeAttValue(structureId);
    StringBuffer_append_s(ss, ptr);
    if(ptr) free(ptr);
    StringBuffer_append_s(ss, "\"");
  }
  StringBuffer_append_s(ss, " coverage=\"");
  ptr = encodeAttValue(coverageId);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\" id=\"");
  StringBuffer_append_l(ss, branchId);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceMark(void *state, int traceId, const char *mark) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<mark" << " trace=\"" << traceId << "\""
//     << " name=\"" << encodeAttValue(mark) << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<mark trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" name=\"");
  ptr = encodeAttValue(mark);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceCoverageStructureStart(void *state, int traceId, const char* name) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<coverage_structure" << " trace=\"" << traceId << "\"" << ">" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<coverage_structure trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"" );

  if( strlen( name ) != 0 )
  {
    StringBuffer_append_s(ss, " name=\"" );
    StringBuffer_append_s(ss, name );
    StringBuffer_append_s(ss, "\"" );
  }
  StringBuffer_append_s(ss, ">\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceFormulaeStart(void *state) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<formulae>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<formulae>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceFormula(void *state, int id, const char *text) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<formula" << " id=\"" << id << "\"" << ">" << "<![CDATA[" << text << "]]>" << "</formula>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<formula id=\"");
  StringBuffer_append_l(ss, id);
  StringBuffer_append_s(ss, "\"><![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(text));
  StringBuffer_append_s(ss, "]]></formula>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceFormulaeEnd(void *state) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << --indent << "</formulae>" << endl;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "</formulae>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceCoverageStart(void *state, const char *id) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<coverage" << " id=\"" << encodeAttValue(id) << "\"" << ">" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<coverage id=\"");
  ptr = encodeAttValue(id);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\">\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceElement(void *state, int id, const char *name) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<element" << " id=\"" << id << "\"" << " name=\"" << encodeAttValue(name) << "\"" << "/>" << endl;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<element id=\"");
  StringBuffer_append_l(ss, id);
  StringBuffer_append_s(ss, "\" name=\"");
  ptr = encodeAttValue(name);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "\"/>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceCoverageEnd(void *state) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << --indent << "</coverage>" << endl;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "</coverage>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceCoverageStructureEnd(void *state) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << --indent << "</coverage_structure>" << endl;

  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "</coverage_structure>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}



/*
 * Other messages
 */
char * TraceXMLFormatter_traceSystemInfo(void *state, int traceId, const char *info);

// TODO: <where> ?
// const list< pair<char *,char *> > &values, const list< char * > &infos

const char * TraceXMLFormatter_traceException(void *state, int traceId, const char *kind, const TraceList *values, const TraceList *infos) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  TracePair *vl;
  TraceListitem *item;

  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<exception trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" kind=\"");
  StringBuffer_append_s(ss, kind);
  StringBuffer_append_s(ss, "\" internal=\"false\">\n");

  // Trace exception values
  if(NULL != values) {
    for(item = values->head;(item != NULL); item = item->next)
    {
      vl = (TracePair *)item->data;
      if(!vl) continue;
// ss << indent << "<property name='"<< cur.first <<"' value='"<< cur.second <<"' />" << endl;
      ptr = Indent_print(st->indent);
      StringBuffer_append_s(ss, ptr);
      if(ptr) free(ptr);
      StringBuffer_append_s(ss, "<property name='");
      StringBuffer_append_s(ss, vl->first);
      StringBuffer_append_s(ss, "' value='");
      StringBuffer_append_s(ss, vl->second);
      StringBuffer_append_s(ss, "' />\n");
    }
  }

  // Trace exception infos
  if(NULL != infos) {
    for(item = infos->head;(item != NULL); item = item->next) {
      ptr = TraceXMLFormatter_traceSystemInfo(state,traceId,(char *)item->data);
      StringBuffer_append_s(ss, ptr);
      if(ptr) free(ptr);
    }
  }

  //  ss << --indent << "</exception>" << endl;
  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "</exception>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
// TODO: <where> ?
// const list< pair<char *,char *> > &values, const list< char * > &infos
const char * TraceXMLFormatter_traceInterimException(void *state, int traceId, const char *kind, const TraceList *values, const TraceList *infos) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  TracePair *vl;
  TraceListitem *item;

  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<exception" << " trace=\"" << traceId << "\"" << " internal=\"false\"" << " interim=\"true\"" << ">" << endl;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<exception trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" kind=\"");
  StringBuffer_append_s(ss, kind);
  StringBuffer_append_s(ss, "\" internal=\"false\" interim=\"true\">\n");

  // Trace exception values
  if(NULL != values) {
    for(item = values->head;(item != NULL); item = item->next)
    {
      vl = (TracePair *)item->data;
      if(!vl) continue;
//  ss << indent << "<property name='"<< cur.first <<"' value='"<< cur.second <<"' />" << endl;
      ptr = Indent_print(st->indent);
      StringBuffer_append_s(ss, ptr);
      if(ptr) free(ptr);
      StringBuffer_append_s(ss, "<property name='");
      StringBuffer_append_s(ss, vl->first);
      StringBuffer_append_s(ss, "' value='");
      StringBuffer_append_s(ss, vl->second);
      StringBuffer_append_s(ss, "' />\n");
    }
  }

//  ss << --indent << "</exception>" << endl;
  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "</exception>\n");

  // Trace exception infos
  if(NULL != infos) {
    for(item = infos->head;(item != NULL); item = item->next) {
      ptr = TraceXMLFormatter_traceSystemInfo(state,traceId,(char *)item->data);
      StringBuffer_append_s(ss, ptr);
      if(ptr) free(ptr);
    }
  }

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
// TODO: <where> ?
const char * TraceXMLFormatter_traceInternalError(void *state, int traceId, const char *info) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<exception" << " trace=\"" << traceId << "\"" << " internal=\"true\"" << ">" << endl;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<exception trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\" internal=\"true\">\n");

//  ss << indent   << "<info><![CDATA[" << info << "]]></info>" << endl;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<info><![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(info));
  StringBuffer_append_s(ss, "]]></info>\n");

//  ss << --indent << "</exception>" << endl;
  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "</exception>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
char * TraceXMLFormatter_traceSystemInfo(void *state, int traceId, const char *info) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent << "<info trace=\"" << traceId << "\">" << " <![CDATA[" << info << "]]>" << "</info>" << endl;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<info trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\"> <![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(info));
  StringBuffer_append_s(ss, "]]></info>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
const char * TraceXMLFormatter_traceUserInfo(void *state, int traceId, const char *info) {
  TraceXMLFormatter_state * st = (TraceXMLFormatter_state *)state;
  char *ptr;
  StringBuffer * ss = StringBuffer_create(-1);
  if((st == NULL) || (ss == NULL)) return NULL;

//  ss << indent++ << "<user_info" << " trace=\"" << traceId << "\"" << ">" << endl;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  st->indent.cur_indent += st->indent.indent_size;
  StringBuffer_append_s(ss, "<user_info trace=\"");
  StringBuffer_append_l(ss, traceId);
  StringBuffer_append_s(ss, "\">\n");

// ss << indent   << "<![CDATA[" << info << "]]>" << endl;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "<![CDATA[");
  StringBuffer_append_s(ss, encodeCdataValue(info));
  StringBuffer_append_s(ss, "]]>\n");

// ss << --indent << "</user_info>" << endl;
  st->indent.cur_indent -= st->indent.indent_size;
  ptr = Indent_print(st->indent);
  StringBuffer_append_s(ss, ptr);
  if(ptr) free(ptr);
  StringBuffer_append_s(ss, "</user_info>\n");

  ptr = StringBuffer_toString(ss);
  StringBuffer_delete(ss);

  return ptr;
}
///////////////////////////////////
TraceFormatter * TraceXMLFormatter_create(int indent_size, char indent_char)
{
TraceFormatter * tf;
TraceXMLFormatter_state * st;

  tf = (TraceFormatter *)malloc(sizeof(*tf));
  if(tf != NULL) {
    st = TraceXMLFormatter_state_create(indent_size, indent_char);
    if(st != NULL) {
      tf->state = st;
      tf->delete_state = TraceXMLFormatter_state_delete;

      tf->startTrace = TraceXMLFormatter_startTrace;
      tf->endTrace = TraceXMLFormatter_endTrace;

      tf->traceScenarioStart = TraceXMLFormatter_traceScenarioStart;
      tf->traceEnvironmentProperties = TraceXMLFormatter_traceEnvironmentProperties;
      tf->traceScenarioParameters = TraceXMLFormatter_traceScenarioParameters;
      tf->traceTestEngineProperty = TraceXMLFormatter_traceTestEngineProperty;
      tf->traceScenarioEnd = TraceXMLFormatter_traceScenarioEnd;

      tf->traceScenarioValue = TraceXMLFormatter_traceScenarioValue;
      tf->traceState = TraceXMLFormatter_traceState;
      tf->traceTransitionStart = TraceXMLFormatter_traceTransitionStart;
      tf->traceTransitionEnd = TraceXMLFormatter_traceTransitionEnd;

      tf->traceModelOperationStart = TraceXMLFormatter_traceModelOperationStart;
      tf->traceModelOperationArgument = TraceXMLFormatter_traceModelOperationArgument;
      tf->traceModelOperationResult = TraceXMLFormatter_traceModelOperationResult;
      tf->traceModelOperationChannel = TraceXMLFormatter_traceModelOperationChannel;
      tf->traceModelOperationTimestamp = TraceXMLFormatter_traceModelOperationTimestamp;
      tf->traceOracleStart = TraceXMLFormatter_traceOracleStart;
      tf->tracePreconditionEnd = TraceXMLFormatter_tracePreconditionEnd;
      tf->traceOracleEnd = TraceXMLFormatter_traceOracleEnd;
      tf->traceModelOperationEnd = TraceXMLFormatter_traceModelOperationEnd;
      tf->traceSeriesStart = TraceXMLFormatter_traceSeriesStart;
      tf->traceSeriesEnd = TraceXMLFormatter_traceSeriesEnd;

      tf->tracePrimeFormula = TraceXMLFormatter_tracePrimeFormula;
      tf->traceCoverageElement = TraceXMLFormatter_traceCoverageElement;
      tf->traceMark = TraceXMLFormatter_traceMark;
      tf->traceCoverageStructureStart = TraceXMLFormatter_traceCoverageStructureStart;
      tf->traceFormulaeStart = TraceXMLFormatter_traceFormulaeStart;
      tf->traceFormula = TraceXMLFormatter_traceFormula;
      tf->traceFormulaeEnd = TraceXMLFormatter_traceFormulaeEnd;
      tf->traceCoverageStart = TraceXMLFormatter_traceCoverageStart;
      tf->traceElement = TraceXMLFormatter_traceElement;
      tf->traceCoverageEnd = TraceXMLFormatter_traceCoverageEnd;
      tf->traceCoverageStructureEnd = TraceXMLFormatter_traceCoverageStructureEnd;

      tf->traceException = TraceXMLFormatter_traceException;
      tf->traceInterimException = TraceXMLFormatter_traceInterimException;
      tf->traceInternalError = TraceXMLFormatter_traceInternalError;
      tf->traceSystemInfo = TraceXMLFormatter_traceSystemInfo;
      tf->traceUserInfo = TraceXMLFormatter_traceUserInfo;
      tf->valid = TraceXMLFormatter_valid;
    }
    else { free(tf); tf = NULL; }
  }
  return tf;
}

