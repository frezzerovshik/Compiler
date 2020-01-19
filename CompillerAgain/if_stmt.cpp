#include "if_stmt.h"
#include "terminal.h"
#include "stmts.h"
#include "boolean.h"
if_stmt::if_stmt(){
	// Empty implementation
}


if_stmt::~if_stmt(){
	// Empty implementation
}

// <if_stmt> ::= IF(<boolean>) <stmts> ELSE <stmts> ENDIF;
// <boolean>::=<factor><logic><factor> | <factor> <compare> <factor> | true | false
void if_stmt::deriving(int pos) {
	if (lexStream[pos].type == KEY_WORD && KeyWords[lexStream[pos].numInValidTable].val == "IF") {
		symbol* newLeaf = new terminal("IF");
		newLeaf->setParent(this);
		_childs.push_back(newLeaf);
		if (lexStream[pos + 1].type == DIVIDE && Dividers[lexStream[pos + 1].numInValidTable].val == "(") {
			symbol* newLeaf = new terminal("(");
			newLeaf->setParent(this);
			_childs.push_back(newLeaf);
			if  (lexStream[pos+2].type == CONSTANT ||
				 lexStream[pos + 2].type == IDENT ||
				(lexStream[pos+2].type == KEY_WORD && KeyWords[lexStream[pos+2].numInValidTable].val == "true") || 
			    (lexStream[pos+2].type == KEY_WORD && KeyWords[lexStream[pos+2].numInValidTable].val == "false")) {

				symbol* newNode = new boolean;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos + 2);
				
				int index = pos + 2;
				while (!(lexStream[index].type == DIVIDE && Dividers[lexStream[index].numInValidTable].val == ")"))
					index++;

				symbol* newLeaf = new terminal(")");
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);

				symbol* newNode_stmt_if = new stmts;
				newNode_stmt_if->setParent(this);
				_childs.push_back(newNode_stmt_if);
				newNode_stmt_if->deriving(index+1);
				while (!(lexStream[index].type == KEY_WORD && Dividers[lexStream[index].numInValidTable].val == "ELSE"))
					index++;

				symbol* newLeaf_else = new terminal("ELSE");
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);

				symbol* newNode_stmt_else = new stmts;
				newNode_stmt_else->setParent(this);
				_childs.push_back(newNode_stmt_else);
				newNode_stmt_else->deriving(index + 1);

				while (!(lexStream[index].type == KEY_WORD && Dividers[lexStream[index].numInValidTable].val == "ENDIF"))
					index++;

				symbol* newLeaf_endif = new terminal("ENDIF");
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);

				if (lexStream[index + 1].type == DIVIDE && Dividers[lexStream[index + 1].numInValidTable].val == ";") {
					symbol* newLeaf = new terminal(";");
					newLeaf->setParent(this);
					_childs.push_back(newLeaf);
				}
				else {
					cout << "Error: expected ;" << endl;
					return;
				}

			}
			else {
				cout << "Error: expected boolean expr" << endl;
				return;
			}
		}
		else {
			cout << "Error: expected (" << endl;
			return;
		}
	}
	else {
		cout << "Error: expected IF" << endl;
		return;
	}
}