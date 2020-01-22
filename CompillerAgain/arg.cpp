#include "arg.h"


//<arg> :: = (<type> <id>, | (<type> < id | <type>< id>); | <type><id>
void arg::deriving(int pos)
{
	if ((lexStream[pos].type == DIVIDE && Dividers[lexStream[pos].numInValidTable].val == "(") && derived == false) {
		symbol* newLeaf_1 = new terminal("(");
		newLeaf_1->setParent(this);
		_childs.push_back(newLeaf_1);
		if (lexStream[pos + 1].type == KEY_WORD && (KeyWords[lexStream[pos + 1].numInValidTable].val == "integer" ||
			KeyWords[lexStream[pos + 1].numInValidTable].val == "bool")) {
			symbol *newNode_1 = new type;
			newNode_1->setParent(this);
			_childs.push_back(newNode_1);
			if (lexStream[pos + 2].type == IDENT) {
				symbol *newNode_2 = new id;
				newNode_2->setParent(this);
				_childs.push_back(newNode_2);
				if (lexStream[pos + 3].type == DIVIDE && Dividers[lexStream[pos + 3].numInValidTable].val == ",") {
					symbol* newLeaf_2 = new terminal(",");
					newLeaf_2->setParent(this);
					_childs.push_back(newLeaf_2);
					derived = true;
				}
				else {
					cout << "Error: expected ," << endl;
					throw 1;
					return;
				}
			}
			else {
				cout << "Error: expected id" << endl;
				throw 1;
				return;
			}
		}
		else {
			cout << "Error: expected type" << endl;
			throw 1;
			return;
		}
	}
	else {
		cout << "Error: expected (" << endl;
		throw 1;
		return;
	}

	if ((lexStream[pos].type == DIVIDE && Dividers[lexStream[pos].numInValidTable].val == "(") && derived == false) {
		symbol* newLeaf_1 = new terminal("(");
		newLeaf_1->setParent(this);
		_childs.push_back(newLeaf_1);
		if (lexStream[pos + 1].type == KEY_WORD && (KeyWords[lexStream[pos + 1].numInValidTable].val == "integer" ||
			KeyWords[lexStream[pos + 1].numInValidTable].val == "bool")) {
			symbol *newNode_1 = new type;
			newNode_1->setParent(this);
			_childs.push_back(newNode_1);
			if (lexStream[pos + 2].type == IDENT) {
				symbol *newNode_2 = new id;
				newNode_2->setParent(this);
				_childs.push_back(newNode_2);
				derived = true;
			}
			else {
				cout << "Error: expected id" << endl;
				throw 1;
				derived = false;
				return;
			}
		}
		else {
			cout << "Error: expected type" << endl;
			throw 1;
			derived = false;
			return;
		}
	}
	else {
		cout << "Error: expected (" << endl;
		throw 1;
		derived = false;
		return;
	}

	if ((lexStream[pos + 1].type == KEY_WORD && (KeyWords[lexStream[pos + 1].numInValidTable].val == "integer" ||
		KeyWords[lexStream[pos + 1].numInValidTable].val == "bool")) && derived == false) {
		symbol *newNode_1 = new type;
		newNode_1->setParent(this);
		_childs.push_back(newNode_1);
		if (lexStream[pos + 2].type == IDENT) {
			symbol *newNode_2 = new id;
			newNode_2->setParent(this);
			_childs.push_back(newNode_2);
			if ((lexStream[pos + 3].type == DIVIDE && Dividers[lexStream[pos + 3].numInValidTable].val == ")") && derived == false)
			{
				symbol* newLeaf_3 = new terminal(")");
				newLeaf_3->setParent(this);
				_childs.push_back(newLeaf_3);
				if ((lexStream[pos + 4].type == DIVIDE && Dividers[lexStream[pos + 4].numInValidTable].val == ";") && derived == false)
				{
					symbol* newLeaf_4 = new terminal(";");
					newLeaf_4->setParent(this);
					_childs.push_back(newLeaf_4);
					derived = true;
				}
				else {
					cout << "Error: expected ;" << endl;
					throw 1;
					derived = false;
					return;
				}
			}
			else {
				cout << "Error: expected )" << endl;
				throw 1;
				derived = false;
				return;
			}
		}
		else {
			cout << "Error: expected id" << endl;
			throw 1;
			derived = false;
			return;
		}
	}
	else {
		cout << "Error: expected type" << endl;
		throw 1;
		derived = false;
		return;
	}

	if((lexStream[pos + 1].type == KEY_WORD && (KeyWords[lexStream[pos + 1].numInValidTable].val == "integer" ||
		KeyWords[lexStream[pos + 1].numInValidTable].val == "bool")) && derived == false) {
		symbol *newNode_1 = new type;
		newNode_1->setParent(this);
		_childs.push_back(newNode_1);
		if (lexStream[pos + 2].type == IDENT) {
			symbol *newNode_2 = new id;
			newNode_2->setParent(this);
			_childs.push_back(newNode_2);
			derived = true;
		}
		else {
			cout << "Error: expected id" << endl;
			throw 1;
			derived = false;
			return;
		}
	}
	else {
		cout << "Error: expected type" << endl;
		throw 1;
		derived = false;
		return;
	}
	cout << "arg" << endl;
}

arg::arg()
{
	setFlag(false);
}


arg::~arg()
{
}
