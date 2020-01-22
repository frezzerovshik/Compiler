#include "eob.h"
#include "block.h"
#include "terminal.h"

#define TIKAU return

eob::eob()
{
	setFlag(false);
}


eob::~eob()
{
}
// <eob>::= END.|END; <block>
void eob::deriving(int pos){
	if (lexStream[pos].type == KEY_WORD && KeyWords[lexStream[pos].numInValidTable].val == "END") {
		symbol* newLeaf = new terminal("END");
		newLeaf->setParent(this);
		_childs.push_back(newLeaf);
		if (lexStream[pos + 1].type == DIVIDE && (Dividers[lexStream[pos+1].numInValidTable].val == "." || Dividers[lexStream[pos+1].numInValidTable].val == ";")) {
			symbol* newLeaf = new terminal(Dividers[lexStream[pos + 1].numInValidTable].val);
			newLeaf->setParent(this);
			_childs.push_back(newLeaf);
			if (Dividers[lexStream[pos + 1].numInValidTable].val == ".") {
				symbol *newNode = new block;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos + 2);
			}
		}
		else {
			cout << "Error: expected . or ;" << endl;
			throw 1;
		}
	}
	else {
		cout << "Error: expected END" << endl;
		throw 1;
	}

	cout << "eob" << endl;

}

