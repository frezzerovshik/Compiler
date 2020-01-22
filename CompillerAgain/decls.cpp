#include "decls.h"
#include "decl.hpp"


decls::decls(){
	//Empty implementation
}
decls::~decls(){
	//Empty implementation
}
// <decls>::=<decls><decl> | <decl>
// <decl>::=<type><loc>;
// <loc>::=<loc>[<nums>] | <id>
void decls::deriving(int pos) {
	if (lexStream[pos].type == KEY_WORD && (KeyWords[lexStream[pos].numInValidTable].val == "integer" || KeyWords[lexStream[pos].numInValidTable].val == "bool") &&
		lexStream[pos + 1].type == IDENT &&
		(lexStream[pos + 2].type == DIVIDE && (Dividers[lexStream[pos + 2].numInValidTable].val == ";"))
		) {
		symbol* newNode = new decl;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos);
		if (lexStream[pos+3].type == KEY_WORD && (KeyWords[lexStream[pos+3].numInValidTable].val == "integer" || KeyWords[lexStream[pos+3].numInValidTable].val == "bool")) {
			symbol* newNode = new decls;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos+3);
		}
	}
	cout << "decls" << endl;
}
