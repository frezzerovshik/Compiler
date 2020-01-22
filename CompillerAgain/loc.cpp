//
//  loc.cpp
//  CompilerAgain
//
//  Created by Артем Шарапов on 10.01.2020.
//  Copyright © 2020 Артем Шарапов. All rights reserved.
//

#include "loc.hpp"
#include "id.hpp"
#include "terminal.h"
#include "nums.hpp"
loc::loc(){
    //Empty implementation
	setFlag(false);
}
loc::~loc(){
    //Empty implementation
}
// <loc>::=<id>[<nums>] | <id> | <nums>
void loc::deriving(int pos){
	if (lexStream[pos].type == IDENT && (lexStream[pos + 1].type == DIVIDE && Dividers[lexStream[pos + 1].numInValidTable].val != "[")) {
		symbol* newNode = new id;
		newNode->setParent(this);
		_childs.push_back(newNode);
		newNode->deriving(pos);
    }
	else {
		if (lexStream[pos].type == CONSTANT) {
			symbol* newNode = new nums;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos);
		}
		else {
			if (lexStream[pos].type == IDENT && (lexStream[pos + 1].type == DIVIDE && Dividers[lexStream[pos + 1].numInValidTable].val == "[")) {
				symbol* newNode = new id;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos);

				symbol* newLeaf = new terminal("[");
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);

				symbol* newConst = new nums;
				newConst->setParent(this);
				_childs.push_back(newConst);
				newConst->deriving(pos + 2);

				newLeaf = new terminal("]");
				newLeaf->setParent(this);
				_childs.push_back(newLeaf);
			}
			else {
				throw 1;
			}
		}
	}
	cout << "loc" << endl;
}
