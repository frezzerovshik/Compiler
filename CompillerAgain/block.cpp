#include "block.h"
#include "decls.h"
#include "stmts.h"
#include "eob.h"

block::block()
{
	setFlag(false);
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
	for (int i = 0; i < lexStream.size(); ++i) {
		if ((lexStream[i].type == IDENT && (lexStream[i + 1].type == DIVIDE && Dividers[lexStream[i + 1].numInValidTable].val == "=")) ||
			(lexStream[i].type == KEY_WORD && (KeyWords[lexStream[i].numInValidTable].val == "IF" || KeyWords[lexStream[i].numInValidTable].val == "DO" || KeyWords[lexStream[i].numInValidTable].val == "WHILE" || KeyWords[lexStream[i].numInValidTable].val == "FOR"))
			) {
			index = i;
			break;
		}
	}
	//If declarations is found, add this non-terminal to tree and try to derive it
	
		symbol* newNode = new decls;//Need to create this class
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos);
	
	//If there are no declarations , check the stream of tokens for the statements, because grammar allows the absence of a declarations
	//If we meet an assignment or some control structures, add a new node to tree and try to derive it

		symbol* newNode_stmt = new stmts;
		newNode_stmt->setParent(this);
		_childs.push_back(newNode_stmt);
		newNode_stmt->deriving(index);
	
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
