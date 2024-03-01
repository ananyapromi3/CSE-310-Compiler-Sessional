#include <iostream>
#include <string>
#include "symbolInfo.h"
using namespace std;
unsigned long sdbmHash(string str)
{
    unsigned long hash = 0;
    for (char c : str)
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}
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
        cout << "\tScopeTable# " << id << " created\n";
    }
    ~ScopeTable()
    {
        cout << "\tScopeTable# " << id << " deleted\n";
        for (int i = 0; i < total_bucket; ++i)
        {
            delete arr[i];
        }
        delete[] arr;
    }
    int hashFunc(string str) { return sdbmHash(str) % total_bucket; }
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
    SymbolInfo *lookup(string symbolName)
    {
        int location = hashFunc(symbolName);
        SymbolInfo *temp = arr[location];
        int pos = 1;
        while (temp)
        {
            if (temp->getName() == symbolName)
            {
                cout << "\t'" << symbolName << "' found at position <" << location + 1 << ", " << pos << "> of ScopeTable# " << id << "\n";
                return temp;
            }
            temp = temp->getNext();
            pos++;
        }
        return NULL;
    }
    bool insertSymbol(string symbolName, string symbolType)
    {
        if (find(symbolName))
        {
            cout << "\t'" << symbolName << "' already exists in the current ScopeTable# " << id << "\n";
            return false;
        }
        int location = hashFunc(symbolName);
        SymbolInfo *temp = arr[location];
        int pos = 1;
        if (!temp)
        {
            arr[location] = new SymbolInfo(symbolName, symbolType);
            cout << "\tInserted  at position <" << location + 1 << ", " << pos << "> of ScopeTable# " << id << "\n";
            return true;
        }
        while (temp->getNext())
        {
            pos++;
            temp = temp->getNext();
        }
        temp->setNext(new SymbolInfo(symbolName, symbolType));
        cout << "\tInserted  at position <" << location + 1 << ", " << pos + 1 << "> of ScopeTable# " << id << "\n";
        return true;
    }
    bool deleteSymbol(string symbolName)
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
                cout << "\tDeleted '" << symbolName << "' from position <" << location + 1 << ", " << pos << "> of ScopeTable# " << id << "\n";
                return true;
            }
            prev = current;
            current = current->getNext();
            pos++;
        }
        cout << "\tNot found in the current ScopeTable# " << id << "\n";
        return false;
    }
    void printScopeTable()
    {
        cout << "\tScopeTable# " << id << "\n";
        for (int i = 0; i < total_bucket; ++i)
        {
            cout << "\t" << i + 1;
            SymbolInfo *current = arr[i];
            while (current)
            {
                cout << " --> (" << current->getName() << "," << current->getType() << ")";
                current = current->getNext();
            }
            cout << "\n";
        }
    }
};