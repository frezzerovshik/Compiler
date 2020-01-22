#include "args.h"
#include "arg.h"


args::args(){
}


args::~args(){
}

// <args> :: = <args><arg> 
// <arg> :: = (<type> <id>, | <type>< id>); | <type><id>
void args::deriving(int pos) {
	if ((lexStream[pos].type == DIVIDE && Dividers[lexStream[pos].numInValidTable].val == "(") &&
		(lexStream[pos+1].type == KEY_WORD && (KeyWords[lexStream[pos+1].numInValidTable].val == "bool" || KeyWords[lexStream[pos+1].numInValidTable].val == "integer")) &&
		lexStream[pos+2].type == IDENT &&
		(lexStream[pos+3].type == DIVIDE && Dividers[lexStream[pos+3].numInValidTable].val == ",")) {

		symbol* newNode = new arg;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos);
		if (lexStream[pos + 4].type == KEY_WORD && (KeyWords[lexStream[pos + 4].numInValidTable].val == "bool" || KeyWords[lexStream[pos + 4].numInValidTable].val == "integer")) {
			symbol* newNode = new args;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos+4);
		}
	}
	else {
		// Error
	}
	cout << "args" << endl;
}