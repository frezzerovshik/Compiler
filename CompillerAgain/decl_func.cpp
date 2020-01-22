#include "decl_func.h"
#include "id.hpp"
#include "args.h"
#include "block.h"
#include "terminal.h"


decl_func::decl_func(){
}


decl_func::~decl_func(){
}

// <decl_func> ::= FUNC <id>< args><block> ENDF;
void decl_func::deriving(int pos) {
	if (lexStream[pos].type == KEY_WORD && KeyWords[lexStream[pos].numInValidTable].val == "FUNC") {
		symbol* newLeaf = new terminal("FUNC");
		newLeaf->setParent(this);
		_childs.push_back(newLeaf);
		if (lexStream[pos+1].type == IDENT) {
			symbol* newNode = new id;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos + 1);
			if (lexStream[pos + 2].type == DIVIDE && Dividers[lexStream[pos + 2].numInValidTable].val == "(") {

				symbol* newNode = new args;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos + 2);

				int index = pos + 3;
				while (!(lexStream[pos + 2].type == DIVIDE && Dividers[lexStream[pos + 2].numInValidTable].val == ")"))
					index++;

				index++;
				symbol* newNode_block = new block;
				newNode_block->setParent(this);
				_childs.push_back(newNode_block);
				newNode->deriving(index);
				for (int i = index; i < lexStream.size(); ++i) {
					if ((lexStream[i].type == KEY_WORD && KeyWords[lexStream[i].numInValidTable].val == "ENDF") && (lexStream[i + 1].type == DIVIDE && Dividers[lexStream[i + 1].numInValidTable].val == ";")) {
						symbol* newLeaf_end = new terminal("ENDF"); symbol* newLeaf_semicolon = new terminal(";");
						newLeaf_end->setParent(this); newLeaf_semicolon->setParent(this);
						_childs.push_back(newLeaf_end); _childs.push_back(newLeaf_semicolon);
						break;
					}
				}
			}
			else {
				// Error
				throw 1;
			}
		}
		else {
			// Error
			throw 1;
		}
	}
	else {
		//Error
		throw 1;
	}
	cout << "decl_func" << endl;
}