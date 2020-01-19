#include "expr.h"
#include "term.h"
#include "call_func.h"
#include "terminal.h"

expr::expr(){
}


expr::~expr(){
}


// <expr> ::=< expr> +< term> |< expr>  – <term> |< term> | <call_func>
// <factor> ::= (<expr>)|<loc>|<num>|true|false
//<term> ::=< term>*<factor> |< term>/<factor> |< factor>
void expr::deriving(int pos) {
	vector<LEX> expression;
	for (int i = pos; i < lexStream.size(); ++i) {
		if (!(lexStream[i].type == DIVIDE && Dividers[lexStream[i].numInValidTable].val == ";")) {
			expression.push_back(lexStream[i]);
		}
		else
			break;
	}
	for (int i = 0; i < expression.size(); ++i) {
		if (expression[i].type == DIVIDE && (Dividers[expression[i].numInValidTable].val == "+" || Dividers[expression[i].numInValidTable].val == "-") && i != 0) {
			symbol* op1 = new expr;
			op1->setParent(this);
			_childs.push_back(op1);
			op1->deriving(i - 1);

			symbol* operand = new terminal(Dividers[expression[i].numInValidTable].val);
			operand->setParent(this);
			_childs.push_back(operand);

			symbol* op2 = new term;
			op2->setParent(this);
			_childs.push_back(op2);
			op2->deriving(i+1);
			break;
		}
	}

}