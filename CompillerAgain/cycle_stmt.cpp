#include "cycle_stmt.h"
#include "while_stmt.h"
#include "for_stmt.h"

cycle_stmt::cycle_stmt(){
	//Empty implementation
}


cycle_stmt::~cycle_stmt(){
	//Empty implementation
}
// <cycle_stmt>::= <for_stmt> | <while_stmt>
void cycle_stmt::deriving(int pos) {
	if (lexStream[pos].type == KEY_WORD) {
		if (KeyWords[lexStream[pos].numInValidTable].val == "FOR") {
			symbol* newNode = new for_stmt;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos);
		}
		else {
			if (KeyWords[lexStream[pos].numInValidTable].val == "WHILE") {
				symbol* newNode = new while_stmt;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos);
			}
			else {
				cout << "Error: expected loop constuction" << endl;
				return;
			}
		}
	}
	else {
		cout << "Error: expected loop constuction" << endl;
		return;
	}
}
