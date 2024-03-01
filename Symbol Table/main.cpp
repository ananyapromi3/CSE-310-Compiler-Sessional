#include <iostream>
#include <string>
#include <sstream>
#include "symbolTable.h"
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    getchar();
    SymbolTable *symbolTable = new SymbolTable(new ScopeTable(n, NULL));
    string command;
    int count = 1;
    while (true)
    {
        getline(cin, command);
        cout << "Cmd " << count << ": " << command << "\n";
        int num = 0;
        string word, arg[10];
        istringstream iss(command);
        while (getline(iss, word, ' '))
        {
            arg[num++] = word;
        }
        if (arg[0] == "Q")
        {
            if (num != 1)
            {
                cout << "\tWrong number of arugments for the command Q\n";
            }
            else
            {
                delete symbolTable;
                break;
            }
        }
        else if (arg[0] == "I")
        {
            if (num != 3)
            {
                cout << "\tWrong number of arugments for the command I\n";
            }
            else
            {
                symbolTable->insert(arg[1], arg[2]);
            }
        }
        else if (arg[0] == "L")
        {
            if (num != 2)
            {
                cout << "\tWrong number of arugments for the command L\n";
            }
            else
            {
                symbolTable->lookup(arg[1]);
            }
        }
        else if (arg[0] == "P")
        {
            if (num != 2)
            {
                cout << "\tWrong number of arugments for the command P\n";
            }
            else if (arg[1] == "C")
            {
                symbolTable->printCurrentScope();
            }
            else if (arg[1] == "A")
            {
                symbolTable->printAllScope();
            }
            else
            {
                cout << "\tInvalid argument for the command P\n";
            }
        }
        else if (arg[0] == "D")
        {
            if (num != 2)
            {
                cout << "\tWrong number of arugments for the command D\n";
            }
            else
            {
                symbolTable->remove(arg[1]);
            }
        }
        else if (arg[0] == "S")
        {
            if (num != 1)
            {
                cout << "\tWrong number of arugments for the command S\n";
            }
            else
            {
                symbolTable->enterScope(n);
            }
        }
        else if (arg[0] == "E")
        {
            if (num != 1)
            {
                cout << "\tWrong number of arugments for the command E\n";
            }
            else
            {
                symbolTable->exitScope();
            }
        }
        else
        {
            cout << "\tInvalid Command\n";
        }
        count++;
    }
    return 0;
}