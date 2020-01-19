#include "boolean.h"
#include "terminal.h"


boolean::boolean()
{
}


boolean::~boolean()
{
}
// <boolean>::=<factor><logic><factor> | <factor> <compare> <factor> | true |false

void boolean::deriving(int pos) {
	if (lexStream[pos].type == KEY_WORD &&
		(KeyWords[lexStream[pos].numInValidTable].val == "true" ||
			KeyWords[lexStream[pos].numInValidTable].val == "false") &&
		lexStream[pos + 1].type != DIVIDE
		) {
		symbol* newLeaf = new terminal(KeyWords[lexStream[pos].numInValidTable].val);
		newLeaf->setParent(this);
		_childs.push_back(newLeaf);
	}
	else {
		
	}
}