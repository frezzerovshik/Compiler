#include "boolean.h"
#include "terminal.h"
#include "factor.h"
#include "logic.h"
#include "compare.h"
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
		symbol* newNode_op1 = new factor;
		newNode_op1->setParent(this);
		_childs.push_back(newNode_op1);
		newNode_op1->deriving(pos);
		int index = pos;
		for (int i = 0; i < lexStream.size(); ++i) {
			if (lexStream[i].type == DIVIDE &&
				((Dividers[lexStream[i].numInValidTable].val == "&" && Dividers[lexStream[i+1].numInValidTable].val == "&")||
					(Dividers[lexStream[i].numInValidTable].val == "|" && Dividers[lexStream[i+1].numInValidTable].val == "|"))) {
				symbol* newNodeOperator = new logic;
				newNodeOperator->setParent(this);
				_childs.push_back(newNodeOperator);
				newNodeOperator->deriving(i);
				index = i + 1;
				break;
			}
			else {
				if (lexStream[i].type == DIVIDE &&
					((Dividers[lexStream[i].numInValidTable].val == ">" && Dividers[lexStream[i + 1].numInValidTable].val == "=") ||
					(Dividers[lexStream[i].numInValidTable].val == "<" && Dividers[lexStream[i + 1].numInValidTable].val == "=") ||
						(Dividers[lexStream[i].numInValidTable].val == "!" && Dividers[lexStream[i + 1].numInValidTable].val == "=") ||
						(Dividers[lexStream[i].numInValidTable].val == "=" && Dividers[lexStream[i + 1].numInValidTable].val == "=") ||
						(Dividers[lexStream[i].numInValidTable].val == "<") ||
						(Dividers[lexStream[i].numInValidTable].val == ">")
						)) {
					symbol* newNodeOperator = new compare;
					newNodeOperator->setParent(this);
					_childs.push_back(newNodeOperator);
					newNodeOperator->deriving(i);
					index = i + 1;
					break;
				}
				else {
					// Error
				}
			}
		}
		symbol* newNode_op2 = new factor;
		newNode_op2->setParent(this);
		_childs.push_back(newNode_op2);
		newNode_op2->deriving(index+1);
	}
}