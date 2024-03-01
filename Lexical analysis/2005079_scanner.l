%option noyywrap
%x STRING
%x SINGLE_COMMENT
%x MULTILINE_COMMENT
%{
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "2005079_symbolTable.h"
#define BUCKET_SIZE 10
using namespace std;
int line_count = 1;
int error_count = 0;
int warning_count = 0;
bool line_starts = true;
int tab_count = 0;
int space_count = 0;
SymbolTable *symbolTable;
ofstream logout;
ofstream tokenout;
string str;
string token;
string temp;
int state_line_count = 0;
string convertUppercase(string str1) {
    string str2 = "";
    char temp;
    for (auto c : str) {
        temp = toupper(c);
        str2 = str2 + temp;
    }
    return str2;
}
int countLeadingWhitespace(string line) {
    int count = 0;
    for (char ch : line) {
        if (ch == ' ') {
            count++;
        } if (ch == '\t') {
            continue;
        } else {
            break;
        }
    }
    return count;
}
int countLeadingTab(string line) {
    int count = 0;
    for (char ch : line) {
        if (ch == '\t') {
            count++;
        } else {
            break;
        }
    }
    return count;
}
string tokenizer(string str1) {
	if(str1 == "\\n") return "\n";
	else if(str1 == "\\t") return "\t";
	else if(str1 == "\\a") return "\a";
	else if(str1 == "\\f") return "\f";
	else if(str1 == "\\r") return "\r";
	else if(str1 == "\\b") return "\b";
	else if(str1 == "\\v") return "\v";
	else if(str1 == "\\\'") return "\'";
	else if(str1 == "\\\"") return "\"";
	else if(str1 == "\\\\") return "\\";
	else if(str1 == "\\0") return "\0";
	else return str;
}
void printWarning() {
	if(line_starts) {
		if (space_count != 0) {
			logout << "Line# " << line_count << ": Warning, tab requrired but got space.\n";
			warning_count++;
		} else if (tab_count != symbolTable->getCurrentScopeLevel() - 1) {
			logout << "Line# " << line_count << ": warning, " << symbolTable->getCurrentScopeLevel() - 1 << " of tabs needed but got " << tab_count << " tabs.\n";
			warning_count++;
		}
	}
	line_starts = false;
}
%}
WHITESPACE [ \t\f\r\v]+ 
KEYWORD if|else|for|while|do|break|int|char|float|double|void|return|switch|case|default|continue
LETTER [a-zA-Z_]
ALPHANUMERIC [a-zA-Z0-9]
ID {LETTER}({LETTER}|{DIGIT})*
SPECIAL \\n|\\t|\\a|\\f|\\r|\\b|\\v|\\\'|\\\"|\\\\|\\0
CHARACTER [^\n\r\\\'\"]|SPECIAL
DIGIT [0-9]
DIGITS {DIGIT}+
INTEGER {DIGITS}[\.]?
FLOAT {DIGITS}(\.{DIGITS})?([eE]{ADD_SUB}?{DIGITS})? 
ADD_SUB [+-]
MUL_DIV [*/%]
INCREMENT "++"|"--"
RELATIONAL ==|<|>|<=|>=|!=
ASSIGNMENT =
LOGICAL &&|\|\|
BITWISE >>|<<|^|&|\|
NOT !
LEFT_PAREN "("
RIGHT_PAREN ")"
LEFT_CURL "{"
RIGHT_CURL "}"
LEFT_SQUARE "["
RIGHT_SQUARE "]"
COMMA ,
SEMICOLON ;
NEWLINE (\r)?\n
%%
{WHITESPACE} { 
	if(line_starts) { 
		string temp = yytext;
		tab_count = countLeadingTab(temp);
		space_count = countLeadingWhitespace(temp);
	}
}
{NEWLINE} { 
	line_count++; 
	line_starts = true; 
	tab_count = 0;
	space_count = 0;
}
{KEYWORD} {
	printWarning();
	str = yytext;
	tokenout << "<" << convertUppercase(yytext) << ", " << yytext<< ">\n";
	logout << "Line# " << line_count << ": Token <" << convertUppercase(yytext) << "> Lexeme " << yytext << " found\n";
}
{INTEGER}	{
	printWarning();
	tokenout << "<CONST_INT, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <CONST_INT> Lexeme " << yytext << " found\n";
}
{FLOAT} {
	printWarning();
	tokenout << "<CONST_FLOAT, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <CONST_FLOAT> Lexeme " << yytext << " found\n";
}
{FLOAT}(\.{DIGITS}?)(\.{DIGITS}?) {
	printWarning();
	logout << "Error at line# " << line_count<< ": TOO_MANY_DECIMAL_POINTS " << yytext<< "\n";
	error_count++;
}
{FLOAT}([eE][+-]?{DIGITS})(\.{DIGITS}?)+ {
	printWarning();
	logout << "Error at line# " << line_count << ": ILLFORMED_NUMBER " << yytext << "\n";
	error_count++;
}
"//" {
	printWarning();
	state_line_count = 0;
	str = yytext;
	BEGIN SINGLE_COMMENT;
}
"/*" {
	printWarning();
	state_line_count = 0;
	str = yytext;
	BEGIN MULTILINE_COMMENT;
}
{ADD_SUB} {
	printWarning();
	tokenout << "<ADDOP, "<< yytext << ">\n";
	logout << "Line# "<< line_count<< ": Token <ADDOP> Lexeme " << yytext << " found\n";
}
{MUL_DIV} {
	printWarning();
	tokenout << "<MULOP, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <MULOP> Lexeme " << yytext << " found\n";
}
{INCREMENT} {
	printWarning();
	tokenout << "<INCOP, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <INCOP> Lexeme " << yytext << " found\n";
}
{RELATIONAL} {
	printWarning();
	tokenout << "<RELOP, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <RELOP> Lexeme " << yytext << " found\n";
}
{ASSIGNMENT} {
	printWarning();
	tokenout << "<ASSIGNOP, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <ASSIGNOP> Lexeme " << yytext << " found\n";
}
{LOGICAL} {
	printWarning();
	tokenout << "<LOGICOP, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <LOGICOP> Lexeme " << yytext << " found\n";
}
{BITWISE} {
	printWarning();
	tokenout << "<BITOP, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <BITOP> Lexeme " << yytext << " found\n";
}
{NOT} {
	printWarning();
	tokenout << "<NOT, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <NOT> Lexeme " << yytext << " found\n";
}
{LEFT_PAREN} {
	printWarning();
	tokenout << "<LPAREN, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <LPAREN> Lexeme " << yytext << " found\n";
}
{RIGHT_PAREN} {
	printWarning();
	tokenout << "<RPAREN, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <RPAREN> Lexeme " << yytext << " found\n";
}
{LEFT_CURL} {
	printWarning();
	tokenout << "<LCURL, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <LCURL> Lexeme " << yytext << " found\n";
	symbolTable->enterScope(BUCKET_SIZE);
}
{RIGHT_CURL} {
	symbolTable->exitScope();
	printWarning();
	tokenout << "<RCURL, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <RCURL> Lexeme " << yytext << " found\n";
}
{LEFT_SQUARE} {
	printWarning();
	tokenout << "<LSQUARE, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <LSQUARE> Lexeme " << yytext << " found\n";
}
{RIGHT_SQUARE} {
	printWarning();
	tokenout << "<RSQUARE, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <RSQUARE> Lexeme " << yytext << " found\n";
}
{COMMA} {
	printWarning();
	tokenout << "<COMMA, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <COMMA> Lexeme " << yytext << " found\n";
}
{SEMICOLON} {
	printWarning();
	tokenout << "<SEMICOLON, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <SEMICOLON> Lexeme " << yytext << " found\n";
}
{ID} {
	printWarning();
	tokenout << "<ID, " << yytext << ">\n";
	logout << "Line# " << line_count << ": Token <ID> Lexeme "<< yytext<< " found\n";
	if(symbolTable->insert(yytext, "ID", logout)) symbolTable->printAllScope(logout);
}
{FLOAT}{ID}	{
	printWarning();
	logout << "Error at line# " << line_count<< ": INVALID_ID_SUFFIX_NUM_PREFIX " << yytext<< "\n";
	error_count++;
}
"\'\'"	{
	printWarning();
	logout << "Error at line# " << line_count << ": EMPTY_CONST_CHAR " << yytext << "\n";
	error_count++;
}
[\']{CHARACTER}*{NEWLINE} {
	printWarning();
	str = yytext;
    str.pop_back();
	logout << "Error at line# " << line_count << ": UNFINISHED_CONST_CHAR " << str << "\n";
	error_count++;
	line_count++;
}
[\']{SPECIAL}*{NEWLINE} {
	printWarning();
	str = yytext;
    str.pop_back();
	logout << "Error at line# " << line_count << ": UNFINISHED_CONST_CHAR " << str << "\n";
	error_count++;
	line_count++;
}
[\']{CHARACTER}{CHARACTER}+[\'] {
	printWarning();
	logout << "Error at line# " << line_count << ": MULTICHAR_CONST_CHAR " << yytext << "\n";
	error_count++;
}
[\']{SPECIAL}[\']	{
	printWarning();
	str = yytext;
	str = str.substr(1, str.size() - 2);
	tokenout << "<CONST_CHAR, " << tokenizer(str) << ">\n";
	logout << "Line# " << line_count << ": Token <CONST_CHAR> Lexeme " << tokenizer(str) << " found\n";
}
[\']{CHARACTER}[\']	{
	printWarning();
	str = yytext;
	str = str.substr(1, str.size() - 2);
	tokenout << "<CONST_CHAR, " << str << ">\n";
	logout << "Line# " << line_count << ": Token <CONST_CHAR> Lexeme " << str << " found\n";
}
[\"] {
	printWarning();
	state_line_count = 0;
	str = yytext;
	token = "";
	BEGIN STRING;
}
<STRING>\" {
	str = str + yytext;
	if(state_line_count == 0) {
		tokenout << "<SINGLE LINE STRING, " << token << ">\n";
		logout<< "Line# " << line_count << ": Token <SINGLE LINE STRING> Lexeme " << str << " found\n";
	}
	else {
		tokenout << "<MULTI LINE STRING, " << token << ">\n";
		logout << "Line# " << line_count<< ": Token <MULTI LINE STRING> Lexeme " << str << " found\n";
	}
	line_count += state_line_count;
	BEGIN 0;
}
<STRING>\\{NEWLINE} {
	str = str + yytext;
	state_line_count++;
}
<STRING>{NEWLINE} {
	line_count += state_line_count;
	logout << "Error at line# " << line_count << ": UNFINISHED_STRING " << str << "\n";
	error_count++;
	line_count++;
	BEGIN 0;
}
<STRING>{SPECIAL} {
	str = str + yytext;
	temp = yytext;
	token = token + tokenizer(temp); 
}
<STRING>. {
	str = str + yytext;
	token = token + yytext; 
}
<STRING><<EOF>> {
	line_count += state_line_count;
	logout << "Error at line# " << line_count << ": UNFINISHED_STRING " << str << "\n";
	error_count++;
	BEGIN 0;
}
<SINGLE_COMMENT>\\{NEWLINE} {
	str = str + yytext;
	state_line_count++;
}
<SINGLE_COMMENT>{NEWLINE} {
	logout << "Line# " << line_count << ": Token <SINGLE LINE COMMENT> Lexeme " << str << " found\n";
	line_count += state_line_count;
	line_count++;
	BEGIN 0;
}
<SINGLE_COMMENT>. {
	str = str + yytext;
}
<SINGLE_COMMENT><<EOF>> {
	logout << "Line# " << line_count << ": Token <SINGLE LINE COMMENT> Lexeme " << str << " found\n";
	line_count += state_line_count;
	BEGIN 0;
}
<MULTILINE_COMMENT>{NEWLINE} {
	str = str + yytext;
	state_line_count++;
}
<MULTILINE_COMMENT>. {
	str = str + yytext;
}
<MULTILINE_COMMENT>"*/" {
	str = str + yytext;
	logout << "Line# " << line_count << ": Token <MULTI LINE COMMENT> Lexeme " << str << " found\n";
	line_count += state_line_count;
	BEGIN 0;
}
<MULTILINE_COMMENT><<EOF>> {
	line_count += state_line_count;
	logout << "Error at line# " << line_count << ": UNFINISHED_COMMENT " << str << "\n";
	error_count++;
	BEGIN 0;
}
. {
	line_starts = false;
	logout << "Error at line# " << line_count << ": UNRECOGNIZED_CHAR " << yytext << "\n";
	error_count++;
}
%%
int main(int argc, char *argv[]) {
	if(argc != 2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	FILE *fin = fopen(argv[1], "r");
	if(fin == NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	logout.open("2005079_log.txt");
	tokenout.open("2005079_token.txt");
    symbolTable = new SymbolTable(new ScopeTable(BUCKET_SIZE, NULL));
	yyin = fin;
	yylex();
	fclose(yyin);
	tokenout.close();
	symbolTable->printAllScope(logout);
	logout <<"Total lines: "<< line_count<<"\n";
	logout <<"Total errors: "<< error_count<<"\n";
	logout <<"Total warnings: "<< warning_count<<"\n";
	logout.close();
	delete symbolTable;
	return 0;
}
