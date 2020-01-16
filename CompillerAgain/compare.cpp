#include "compare.h"
#include "terminal.h"


compare::compare(){
	//Empty implementation
}


compare::~compare(){
	//Empty implementation
}
// <compare> ::= > | < | == | != | >= | <=
void compare::deriving(int pos) {
	if (lexStream[pos].type == DIVIDE && lexStream[pos + 1].type == DIVIDE) {
		if ((Dividers[lexStream[pos].numInValidTable].val == "=" && Dividers[lexStream[pos+1].numInValidTable].val == "=")||
			(Dividers[lexStream[pos].numInValidTable].val == "<" && Dividers[lexStream[pos].numInValidTable].val == "=")||
			(Dividers[lexStream[pos].numInValidTable].val == ">" && Dividers[lexStream[pos].numInValidTable].val == "=") ||
			(Dividers[lexStream[pos].numInValidTable].val == "!" && Dividers[lexStream[pos].numInValidTable].val == "=")) {
			symbol* newLeaf_1 = new terminal(Dividers[lexStream[pos].numInValidTable].val);
			symbol* newLeaf_2 = new terminal(Dividers[lexStream[pos+1].numInValidTable].val);
			newLeaf_1->setParent(this);
			newLeaf_2->setParent(this);
			_childs.push_back(newLeaf_1);
			_childs.push_back(newLeaf_2);
		}
		else {
			cout << "Error: expected an operator" << endl;
			return;
		}
	}
	else {
		if (lexStream[pos].type == DIVIDE) {
			if (Dividers[lexStream[pos].numInValidTable].val == ">" || Dividers[lexStream[pos].numInValidTable].val == "<") {
				symbol* newLeaf = new terminal(Dividers[lexStream[pos].numInValidTable].val);
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);
			}
			else {
				cout << "Error: expected an operator" << endl;
				return;
			}
		}
		else {
			cout << "Error: expected an operator" << endl;
			return;
		}
	}
}