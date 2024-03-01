#include <iostream>
#include <string>
#include "scopeTable.h"
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
        // temp->setParent(current);
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
    bool insert(string symbol, string type) { return this->current->insertSymbol(symbol, type); }
    bool remove(string symbol) { return this->current->deleteSymbol(symbol); }
    SymbolInfo *lookup(string symbol)
    {
        ScopeTable *temp = current;
        while (temp->getParent())
        {
            if (temp->find(symbol))
            {
                return temp->lookup(symbol);
            }
            temp = temp->getParent();
        }
        if (!temp->find(symbol))
        {
            cout << "\t'" << symbol << "' not found in any of the ScopeTables\n";
        }
        return temp->lookup(symbol);
    }
    void printCurrentScope() { this->current->printScopeTable(); }
    void printAllScope()
    {
        ScopeTable *temp = current;
        while (temp)
        {
            temp->printScopeTable();
            temp = temp->getParent();
        }
    }
};