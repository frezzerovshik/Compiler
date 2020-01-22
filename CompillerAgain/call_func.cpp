#include "call_func.h"
#include "id.hpp"
#include "args.h"



call_func::call_func(){
	// Empty implementation
	setFlag(false);
}


call_func::~call_func(){
	// Empty implementation
}
// <call_func>::= <id><args>
void call_func::deriving(int pos) {
	if (lexStream[pos].type == IDENT) {
		if (lexStream[pos + 1].type == DIVIDE && Dividers[lexStream[pos + 1].numInValidTable].val == "(") {
			symbol* newNode_1 = new id;
			newNode_1->setParent(this);
			_childs.push_back(newNode_1);
			newNode_1->deriving(pos);
			symbol* newNode_2 = new args;
			newNode_2->setParent(this);
			_childs.push_back(newNode_1);
			newNode_2->deriving(pos+1);
		}
		else {
			cout << "Error : expected (" << endl;
			throw 1;
			return;
		}
	}
	else {
		cout << "Error : expected id" << endl;
		throw 1;
		return;
	}
	cout << "call func" << endl;
}