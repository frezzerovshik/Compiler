#include "while_stmt.h"
#include "terminal.h"
#include "stmts.h"
#include "eob.h"
#include "boolean.h"
while_stmt::while_stmt(){
}


while_stmt::~while_stmt(){
}
// <while_stmt>::= WHILE(<boolean>) DO <stmts> <eob> |DO <stmts> WHILE(<boolean>);
void while_stmt::deriving(int pos) {
	if (lexStream[pos].type == KEY_WORD) {
		if (KeyWords[lexStream[pos].numInValidTable].val == "WHILE" || KeyWords[lexStream[pos].numInValidTable].val == "DO") {
			symbol* newNode = new terminal(KeyWords[lexStream[pos].numInValidTable].val);
			newNode->setParent(this);
			_childs.push_back(newNode);
			if (lexStream[pos + 1].type == DIVIDE && Dividers[lexStream[pos + 1].numInValidTable].val == "(") {
				symbol* newLeaf = new terminal("(");
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);

				symbol* newNode = new boolean;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos + 2);

				int index{};
				bool flag = false;
				for (int i = 0; i < lexStream.size(); ++i) {
					if (lexStream[i].type == DIVIDE && Dividers[lexStream[i].numInValidTable].val == ")") {
						index = i;
						flag == true;
						break;
					}
				}
				if (flag == true) {
					symbol* newLeaf = new terminal(")");
					newLeaf->setParent(this);
					_childs.push_back(newLeaf);
					if (lexStream[index + 1].type == KEY_WORD && KeyWords[lexStream[index + 1].numInValidTable].val == "DO") {
						symbol* newLeaf = new terminal("DO");
						newLeaf->setParent(this);
						_childs.push_back(newLeaf);

						symbol* newNode = new stmts;
						newNode->setParent(this);
						_childs.push_back(newNode);
						newNode->deriving(index+2);

						for (int i = 0; i < lexStream.size(); ++i) {
							if (lexStream[i].type == KEY_WORD && KeyWords[lexStream[i].numInValidTable].val == "END") {
								symbol* newNode = new eob;
								newNode->setParent(this);
								_childs.push_back(newNode);
								newNode->deriving(i);
								break;
							}
						}

					}
					else {
						//Error
						throw 1;
					}
				}
				else {
					// Error
					throw 1;
				}
			}
			else{
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
		// Error
		throw 1;
	}
	cout << "while" << endl;
}