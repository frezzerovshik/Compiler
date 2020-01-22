#include "stmt.h"
#include "ass.h"
#include "cycle_stmt.h"
#include "if_stmt.h"


stmt::stmt(){
}


stmt::~stmt(){
}

// < stmt>:: = <ass> | <cycle_stmt> | <if_stmt>
void stmt::deriving(int pos) {
	if (lexStream[pos].type == KEY_WORD && KeyWords[lexStream[pos].numInValidTable].val == "IF") {
		symbol* newNode = new if_stmt;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos);
	}
	else {
		if (lexStream[pos].type == KEY_WORD && 
			(KeyWords[lexStream[pos].numInValidTable].val == "WHILE" || 
				KeyWords[lexStream[pos].numInValidTable].val == "DO" || 
				KeyWords[lexStream[pos].numInValidTable].val == "FOR")) {
			symbol* newNode = new cycle_stmt;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos);
		}
		else {
			symbol* newNode = new ass;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos);
		}
	}
	cout << "stmt" << endl;
}