#include "unary.h"
#include "terminal.h"


unary::unary(){
	//Emty implementation
	setFlag(false);
}


unary::~unary(){
	//Emty implementation
}

void unary::deriving(int pos) {
	if (lexStream[pos].type == DIVIDE && lexStream[pos + 1].type == DIVIDE) {
		if ((Dividers[lexStream[pos].numInValidTable].val == "+" && Dividers[lexStream[pos + 1].numInValidTable].val == "+") ||
			(Dividers[lexStream[pos].numInValidTable].val == "-" && Dividers[lexStream[pos + 1].numInValidTable].val == "-")
			) {
			symbol* newLeaf_1 = new terminal(Dividers[lexStream[pos].numInValidTable].val);
			symbol* newLeaf_2 = new terminal(Dividers[lexStream[pos + 1].numInValidTable].val);
			newLeaf_1->setParent(this);
			newLeaf_2->setParent(this);
			_childs.push_back(newLeaf_1);
			_childs.push_back(newLeaf_2);
		}
		else {
			cout << "Error : characters must be equal" << endl;
			throw 1;
			return;
		}
	}
	else {
		cout << "Error : unexpected constuction" << endl;
		throw 1;
		return;
	}
	cout << "unary" << endl;
}