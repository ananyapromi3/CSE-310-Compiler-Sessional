#include <iostream>
#include <string>
#include "2005079_scopeTable.h"
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
        // ScopeTable *temp = current;
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
    bool remove(string symbol) { return this->current->deleteSymbol(symbol); }
    SymbolInfo *lookup(string symbol, ostream &out = cout)
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
        if (!temp->find(symbol))
        {
            out << "\t'" << symbol << "' not found in any of the ScopeTables\n";
        }
        return temp->lookup(symbol, out);
    }
    void printCurrentScope(ostream &out = cout) { this->current->printScopeTable(out); }
    void printAllScope(ostream &out = cout)
    {
        ScopeTable *temp = current;
        while (temp)
        {
            temp->printScopeTable(out);
            temp = temp->getParent();
        }
    }
};