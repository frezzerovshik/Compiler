#include "block.h"
#include "decls.h"
#include "stmts.h"
#include "eob.h"

block::block()
{
}


block::~block()
{
}
// <block>::= <decls><stmts><eob>
void block::deriving(int pos) {
	int index = pos;
	bool declIsFound = false;
	bool endIsFound = false;
	/*Check the stream of tokens for the declarations*/
	while (declIsFound == false) {
		if (lexStream[index].type == KEY_WORD) {
			if (KeyWords[lexStream[index].numInValidTable].val == "integer" || KeyWords[lexStream[index].numInValidTable].val == "bool") {
				if (lexStream[index + 1].type == IDENT && (lexStream[index + 2].type == DIVIDE && Dividers[lexStream[index + 2].numInValidTable].val == ";")) {
					index += 3;
				}
			}
		}
		else {
			declIsFound = true;
		}
	}
	//If declarations is found, add this non-terminal to tree and try to derive it
	if (declIsFound == true) {
		symbol* newNode = new decls;//Need to create this class
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos);
	}
	//If there are no declarations , check the stream of tokens for the statements, because grammar allows the absence of a declarations
	//If we meet an assignment or some control structures, add a new node to tree and try to derive it
	if ((lexStream[index].type = IDENT && (lexStream[index + 1].type == DIVIDE && Dividers[lexStream[index + 1].numInValidTable].val == "=")) 
	|| (lexStream[index].type == KEY_WORD && KeyWords[lexStream[index].numInValidTable].val!="END")) {
		symbol* newNode = new stmts;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(index);
	}
	//Need to find an eob non-terminal
	while (index < lexStream.size()) {
		if (lexStream[index].type == KEY_WORD) {
			if (KeyWords[lexStream[index].numInValidTable].val == "END") {
				endIsFound = true;
				break;
			}
		}
		index++;
	}
	//In cause of stmts and decls can be empty lines, this rule have just one necessery non-terminal - <eob> , if we met this  - add to tree and try to derive , else return an error
	if (endIsFound) {
		symbol* newNode = new eob;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(index);
	}
	else {
		cout << "Синтаксическая ошибка: отсутствует END" << endl;
		return;
	}
	
}
