#include <iostream>
#include <string>
#include <vector>
#include "2005079_SymbolType.h"
#include "2005079_Utilities.h"
#define INTSIZE 2
using namespace std;
static int globalLabelCount = 0;
static int tempVarDeclar = 0;
static int loopCount = 0;
static string currentScope = "";
class SymbolInfo
{
    string name, type, rule, dataType;
    SymbolInfo *next;
    int lineStart, lineEnd;
    vector<SymbolInfo *> children;
    vector<SymbolInfo *> paramFunc;
    vector<SymbolInfo *> listItem;
    SymbolType symbolType;
    SymbolCategory symbolCategory;
    double value;
    int arrSize;
    bool isGlobal;
    int stackOffsetVal;
    int labelCount;
    int *arrElems;

public:
    SymbolInfo(string name, string type)
    {
        this->name = name;
        this->type = type;
        this->next = NULL;
    }
    SymbolInfo(string name, string type, int lineStart, int lineEnd, SymbolCategory symbolCategory = TYPE, double value = 1.0)
    {
        this->name = name;
        this->type = type;
        this->lineStart = lineStart;
        this->lineEnd = lineEnd;
        this->rule = type + " : " + name;
        this->next = NULL;
        this->value = value;
        this->symbolCategory = symbolCategory;
        this->isGlobal = false;
    }
    ~SymbolInfo() { delete next; }
    void setName(string name) { this->name = name; }
    void setType(string type) { this->type = type; }
    void setRule(string rule) { this->rule = rule; }
    void setLineStart(int start) { this->lineStart = start; }
    void setLineEnd(int end) { this->lineEnd = end; }
    void setDataType(string dataType) { this->dataType = dataType; }
    void setNext(SymbolInfo *next) { this->next = next; }
    void setValue(double val) { this->value = val; }
    void setSymbolType(SymbolType symbolType) { this->symbolType = symbolType; }
    void setSymbolCategory(SymbolCategory symbolCategory) { this->symbolCategory = symbolCategory; }
    void setLabelCount(int labelCount) { this->labelCount = labelCount; }
    int getLabelCount() { return this->labelCount; }
    string getName() { return name; }
    string getType() { return type; }
    string getRule() { return rule; }
    bool getGlobal() { return isGlobal; }
    void setGlobal(bool flag) { this->isGlobal = flag; }
    int getStackOffsetVal() { return this->stackOffsetVal; }
    void setStackOffset(int stackOffsetVal) { this->stackOffsetVal = stackOffsetVal; }
    int getArrSize() { return arrSize; }
    void setArrSize(int arrSize)
    {
        this->arrSize = arrSize;
        this->arrElems = new int[arrSize];
    }
    int getLineStart() { return lineStart; }
    int getLineEnd() { return lineEnd; }
    double getValue() { return value; }
    SymbolInfo *getNext() { return next; }
    vector<SymbolInfo *> getListItem() { return listItem; }
    vector<SymbolInfo *> getParamFunc() { return paramFunc; }
    vector<SymbolInfo *> getChildren() { return children; }
    string getDataType() { return dataType; }
    SymbolType getSymbolType() { return symbolType; }
    SymbolCategory getSymbolCategory() { return symbolCategory; }
    void addChild(SymbolInfo *child) { children.push_back(child); }
    void addParamFunc(SymbolInfo *param) { paramFunc.push_back(param); }
    void addItem(SymbolInfo *item) { listItem.push_back(item); }
    void printParseTree(int level, ostream &out)
    {
        for (int i = 0; i < level; i++)
        {
            out << " ";
        }
        out << rule << "\t";
        if (this->symbolCategory == TOKEN)
        {
            out << "<Line: " << lineStart << ">\n";
        }
        else
        {
            out << "<Line: " << lineStart << "-" << lineEnd << ">\n";
        }
        for (auto child : children)
        {
            child->printParseTree(level + 1, out);
        }
    }
    void ICG(vector<SymbolInfo *> globalVarList, ostream &out)
    {
        if (this->getRule() == "start : program")
        {
            printHeader(globalVarList, out);
            children[0]->ICG(out);
            out << "\n";
            printLibrary(out);
            out << "END main\n";
        }
    }
    void ICG(ostream &out)
    {
        if (this->getRule() == "program : program unit")
        {
            children[0]->ICG(out);
            children[1]->ICG(out);
        }
        else if (this->getRule() == "program : unit")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "var_declaration : type_specifier declaration_list SEMICOLON")
        {
            children[1]->ICG(out);
        }
        else if (this->getRule() == "unit : var_declaration")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "unit : func_declaration")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "unit : func_definition")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON")
        {
        }
        else if (this->getRule() == "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON")
        {
        }
        else if (this->getRule() == "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement")
        {
            out << children[1]->getName() << " PROC\n";
            currentScope = children[1]->getName();
            if (children[1]->getName() == "main")
            {
                out << "\tMOV AX, @DATA\n";
                out << "\tMOV DS, AX\n";
            }
            out << "\tPUSH BP\n";
            out << "\tMOV BP, SP\n";
            children[3]->ICG(out);
            children[5]->ICG(out);
            out << "exit_" << currentScope << ":\n";
            out << "\tADD SP, " << tempVarDeclar * INTSIZE << "\n";
            tempVarDeclar = 0;
            out << "\tPOP BP\n";
            if (children[1]->getName() == "main")
            {
                out << "\tMOV AX, 4CH\n";
                out << "\tINT 21H\n";
            }
            else
            {
                out << "\tRET " << children[1]->getParamFunc().size() * INTSIZE << "\n";
            }
            out << children[1]->getName() << " ENDP\n\n";
            currentScope = "";
        }
        else if (this->getRule() == "func_definition : type_specifier ID LPAREN RPAREN compound_statement")
        {
            out << children[1]->getName() << " PROC\n";
            currentScope = children[1]->getName();
            if (children[1]->getName() == "main")
            {
                out << "\tMOV AX, @DATA\n";
                out << "\tMOV DS, AX\n";
            }
            out << "\tPUSH BP\n";
            out << "\tMOV BP, SP\n";
            children[4]->ICG(out);
            out << "exit_" << currentScope << ":\n";
            if (children[1]->getName() == "main")
            {
                out << "\tADD SP, " << tempVarDeclar * INTSIZE << "\n";
                tempVarDeclar = 0;
                out << "\tPOP BP\n";
                out << "\tMOV AX, 4CH\n";
                out << "\tINT 21H\n";
            }
            else
            {
                out << "\tPOP BP\n";
                out << "\tRET\n";
            }
            out << children[1]->getName() << " ENDP\n\n";
            currentScope = "";
        }
        else if (this->getRule() == "parameter_list : parameter_list COMMA type_specifier ID")
        {
        }
        else if (this->getRule() == "parameter_list : parameter_list COMMA type_specifier")
        {
        }
        else if (this->getRule() == "parameter_list : type_specifier ID")
        {
        }
        else if (this->getRule() == "parameter_list : type_specifier")
        {
        }
        else if (this->getRule() == "compound_statement : LCURL statements RCURL")
        {
            children[1]->ICG(out);
        }
        else if (this->getRule() == "compound_statement : LCURL RCURL")
        {
        }
        else if (this->getRule() == "var_declaration : type_specifier declaration_list SEMICOLON")
        {
            children[1]->ICG(out);
        }
        else if (this->getRule() == "type_specifier : INT")
        {
        }
        else if (this->getRule() == "type_specifier : FLOAT")
        {
        }
        else if (this->getRule() == "type_specifier : VOID")
        {
        }
        else if (this->getRule() == "declaration_list : declaration_list COMMA ID")
        {
            children[0]->ICG(out);
            if (!children[2]->getGlobal())
            {
                if (children[2]->getDataType() == "INT")
                {
                    out << "\tSUB SP, " << INTSIZE << "\n";
                    tempVarDeclar++;
                }
            }
        }
        else if (this->getRule() == "declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE")
        {
            children[0]->ICG(out);
            if (!children[2]->getGlobal())
            {
                if (children[2]->getDataType() == "INT")
                {
                    out << "\tSUB SP, " << INTSIZE * children[4]->getValue() << "\n";
                    tempVarDeclar += children[4]->getValue();
                }
            }
        }
        else if (this->getRule() == "declaration_list : ID")
        {
            if (!children[0]->getGlobal())
            {
                if (children[0]->getDataType() == "INT")
                {
                    out << "\tSUB SP, " << INTSIZE << "\t\t\t; Line " << this->getLineStart() << "\n";
                    tempVarDeclar++;
                }
            }
        }
        else if (this->getRule() == "declaration_list : ID LSQUARE CONST_INT RSQUARE")
        {
            if (!children[0]->getGlobal())
            {
                if (children[0]->getDataType() == "INT")
                {
                    out << "\tSUB SP, " << INTSIZE * children[2]->getValue() << "\t\t\t; Line " << this->getLineStart() << "\n";
                    tempVarDeclar += children[2]->getValue();
                }
            }
        }
        else if (this->getRule() == "statements : statement")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "statements : statements statement")
        {
            children[0]->ICG(out);
            children[1]->ICG(out);
        }
        else if (this->getRule() == "statement : var_declaration")
        {
            this->setLabelCount(++globalLabelCount);
            out << "L" << this->getLabelCount() << ":\n";
            children[0]->ICG(out);
        }
        else if (this->getRule() == "statement : expression_statement")
        {
            this->setLabelCount(++globalLabelCount);
            out << "L" << this->getLabelCount() << ":\n";
            children[0]->ICG(out);
        }
        else if (this->getRule() == "statement : compound_statement")
        {
            this->setLabelCount(++globalLabelCount);
            out << "L" << this->getLabelCount() << ":\n";
            children[0]->ICG(out);
        }
        else if (this->getRule() == "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement")
        {
            loopCount++;
            this->setLabelCount(++globalLabelCount);
            out << "L" << this->getLabelCount() << ":\n";
            children[2]->ICG(out);
            int loopLabel = globalLabelCount + 1;
            int loopOut = loopCount;
            out << "L" << ++globalLabelCount << ":\n";
            children[3]->ICG(out);
            out << "\tCMP AX, 0\n";
            out << "\tJE LL" << loopCount << "\n";
            children[6]->ICG(out);
            children[4]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tJMP L" << loopLabel << "\n";
            out << "LL" << loopOut << ":\n";
        }
        else if (this->getRule() == "statement : IF LPAREN expression RPAREN statement")
        {
            loopCount++;
            int loopOut1 = loopCount;
            loopCount++;
            int loopOut2 = loopCount;
            this->setLabelCount(++globalLabelCount);
            out << "L" << this->getLabelCount() << ":\n";
            children[2]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tCMP AX, 0\n";
            out << "\tJNE LL" << loopOut1 << "\n";
            out << "\tJMP LL" << loopOut2 << "\n";
            out << "LL" << loopOut1 << ":\n";
            children[4]->ICG(out);
            out << "LL" << loopOut2 << ":\n";
        }
        else if (this->getRule() == "statement : IF LPAREN expression RPAREN statement ELSE statement")
        {
            loopCount++;
            int loopOut1 = loopCount;
            loopCount++;
            int loopOut2 = loopCount;
            loopCount++;
            int loopOut3 = loopCount;
            this->setLabelCount(++globalLabelCount);
            out << "L" << this->getLabelCount() << ":\n";
            children[2]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tCMP AX, 0\n";
            out << "\tJNE LL" << loopOut1 << "\n";
            out << "\tJE LL" << loopOut2 << "\n";
            out << "LL" << loopOut1 << ":\n";
            children[4]->ICG(out);
            out << "\tJMP LL" << loopOut3 << "\n";
            out << "LL" << loopOut2 << ":\n";
            children[6]->ICG(out);
            out << "LL" << loopOut3 << ":\n";
        }
        else if (this->getRule() == "statement : WHILE LPAREN expression RPAREN statement")
        {
            loopCount++;
            this->setLabelCount(++globalLabelCount);
            out << "L" << this->getLabelCount() << ":\n";
            int loopLabel = this->getLabelCount();
            int loopOut = loopCount;
            children[2]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tCMP AX, 0\n";
            out << "\tJE LL" << loopCount << "\n";
            children[4]->ICG(out);
            out << "\tJMP L" << loopLabel << "\n";
            out << "LL" << loopOut << ":\n";
        }
        else if (this->getRule() == "statement : PRINTLN LPAREN ID RPAREN SEMICOLON")
        {
            if (children[2]->getGlobal())
            {
                out << "\tMOV AX, " + children[2]->getName() + "\t\t\t; Line " << this->getLineStart() << "\n";
                out << "\tCALL print_output\n";
                out << "\tCALL new_line\n";
            }
            else
            {
                out << "\tMOV AX, [BP - " << INTSIZE * children[2]->getStackOffsetVal() << "]\t\t\t; Line " << this->getLineStart() << "\n";
                out << "\tCALL print_output\n";
                out << "\tCALL new_line\n";
            }
        }
        else if (this->getRule() == "statement : RETURN expression SEMICOLON")
        {
            out << "L" << ++globalLabelCount << ":\n";
            children[1]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tJMP exit_" << currentScope << "\n";
        }
        else if (this->getRule() == "expression_statement : SEMICOLON")
        {
        }
        else if (this->getRule() == "expression_statement : expression SEMICOLON")
        {
            children[0]->ICG(out);
            out << "\tPOP AX\n";
        }
        else if (this->getRule() == "variable : ID")
        {
        }
        else if (this->getRule() == "variable : ID LSQUARE expression RSQUARE")
        {
            children[2]->ICG(out);
            out << "\tPOP AX\n";
        }
        else if (this->getRule() == "expression : logic_expression")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "expression : variable ASSIGNOP logic_expression")
        {
            if (children[0]->getGlobal())
            {
                if (children[0]->getSymbolType() == ARRAY)
                {
                    children[0]->ICG(out);
                    out << "\tPUSH AX\n";
                    children[2]->ICG(out);
                    out << "\tPOP AX\n";
                    out << "\tPOP BX\n";
                    out << "\tPUSH AX\n";
                    out << "\tMOV AX, " << INTSIZE << "\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tPOP AX\n";
                    out << "\tMOV " << children[0]->getName() << "[BX], AX\n";
                }
                else
                {
                    children[2]->ICG(out);
                    out << "\tPOP AX\n";
                    out << "\tMOV " << children[0]->getName() << ", AX\n";
                }
            }
            else
            {
                if (children[0]->getSymbolType() == ARRAY)
                {
                    children[0]->ICG(out);
                    out << "\tPUSH AX\n";
                    children[2]->ICG(out);
                    out << "\tPOP AX\n";
                    out << "\tPOP BX\n";
                    out << "\tPUSH AX\n";
                    out << "\tMOV AX, " << INTSIZE << "\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV AX, " << tempVarDeclar * INTSIZE << "\n";
                    out << "\tSUB AX, BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tPOP AX\n";
                    out << "\tMOV SI, BX\n";
                    out << "\tNEG SI\n";
                    out << "\tMOV [BP + SI], AX\n";
                }
                else
                {
                    children[2]->ICG(out);
                    out << "\tPOP AX\n";
                    if (children[0]->getStackOffsetVal() < 0)
                    {
                        out << "\tMOV [BP + " << (-1) * INTSIZE * children[0]->getStackOffsetVal() << "], AX\n";
                    }
                    else
                    {
                        out << "\tMOV [BP - " << INTSIZE * children[0]->getStackOffsetVal() << "], AX\n";
                    }
                }
            }
            out << "\tPUSH AX\n";
        }
        else if (this->getRule() == "logic_expression : rel_expression")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "logic_expression : rel_expression LOGICOP rel_expression")
        {
            children[0]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tCMP AX, 0\n";
            if (children[1]->getName() == "||")
            {
                out << "\tJNE L" << globalLabelCount + 2 << "\n";
                out << "\tJMP L" << globalLabelCount + 1 << "\n";
            }
            else if (children[1]->getName() == "&&")
            {
                out << "\tJNE L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 3 << "\n";
            }
            out << "L" << ++globalLabelCount << ":\n";
            children[2]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tCMP AX, 0\n";
            if (children[1]->getName() == "||")
            {
                out << "\tJNE L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 2 << "\n";
            }
            else if (children[1]->getName() == "&&")
            {
                out << "\tJNE L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 2 << "\n";
            }
            out << "L" << ++globalLabelCount << ":\n";
            out << "\tMOV AX, 1\n";
            out << "\tJMP L" << globalLabelCount + 2 << "\n";
            out << "L" << ++globalLabelCount << ":\n";
            out << "\tMOV AX, 0\n";
            out << "L" << ++globalLabelCount << ":\n";
            out << "\tPUSH AX\n";
        }
        else if (this->getRule() == "rel_expression : simple_expression")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "rel_expression : simple_expression RELOP simple_expression")
        {
            children[0]->ICG(out);
            children[2]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tMOV DX, AX\n";
            out << "\tPOP AX\n";
            out << "\tCMP AX, DX\n";
            if (children[1]->getName() == "<=")
            {
                out << "\tJLE L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 2 << "\n";
            }
            else if (children[1]->getName() == "!=")
            {
                out << "\tJNE L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 2 << "\n";
            }
            else if (children[1]->getName() == "==")
            {
                out << "\tJE L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 2 << "\n";
            }
            else if (children[1]->getName() == ">=")
            {
                out << "\tJGE L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 2 << "\n";
            }
            else if (children[1]->getName() == ">")
            {
                out << "\tJG L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 2 << "\n";
            }
            else if (children[1]->getName() == "<")
            {
                out << "\tJL L" << globalLabelCount + 1 << "\n";
                out << "\tJMP L" << globalLabelCount + 2 << "\n";
            }
            out << "L" << ++globalLabelCount << ":\n";
            out << "\tMOV AX, 1\n";
            out << "\tJMP L" << globalLabelCount + 2 << "\n";
            out << "L" << ++globalLabelCount << ":\n";
            out << "\tMOV AX, 0\n";
            out << "L" << ++globalLabelCount << ":\n";
            out << "\tPUSH AX\n";
        }
        else if (this->getRule() == "simple_expression : term")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "simple_expression : simple_expression ADDOP term")
        {
            children[2]->ICG(out);
            children[0]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tMOV DX, AX\n";
            out << "\tPOP AX\n";
            if (children[1]->getName() == "+")
            {
                out << "\tADD AX, DX\n";
            }
            else
            {
                out << "\tSUB DX, AX\n";
                out << "\tMOV AX, DX\n";
            }
            out << "\tPUSH AX\n";
        }
        else if (this->getRule() == "term : unary_expression")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "term : term MULOP unary_expression")
        {
            children[2]->ICG(out);
            children[0]->ICG(out);
            out << "\tPOP AX\n";
            out << "\tMOV CX, AX\n";
            out << "\tPOP AX\n";
            out << "\tCWD\n";
            if (children[1]->getName() == "*")
            {
                out << "\tMUL CX\n";
                out << "\tPUSH AX\n";
            }
            else
            {
                out << "\tXOR AX, CX\n";
                out << "\tXOR CX, AX\n";
                out << "\tXOR AX, CX\n";
                out << "\tDIV CX\n";
                if (children[1]->getName() == "%")
                {
                    out << "\tPUSH DX\n";
                }
                else
                {
                    out << "\tPUSH AX\n";
                }
            }
        }
        else if (this->getRule() == "unary_expression : ADDOP unary_expression")
        {
            children[1]->ICG(out);
            if (children[0]->getName() == "-")
            {
                out << "\tPOP AX\n";
                out << "\tNEG AX\n";
                out << "\tPUSH AX\n";
            }
        }
        else if (this->getRule() == "unary_expression : NOT unary_expression")
        {
            children[1]->ICG(out);
        }
        else if (this->getRule() == "unary_expression : factor")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "factor : variable")
        {
            children[0]->ICG(out);
            if (children[0]->getGlobal())
            {
                if (children[0]->getSymbolType() == ARRAY)
                {
                    out << "\tPUSH AX\n";
                    out << "\tPOP BX\n";
                    out << "\tMOV AX, " << INTSIZE << "\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV AX, " << children[0]->getName() << "[BX]\n";
                    out << "\tPUSH AX\n";
                }
                else
                {
                    out << "\tMOV AX, " << children[0]->getName() << "\t\t\t; Line " << this->getLineStart() << "\n";
                    out << "\tPUSH AX\n";
                }
            }
            else
            {
                if (children[0]->getSymbolType() == ARRAY)
                {
                    out << "\tPUSH AX\n";
                    out << "\tPOP BX\n";
                    out << "\tMOV AX, " << INTSIZE << "\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV AX, " << tempVarDeclar * INTSIZE << "\n";
                    out << "\tSUB AX, BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV SI, BX\n";
                    out << "\tNEG SI\n";
                    out << "\tMOV AX, [BP + SI]\n";
                    out << "\tPUSH AX\n";
                }
                else
                {
                    if (children[0]->getStackOffsetVal() < 0)
                    {
                        out << "\tMOV AX, [BP + " << children[0]->getStackOffsetVal() * INTSIZE * (-1) << "]\t\t\t; Line " << this->getLineStart() << "\n";
                    }
                    else
                    {
                        out << "\tMOV AX, [BP - " << children[0]->getStackOffsetVal() * INTSIZE << "]\t\t\t; Line " << this->getLineStart() << "\n";
                    }
                    out << "\tPUSH AX\n";
                }
            }
        }
        else if (this->getRule() == "factor : ID LPAREN argument_list RPAREN")
        {
            children[2]->ICG(out);
            out << "\tCALL " << children[0]->getName() << "\n";
            out << "\tPUSH AX\n";
        }
        else if (this->getRule() == "factor : LPAREN expression RPAREN")
        {
            children[1]->ICG(out);
        }
        else if (this->getRule() == "factor : CONST_INT")
        {
            out << "\tMOV AX, " << children[0]->getValue() << "\t\t\t; Line " << this->getLineStart() << "\n";
            out << "\tPUSH AX\n";
        }
        else if (this->getRule() == "factor : CONST_FLOAT")
        {
            out << "\tMOV AX, " << children[0]->getValue() << "\t\t\t; Line " << this->getLineStart() << "\n";
            out << "\tPUSH AX\n";
        }
        else if (this->getRule() == "factor : variable INCOP")
        {
            children[0]->ICG(out);
            if (children[0]->getGlobal())
            {
                if (children[0]->getSymbolType() == ARRAY)
                {
                    out << "\tPUSH AX\n";
                    out << "\tPOP CX\n";
                    out << "\tPUSH CX\n";
                    out << "\tPOP BX\n";
                    out << "\tMOV AX, " << INTSIZE << "\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV AX, " << children[0]->getName() << "[BX]\n";
                    out << "\tPUSH AX\n";
                    out << "\tINC AX\n";
                    out << "\tPUSH CX\n";
                    out << "\tPOP BX\n";
                    out << "\tPUSH AX\n";
                    out << "\tMOV AX, 2\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tPOP AX\n";
                    out << "\tMOV " << children[0]->getName() << "[BX], AX\n";
                }
                else
                {
                    out << "\tMOV AX, " << children[0]->getName() << "\t\t\t; Line " << this->getLineStart() << "\n";
                    out << "\tPUSH AX\n";
                    out << "\tINC AX\n";
                    out << "\tMOV " << children[0]->getName() << ", AX\n";
                }
            }
            else
            {
                if (children[0]->getSymbolType() == ARRAY)
                {
                    out << "\tPUSH AX\n";
                    out << "\tPOP CX\n";
                    out << "\tMOV AX, " << INTSIZE << "\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV AX, " << tempVarDeclar * INTSIZE << "\n";
                    out << "\tSUB AX, BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV SI, BX\n";
                    out << "\tNEG SI\n";
                    out << "\tMOV AX, [BP+SI]\n";
                    out << "\tPUSH AX\n";
                    out << "\tINC AX\n";
                    out << "\tPUSH CX\n";
                    out << "\tPOP BX\n";
                    out << "\tPUSH AX\n";
                    out << "\tMOV AX, 2\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tPOP AX\n";
                    out << "\tMOV AX, " << tempVarDeclar * INTSIZE << "\n";
                    out << "\tSUB AX, BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV SI, BX\n";
                    out << "\tNEG SI\n";
                    out << "\tMOV AX, [BP+SI]\n";
                }
                else
                {
                    if (children[0]->getStackOffsetVal() < 0)
                    {
                        out << "\tMOV AX, [BP + " << children[0]->getStackOffsetVal() * INTSIZE * (-1) << "]\t\t\t; Line " << this->getLineStart() << "\n";
                    }
                    else
                    {
                        out << "\tMOV AX, [BP - " << children[0]->getStackOffsetVal() * INTSIZE << "]\t\t\t; Line " << this->getLineStart() << "\n";
                    }
                    out << "\tPUSH AX\n";
                    out << "\tINC AX\n";
                    if (children[0]->getStackOffsetVal() < 0)
                    {
                        out << "\tMOV [BP + " << children[0]->getStackOffsetVal() * (-1) * INTSIZE << "], AX\n";
                    }
                    else
                    {
                        out << "\tMOV [BP - " << children[0]->getStackOffsetVal() * INTSIZE << "], AX\n";
                    }
                }
            }
        }
        else if (this->getRule() == "factor : variable DECOP")
        {
            if (children[0]->getGlobal())
            {
                if (children[0]->getSymbolType() == ARRAY)
                {
                    out << "\tPUSH AX\n";
                    out << "\tPOP CX\n";
                    out << "\tMOV AX, " << INTSIZE << "\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV AX, " << children[0]->getName() << "[BX]\n";
                    out << "\tPUSH AX\n";
                    out << "\tDEC AX\n";
                    out << "\tPUSH CX\n";
                    out << "\tPOP BX\n";
                    out << "\tPUSH AX\n";
                    out << "\tMOV AX, 2\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tPOP AX\n";
                    out << "\tMOV " << children[0]->getName() << "[BX], AX\n";
                }
                else
                {
                    out << "\tMOV AX, " << children[0]->getName() << "\t\t\t; Line " << this->getLineStart() << "\n";
                    out << "\tPUSH AX\n";
                    out << "\tDEC AX\n";
                    out << "\tMOV " << children[0]->getName() << ", AX\n";
                }
            }
            else
            {
                if (children[0]->getSymbolType() == ARRAY)
                {
                    out << "\tPUSH AX\n";
                    out << "\tPOP CX\n";
                    out << "\tMOV AX, " << INTSIZE << "\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV AX, " << tempVarDeclar * INTSIZE << "\n";
                    out << "\tSUB AX, BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV SI, BX\n";
                    out << "\tNEG SI\n";
                    out << "\tMOV AX, [BP+SI]\n";
                    out << "\tPUSH AX\n";
                    out << "\tDEC AX\n";
                    out << "\tPUSH CX\n";
                    out << "\tPOP BX\n";
                    out << "\tPUSH AX\n";
                    out << "\tMOV AX, 2\n";
                    out << "\tMUL BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tPOP AX\n";
                    out << "\tMOV AX, " << tempVarDeclar * INTSIZE << "\n";
                    out << "\tSUB AX, BX\n";
                    out << "\tMOV BX, AX\n";
                    out << "\tMOV SI, BX\n";
                    out << "\tNEG SI\n";
                    out << "\tMOV AX, [BP+SI]\n";
                }
                else
                {
                    if (children[0]->getStackOffsetVal() < 0)
                    {
                        out << "\tMOV AX, [BP + " << children[0]->getStackOffsetVal() * (-1) * INTSIZE << "]\t\t\t; Line " << this->getLineStart() << "\n";
                    }
                    else
                    {
                        out << "\tMOV AX, [BP - " << children[0]->getStackOffsetVal() * INTSIZE << "]\t\t\t; Line " << this->getLineStart() << "\n";
                    }
                    out << "\tPUSH AX\n";
                    out << "\tDEC AX\n";
                    if (children[0]->getStackOffsetVal() < 0)
                    {
                        out << "\tMOV [BP + " << children[0]->getStackOffsetVal() * (-1) * INTSIZE << "], AX\n";
                    }
                    else
                    {
                        out << "\tMOV [BP - " << children[0]->getStackOffsetVal() * INTSIZE << "], AX\n";
                    }
                }
            }
        }
        else if (this->getRule() == "argument_list : arguments")
        {
            children[0]->ICG(out);
        }
        else if (this->getRule() == "arguments : arguments COMMA logic_expression")
        {
            children[0]->ICG(out);
            children[2]->ICG(out);
        }
        else
        {
            for (SymbolInfo *child : children)
            {
                child->ICG(out);
            }
        }
    }

    // utility functions
    void printHeader(vector<SymbolInfo *> globalVarList, ostream &out)
    {
        out << ".MODEL SMALL\n";
        out << ".STACK 1000H\n";
        out << ".DATA\n";
        out << "\tNUMBER DB \"00000$\"\n";
        for (int i = 0; i < globalVarList.size(); i++)
        {
            if (globalVarList[i]->getSymbolType() == ARRAY)
            {
                out << "\t" << globalVarList[i]->name << " DW " << globalVarList[i]->getArrSize() << " DUP (0000H)\n";
            }
            else if (globalVarList[i]->getSymbolType() == VARIABLE)
            {
                out << "\t" << globalVarList[i]->name << " DW 1 DUP (0000H)\n";
            }
        }
        out << ".CODE\n";
    }
};
