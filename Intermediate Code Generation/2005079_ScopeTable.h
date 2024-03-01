#include <iostream>
#include <string>
#include "2005079_SymbolInfo.h"
using namespace std;
class ScopeTable
{
    SymbolInfo **arr;
    int total_bucket;
    ScopeTable *parentScope;
    string id;
    int childCount;

public:
    ScopeTable(int n, ScopeTable *parent)
    {
        total_bucket = n;
        arr = new SymbolInfo *[n];
        for (int i = 0; i < n; ++i)
        {
            arr[i] = NULL;
        }
        if (parent)
        {
            setParent(parent);
        }
        else
        {
            childCount = 0;
            id = "1";
            parentScope = NULL;
        }
    }
    ~ScopeTable() { delete[] arr; }
    int hashFunc(string str) { return sdbmHash(str) % total_bucket; }
    int getLevel()
    {
        int level = 0;
        ScopeTable *temp = this;
        while (temp)
        {
            level++;
            temp = temp->getParent();
        }
        return level;
    }
    string getId() { return id; }
    void setParent(ScopeTable *parent)
    {
        if (parentScope != parent)
        {
            parent->childCount++;
        }
        this->parentScope = parent;
        this->id = parent->id + "." + to_string(parent->childCount);
    }
    ScopeTable *getParent() { return parentScope; }
    bool find(string symbolName)
    {
        int location = hashFunc(symbolName);
        SymbolInfo *temp = arr[location];
        while (temp)
        {
            if (temp->getName() == symbolName)
            {
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }
    SymbolInfo *lookup(string symbolName, ostream &out = cout)
    {
        int location = hashFunc(symbolName);
        SymbolInfo *temp = arr[location];
        int pos = 1;
        while (temp)
        {
            if (temp->getName() == symbolName)
            {
                return temp;
            }
            temp = temp->getNext();
            pos++;
        }
        return NULL;
    }
    bool insertSymbol(string symbolName, string symbolType, ostream &out = cout)
    {
        if (find(symbolName))
        {
            return false;
        }
        int location = hashFunc(symbolName);
        SymbolInfo *temp = arr[location];
        int pos = 1;
        if (!temp)
        {
            arr[location] = new SymbolInfo(symbolName, symbolType);
            return true;
        }
        while (temp->getNext())
        {
            pos++;
            temp = temp->getNext();
        }
        temp->setNext(new SymbolInfo(symbolName, symbolType));
        return true;
    }
    bool insertSymbol(SymbolInfo *symbolInfo)
    {
        if (find(symbolInfo->getName()))
        {
            return false;
        }
        int location = hashFunc(symbolInfo->getName());
        SymbolInfo *temp = arr[location];
        int pos = 1;
        if (!temp)
        {
            arr[location] = symbolInfo;
            return true;
        }
        while (temp->getNext())
        {
            pos++;
            temp = temp->getNext();
        }
        temp->setNext(symbolInfo);
        return true;
    }
    bool deleteSymbol(string symbolName, ostream &out = cout)
    {
        int location = hashFunc(symbolName);
        SymbolInfo *current = arr[location];
        SymbolInfo *prev = NULL;
        int pos = 1;
        while (current)
        {
            if (current->getName() == symbolName)
            {
                if (!prev)
                {
                    arr[location] = current->getNext();
                }
                else
                {
                    prev->setNext(current->getNext());
                }
                delete current;
                out << "\tDeleted '" << symbolName << "' from position <" << location + 1 << ", " << pos << "> of ScopeTable# " << id << "\n";
                return true;
            }
            prev = current;
            current = current->getNext();
            pos++;
        }
        out << "\tNot found in the current ScopeTable# " << id << "\n";
        return false;
    }
    void printScopeTable(ostream &out = cout)
    {
        out << "\tScopeTable# " << id << "\n";
        for (int i = 0; i < total_bucket; ++i)
        {
            int flag = 0;
            SymbolInfo *current = arr[i];
            if (current)
            {
                flag = 1;
                out << "\t" << i + 1 << "--> ";
            }
            while (current)
            {
                out << "<" << current->getName() << ",";
                if (current->getSymbolType() == FUNCTION)
                {
                    out << "FUNCTION," << current->getDataType() << "> ";
                }
                else if (current->getSymbolType() == ARRAY)
                {
                    out << "ARRAY> ";
                }
                else
                {
                    out << current->getDataType() << "> ";
                }
                current = current->getNext();
            }
            if (flag)
            {
                out << "\n";
            }
        }
    }
    vector<SymbolInfo *> getVars()
    {
        vector<SymbolInfo *> vars;
        for (int i = 0; i < total_bucket; i++)
        {
            SymbolInfo *var = arr[i];
            while (var)
            {
                vars.push_back(var);
                var = var->getNext();
            }
        }
        return vars;
    }
};