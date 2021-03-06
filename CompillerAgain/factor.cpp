#include "factor.h"
#include "expr.h"
#include "loc.hpp"
#include "nums.hpp"
#include "terminal.h"
factor::factor()
{
	setFlag(false);
}


factor::~factor(){
}

// <factor> ::= (<expr>)|<loc>|<num>|true|false
void factor::deriving(int pos) {
	bool isDerived = false;
	if (lexStream[pos ].type == DIVIDE && Dividers[lexStream[pos ].numInValidTable].val == "(") {
		symbol* newLeaf = new terminal("(");
		newLeaf->setParent(this);
		_childs.push_back(newLeaf);

		symbol* newNode = new expr;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos + 1);

		symbol* newLeaf_close = new terminal(")");
		newLeaf_close->setParent(this);
		_childs.push_back(newLeaf_close);
	}
	else {
		if (lexStream[pos].type == IDENT) {
			if (Identifiers[lexStream[pos + 1].numInValidTable].wasDeclarated == false) {
				cout << "Error: identifier must be declarated" << endl;
				throw 1;
			}
			symbol* newNode = new loc;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos);
		}
		else {
			if (lexStream[pos-1].type == CONSTANT) {

				symbol* newNode = new nums;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos-1);
			}
			else {
				if (lexStream[pos].type == KEY_WORD && (KeyWords[lexStream[pos].numInValidTable].val == "true" || KeyWords[lexStream[pos].numInValidTable].val == "false")) {
					symbol* newLeaf = new terminal(KeyWords[lexStream[pos].numInValidTable].val);
					newLeaf->setParent(this);
					_childs.push_back(newLeaf);
				}
				else {
					cout << "Syntax undefined error" << endl;
					throw 1;
					return;
				}
			}
		}
	}

	cout << "factor" << endl;
}