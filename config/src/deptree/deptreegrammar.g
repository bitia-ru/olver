// this will be included in all generated files 
#header <<

#include "deptreecommon.h"
#include "ATokPtr.h"
#include "DepTree.h"

#ifdef WIN32

#pragma warning ( disable : 4305 )
#pragma warning ( disable : 4309 )
#pragma warning ( disable : 4065 )
#pragma warning ( disable : 4700 )

#endif

extern int lineNumber;

>>

// parser includes
<<

typedef ANTLRCommonToken ANTLRToken;


#define CREATE_DEF(name, type)\
		depDefinition = new DepDefinition();\
		depDefinition->setType(type);\
		depDefinition->setName(mytoken(name)->getText());\
		depTree->getRoot().addDefinition(depDefinition);
>>

#token ROOT					"root"
#token CLUSTER				"cluster"
#token SUBSYSTEM			"subsystem"
#token GROUP				"group"
#token SCENARIO				"scenario"
#token TRANSITION			"transition"
#token SPECIFICATION		"specification"
#token REACTION				"reaction"
#token FUNCTION				"function"

#token SCOPE				"scope"
#token OPTION				"option"
#token TYPE					"type"
#token KIND					"kind"
#token DESTINATION			"destination"
#token DESCRIPTION			"description"
#token VALUES				"values"
#token DEFAULT				"default:"

#token IDENTIFIER			"[a-zA-Z_\.][a-zA-Z0-9_\.]*"
#token INTEGER				"{\+|\-}[0-9]+"

#token EQUAL        "="
#token COMMA        ","
#token LPAREN       "\("
#token RPAREN       "\)"
#token LCURLY       "\{"
#token RCURLY       "\}"
#token BR           "[\n]"

#token SPACE		"[\ \r\t]+"				<< skip (); >>
#token				"\/\/ ~[\n]*"           << skip (); >>
#token				"/\*"					<< mode (COMMENT); skip (); >>


#token QUOTE        "\""                    << replstr(""); mode (STRINGS); more (); >>
#token				"/\@"					<< replstr(""); mode (EXT_STRINGS); more (); >>

#token ALL "~[\n\r]"

#lexclass STRINGS
#token STRING "\""                              << replstr(""); mode (START); >>
#token "~[\"\n\r]+"                             << more (); >>
#token STRINGTRASH "[\n\r]"                     << replstr(""); mode (START); >>

#lexclass EXT_STRINGS
#token EXT_STRING "\@/"                          << replstr(""); mode (START); >>
#token "\@"										 << more (); >>
#token "[\ \n\r\t]+"								 << replstr(" "); more();>>
#token "~[\@\n\r\t]+"                            << more (); >>

#lexclass COMMENT
#token				"[\n\r]"      << lineNumber++; skip(); >>
#token				"\*/"         << mode (START); skip (); >>
#token				"\*"          << skip (); >>
#token				"~[\*\n\r]+"  << skip (); >>

#tokclass ID { IDENTIFIER ROOT CLUSTER SUBSYSTEM GROUP SCENARIO TRANSITION SPECIFICATION REACTION FUNCTION SCOPE OPTION TYPE KIND DESTINATION DESCRIPTION VALUES DEFAULT} 
#tokclass NODE { ROOT CLUSTER SUBSYSTEM GROUP SCENARIO TRANSITION SPECIFICATION REACTION FUNCTION }


class DepTreeParser {
<<
public:
	bool result;

protected:
	virtual bool isTokenBufferEmpty()=0;
	virtual void reportParseError() = 0;

protected:
	DepTree* depTree;
	string fileName;
>>

root  [string fileNameIn] > [DepTree *depTree]

:
	<<
		result = true;
		depTree = $depTree = new DepTree();
		fileName = fileNameIn;
	>>
	def_statements
;

def_statements
:
	(def_statement | config_statement | br)+
	<<
	if (!isTokenBufferEmpty())
	{
		reportParseError();
	}
    >>

;

def_statement
:
	(
		def_root
		|
		def_cluster
		|
		def_subsystem
		|
		def_group
		|
		def_scenario
		|
		def_transition
		|
		def_specification
		|
		def_reaction
		|
		def_function
	)
	exception default: <<reportParseError();>>
;

def_root
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	ROOT name:ID 
	<<
		CREATE_DEF(name, DepRoot);
	>>
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

def_cluster
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	CLUSTER name:ID 
	<<
		CREATE_DEF(name, DepCluster);
	>>
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

def_subsystem
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	SUBSYSTEM name:ID 
	<<
		CREATE_DEF(name, DepSubsystem);
	>>	
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

def_group
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	GROUP name:ID 
	<<
		CREATE_DEF(name, DepGroup);
	>>	
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

def_scenario
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	SCENARIO name:ID
	<<
		CREATE_DEF(name, DepScenario);
	>>
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

def_transition
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	TRANSITION name:ID 
	<<
		CREATE_DEF(name, DepTransition);
	>>
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

def_specification
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	SPECIFICATION name:ID
	<<
		CREATE_DEF(name, DepSpecification);
	>>	 
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

def_reaction
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	REACTION name:ID 
	<<
		CREATE_DEF(name, DepReaction);
	>>
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

def_function
:
	<<
		DepDefinition* depDefinition = 0;
	>>
	FUNCTION name:ID 
	<<
		CREATE_DEF(name, DepFunction);
	>>
	body < [depDefinition]
	exception default: <<reportParseError();>>
;

body < [DepDefinition* depDefinition]
:
	LCURLY { list < [depDefinition] }  RCURLY br
	exception default: <<reportParseError();>>
;

list < [DepDefinition* depDefinition]
:
	child < [depDefinition] (COMMA (br)* child < [depDefinition])*
	exception default: <<reportParseError();>>
;

child < [DepDefinition* depDefinition]
:
	<<
		string n;
		DepPredicate* predicate = 0;
	>>
	
	id:ID 
	<<
		depDefinition->addDefinitionName(mytoken(id)->getText());

		// each child name should have a predicate
		predicate = new DepPredicate();
		depDefinition->addPredicate(predicate);
	>>
	{
		LPAREN var:ID EQUAL number > [n] RPAREN
		<<
			predicate->setPredicate(mytoken(var)->getText(), atoi(n.c_str()));
		>>
	}
	exception default: <<reportParseError();>>
;

number > [string n]
:
	i:INTEGER
	<<
		$n = mytoken(i)->getText();
	>>
	exception default: <<reportParseError();>>
;

br
:
	<<
		lineNumber++;
	>>
	BR
	exception default: <<reportParseError();>>
;

config_statement
:
	(
		scope_statement
		|
		option_statement
	)
	exception default: <<reportParseError();>>	
;


scope_statement
:
	<<
		OptScope* scope = 0;
		DepDefinitionType scopeType = DepUnknown;
	>>
	SCOPE 
    {
	    node:NODE 
        <<
            scopeType = resolveDefType(mytoken(node)->getText());
        >>
    }
	name:IDENTIFIER
	<<
		scope = depTree->getScopeInstance(scopeType, mytoken(name)->getText());
	>>
	LCURLY id:ID 
	<<
		scope->addOptionName(mytoken(id)->getText());
	>>
	(
	    COMMA (br)* idc:ID
	    <<
	  	    scope->addOptionName(mytoken(idc)->getText());
		>>
	)* 
	RCURLY br
	exception default: <<reportParseError();>>	
;

option_statement
:
	<<
		OptDefinition* option = 0;
	>>
	OPTION name:ID 
	<<
		option = new OptDefinition();
		depTree->addOption(option);
		option->setName(mytoken(name)->getText());
	>>
	LCURLY br option_body < [option] RCURLY br
	exception default: <<reportParseError();>>	
;

option_body < [OptDefinition* option]
:
	TYPE ts:STRING (br)*
	KIND kd:STRING (br)*
	DESTINATION ds:STRING (br)*
	DESCRIPTION des:EXT_STRING (br)*
	<<
		option->setType(mytoken(ts)->getText());
		option->setKind(mytoken(kd)->getText());
		option->setDestinationFile(mytoken(ds)->getText());
		option->setDescription(mytoken(des)->getText());
	>>
	value_list_statement < [option] (br)*
	exception default: <<reportParseError();>>	
;

value_list_statement < [OptDefinition* option]
:
	VALUES LCURLY br value_list_body  < [option] RCURLY br
	exception default: <<reportParseError();>>	
;

value_list_body  < [OptDefinition* option]
:
	(value_record < [option])+
	exception default: <<reportParseError();>>	
;

value_record < [OptDefinition* option]
:
	<<
		string n;
		OptValue* value = new OptValue();	
		option->addValue(value);
	>>
	{
		DEFAULT
		<<
			value->isDefault = true;	
		>>
	} 
	number > [n] 
	{
	 id:ID
	 <<
	    value->enumeration = mytoken(id)->getText();
	 >>
	} 
	
	s:EXT_STRING br
	<<
		value->name = mytoken(s)->getText();
		value->value = atoi(n.c_str());

	>>
	exception default: <<reportParseError();>>	
;