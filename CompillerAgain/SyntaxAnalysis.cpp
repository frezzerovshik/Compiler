#include "SyntaxAnalysis.h"
#include "S.h"
#include "symbol.h"

using namespace std;

/*
#define MARK 0
#define BOOL 1
#define OP 2
#define INT 3
#define VAL 4
#define ADDR 5
*/

bool SyntaxAnalysis::check_vector(vector<symbol*> line, vector<token>* polis) {
	for (int i = 0; i < line.size(); ++i) {
		if (line[i]->getFlag()) {
			if (isDivider(line[i]->_value)) {
				if (isOperator(line[i]->_value)) {
					token newTokenOperation(OP, line[i]->_value);
					int typeOperand = isConst(line[i - 1]->_value) == true ? INT : VAL;
					token firstOperand(typeOperand, line[i - 1]->_value);
					if (i + 1 == line.size() - 1) {
						typeOperand = isConst(line[i + 1]->_value) == true ? INT : VAL;
						token secondOperand(typeOperand, line[i + 1]->_value);
						polis->push_back(firstOperand);
						polis->push_back(secondOperand);
						polis->push_back(newTokenOperation);
					}
					else {
						break;
					}
				}
			}
			else {
				continue;
			}
			check_vector(line[i]->_childs, polis);
		}
		else {
			continue;
		}
		
	}
}
SyntaxAnalysis::SyntaxAnalysis()
{
}


SyntaxAnalysis::~SyntaxAnalysis()
{
}

symbol* SyntaxAnalysis::treeMake() {
	symbol* startSymbol = new S;
	try {
		startSymbol->deriving(0);
		cout << "Successful syntax analysis" << endl;
	}
	catch (...) {
		cout << "Unsuccessful syntax analysis" << endl;
	
	}
}

vector<token> SyntaxAnalysis::reversePolishNotationMake() {
	vector<token> reversePolishNotation;
	root = treeMake();
	check_vector(root->_childs, &reversePolishNotation);
	return reversePolishNotation;
}

