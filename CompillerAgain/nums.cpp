//
//  nums.cpp
//  CompilerAgain
//
//  Created by Артем Шарапов on 10.01.2020.
//  Copyright © 2020 Артем Шарапов. All rights reserved.
//

#include "nums.hpp"
#include "terminal.h"
nums::nums(){
    //Empty implementation
}
nums::~nums(){
    //Empty implementation
}
void nums::deriving(int pos){
    if(lexStream[pos].type == CONSTANT){
        symbol* newLeaf = new terminal(Constants[lexStream[pos].numInValidTable].val);
        newLeaf->setParent(this);
        _childs.push_back(newLeaf);
    }
    else{
        cout<<"Unexpected error"<<endl;
		throw 1;
        return;
    }
	cout << "nums" << endl;
}
