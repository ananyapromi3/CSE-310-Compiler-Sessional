#include <iostream>
#include <string>
#include <vector>
#include "2005079_SymbolType.h"
using namespace std;
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
    string getName() { return name; }
    string getType() { return type; }
    string getRule() { return rule; }
    int getLineStart() { return lineStart; }
    int getLineEnd() { return lineEnd; }
    double getValue() { return value; }
    SymbolInfo *getNext() { return next; }
    vector<SymbolInfo *> getListItem() { return listItem; }
    vector<SymbolInfo *> getParamFunc() { return paramFunc; }
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
        out << rule;
        if (this->symbolCategory == TOKEN)
        {
            out << "\t<Line: " << lineStart << ">\n";
        }
        else
        {
            out << " \t<Line: " << lineStart << "-" << lineEnd << ">\n";
        }
        for (auto child : children)
        {
            child->printParseTree(level + 1, out);
        }
    }
};