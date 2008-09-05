#ifndef DEPTREE_H
#define DEPTREE_H


/************************************************************************/
/* DepPredicate                                                         */
/************************************************************************/

class DEP_EXT_CLASS DepPredicate
{
public:
    DepPredicate();

public:
    bool isDefined();
    string toString();    

    void setPredicate(string id, int value);

private:
    string id;
    int value;  
    bool defined;
};

/************************************************************************/
/* DepDefinition                                                        */
/************************************************************************/

enum DepDefinitionType
    {
        DepUnknown = 0,
        DepRoot,
        DepCluster,
        DepSubsystem,
        DepGroup,
        DepScenario,
        DepTransition,
        DepSpecification,
        DepReaction,
        DepFunction
    };

string toString_DepDefinitionType(DepDefinitionType type);

extern DepDefinitionType DepChildType[];

DepDefinitionType resolveDefType(string defTypeString);

class OptScope;

class DEP_EXT_CLASS DepDefinition
{
public:
    DepDefinition();
    ~DepDefinition();

public:
    void addDefinitionName(string name);
    int getDefinitionNameCount();
    string getDefinitionNameAt(int index);
    
    void addDefinition(DepDefinition* child);
    int getDefinitionCount();
    DepDefinition* getDefinitionAt(int index);
    DepDefinition* getDefinition(string name, DepDefinitionType type);

    void addPredicate(DepPredicate* predicate);
    
    void setType(DepDefinitionType type);
    DepDefinitionType getType();
    
    void setName(string name);
    string getName();
    string getFullName();

    string getCanonPath();

    void setScope(OptScope* scope);
    OptScope* getScope();

    void setParent(DepDefinition* parent);
    DepDefinition* getParent();

    bool isAction();

    string toString();
    void printNames();
    void printDefinitions(int ident = 0, DepPredicate* predicate = 0);

private:
    DepDefinitionType type;
    string name;
    string parent_name;
    vector<string>  definitionNames;
    vector<DepDefinition*> definitions;
    vector<DepPredicate*> predicates;
    OptScope* scope;
    DepDefinition* parent;
};

/************************************************************************/
/* DepTree                                                              */
/************************************************************************/

class OptScope;
class OptDefinition;

class DEP_EXT_CLASS DepTree 
{
public:
    DepTree();
    ~DepTree();

public:
    DepDefinition& getRoot();
    void resolveReferences();
    bool isReferencesResolved();

    void addScope(OptScope* scope);
    OptScope* getScopeInstance(DepDefinitionType scopeType, string name);
    int getScopeCount();
    OptScope* getScopeAt(int index);

    void addOption(OptDefinition* option);
    bool hasOption(string scopeName, string optionName);
    OptDefinition* findOption(string scopeName, string optionName);
    int getOptionCount();
    OptDefinition* getOptionAt(int index);
    
    void printDefinitions();
    void printClusters();
    void printOptions();
    void printScopes();

private:
    void resolveReferences(DepDefinition* depDefinition);
    void resolveReference(DepDefinition* depDefinition, string name);

    void resolveReferences(OptScope* scope);
    void resolveReferences(OptScope* scope, string name);

private:
    DepDefinition root;
    bool referencesResolved; 
    vector<OptScope*> scopes;
    vector<OptDefinition*> options;
};

/************************************************************************/
/* OptScope                                                             */
/************************************************************************/

class OptDefinition;

class DEP_EXT_CLASS OptScope
{
public:
    OptScope();

public:
    void setName(string name);
    string getName();

    void setDefType(string defTypeString);
    void setDefType(DepDefinitionType defType);
    DepDefinitionType getDefType();

    void setParent(DepDefinition * parent);
    DepDefinition * getParent();

    void addOptionName(string name);
    int getOptionNameCount();
    string getOptionNameAt(int index);
        
    void addOption(OptDefinition* option);
    OptDefinition* getOptionAt(int index);
    int getOptionCount();

    void printOptions();
    string toString();
    
private:
    string name;
    DepDefinitionType defType;
    vector<string>  optionNames;
    vector<OptDefinition*> options;
    DepDefinition* parent;
};

/************************************************************************/
/* OptValue                                                             */
/************************************************************************/
class DEP_EXT_CLASS OptValue
{
public:
    OptValue();

public:
    string toString();
    
public:
    string name;
    int value;
    string enumeration;
    bool isDefault;
};



/************************************************************************/
/* OptDefinition                                                        */
/************************************************************************/


enum OptType 
    {
        OptUnknown = 0,
        OptBool,
        OptInt,
        OptSet,
        OptString
    };

extern string OptTypeString[];

string toString_OptType(OptType type);

enum OptKind
    {
        KindUnknown = 0,
        KindVariable,
        KindDefine
    };

extern string OptKindString[];

string toString_OptKind(OptKind kinf);

class DEP_EXT_CLASS OptDefinition
{
public:
    OptDefinition();
    ~OptDefinition();

public:
    void setName(string name);
    string getName();

    void setType(string typeString);
    void setType(OptType type);
    OptType getType();

    void setKind(string kindString);
    void setKind(OptKind kind);
    OptKind getKind();

    void setDestinationFile(string fileName);
    string getDestinationFile();
    void setDescription(string description);
    string getDescription();

    void addValue(OptValue* value);
    vector<OptValue*> getValues();
    OptValue* getDefaultValue();
    OptValue* getValueByName(string name);
    OptValue* getValueByEnumeration(string enumeration);
    OptValue* getValueByValue(string val);
    
    string generateEnumeration();

    void printContents();
    string toString();
    
    bool isAlreadyGenerated();
    void setAlreadyGenerated(bool flag);    

private:
    string name;
    OptType type;
    OptKind kind;
    string destinationFile;
    string description;
    vector<OptValue*> values;
    bool alreadyGenerated;
};

#endif /* DEPTREE_H */
