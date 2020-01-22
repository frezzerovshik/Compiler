//
//  type.cpp
//  CompilerAgain
//
//  Created by Артем Шарапов on 10.01.2020.
//  Copyright © 2020 Артем Шарапов. All rights reserved.
//

#include "type.hpp"
#include "terminal.h"
type::type(){
    //Empty implementation
	setFlag(false);
}
type::~type(){
    //Empty implementation
}
void type::deriving(int pos){
    string leafValue;
    if(lexStream[pos].type == KEY_WORD){
        if(KeyWords[lexStream[pos].numInValidTable].val == "integer")
            leafValue = "integer";
        else{
            if(KeyWords[lexStream[pos].numInValidTable].val == "bool")
                leafValue = "bool";
            else{
                cout<<"Error : uncorrect type"<<endl;
                return;
            }
        }
    }
    if(!leafValue.empty()){
        symbol* newLeaf = new terminal(leafValue);
        newLeaf->setParent(this);
        _childs.push_back(newLeaf);
    }
    else{
        cout<<"Unexpected error"<<endl;
		throw 1;
        return;
    }
	cout << "type" << endl;
}
