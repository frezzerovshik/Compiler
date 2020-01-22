#pragma once
#include <string>
#include <vector>
#include "parser.hpp"
#include "symbol.h"
#define MARK 0
#define BOOL 1
#define OP 2
#define INT 3
#define VAL 4
#define ADDR 5

class S;
typedef struct token {
	string val;
	int type;
	token();
	token(int _type, string _val);
}token;
class SyntaxAnalysis : public parser{
	symbol* root;
public:
	symbol* treeMake();
	vector<token> reversePolishNotationMake();
	SyntaxAnalysis();
	~SyntaxAnalysis();
	bool isIdentifier(string cmp);
	bool isConst(string cmp);
	bool isOperator(string cmp);
	bool check_vector(vector<symbol*> line, vector<token>* polis);
};

