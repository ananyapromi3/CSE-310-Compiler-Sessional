%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <cassert>
#include <fstream>
#include "2005079_SymbolTable.h"
#define BUCKET_SIZE 11
using namespace std;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
SymbolTable *symbolTable;
vector<SymbolInfo *> tempParamList;
int temp_line = 0;
ofstream parseout;
ofstream logout;
ofstream errorout;
extern int line_count;
extern int error_count;
void yyerror(char *s) 
{
	errorout << "Line# " << line_count << ": " << s << "\n";
	logout << "Error at line no " << line_count << " : syntax error\n";
	error_count++;
}
void checkFunc(SymbolInfo *typeSpecifier, SymbolInfo *id, SymbolInfo *parameterList) {}
void checkFunc(SymbolInfo *typeSpecifier, SymbolInfo *id) {}
%}
%nonassoc RPAREN 
%nonassoc ELSE
%error-verbose
%union 
{
    SymbolInfo* symbolInfo; 
}
%token<symbolInfo> IF ELSE FOR WHILE DO BREAK CONTINUE RETURN VOID SWITCH CASE DEFAULT PRINTLN ADDOP MULOP INCOP RELOP ASSIGNOP LOGICOP BITOP NOT INT CHAR FLOAT DOUBLE ID NEWLINE LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE COMMA SEMICOLON DECOP CONST_CHAR CONST_FLOAT CONST_INT
%type<symbolInfo> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments error
%%
start : 
	program
	{
		logout << "start : program\n";
		$$ = new SymbolInfo("", "start", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("start : program");
		$$->addChild($1);
		$$->printParseTree(0, parseout);
	}
	;
program : 
	program unit 
	{
		logout << "program : program unit\n";
		$$ = new SymbolInfo("", "program", $1->getLineStart(), $2->getLineEnd());	
		$$->setRule("program : program unit");
		$$->addChild($1); 
		$$->addChild($2);
	}
	| unit
	{
		logout << "program : unit\n";
		$$ = new SymbolInfo("", "program", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("program : unit");
		$$->addChild($1);
	}
	;
unit : 
	var_declaration
	{
		logout << "unit : var_declaration\n";
		$$ = new SymbolInfo("", "unit", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("unit : var_declaration");
		$$->addChild($1);
	}
    | func_declaration
	{
		logout << "unit : func_declaration\n";
		$$ = new SymbolInfo("", "unit", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("unit : func_declaration");
		$$->addChild($1);
	}
    | func_definition
	{
		logout << "unit : func_definition\n";
		$$ = new SymbolInfo("", "unit", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("unit : func_definition");
		$$->addChild($1);
	}
	|
	error
	{
		$$ = new SymbolInfo("", "unit", line_count, line_count);
		$$->setRule("unit : error");
	}
    ;
func_declaration : 
	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
	{
		logout << "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n";
		$$ = new SymbolInfo("", "func_declaration", $1->getLineStart(), $6->getLineEnd());
		$$->setRule("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
		$$->addChild($6);
		for (auto item: $4->getListItem())
		{
			$2->addParamFunc(item);
		}
		$2->setSymbolType(FUNCTION);
		$2->setDataType($1->getDataType());
		if(!symbolTable->insert($2))
		{
			errorout << "Line# " << line_count << ": Redefinition of parameter \'" << $2->getName() << "\'\n";
			error_count++;
		}
	}
	| type_specifier ID LPAREN RPAREN SEMICOLON
	{
		logout << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n";
		$$ = new SymbolInfo("", "func_declaration", $1->getLineStart(), $5->getLineEnd());
		$$->setRule("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
		$2->setSymbolType(FUNCTION);
		$2->setDataType($1->getDataType());
		if(!symbolTable->insert($2))
		{
			errorout << "Line# " << line_count << ": Redefinition of parameter \'" << $2->getName() << "\'\n";
			error_count++;
		}
	}
	| type_specifier ID LPAREN error RPAREN SEMICOLON
	{
		logout << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n";
		$$ = new SymbolInfo("", "func_declaration", $1->getLineStart(), $6->getLineEnd());
		$$->setRule("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
		$$->addChild($6);
		$2->setSymbolType(FUNCTION);
		$2->setDataType($1->getDataType());
		if(!symbolTable->insert($2))
		{
			errorout << "Line# " << line_count << ": Redefinition of parameter \'" << $2->getName() << "\'\n";
			error_count++;
		}
	}
	; 
func_definition : 
	type_specifier ID LPAREN parameter_list RPAREN 
	{ 
		for (auto item: $4->getListItem())
		{
			$2->addParamFunc(item);
		}
		$2->setSymbolType(FUNCTION);
		$2->setDataType($1->getDataType());
		tempParamList.clear();
		temp_line = line_count;
		for (auto item: $4->getListItem())
		{
			tempParamList.push_back(item);
		}
		SymbolInfo *temp = symbolTable->lookup($2->getName());
		if (temp && temp->getSymbolType() != $2->getSymbolType())
		{
			errorout << "Line# " << line_count << ": \'" << $2->getName() << "\' redeclared as different kind of symbol\n";
			error_count++;
		}
		else if(temp && (temp->getDataType() != $2->getDataType() || temp->getParamFunc().size() != tempParamList.size()))
		{
			errorout << "Line# " << line_count << ": Conflicting types for \'" << $2->getName() << "\'\n";
			error_count++;
		}
	} 
	compound_statement
	{
		logout << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
		$$ = new SymbolInfo("", "func_declaration", $1->getLineStart(), $7->getLineEnd());
		$$->setRule("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
		$$->addChild($7);
		symbolTable->insert($2);
	}
	| type_specifier ID LPAREN RPAREN
	{
		$2->setSymbolType(FUNCTION);
		$2->setDataType($1->getDataType());
		tempParamList.clear();
		SymbolInfo *temp = symbolTable->lookup($2->getName());
		if (temp && temp->getSymbolType() != $2->getSymbolType())
		{
			errorout << "Line# " << line_count << ": \'" << $2->getName() << "\' redeclared as different kind of symbol\n";
			error_count++;
		}
		else if(temp && (temp->getDataType() != $2->getDataType() || temp->getParamFunc().size()))
		{
			errorout << "Line# " << line_count << ": Conflicting types for \'" << $2->getName() << "\'\n";
			error_count++;
		}
	}
	compound_statement
	{
		logout << "func_definition : type_specifier ID LPAREN RPAREN compound_statement\n";
		$$ = new SymbolInfo("", "func_declaration", $1->getLineStart(), $6->getLineEnd());
		$$->setRule("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($6);
		symbolTable->insert($2);
	}
	|
	type_specifier ID LPAREN parameter_list error RPAREN 
	{ 
		$2->setSymbolType(FUNCTION);
		$2->setDataType($1->getDataType());
		tempParamList.clear();
		temp_line = line_count;
		for (auto item: $4->getListItem())
		{
			tempParamList.push_back(item);
		}
		SymbolInfo *temp = symbolTable->lookup($2->getName());
		if (temp && temp->getSymbolType() != $2->getSymbolType())
		{
			errorout << "Line# " << line_count << ": \'" << $2->getName() << "\' redeclared as different kind of symbol\n";
			error_count++;
		}
		else if(temp && (temp->getDataType() != $2->getDataType() || temp->getParamFunc().size()))
		{
			errorout << "Line# " << line_count << ": Conflicting types for \'" << $2->getName() << "\'\n";
			error_count++;
		}
	} 
	compound_statement
	{
		$$ = new SymbolInfo("", "func_declaration", $1->getLineStart(), $8->getLineEnd());
		$$->setRule("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
		$$->addChild($8);
	}
 	;				
parameter_list : 
	parameter_list COMMA type_specifier ID
	{
		logout << "parameter_list : parameter_list COMMA type_specifier ID\n";
		$$ = new SymbolInfo("", "parameter_list", $1->getLineStart(), $4->getLineEnd());
		$$->setRule("parameter_list : parameter_list COMMA type_specifier ID");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$4->setDataType($3->getDataType());
		$4->setSymbolType(VARIABLE);
		for(auto item: $1->getListItem())
		{
			$$->addItem(item);
		}
		$$->addItem($4);
	}
	| parameter_list COMMA type_specifier
	{
		logout << "parameter_list : parameter_list COMMA type_specifier\n";
		$$ = new SymbolInfo("", "parameter_list", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("parameter_list : parameter_list COMMA type_specifier");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		for(auto item: $1->getListItem())
		{
			$$->addItem(item);
		}
		SymbolInfo *temp = new SymbolInfo("NN", "ID", $3->getLineStart(), $3->getLineEnd());
		temp->setDataType($3->getDataType());
		$$->addItem(temp);
	}
 	| type_specifier ID
	{
		logout << "parameter_list : type_specifier ID\n";
		$$ = new SymbolInfo("", "parameter_list", $1->getLineStart(), $2->getLineEnd());
		$$->setRule("parameter_list : type_specifier ID");
		$$->addChild($1);
		$$->addChild($2);
		$2->setDataType($1->getDataType());
		$2->setSymbolType(VARIABLE);
		$$->addItem($2);
	}
	| type_specifier
	{
		logout << "parameter_list : type_specifier\n";
		$$ = new SymbolInfo("", "parameter_list", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("parameter_list : type_specifier");
		$$->addChild($1);
		SymbolInfo *temp = new SymbolInfo("NN", "ID", $1->getLineStart(), $1->getLineEnd());
		temp->setDataType($1->getDataType());
		$$->addItem(temp);
	}
 	;
compound_statement : 
	LCURL 
	{
		symbolTable->enterScope(BUCKET_SIZE);
		for (auto item: tempParamList)
		{
			if(!symbolTable->insert(item))
			{
				errorout << "Line# " << temp_line << ": Redefinition of parameter \'" << item->getName() << "\'\n";
				error_count++;
				break;
			}
		}
	}
	statements RCURL
	{
		logout << "compound_statement : LCURL statements RCURL\n";
		$$ = new SymbolInfo("", "compound_statement", $1->getLineStart(), $4->getLineEnd());
		$$->setRule("compound_statement : LCURL statements RCURL");
		$$->addChild($1);
		$$->addChild($3);
		$$->addChild($4);
		symbolTable->printCurrentScope(logout);
		symbolTable->printParentScope(logout);
		symbolTable->exitScope();
	}
 	| LCURL 
	{
		symbolTable->enterScope(BUCKET_SIZE);
		for (auto item: tempParamList)
		{
			if(!symbolTable->insert(item))
			{
				errorout << "Line# " << temp_line << ": Redefinition of parameter \'" << item->getName() << "\'\n";
				error_count++;
				break;
			}
		}
	}
	RCURL
	{
		logout << "compound_statement : LCURL RCURL\n";
		$$ = new SymbolInfo("", "compound_statement", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("compound_statement : LCURL RCURL");
		$$->addChild($1);
		$$->addChild($3);
		symbolTable->printCurrentScope(logout);
		symbolTable->printParentScope(logout);
		symbolTable->exitScope();
	}
 	;	    
var_declaration : 
	type_specifier declaration_list SEMICOLON
	{
		logout << "var_declaration : type_specifier declaration_list SEMICOLON\n";
		$$ = new SymbolInfo("", "var_declaration", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("var_declaration : type_specifier declaration_list SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		for(auto item: $2->getListItem())
		{
			item->setDataType($1->getDataType());
			SymbolInfo *temp = symbolTable->lookup(item->getName());
			if(item->getDataType() == "VOID")
			{
				errorout << "Line# " << item->getLineStart() << ": Variable or field \'" << item->getName() << "\' declared void\n";
				error_count++;
			}
			else if (temp && temp->getDataType() != item->getDataType())
			{
				errorout << "Line# " << item->getLineStart() << ": Conflicting types for\'" << item->getName() << "'\n";
				error_count++;
			}
			else if(!symbolTable->insert(item))
			{
				errorout << "Line# " << item->getLineStart() << ": Redefinition of parameter \'" << item->getName() << "\'\n";
				error_count++;
			}
		}
	}
	| type_specifier declaration_list error SEMICOLON
	{
		logout << "var_declaration : type_specifier declaration_list SEMICOLON\n";
		$$ = new SymbolInfo("", "var_declaration", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("var_declaration : type_specifier declaration_list SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		for(auto item: $2->getListItem())
		{
			item->setDataType($1->getDataType());
			SymbolInfo *temp = symbolTable->lookup(item->getName());
			if(item->getDataType() == "VOID")
			{
				errorout << "Line# " << item->getLineStart() << ": Variable or field \'" << item->getName() << "\' declared void\n";
				error_count++;
			}
			else if (temp && temp->getDataType() != item->getDataType())
			{
				errorout << "Line# " << item->getLineStart() << ": Conflicting types for\'" << item->getName() << "'\n";
				error_count++;
			}
			else if(!symbolTable->insert(item))
			{
				errorout << "Line# " << item->getLineStart() << ": Redefinition of parameter \'" << item->getName() << "\'\n";
				error_count++;
			}
		}
	}
	| type_specifier error SEMICOLON
	{
		logout << "var_declaration : type_specifier declaration_list SEMICOLON\n";
		$$ = new SymbolInfo("", "var_declaration", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("var_declaration : type_specifier declaration_list SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
	}
 	;	 
type_specifier	: 
	INT
	{
		logout << "type_specifier : INT\n";
		$$ = new SymbolInfo("INT", "type_specifier", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("type_specifier : INT");
		$$->addChild($1);
		$$->setDataType("INT");
	}
 	| FLOAT
	{
		logout << "type_specifier : FLOAT\n";
		$$ = new SymbolInfo("FLOAT", "type_specifier", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("type_specifier : FLOAT");
		$$->addChild($1);
		$$->setDataType("FLOAT");
	}
 	| VOID
	{
		logout << "type_specifier : VOID\n";
		$$ = new SymbolInfo("VOID", "type_specifier", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("type_specifier : VOID");
		$$->addChild($1);
		$$->setDataType("VOID");
	}
 	;
declaration_list : 
	declaration_list COMMA ID
	{
		logout << "declaration_list : declaration_list COMMA ID\n";
		$$ = new SymbolInfo("", "declaration_list", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("declaration_list : declaration_list COMMA ID");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		for(auto item: $1->getListItem())
		{
			$$->addItem(item);
		}
		$$->addItem($3);
		$3->setSymbolType(VARIABLE);
	}
 	| declaration_list COMMA ID LSQUARE CONST_INT RSQUARE 
	{
		logout << "declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE\n";
		$$ = new SymbolInfo("", "declaration_list", $1->getLineStart(), $6->getLineEnd());
		$$->setRule("declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
		$$->addChild($6);
		for(auto item: $1->getListItem())
		{
			$$->addItem(item);
		}
		$$->addItem($3);
		$3->setSymbolType(ARRAY);
	}
 	| ID
	{
		logout << "declaration_list : ID\n";
		$$ = new SymbolInfo("", "declaration_list", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("declaration_list : ID");
		$$->addChild($1);
		$$->addItem($1);
		$1->setSymbolType(VARIABLE);
	}
 	| ID LSQUARE CONST_INT RSQUARE
	{
		logout << "declaration_list : ID LSQUARE CONST_INT RSQUARE\n";
		$$ = new SymbolInfo("", "declaration_list", $1->getLineStart(), $4->getLineEnd());
		$$->setRule("declaration_list : ID LSQUARE CONST_INT RSQUARE");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addItem($1);
		$1->setSymbolType(ARRAY);
	}
 	;
statements : 
	statement
	{
		logout << "statements : statement\n";
		$$ = new SymbolInfo("", "statements", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("statements : statement");
		$$->addChild($1);
	}
	| statements statement
	{
		logout << "statements : statements statement\n";
		$$ = new SymbolInfo("", "statements", $1->getLineStart(), $2->getLineEnd());
		$$->setRule("statements : statements statement");
		$$->addChild($1);
		$$->addChild($2);
	}
	;
	   
statement : 
	var_declaration
	{
		logout << "statement : var_declaration\n";
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("statement : var_declaration");
		$$->addChild($1);	
	}
	| expression_statement
	{
		logout << "statement : expression_statement\n";	
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("statement : expression_statement");
		$$->addChild($1);
	}
	| compound_statement
	{
		logout << "statement : compound_statement\n";
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("statement : compound_statement");
		$$->addChild($1);	
	}
	| FOR LPAREN expression_statement expression_statement expression RPAREN statement
	{
		logout << "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n";	
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $7->getLineEnd());
		$$->setRule("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
		$$->addChild($6);
		$$->addChild($7);	
	}
	| IF LPAREN expression RPAREN statement
	{
		logout << "statement : IF LPAREN expression RPAREN statement\n";	
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $5->getLineEnd());
		$$->setRule("statement : IF LPAREN expression RPAREN statement");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
	}
	| IF LPAREN expression RPAREN statement ELSE statement
	{
		logout << "statement : IF LPAREN expression RPAREN statement ELSE statement\n";	
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $7->getLineEnd());
		$$->setRule("statement : IF LPAREN expression RPAREN statement ELSE statement");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
		$$->addChild($6);
		$$->addChild($7);
	}
	| WHILE LPAREN expression RPAREN statement
	{
		logout << "statement : WHILE LPAREN expression RPAREN statement\n";	
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $5->getLineEnd());
		$$->setRule("statement : WHILE LPAREN expression RPAREN statement");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);
	}
	| PRINTLN LPAREN ID RPAREN SEMICOLON
	{
		logout << "statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n";	
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $5->getLineEnd());
		$$->setRule("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		$$->addChild($5);	
	}
	| RETURN expression SEMICOLON
	{
		logout << "statement : RETURN expression SEMICOLON\n";	
		$$ = new SymbolInfo("", "statement", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("statement : RETURN expression SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
	}
	; 
expression_statement : 
	SEMICOLON			
	{
		logout << "expression_statement : SEMICOLON\n";	
		$$ = new SymbolInfo("", "expression_statement", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("expression_statement : SEMICOLON");
		$$->addChild($1);
	}
	| expression SEMICOLON 
	{
		logout << "expression_statement : expression SEMICOLON\n";	
		$$ = new SymbolInfo("", "expression_statement", $1->getLineStart(), $2->getLineEnd());
		$$->setRule("expression_statement : expression SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
	}
	| error SEMICOLON
	{
		logout << "expression_statement : expression SEMICOLON\n";	
		$$ = new SymbolInfo("", "expression_statement", $1->getLineStart(), $2->getLineEnd());
		$$->setRule("expression_statement : expression SEMICOLON");
		$$->addChild($1);
		$$->addChild($2);
	}
	;
variable : 
	ID
	{
		logout << "variable : ID\n";
		$$ = new SymbolInfo("", "variable", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("variable : ID");
		$$->addChild($1);	
		SymbolInfo *temp = symbolTable->lookupAll($1->getName());
		if(!temp)
		{
			errorout << "Line# " << $1->getLineStart() << ": Undeclared variable \'" << $1->getName() << "\'\n";
			error_count++;
		}
		else
		{
			$$->setSymbolType(temp->getSymbolType());
			$1->setSymbolType(temp->getSymbolType());
			$$->setDataType(temp->getDataType());
			$1->setDataType(temp->getDataType());
			$1->setValue(temp->getValue());
			$$->setValue(temp->getValue());
		}
	}
	| ID LSQUARE expression RSQUARE
	{
		logout << "variable : ID LSQUARE expression RSQUARE\n";	
		$$ = new SymbolInfo("", "variable", $1->getLineStart(), $4->getLineEnd());
		$$->setRule("variable : ID LSQUARE expression RSQUARE");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		SymbolInfo *temp = symbolTable->lookupAll($1->getName());
		if($3->getDataType() != "INT" && ($3->getSymbolType() != ARRAY && $3->getSymbolType() != FUNCTION))
		{
			errorout << "Line# " << $1->getLineStart() << ": Array subscript is not an integer\n";
			error_count++;
		}
		if(!temp)
		{
			errorout << "Line# " << $1->getLineStart() << ": Undeclared variable \'" << $1->getName() << "\'\n";
			error_count++;
		}
		else if (temp->getSymbolType() != ARRAY)
		{
			errorout << "Line# " << $1->getLineStart() << ": \'" << $1->getName() << "\' is not an array\n";
			error_count++;
		}
		else
		{
			$$->setDataType(temp->getDataType());
			$1->setDataType(temp->getDataType());
			$$->setSymbolType(VARIABLE);
			$1->setSymbolType(ARRAY);
		};
	}
	;
 expression : 
 	logic_expression 
	{
		logout << "expression : logic_expression\n";
		$$ = new SymbolInfo("", "expression", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("expression : logic_expression");
		$$->addChild($1);
		$$->setDataType($1->getDataType());
		$$->setSymbolType($1->getSymbolType());
	}
	| variable ASSIGNOP logic_expression 
	{
		logout << "expression : variable ASSIGNOP logic_expression\n";
		$$ = new SymbolInfo("", "expression", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("expression : variable ASSIGNOP logic_expression");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		if($3->getSymbolType() == ARRAY || $3->getSymbolType() == FUNCTION || $1->getSymbolType() == ARRAY || $1->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if($1->getDataType() == "VOID" || $3->getDataType() == "VOID")
		{
			errorout << "Line# " << $1->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else
		{
			$$->setDataType("INT");
		}
		if($1->getDataType() == "INT" && $3->getDataType() == "FLOAT")
		{
			errorout << "Line# " << $1->getLineStart() << ": Warning: possible loss of data in assignment of FLOAT to INT\n";
			error_count++;
		}
	}
	;
logic_expression : 
	rel_expression 
	{
		logout << "logic_expression : rel_expression\n";
		$$ = new SymbolInfo("", "logic_expression", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("logic_expression : rel_expression");
		$$->addChild($1);
		$$->setDataType($1->getDataType());
		$$->setValue($1->getValue());
		$$->setSymbolType($1->getSymbolType());
	}
	| rel_expression LOGICOP rel_expression 
	{
		logout << "logic_expression : rel_expression LOGICOP rel_expression\n";
		$$ = new SymbolInfo("", "logic_expression", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("logic_expression : rel_expression LOGICOP rel_expression");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		if($3->getSymbolType() == ARRAY || $3->getSymbolType() == FUNCTION || $1->getSymbolType() == ARRAY || $1->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if($1->getDataType() == "VOID" || $3->getDataType() == "VOID")
		{
			errorout << "Line# " << $1->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else
		{
			$$->setDataType("INT");
		}
	}	
	;
rel_expression : 
	simple_expression 
	{
		logout << "rel_expression : simple_expression\n";	
		$$ = new SymbolInfo("", "rel_expression", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("rel_expression : simple_expression");
		$$->addChild($1);
		$$->setDataType($1->getDataType());
		$$->setValue($1->getValue());
		$$->setSymbolType($1->getSymbolType());
	}
	| simple_expression RELOP simple_expression	
	{
		logout << "rel_expression : simple_expression RELOP simple_expression\n";	
		$$ = new SymbolInfo("", "rel_expression", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("rel_expression : simple_expression RELOP simple_expression");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		if($3->getSymbolType() == ARRAY || $3->getSymbolType() == FUNCTION || $1->getSymbolType() == ARRAY || $1->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if($1->getDataType() == "VOID" || $3->getDataType() == "VOID")
		{
			errorout << "Line# " << $1->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else
		{
			$$->setDataType("INT");
		}
	}
	;			
simple_expression : 
	term 
	{
		logout << "simple_expression : term\n";
		$$ = new SymbolInfo("", "simple_expression", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("simple_expression : term");
		$$->addChild($1);
		$$->setDataType($1->getDataType());
		$$->setValue($1->getValue());
		$$->setSymbolType($1->getSymbolType());
	}
	| simple_expression ADDOP term 
	{
		logout << "simple_expression : simple_expression ADDOP term\n";
		$$ = new SymbolInfo("", "simple_expression", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("simple_expression : simple_expression ADDOP term");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		if($3->getSymbolType() == ARRAY || $3->getSymbolType() == FUNCTION || $1->getSymbolType() == ARRAY || $1->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if($1->getDataType() == "VOID" || $3->getDataType() == "VOID")
		{
			errorout << "Line# " << $1->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else if($1->getDataType() == "FLOAT" || $3->getDataType() == "FLOAT")
		{
			$$->setDataType("FLOAT");
		}
		else
		{
			$$->setDataType("INT");
		}
	}
	;				
term :	
	unary_expression 
	{
		logout << "term : unary_expression\n";
		$$ = new SymbolInfo("", "term", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("term : unary_expression");
		$$->addChild($1);
		$$->setDataType($1->getDataType());
		$$->setValue($1->getValue());
		$$->setSymbolType($1->getSymbolType());
	}
    |  term MULOP unary_expression
	{
		logout << "term : term MULOP unary_expression\n";
		$$ = new SymbolInfo("", "term", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("term : term MULOP unary_expression");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		if($3->getSymbolType() == ARRAY || $3->getSymbolType() == FUNCTION || $1->getSymbolType() == ARRAY || $1->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if(($2->getName() == "%" || $2->getName() == "/") && $3->getValue() == 0)
		{
			errorout << "Line# " << $1->getLineStart() << ": Warning: division by zero\n";
			error_count++;
		}
		else if($2->getName() == "%" && ($3->getDataType() != "INT" || $1->getDataType() != "INT"))
		{
			errorout << "Line# " << $1->getLineStart() << ": Operands of modulus must be integers\n";
			error_count++;
		}
		else if($1->getDataType() == "VOID" || $3->getDataType() == "VOID")
		{
			errorout << "Line# " << $1->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else if($1->getDataType() == "FLOAT" || $3->getDataType() == "FLOAT")
		{
			$$->setDataType("FLOAT");
		}
		else
		{
			$$->setDataType("INT");
		}
	}
    ;
unary_expression : 
	ADDOP unary_expression 
	{
		logout << "unary_expression : ADDOP unary_expression\n";
		$$ = new SymbolInfo("", "unary_expression", $1->getLineStart(), $2->getLineEnd());
		$$->setRule("unary_expression : ADDOP unary_expression");
		$$->addChild($1);
		$$->addChild($2);
		if($2->getDataType() == "VOID")
		{
			errorout << "Line# " << $1->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else if($2->getSymbolType() == ARRAY || $2->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else
		{
			$$->setDataType($2->getDataType());
		}
	} 
	| NOT unary_expression 
	{
		logout << "unary_expression : NOT unary_expression\n";
		$$ = new SymbolInfo("", "unary_expression", $1->getLineStart(), $2->getLineEnd());
		$$->setRule("unary_expression : NOT unary_expression");
		$$->addChild($1);
		$$->addChild($2);
		if($2->getDataType() == "VOID")
		{
			errorout << "Line# " << $1->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else if($2->getSymbolType() == ARRAY || $2->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else
		{
			$$->setDataType($2->getDataType());
		}
	}
	| factor 
	{
		logout << "unary_expression : factor\n";
		$$ = new SymbolInfo("", "unary_expression", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("unary_expression : factor");
		$$->addChild($1);
		$$->setDataType($1->getDataType());
		$$->setValue($1->getValue());
		$$->setSymbolType($1->getSymbolType());
	}
	;
factor	: 
	variable 
	{
		logout << "factor : variable\n";
		$$ = new SymbolInfo("", "factor", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("factor : variable");
		$$->addChild($1);
		$$->setDataType($1->getDataType());
		$$->setSymbolType($1->getSymbolType());
	}
	| ID LPAREN argument_list RPAREN
	{
		logout << "factor : ID LPAREN argument_list RPAREN\n";
		$$ = new SymbolInfo("", "factor", $1->getLineStart(), $4->getLineEnd());
		$$->setRule("factor : ID LPAREN argument_list RPAREN");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->addChild($4);
		SymbolInfo *temp = symbolTable->lookupAll($1->getName());
		if (temp && temp->getSymbolType() == FUNCTION)
		{
			$$->setDataType(temp->getDataType());
			if (temp->getParamFunc().size() > $3->getListItem().size())
			{
				errorout << "Line# " << $1->getLineStart() << ": Too few arguments to function \'" << temp->getName() << "\'\n";
				error_count++;
			}
			else if (temp->getParamFunc().size() < $3->getListItem().size())
			{
				errorout << "Line# " << $1->getLineStart() << ": Too many arguments to function \'" << temp->getName() << "\'\n";
				error_count++;
			}
			else 
			{
				for (int i = 0; i < temp->getParamFunc().size(); i++)
				{
					if (temp->getParamFunc()[i]->getDataType() != $3->getListItem()[i]->getDataType())
					{
						errorout << "Line# " << $3->getListItem()[i]->getLineStart() << ": Type mismatch for argument " << i + 1 << " of \'" << temp->getName() << "\'\n";
						error_count++;
					}
				}
			}
		}
		else 
		{
			errorout << "Line# " << $1->getLineStart() << ": Undeclared function \'" << $1->getName() << "\'\n";
			error_count++;
		}
	}
	| LPAREN expression RPAREN
	{
		logout << "factor : LPAREN expression RPAREN\n";
		$$ = new SymbolInfo("", "factor", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("factor : LPAREN expression RPAREN");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		$$->setDataType($2->getDataType());
	}
	| CONST_INT 
	{
		logout << "factor : CONST_INT\n";
		$$ = new SymbolInfo("", "factor", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("factor : CONST_INT");
		$$->addChild($1);
		$$->setDataType("INT");
		$$->setValue($1->getValue());
	}
	| CONST_FLOAT 
	{
		logout << "factor : CONST_FLOAT\n";
		$$ = new SymbolInfo("", "factor", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("factor : CONST_FLOAT");
		$$->addChild($1);
		$$->setDataType("FLOAT");
		$$->setValue($1->getValue());
	}
	| variable INCOP 
	{
		logout << "factor : variable INCOP\n";
		$$ = new SymbolInfo("", "factor", $1->getLineStart(), $2->getLineEnd());
		$$->setRule("factor : variable INCOP");
		$$->addChild($1);
		$$->addChild($2);
		if($1->getSymbolType() == ARRAY || $1->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else 
		{
			$$->setDataType($1->getDataType());
			$$->setValue($1->getValue() + 1);
		}
	}
	| variable DECOP 
	{
		logout << "factor : variable DECOP\n";
		$$ = new SymbolInfo("", "factor", $1->getLineStart(), $2->getLineEnd());
		$$->setRule("factor : variable DECOP");
		$$->addChild($1);
		$$->addChild($2);
		if($1->getSymbolType() == ARRAY || $1->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << $1->getLineStart() << ": \'" << $1->getName() << "\' Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else 
		{
			$$->setDataType($1->getDataType());
			$$->setValue($1->getValue() - 1);
		}
	}
	;
argument_list : 
	arguments
	{
		logout << "argument_list : arguments\n";
		$$ = new SymbolInfo("", "argument_list", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("argument_list : arguments");
		$$->addChild($1);
		for (auto item: $1->getListItem())
		{
			$$->addItem(item);
		}
	}
	| 
	{
		$$ = new SymbolInfo("", "argument_list", line_count, line_count);
	}
	;
	
arguments : 
	arguments COMMA logic_expression
	{
		logout << "arguments : arguments COMMA logic_expression\n";
		$$ = new SymbolInfo("", "arguments", $1->getLineStart(), $3->getLineEnd());
		$$->setRule("arguments : arguments COMMA logic_expression");
		$$->addChild($1);
		$$->addChild($2);
		$$->addChild($3);
		for (auto item: $1->getListItem())
		{
			$$->addItem(item);
		}
		$$->addItem($3);
	}
	| logic_expression
	{
		logout << "arguments : logic_expression\n";
		$$ = new SymbolInfo("", "arguments", $1->getLineStart(), $1->getLineEnd());
		$$->setRule("arguments : logic_expression");
		$$->addChild($1);
		$$->addItem($1);
	}
	;
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
	line_count = 1;
	error_count = 0;
	logout.open("logout.txt");
	errorout.open("error.txt");
	parseout.open("parsetree.txt");
        symbolTable = new SymbolTable(new ScopeTable(BUCKET_SIZE, NULL));
	yyin = fin;
	yyparse();
	fclose(yyin);
	errorout.close();
	logout <<"Total Lines: "<< line_count<<"\n";
	logout <<"Total Errors: "<< error_count<<"\n";
	logout.close();
	parseout.close();
	return 0;
}


