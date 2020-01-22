#include "term.h"
#include "factor.h"
#include "terminal.h"

term::term()
{
}


term::~term(){

}

//<term> ::=< term>*<factor> |< term>/<factor> |< factor>
void term::deriving(int pos) {
	vector<LEX> expression;
	for (int i = pos; i < lexStream.size(); ++i) {
		if (!(lexStream[i].type == DIVIDE && Dividers[lexStream[i].numInValidTable].val == ";")) {
			expression.push_back(lexStream[i]);
		}
		else
			break;
	}
	bool flag = false;
	for (int i = 0; i < expression.size(); ++i) {
		if (expression[i].type == DIVIDE && (Dividers[expression[i].numInValidTable].val == "*" || Dividers[expression[i].numInValidTable].val == "/") && i != 0) {
			symbol* op1 = new term;
			op1->setParent(this);
			_childs.push_back(op1);
			op1->deriving(i - 1);

			symbol* operand = new terminal(Dividers[expression[i].numInValidTable].val);
			operand->setParent(this);
			_childs.push_back(operand);

			symbol* op2 = new factor;
			op2->setParent(this);
			_childs.push_back(op2);
			op2->deriving(i + 1);
			flag = true;
			break;
		}
	}
	if (flag == true) {
		symbol* op = new factor;
		op->setParent(this);
		_childs.push_back(op);
		op->deriving(pos);
	}
	cout << "term" << endl;
}
