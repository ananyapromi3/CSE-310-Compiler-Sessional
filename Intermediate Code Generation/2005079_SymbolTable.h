#include <iostream>
#include <string>
#include "2005079_ScopeTable.h"
using namespace std;
class SymbolTable
{
    ScopeTable *current;

public:
    SymbolTable(ScopeTable *current)
    {
        this->current = current;
    }
    ~SymbolTable()
    {
        while (current)
        {
            ScopeTable *next = current->getParent();
            delete current;
            current = next;
        }
    }
    void enterScope(int n)
    {
        ScopeTable *temp = new ScopeTable(n, current);
        this->current = temp;
    }
    void exitScope()
    {
        if (current->getParent())
        {
            ScopeTable *temp = current;
            this->current = current->getParent();
            delete temp;
        }
        else
        {
            cout << "\tScopeTable# " << current->getId() << " cannot be deleted\n";
        }
    }
    int getCurrentScopeLevel() { return current->getLevel(); }
    bool insert(string symbol, string type, ostream &out = cout) { return this->current->insertSymbol(symbol, type, out); }
    bool insert(SymbolInfo *symbolInfo) { return this->current->insertSymbol(symbolInfo); }
    bool remove(string symbol) { return this->current->deleteSymbol(symbol); }
    SymbolInfo *lookupAll(string symbol, ostream &out = cout)
    {
        ScopeTable *temp = current;
        while (temp->getParent())
        {
            if (temp->find(symbol))
            {
                return temp->lookup(symbol, out);
            }
            temp = temp->getParent();
        }
        return temp->lookup(symbol, out);
    }
    SymbolInfo *lookup(string symbol, ostream &out = cout)
    {
        return current->lookup(symbol, out);
    }
    void printCurrentScope(ostream &out = cout) { this->current->printScopeTable(out); }
    void printParentScope(ostream &out = cout)
    {
        if (this->current->getParent())
        {
            this->current->getParent()->printScopeTable(out);
        }
    }
    void printAllScope(ostream &out = cout)
    {
        ScopeTable *temp = current;
        while (temp)
        {
            temp->printScopeTable(out);
            temp = temp->getParent();
        }
    }
    vector<SymbolInfo *> getGlobalVars()
    {
        ScopeTable *temp = current;
        while (temp->getParent())
        {
            temp = temp->getParent();
        }
        for (SymbolInfo *var : temp->getVars())
        {
            var->setGlobal(true);
        }
        return temp->getVars();
    }
};