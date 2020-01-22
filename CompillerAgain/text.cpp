#include "text.h"
#include "terminal.h"


text::text(){

}


text::~text(){

}
// <text> ::= '<любой набор символов>'
void text::deriving(int pos) {
	if (lexStream[pos].type == DIVIDE && Dividers[lexStream[pos].numInValidTable].val == "'") {
		symbol* newLeaf = new terminal("'");
		newLeaf->setParent(this);
		_childs.push_back(newLeaf);
		for (int i = pos + 1; i < lexStream.size(); ++i) {
			if (lexStream[i].type == DIVIDE && Dividers[lexStream[i].numInValidTable].val == "'") {
				symbol* newLeaf = new terminal("'");
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);
				break;
			}
			else {
				string valueOfChar;
				switch (lexStream[i].type){
				case DIVIDE:
					valueOfChar = Dividers[lexStream[i].numInValidTable].val;
					break;
				case IDENT:
					valueOfChar = Identifiers[lexStream[i].numInValidTable].val;
					break;
				case CONSTANT:
					valueOfChar = Constants[lexStream[i].numInValidTable].val;
					break;
				case KEY_WORD:
					valueOfChar = KeyWords[lexStream[i].numInValidTable].val;
					break;
				default:
					cout << "Error of lexial analyzer" << endl;
					throw 1;
					return;
					break;
				}
				symbol* newLeaf = new terminal(valueOfChar);
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);
			}
		}
	}
	else {
		cout << "Error:expected '" << endl;
		throw 1;
		return;
	}
	cout << "text" << endl;
}
