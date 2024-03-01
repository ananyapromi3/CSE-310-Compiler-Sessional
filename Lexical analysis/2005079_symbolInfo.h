#include <iostream>
#include <string>
using namespace std;
class SymbolInfo
{
    string name, type;
    SymbolInfo *next;

public:
    SymbolInfo(string name, string type)
    {
        this->name = name;
        this->type = type;
        this->next = NULL;
    }
    ~SymbolInfo() { delete next; }
    void setNext(SymbolInfo *next) { this->next = next; }
    string getName() { return name; }
    string getType() { return type; }
    SymbolInfo *getNext() { return next; }
};