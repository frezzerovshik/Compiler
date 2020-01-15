#include "S.h"
#include "terminal.h"
#include "block.h"


S::S()
{
}


S::~S()
{
}
void S::deriving(int pos) {
	// <S>::=PROGRAMM;<block>
	if (lexStream[pos].type == KEY_WORD) {
		if (KeyWords[lexStream[pos].numInValidTable].val == "PROGRAMM") {
			symbol* leaf = new terminal("PROGRAMM");
			leaf->setParent(this);
			_childs.push_back(leaf);
			if (lexStream[pos+1].type == DIVIDE) {
				if (Dividers[lexStream[pos + 1].numInValidTable].val == ";") {
					symbol* leaf = new terminal(";");
					leaf->setParent(this);
					_childs.push_back(leaf);
					if (lexStream[pos + 2].type == KEY_WORD && (KeyWords[lexStream[pos + 2].numInValidTable].val == "integer" || KeyWords[lexStream[pos + 2].numInValidTable].val == "bool")) {
						symbol* newNode = new block;
						newNode->setParent(this);
						_childs.push_back(newNode);
						newNode->deriving(pos + 2);
					}
				}
			}
		}
	}
	else {
		cout << "Error - point of enty in application is not defined correctly" << endl;
		return;
	}
}
