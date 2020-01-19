#include "ass.h"
#include "loc.hpp"
#include "terminal.h"
#include "expr.h"
ass::ass(){
}


ass::~ass(){
}

// <ass> ::=< loc> = <expr>; | <loc> = <loc>;
// <loc> ::=< loc>[<nums>] | <id>
// <expr> ::=< expr> + < term> |< expr>  – <term> |< term> | <call_func>

void ass::deriving(int pos) {
	if (lexStream[pos].type == IDENT) {
		symbol* newNode = new loc;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos);
		bool flag = false;
		int index{};
		for (int i = pos + 1; i < lexStream.size(); ++i) {
			if (lexStream[i].type == DIVIDE && Dividers[lexStream[i].numInValidTable].val == "=") {
				symbol* newLeaf = new terminal("=");
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);
				flag = true;
				index = i;
				break;
			}
		}
		if (flag) {
			bool signOfSemicolon = false;
			bool signOfExpr = false;
			for (int i = index + 1; i < lexStream.size(); ++i) {
				if (lexStream[i].type == DIVIDE && Dividers[lexStream[i].numInValidTable].val == ";") {
					!signOfSemicolon;
					break;
				}
				else {
					if (lexStream[i].type == DIVIDE && 
						  (Dividers[lexStream[i].numInValidTable].val == "+"|| 
						   Dividers[lexStream[i].numInValidTable].val == "-" || 
						   Dividers[lexStream[i].numInValidTable].val == "/" || 
						   Dividers[lexStream[i].numInValidTable].val == "*")) {
						signOfExpr = true;
					}
				}
			}
			if (signOfExpr == false) {
				symbol* newNode = new loc;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(index+1);
				if (signOfSemicolon == false) {
					// Error
				}
				else {
					symbol* newLeaf = new terminal(";");
					newLeaf->setParent(this);
					_childs.push_back(newLeaf);
				}
			}
			else {
				symbol* newNode = new expr;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(index + 1);
				if (signOfSemicolon == false) {
					// Error
				}
				else {
					symbol* newLeaf = new terminal(";");
					newLeaf->setParent(this);
					_childs.push_back(newLeaf);
				}
			}
		}
		else {
			// Error
		}
	}
	else {
		// Error
	}
}