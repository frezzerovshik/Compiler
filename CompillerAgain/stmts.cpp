#include "stmts.h"
#include "stmt.h"


stmts::stmts(){
    
}


stmts::~stmts(){
    
}
// <stmts>::= <stmts><stmt>  | <stmt>
// < stmt>::= <ass>; | <ass> | <cycle_stmt> | <if_stmt>
void stmts::deriving(int pos){
	if (lexStream[pos].type == IDENT) {
		int end{};
		for (int i = pos + 1; i < lexStream.size(); ++i) {
			if (lexStream[i].type == DIVIDE && Dividers[lexStream[i].numInValidTable].val == ";") {
				end = i;
				break;
			}
		}
		symbol* newNode = new stmt;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos);

		symbol* newNode_stmts = new stmts;
		newNode_stmts->setParent(this);
		_childs.push_back(newNode_stmts);
		newNode_stmts->deriving(end+1);
	}
	else {
		if (lexStream[pos].type == KEY_WORD && (KeyWords[lexStream[pos].numInValidTable].val == "WHILE" ||
			KeyWords[lexStream[pos].numInValidTable].val == "DO" ||
			KeyWords[lexStream[pos].numInValidTable].val == "FOR")) {
			int end{};
			for (int i = pos + 1; i < lexStream.size(); ++i) {
				if (lexStream[i].type == KEY_WORD && (KeyWords[lexStream[i].numInValidTable].val == "END")) {
					end = i;
					break;
				}
			}
			symbol* newNode = new stmt;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos);

			symbol* newNode_stmts = new stmts;
			newNode_stmts->setParent(this);
			_childs.push_back(newNode_stmts);
			newNode_stmts->deriving(end + 2);
		}
		else {
			if (lexStream[pos].type == KEY_WORD && (KeyWords[lexStream[pos].numInValidTable].val == "IF")) {
				int end{};
				for (int i = pos + 1; i < lexStream.size(); ++i) {
					if (lexStream[i].type == KEY_WORD && (KeyWords[lexStream[i].numInValidTable].val == "ENDIF")) {
						end = i;
						break;
					}
				}
				symbol* newNode = new stmt;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos);

				symbol* newNode_stmts = new stmts;
				newNode_stmts->setParent(this);
				_childs.push_back(newNode_stmts);
				newNode_stmts->deriving(end + 2);
			}
			else {
				// Error
			}
		}
	}
}
