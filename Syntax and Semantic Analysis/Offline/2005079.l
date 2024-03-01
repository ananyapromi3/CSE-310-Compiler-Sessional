%option noyywrap
%x STRING
%x SINGLE_COMMENT
%x MULTILINE_COMMENT
%{
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "2005079_symbolTable.h"
#include "y.tab.hpp"
#define BUCKET_SIZE 11
using namespace std;
int line_count = 1;
int error_count = 0;
int warning_count = 0;
bool line_starts = true;
int tab_count = 0;
int space_count = 0;
extern SymbolTable *symbolTable;
extern ofstream logout;
extern ofstream errorout;
extern ofstream parseout;
string str;
string token;
string temp;
int state_line_count = 0;
string convertUppercase(string str1) 
{
    string str2 = "";
    char temp;
    for (auto c : str) 
	{
        temp = toupper(c);
        str2 = str2 + temp;
    }
    return str2;
}
int countLeadingWhitespace(string line) 
{
    int count = 0;
    for (char ch : line) 
	{
        if (ch == ' ') 
		{
            count++;
        } 
		if (ch == '\t') 
		{
            continue;
        } 
		else 
		{
            break;
        }
    }
    return count;
}
int countLeadingTab(string line) 
{
    int count = 0;
    for (char ch : line) 
	{
        if (ch == '\t') count++;
		else break;
    }
    return count;
}
string tokenizer(string str1) 
{
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
void printWarning() 
{
	if(line_starts) 
	{
		if (space_count != 0) 
		{
			logout << "Line# " << line_count << ": Warning, tab requrired but got space.\n";
			warning_count++;
		} 
		else if (tab_count != symbolTable->getCurrentScopeLevel() - 1) 
		{
			logout << "Line# " << line_count << ": warning, " << symbolTable->getCurrentScopeLevel() - 1 << " of tabs needed but got " << tab_count << " tabs.\n";
			warning_count++;
		}
	}
	line_starts = false;
}
void handleKeyword() 
{
	str = yytext;
	yylval.symbolInfo = new SymbolInfo(str, convertUppercase(str), line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <" << convertUppercase(str) << "> Lexeme " << yytext << " found\n";
}
%}
WHITESPACE [ \t\f\r\v]+ 
KEYWORD if|else|for|while|do|break|int|char|float|double|void|return|switch|case|default|continue|printf
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
INCREMENT "++"
DECREMENT "--"
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
	if(line_starts) 
	{ 
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
"if" {
	handleKeyword();
	return IF;
}
"else" {
	handleKeyword();
	return ELSE;
}
"for" {
	handleKeyword();
	return FOR;
}
"while" {
	handleKeyword();
	return WHILE;
}
"do" {
	handleKeyword();
	return DO;
}
"break" {
	handleKeyword();
	return BREAK;
}
"int" {
	handleKeyword();
	return INT;
}
"char" {
	handleKeyword();
	return CHAR;
}
"float" {
	handleKeyword();
	return FLOAT;
}
"double" {
	handleKeyword();
	return DOUBLE;
}
"void" {
	handleKeyword();
	return VOID;
}
"return" {
	handleKeyword();
	return RETURN;
}
"switch" {
	handleKeyword();
	return SWITCH;
}
"case" {
	handleKeyword();
	return CASE;
}
"default" {
	handleKeyword();
	return DEFAULT;
}
"continue" {
	handleKeyword();
	return CONTINUE;
}
"println" {
	handleKeyword();
	return PRINTLN;
}
{INTEGER} {
	str = yytext;
	yylval.symbolInfo = new SymbolInfo(yytext, "CONST_INT", line_count, line_count, TOKEN, stod(str));
	logout << "Line# " << line_count << ": Token <CONST_INT> Lexeme " << yytext << " found\n";
	return CONST_INT;
}
{FLOAT} {
	str = yytext;
	yylval.symbolInfo = new SymbolInfo(yytext, "CONST_FLOAT", line_count, line_count, TOKEN, stod(str));
	logout << "Line# " << line_count << ": Token <CONST_FLOAT> Lexeme " << yytext << " found\n";
	return CONST_FLOAT;
}
{FLOAT}(\.{DIGITS}?)(\.{DIGITS}?) {
	logout << "Error at line# " << line_count<< ": TOO_MANY_DECIMAL_POINTS " << yytext<< "\n";
	error_count++;
}
{FLOAT}([eE][+-]?{DIGITS})(\.{DIGITS}?)+ {
	logout << "Error at line# " << line_count << ": ILLFORMED_NUMBER " << yytext << "\n";
	error_count++;
}
"//" {
	state_line_count = 0;
	str = yytext;
	BEGIN SINGLE_COMMENT;
}
"/*" {
	state_line_count = 0;
	str = yytext;
	BEGIN MULTILINE_COMMENT;
}
{ADD_SUB} {
	yylval.symbolInfo = new SymbolInfo(yytext, "ADDOP", line_count, line_count, TOKEN);
	logout << "Line# "<< line_count<< ": Token <ADDOP> Lexeme " << yytext << " found\n";
	return ADDOP;
}
{MUL_DIV} {
	yylval.symbolInfo = new SymbolInfo(yytext, "MULOP", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <MULOP> Lexeme " << yytext << " found\n";
	return MULOP;
}
{INCREMENT} {
	yylval.symbolInfo = new SymbolInfo(yytext, "INCOP", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <INCOP> Lexeme " << yytext << " found\n";
	return INCOP;
}
{DECREMENT} {
	yylval.symbolInfo = new SymbolInfo(yytext, "DECOP", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <DECOP> Lexeme " << yytext << " found\n";
	return DECOP;
}
{RELATIONAL} {
	yylval.symbolInfo = new SymbolInfo(yytext, "RELOP", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <RELOP> Lexeme " << yytext << " found\n";
	return RELOP;
}
{ASSIGNMENT} {
	yylval.symbolInfo = new SymbolInfo(yytext, "ASSIGNOP", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <ASSIGNOP> Lexeme " << yytext << " found\n";
	return ASSIGNOP;
}
{LOGICAL} {
	yylval.symbolInfo = new SymbolInfo(yytext, "LOGICOP", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <LOGICOP> Lexeme " << yytext << " found\n";
	return LOGICOP;
}
{BITWISE} {
	yylval.symbolInfo = new SymbolInfo(yytext, "BITOP", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <BITOP> Lexeme " << yytext << " found\n";
	return BITOP;
}
{NOT} {
	yylval.symbolInfo = new SymbolInfo(yytext, "NOT", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <NOT> Lexeme " << yytext << " found\n";
	return NOT;
}
{LEFT_PAREN} {
	yylval.symbolInfo = new SymbolInfo(yytext, "LPAREN", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <LPAREN> Lexeme " << yytext << " found\n";
	return LPAREN;
}
{RIGHT_PAREN} {
	yylval.symbolInfo = new SymbolInfo(yytext, "RPAREN", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <RPAREN> Lexeme " << yytext << " found\n";
	return RPAREN;
}
{LEFT_CURL} {
	yylval.symbolInfo = new SymbolInfo(yytext, "LCURL", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <LCURL> Lexeme " << yytext << " found\n";
	return LCURL;
}
{RIGHT_CURL} {
	yylval.symbolInfo = new SymbolInfo(yytext, "RCURL", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <RCURL> Lexeme " << yytext << " found\n";
	return RCURL;
}
{LEFT_SQUARE} {
	yylval.symbolInfo = new SymbolInfo(yytext, "LSQUARE", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <LSQUARE> Lexeme " << yytext << " found\n";
	return LSQUARE;
}
{RIGHT_SQUARE} {
	yylval.symbolInfo = new SymbolInfo(yytext, "RSQUARE", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <RSQUARE> Lexeme " << yytext << " found\n";
	return RSQUARE;
}
{COMMA} {
	yylval.symbolInfo = new SymbolInfo(yytext, "COMMA", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <COMMA> Lexeme " << yytext << " found\n";
	return COMMA;
}
{SEMICOLON} {
	yylval.symbolInfo = new SymbolInfo(yytext, "SEMICOLON", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <SEMICOLON> Lexeme " << yytext << " found\n";
	return SEMICOLON;
}
{ID} {
	yylval.symbolInfo = new SymbolInfo(yytext, "ID", line_count, line_count, TOKEN);
	logout << "Line# " << line_count << ": Token <ID> Lexeme "<< yytext<< " found\n";
	return ID;
}
{FLOAT}{ID}	{
	logout << "Error at line# " << line_count<< ": INVALID_ID_SUFFIX_NUM_PREFIX " << yytext<< "\n";
	error_count++;
}
"\'\'"	{
	logout << "Error at line# " << line_count << ": EMPTY_CONST_CHAR " << yytext << "\n";
	error_count++;
}
[\']{CHARACTER}*{NEWLINE} {
	str = yytext;
    str.pop_back();
	logout << "Error at line# " << line_count << ": UNFINISHED_CONST_CHAR " << str << "\n";
	error_count++;
	line_count++;
}
[\']{SPECIAL}*{NEWLINE} {
	str = yytext;
    str.pop_back();
	logout << "Error at line# " << line_count << ": UNFINISHED_CONST_CHAR " << str << "\n";
	error_count++;
	line_count++;
}
[\']{CHARACTER}{CHARACTER}+[\'] {
	logout << "Error at line# " << line_count << ": MULTICHAR_CONST_CHAR " << yytext << "\n";
	error_count++;
}
[\']{SPECIAL}[\']	{
	str = yytext;
	str = str.substr(1, str.size() - 2);
	str = tokenizer(str);
	yylval.symbolInfo = new SymbolInfo(str, "CONST_CHAR", line_count, line_count, TOKEN , str[0]);
	logout << "Line# " << line_count << ": Token <CONST_CHAR> Lexeme " << tokenizer(str) << " found\n";
	return CONST_CHAR;
}
[\']{CHARACTER}[\']	{
	str = yytext;
	str = str.substr(1, str.size() - 2);
	yylval.symbolInfo = new SymbolInfo(str, "CONST_CHAR", line_count, line_count, TOKEN, str[0]);
	logout << "Line# " << line_count << ": Token <CONST_CHAR> Lexeme " << str << " found\n";
	return CONST_CHAR;
}
[\"] {
	state_line_count = 0;
	str = yytext;
	token = "";
	BEGIN STRING;
}
<STRING>\" {
	str = str + yytext;
	line_count += state_line_count;
	BEGIN 0;
}
<STRING>\\{NEWLINE} {
	str = str + yytext;
	state_line_count++;
}
<STRING>{NEWLINE} {
	line_count += state_line_count;
	logout << "Error at line# " << line_count << ": UNFINISHED STRING " << str << "\n";
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
	logout << "Error at line# " << line_count << ": UNFINISHED STRING " << str << "\n";
	error_count++;
	BEGIN 0;
}
<SINGLE_COMMENT>\\{NEWLINE} {
	str = str + yytext;
	state_line_count++;
}
<SINGLE_COMMENT>{NEWLINE} {
	line_count += state_line_count;
	line_count++;
	BEGIN 0;
}
<SINGLE_COMMENT>. {
	str = str + yytext;
}
<SINGLE_COMMENT><<EOF>> {
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
	line_count += state_line_count;
	BEGIN 0;
}
<MULTILINE_COMMENT><<EOF>> {
	line_count += state_line_count;
	logout << "Error at line# " << line_count << ": UNFINISHED COMMENT " << str << "\n";
	error_count++;
	BEGIN 0;
}
. {
	line_starts = false;
	logout << "Error at line# " << line_count << ": UNRECOGNIZED CHAR " << yytext << "\n";
	error_count++;
}
%%
