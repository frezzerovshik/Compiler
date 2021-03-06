//
//  decl.cpp
//  CompilerAgain
//
//  Created by Артем Шарапов on 10.01.2020.
//  Copyright © 2020 Артем Шарапов. All rights reserved.
//

#include "decl.hpp"
#include "loc.hpp"
#include "type.hpp"
decl::decl(){
    //Emty implementation
	setFlag(false);
}
decl::~decl(){
    //Empty implementation
}
// <decl>::=<type><loc>;
// <loc>::=<loc>[<nums>] | <id>
void decl::deriving(int pos){
    if(lexStream[pos].type == KEY_WORD &&
      (KeyWords[lexStream[pos].numInValidTable].val == "integer" ||
       KeyWords[lexStream[pos].numInValidTable].val == "bool")){
          symbol* newNode = new type;
          newNode->setParent(this);
          _childs.push_back(newNode);
          newNode->deriving(pos);
          if(lexStream[pos+1].type == IDENT){
			  if (Identifiers[lexStream[pos + 1].numInValidTable].wasDeclarated == true) {
				  cout << "Error: identifier was declarated" << endl;
				  throw 1;
			  }
              symbol* newNode = new loc;
              newNode->setParent(this);
              _childs.push_back(newNode);
              newNode->deriving(pos+1);
          }
      }
    else{
        cout<<"Error - need to set type of variable or returned value"<<endl;
		throw 1;
        return;
    }
	cout << "decl" << endl;
}
