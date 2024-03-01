#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#define printLibraryFile "2005079_PrintLibrary.asm"
using namespace std;
static unsigned long sdbmHash(string str)
{
    unsigned long hash = 0;
    for (char c : str)
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

// FOR ASM
static void printLibrary(ostream &out)
{
    string fileContent = "";
    string line;
    ifstream inputFile(printLibraryFile);
    if (!inputFile.is_open())
    {
        cout << "Error opening the file!\n";
        return;
    }
    while (getline(inputFile, line))
    {
        fileContent = fileContent + line + "\n";
    }
    inputFile.close();
    out << fileContent << "\n";
}

// Code optimization
static vector<string> tokenizeLine(string line)
{
    vector<string> tokens;
    string temp = "";
    for (char c : line)
    {
        if (c != ' ' && c != '\t' && c != ',')
        {
            temp = temp + c;
        }
        else if (temp != "")
        {
            tokens.push_back(temp);
            temp = "";
        }
    }
    if (temp != "")
    {
        tokens.push_back(temp);
    }
    return tokens;
}
static void optimizeCode(ifstream &in, ostream &out)
{
    vector<string> lines;
    string line;
    while (getline(in, line))
    {
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++)
    {
        vector<string> tokens1, tokens2;
        tokens1 = tokenizeLine(lines[i]);
        if (i < lines.size() - 1)
        {
            tokens2 = tokenizeLine(lines[i + 1]);
            if (tokens1.size() >= 3 && tokens2.size() >= 3 && tokens1[0] == "MOV" && tokens2[0] == "MOV" && tokens1[1] == tokens2[2] && tokens1[2] == tokens2[1])
            {
                i++;
            }
            else if (tokens1.size() >= 2 && tokens2.size() >= 2 && tokens1[0] == "PUSH" && tokens2[0] == "POP" && tokens1[1] == tokens2[1])
            {
                i++;
            }
            else
            {
                out << lines[i] << "\n";
            }
        }
        else if (tokens1.size() >= 3 && (tokens1[0] == "ADD" || tokens1[0] == "SUB") && tokens1[2] == "0")
        {
        }
        else if (tokens1.size() >= 3 && tokens1[0] == "MUL" && tokens1[2] == "1")
        {
        }
        else
        {
            out << lines[i] << "\n";
        }
    }
}

// yacc -d -o y.tab.cpp 2005079.y
// echo 'Generated the parser Cpp file as well the header file'
// g++ -w -c -o y.o y.tab.cpp
// echo 'Generated the parser object file'
// flex -o lex.yy.cpp 2005079.l
// echo 'Generated the scanner Cpp file'
// g++ -w -c -o l.o lex.yy.cpp
// echo 'Generated the scanner object file'
// g++ y.o l.o -o test.exe
// echo 'All ready, running'
// ./test.exe input.c
