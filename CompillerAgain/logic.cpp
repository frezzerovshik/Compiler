#include "logic.h"


//<logic>::= && | ||
void logic::deriving(int pos)
{
	if ((lexStream[pos].type == DIVIDE && Dividers[lexStream[pos].numInValidTable].val == "&")) {
		if ((lexStream[pos + 1].type == DIVIDE && Dividers[lexStream[pos + 1].numInValidTable].val == "&")) {
			symbol* newLeaf_1 = new terminal("&&");
			newLeaf_1->setParent(this);
			_childs.push_back(newLeaf_1);
		}
	}
	if ((lexStream[pos].type == DIVIDE && Dividers[lexStream[pos].numInValidTable].val == "|")) {
		if ((lexStream[pos + 1].type == DIVIDE && Dividers[lexStream[pos + 1].numInValidTable].val == "|")) {
			symbol* newLeaf_2 = new terminal("||");
			newLeaf_2->setParent(this);
			_childs.push_back(newLeaf_2);
		}
	}
}

logic::logic()
{
}


logic::~logic()
{
}
