#include "deptree/deptreecommon.h"
#include "deptree/DepTree.h"


DepDefinitionType DepChildType[] = 
    {
        DepUnknown,
        DepUnknown,
        DepRoot,
        DepCluster,
        DepSubsystem,
        DepGroup,
        DepScenario,
        DepTransition,
        DepTransition,
        DepTransition,
    };

string DepDefinitionTypeString[] = 
    {
        "Unknown",
        "Root",
        "Cluster",
        "Subsystem",
        "Group",
        "Scenario",
        "Transition",
        "Specification",
        "Reaction",
        "Function"
    };

string toString_DepDefinitionType(DepDefinitionType type)
{
    if(type<0 || type>9)
        type = DepUnknown;

    return DepDefinitionTypeString[type];
}

/**/

string OptTypeString[] = {
        "unknown",
        "bool",
        "int",
        "set",
        "string"
};

string toString_OptType(OptType type)
{
    if(type<0 || type>4)
        type = OptUnknown;

    return OptTypeString[type];
}

/**/

string OptKindString[] = {
        "unknown",
        "var",
        "def"
};

string toString_OptKind(OptKind kind)
{
    if(kind<0 || kind>2)
        kind = KindUnknown;

    return OptKindString[kind];
}

DepDefinitionType resolveDefType(string defTypeString)
{
    for (int i = 0; i < 10; i++)
	{
		if (defTypeString == DepDefinitionTypeString[i])
		{
			return (DepDefinitionType)i;
		}
	}
    return DepUnknown;
}

/************************************************************************/
/* DepTree                                                              */
/************************************************************************/

DepTree::DepTree()
{
    root.setType(DepRoot);
    root.setName("global"); // Root
    referencesResolved = false;
}


DepTree::~DepTree()
{
    {
        for(int i = 0; i < scopes.size(); i++)
        {
            delete(scopes[i]);
        }
    }
    {
        for(int i = 0; i < options.size(); i++)
        {
            delete(options[i]);
        }
    }
}

DepDefinition& DepTree::getRoot()
{
    return root;
}

void DepTree::resolveReferences()
{
    referencesResolved = true;

    // resolve structure
    {    
        int definitionCount = root.getDefinitionCount();
        for (int i = 0; i < definitionCount; i++)
        {
            DepDefinition* depDefinition = root.getDefinitionAt(i);
            resolveReferences(depDefinition);
        }   
    }
    // resolve options
    {
        int optionCount = options.size();
        int i;
        for (i = 0; i < optionCount; i++)
        {
            OptDefinition* option = options[i];
            option->setAlreadyGenerated(false);
        }

        int scopeCount = scopes.size();
        for (i = 0; i < scopeCount; i++)
        {
            OptScope* scope = scopes[i];
            resolveReferences(scope);
        }

        optionCount = options.size();
        for (i = 0; i < optionCount; i++)
        {
            OptDefinition* option = options[i];
            if ( !option->isAlreadyGenerated() )
            {
                printf("Option %s is beyound the scope\n", option->getName().c_str() );
                referencesResolved = false;
            }
        }

    }
    // resolve scope binding
    {    
        int definitionCount = root.getDefinitionCount();
        int scopeCount = scopes.size();
        
        for (int j = 0; j < scopeCount; j++)
        {
            OptScope* scope = scopes[j];
            string scopeName = scope->getName();
            DepDefinitionType scopeDefType = scope->getDefType();
            bool scopeFound = false;

            if( (scopeDefType == DepUnknown || scopeDefType == DepRoot) && scopeName == root.getFullName() )
            {
                root.setScope(scope);
                scopeFound = true;
            }

            for (int i = 0; i < definitionCount; i++)
            {
                DepDefinition* depDefinition = root.getDefinitionAt(i);

                if (  ( (scopeDefType == DepUnknown) || (scopeDefType == depDefinition->getType()) )
                    &&( scopeName == depDefinition->getFullName() )
                    )
                {
                    if(scopeFound)
                    {
                        printf("Ambigous scope definition: %s %s\n", 
                                    toString_DepDefinitionType(scopeDefType).c_str(),
                                    scopeName.c_str()
                               );
                    }
                    depDefinition->setScope(scope);
                    scopeFound = true;
                }
            }
            
            if(!scopeFound)
            {
                printf("Wrong scope definition: %s %s\n", 
                            toString_DepDefinitionType(scopeDefType).c_str(),
                            scopeName.c_str()
                       );
                referencesResolved = false;
            }
        }   
    }
}

void DepTree::resolveReferences(DepDefinition* depDefinition)
{
    int childCount = depDefinition->getDefinitionNameCount();

    for (int i = 0; i < childCount; i++)
    {
        string definitionName = depDefinition->getDefinitionNameAt(i);
        resolveReference(depDefinition, definitionName);
    }
}

void DepTree::resolveReference(DepDefinition* depDefinition, string name)
{
    bool referenceFound = false;
  
    int definitionCount = root.getDefinitionCount();
	for(int trace=0;trace<=1;trace++){
		for (int i = 0; i < definitionCount; i++)
		{
			DepDefinition* definition = root.getDefinitionAt(i);
			
			// type check
			if (DepChildType[definition->getType()] == depDefinition->getType())
			{
				// name check
				if (
					definition->getFullName() == name 
					|| 
					definition->getFullName() == (depDefinition->getName() + "." + name)
					|| 
					definition->getFullName() == (depDefinition->getFullName() + "." + name)
					)
				{
					depDefinition->addDefinition(definition);
					referenceFound = true;
					break;
				}
			}
			if(trace){
				printf("trace: search in: %s %s %s\n", 
					toString_DepDefinitionType(definition->getType()).c_str(), definition->getFullName().c_str(), definition->getName().c_str());
			}
		}
		
		if (!referenceFound && !depDefinition->isAction())
		{
			printf("error : unresolved reference : (%s) %s -> %s\n", toString_DepDefinitionType(depDefinition->getType()).c_str(), depDefinition->getFullName().c_str(), name.c_str());
			referencesResolved = false;
		}else
			break;	// for (trace...)
	}
}

void DepTree::resolveReferences(OptScope* scope)
{
    int optionNamesCount = scope->getOptionNameCount();
    for (int i = 0; i < optionNamesCount; i++)
    {
        string optionName = scope->getOptionNameAt(i);
        resolveReferences(scope, optionName);
    }
}

void DepTree::resolveReferences(OptScope* scope, string name)
{
    bool referenceFound = false;

    int optionCount = options.size();
    for (int i = 0; i < optionCount; i++)
    {
        OptDefinition* option = options[i];
        if (option->getName() == name)
        {
            option->setAlreadyGenerated(true);
            scope->addOption(option);
            referenceFound = true;
            break;
        }
    }

    if (!referenceFound)
    {
        printf("error : unresolved option : %s -> %s\n", scope->getName().c_str(), name.c_str());
        referencesResolved = false;
    }
}

bool DepTree::isReferencesResolved()
{
    return referencesResolved;
}


void DepTree::addScope(OptScope* scope)
{
    scopes.push_back(scope);
}

OptScope* DepTree::getScopeInstance(DepDefinitionType scopeType, string name)
{
    int scopeCount = scopes.size();  
    for (int i = 0; i < scopeCount; i++)
    {
        OptScope* scope = scopes[i];
        if (  (scope->getName() == name)
            &&(scope->getDefType() == scopeType)
            )
        {
            return scope;
        }
    }
    
    OptScope* scope = new OptScope();
    scope->setName(name);
    scope->setDefType(scopeType);
    addScope(scope);
   
    return scope;
}

void DepTree::addOption(OptDefinition* option)
{
    options.push_back(option);
}

int DepTree::getScopeCount()
{
	return scopes.size();
}

OptScope* DepTree::getScopeAt(int index)
{
	return scopes[index];
}

bool DepTree::hasOption(string scopeName, string optionName)
{
	int scopeCount = scopes.size();
    for(int i = 0; i < scopeCount; i++)
    {
		OptScope *os = scopes[i];
		
		if (os->getName() == scopeName)
		{
			int optionCount = os->getOptionCount();
			for (int j = 0; j < optionCount; j++)
			{
				OptDefinition* od = os->getOptionAt(j);
				if (od->getName() == optionName)
				{
					return true;
				}
			}		
		}
    }	
	return false;
}

int DepTree::getOptionCount()
{
	return options.size();
}

OptDefinition* DepTree::getOptionAt(int index)
{
	return options[index];
}

OptDefinition* DepTree::findOption(string scopeName, string optionName)
{
    OptDefinition* result = 0;
	int scopeCount = scopes.size();
    for(int i = 0; i < scopeCount; i++)
    {
		OptScope *os = scopes[i];
		
		if (os->getName() == scopeName)
		{
			int optionCount = os->getOptionCount();
			for (int j = 0; j < optionCount; j++)
			{
				OptDefinition* od = os->getOptionAt(j);
				if (od->getName() == optionName)
				{
                    if(result)
                    {
                        printf("Option redifinition: %s\n\n", od->getName().c_str() );
                        return 0;
                    }
					result = od;
				}
			}		
		}
    }	
	return result;
}

void DepTree::printDefinitions()
{
    int childCount = root.getDefinitionCount();
    
    for (int i = 0; i < childCount; i++)
    {
        DepDefinition* child = root.getDefinitionAt(i);
        child->printNames();
    }
}

void DepTree::printClusters()
{
    printf("\n\nPrinting Clusters...\n");   

    int childCount = root.getDefinitionCount();
    
    for (int i = 0; i < childCount; i++)
    {
        DepDefinition* child = root.getDefinitionAt(i);

        if (child->getType() == DepCluster)
        {
            child->printDefinitions();
        }
    }
}

void DepTree::printOptions()
{
    printf("\n\nPrinting Options...\n");
    for(int i = 0; i < options.size(); i++)
    {
        printf("\nOPTION    %s\n", options[i]->getName().c_str());
        options[i]->printContents();
    }
}

void DepTree::printScopes()
{
    printf("\n\nPrinting Scopes...\n");
    for(int i = 0; i < scopes.size(); i++)
    {
        printf("\nSCOPE    %s\n", scopes[i]->getName().c_str());
        scopes[i]->printOptions();
    }
}



/************************************************************************/
/* DepDefinition                                                        */
/************************************************************************/

DepDefinition::DepDefinition()
{
    name = "";
    type = DepUnknown;
    scope = 0;
    parent = 0;
}

DepDefinition::~DepDefinition()
{
    for (int i = 0; i < predicates.size(); i++)
    {
        delete(predicates[i]);
    }
    
    if (type == DepRoot)
    {
        for (int i = 0; i < definitions.size(); i++)
        {
            delete(definitions[i]);
        }
    }
}

void DepDefinition::addDefinitionName(string name)
{
    definitionNames.push_back(name);
}

int DepDefinition::getDefinitionNameCount()
{
    return definitionNames.size();
}

string DepDefinition::getDefinitionNameAt(int index)
{
    return definitionNames[index];
}

void DepDefinition::addDefinition(DepDefinition* depDefinition)
{
    definitions.push_back(depDefinition);
    depDefinition->setParent(this);
}

int DepDefinition::getDefinitionCount()
{
    return definitions.size();
}

DepDefinition* DepDefinition::getDefinitionAt(int index)
{
    return definitions[index];
}

DepDefinition* DepDefinition::getDefinition(string name, DepDefinitionType type)
{
	if (DepChildType[type] == getType())
	{
        for (int i = 0; i < definitions.size(); i++)
        {
       		DepDefinition* definition = definitions[i];

            // name check
            if (definition->getName() == name)
            {
				return definition;
            }
        }
    }	
    return 0;
}

void DepDefinition::addPredicate(DepPredicate* predicate)
{
    predicates.push_back(predicate);
}

void DepDefinition::setType(DepDefinitionType type)
{
    this->type = type;
}

DepDefinitionType DepDefinition::getType()
{
    return type;
}

void DepDefinition::setName(string name)
{
        int pos = name.find(".");

	if (pos != -1)
	{
		parent_name = name.substr(0, pos);
		this->name = name.substr(pos + 1, name.length() - pos);
	}
	else
	{
	    this->name = name;
	}
}

string DepDefinition::getName()
{
    return name;
}

string DepDefinition::getFullName()
{
	if (parent_name.compare("") != 0)
	{
		return parent_name + "." + name;
	}
	else
	{
		return name;
	}
}

string DepDefinition::getCanonPath()
{
    DepDefinition * tmp = this;
    DepDefinition * tmp_prev = NULL;

    while( tmp && tmp->parent && (tmp->parent->type != DepRoot) )
    {
        tmp_prev = tmp;
        tmp = tmp->parent;
    }

    if(!tmp)
        return "PathFailed";

    return tmp->getName()+(tmp_prev ? "."+tmp_prev->getName() : "");
}

void DepDefinition::setScope(OptScope* scope)
{
    this->scope = scope;
    
    if(scope->getParent() == this)
        scope->setParent(this);
}

OptScope* DepDefinition::getScope()
{
    return scope;
}

void DepDefinition::setParent(DepDefinition* parent)
{
    this->parent = parent;
}

DepDefinition* DepDefinition::getParent()
{
    return parent;
}

bool DepDefinition::isAction()
{
    return getType() == DepSpecification || getType() == DepReaction || getType() == DepFunction;
}

string DepDefinition::toString()
{
    string result = name;

    result += "\n";
    
    {
        for (int i = 0; i < definitionNames.size(); i++)
        {
            result += "    " + definitionNames[i] + "\n";
        }
    }
    {
        for (int i = 0; i < definitions.size(); i++)
        {
            result += definitions[i]->toString();
        }
    }

    return result;
}

void DepDefinition::printDefinitions(int ident /* 0 */, DepPredicate* predicate /* 0 */)
{
    string space = "";

    {
        for (int i = 0; i < ident; i++)
        {
            space += "    ";
        }
    }

    printf("%s%s", space.c_str(), name.c_str());

    if (predicate)
    {
        printf ("\t%s", predicate->toString().c_str());
    }

    printf("\n");

    if (scope)
    {
        printf("%sSCOPE: %s\n", space.c_str(), scope->getName().c_str());
    }

    {
        for (int i = 0; i < definitions.size(); i++)
        {
            definitions[i]->printDefinitions(++ident, predicates[i]);
            ident--;
        }
    }

    if (isAction())
    {
        for (int i = 0; i < definitionNames.size(); i++)
        {
            printf("%s    %s\n", space.c_str(), definitionNames[i].c_str());
        }
    }
}

void DepDefinition::printNames()
{
    printf("%s\n", name.c_str());
    {
        for (int i = 0; i < definitionNames.size(); i++)
        {
            printf("    %s\n", definitionNames[i].c_str());
        }
    }
}

/************************************************************************/
/* DepPredicate                                                         */
/************************************************************************/

DepPredicate::DepPredicate()
{
    id = "undefined";
    value = 0;
    defined = false;
}

void DepPredicate::setPredicate(string id, int value)
{
    this->id = id;
    this->value = value;
    defined = true;
}

bool DepPredicate::isDefined()
{
    return defined;
}

string DepPredicate::toString()
{
    if (!defined)
    {
        return "";
    }
    else
    {
        return "(" + id + " = " + intToString(value) + ")";
    }
}

/************************************************************************/
/* OptScope                                                             */
/************************************************************************/

OptScope::OptScope()
{
    name = "";
    parent = NULL;
    defType = DepUnknown;
}

void OptScope::setName(string name)
{
    this->name = name;
}

string OptScope::getName()
{
    return name;
}

void OptScope::setDefType(string defTypeString)
{
    setDefType( resolveDefType(defTypeString) );
}

void OptScope::setDefType(DepDefinitionType defType)
{
    this->defType = defType;
}

DepDefinitionType OptScope::getDefType()
{
    return this->defType;
}

void OptScope::setParent(DepDefinition * parent)
{
    this->parent = parent;
    
    if(parent->getScope() == this)
        parent->setScope(this);
}

DepDefinition * OptScope::getParent()
{
    return parent;
}

void OptScope::addOptionName(string name)
{
    optionNames.push_back(name);
}

int OptScope::getOptionNameCount()
{
    return optionNames.size();
}

string OptScope::getOptionNameAt(int index)
{
    return optionNames[index];
}
    
void OptScope::addOption(OptDefinition* option)
{
    options.push_back(option);
}

OptDefinition* OptScope::getOptionAt(int index)
{
    return options[index];
}

int OptScope::getOptionCount()
{
	return options.size();
}

void OptScope::printOptions()
{
    printf("Printing options...\n");
    for(int i = 0; i < options.size(); i++)
    {
        printf("    %s\n", options[i]->getName().c_str());
    }
}

string OptScope::toString()
{
    return name;
}


/************************************************************************/
/* OptValue                                                             */
/************************************************************************/
OptValue::OptValue()
{
    name = "";
    value = 0;
    isDefault = false;
}

string OptValue::toString()
{
    string result = name + "\t= " + intToString(value);
    if (isDefault)
    {
        result += " (default)";
    }
    return result;
}

/************************************************************************/
/* OptDefinition                                                        */
/************************************************************************/

OptDefinition::OptDefinition()
{
    name = "";
    type = OptUnknown;
    destinationFile = "";
    description = "";
    alreadyGenerated = false;
}

OptDefinition::~OptDefinition()
{
    for (int i = 0; i < values.size(); i++)
    {
        delete(values[i]);
    }
}

bool OptDefinition::isAlreadyGenerated()
{
	return alreadyGenerated;
}

void OptDefinition::setAlreadyGenerated(bool flag)
{
	alreadyGenerated = flag;
}

extern int lineNumber;

void OptDefinition::setName(string name)
{
    this->name = name;
}

string OptDefinition::getName()
{
    return name;
}

void OptDefinition::setType(OptType type)
{
    this->type = type;
}

OptType OptDefinition::getType()
{
    return type;
}

void OptDefinition::setType(string typeString)
{
	for (int i = 0; i < 5; i++)
	{
		if (typeString == OptTypeString[i])
		{
			setType((OptType)i);
			return;
		}
	}
    setType(OptUnknown);
}

void OptDefinition::setKind(OptKind kind)
{
    this->kind = kind;
}

OptKind OptDefinition::getKind()
{
    return kind;
}

void OptDefinition::setKind(string kindString)
{
	for (int i = 0; i < 3; i++)
	{
		if (kindString == OptKindString[i])
		{
			setKind((OptKind)i);
			return;
		}
	}
    setKind(KindUnknown);
}

void OptDefinition::setDestinationFile(string fileName)
{
    this->destinationFile = fileName;
}

string OptDefinition::getDestinationFile()
{
	return destinationFile;
}

void OptDefinition::setDescription(string description)
{
    this->description = description;
}

string OptDefinition::getDescription()
{
	return description;
}

void OptDefinition::addValue(OptValue* value)
{
    values.push_back(value);
}

OptValue* OptDefinition::getDefaultValue()
{
    for (int i = 0; i < values.size(); i++)
    {
        OptValue* value = values[i];
        if (value->isDefault)
        {
        	return value;
        }
    }
    return 0;
}

OptValue* OptDefinition::getValueByName(string name)
{
    for (int i = 0; i < values.size(); i++)
    {
        OptValue* value = values[i];
        if (value->name == name)
        {
        	return value;
        }
    }
    printf( "\nFunction getValueByName failed on \"%s\"\n", name.c_str() );
    return 0;
}

OptValue* OptDefinition::getValueByEnumeration(string enumeration)
{
    for (int i = 0; i < values.size(); i++)
    {
        OptValue* value = values[i];
        if (value->enumeration == enumeration)
        {
        	return value;
        }
    }
    printf( "\nFunction getValueByEnumeration failed on \"%s\"\n", enumeration.c_str() );
    return 0;
}

OptValue* OptDefinition::getValueByValue(string val)
{
    for (int i = 0; i < values.size(); i++)
    {
        OptValue* value = values[i];
        char buf[16];
        sprintf(buf, "%i", value->value);
        if (string(buf) == val)
        {
        	return value;
        }
    }
    printf( "\nFunction getValueByValue failed on \"%s\"\n", val.c_str() );
    return 0;
}

vector<OptValue*> OptDefinition::getValues()
{
    return values;
}

string OptDefinition::generateEnumeration()
{
	/*
	string result = "enum {\n";
	
  	for (int i = 0; i < values.size(); i++)
    {
    	OptValue* value = values[i];
    	char buffer[64];
    	sprintf(buffer, "%d", value->value);
        result += "\t" + value->enumeration + " = " + buffer; 
        if (i < values.size() - 1)
        {
        	result +=  ",";
        }
        result += "\n";
    }	
		
	result += "}";
	return result;
	*/
	
	string result = "";
	
 	for (int i = 0; i < values.size(); i++)
    {
    	OptValue* value = values[i];
    	char buffer[64];
    	sprintf(buffer, "%d", value->value);
        result += "#define " + value->enumeration + " " + buffer + "\n"; 
    }		
	
	return result;
}

void OptDefinition::printContents()
{
    printf("type:\t%s\n", OptTypeString[type].c_str());
    printf("dest:\t%s\n", destinationFile.c_str());
    printf("desc:\n%s\n", description.c_str());
    printf("Printing option values...\n");
    for (int i = 0; i < values.size(); i++)
    {
        printf ("    %s\n", values[i]->toString().c_str());
    }
}

string OptDefinition::toString()
{
    string result = "";

    result += name;
    if (values.size())
    {
        result += "(" + values[0]->toString();
        for (int i = 1; i < values.size(); i++)
        {
            result += ", " + values[i]->toString();
        }
        result += ")";
    }

    return result;
}
