//
//  id.cpp
//  CompilerAgain
//
//  Created by Артем Шарапов on 10.01.2020.
//  Copyright © 2020 Артем Шарапов. All rights reserved.
//

#include "id.hpp"
#include "terminal.h"

id::id(){
    //Empty implementation
}
id::~id(){
    //Empty implementation
}
void id::deriving(int pos){
    if(lexStream[pos].type == IDENT){
        symbol* newLeaf = new terminal(Identifiers[lexStream[pos].numInValidTable].val);
        newLeaf->setParent(this);
    }
    else{
        cout<<"Error: unexpected symbol"<<endl;
		throw 1;
    }
	cout << "id" << endl;
}


