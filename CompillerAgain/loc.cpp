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
}
loc::~loc(){
    //Empty implementation
}
// <loc>::=<loc>[<nums>] | <id>
void loc::deriving(int pos){
    if(lexStream[pos].type == IDENT && (lexStream[pos+1].type == DIVIDE && Dividers[lexStream[pos+1].numInValidTable].val !="[")){
        symbol* newNode = new id;
        newNode->setParent(this);
        _childs.push_back(newNode);
        newNode->deriving(pos);
    }
    else{
        if(lexStream[pos].type == IDENT){
            if(lexStream[pos+1].type == DIVIDE &&
               Dividers[lexStream[pos+1].numInValidTable].val == "["){
                
                symbol* newNode = new id;
                newNode->setParent(this);
                _childs.push_back(newNode);
                newNode->deriving(pos);
                
                symbol* newLeaf= new terminal("[");
                _childs.push_back(newLeaf);
                
                if(lexStream[pos+2].type == CONSTANT){
                    symbol* newNode = new nums;
                    newNode->setParent(this);
                    _childs.push_back(newNode);
                    newNode->deriving(pos);
                    if(lexStream[pos+3].type == DIVIDE && Dividers[lexStream[pos+3].numInValidTable].val == "]"){
                        symbol* newLeaf= new terminal("]");
                        _childs.push_back(newLeaf);
                        if(lexStream[pos+4].type == DIVIDE && Dividers[lexStream[pos+4].numInValidTable].val == "["){
                            symbol* newNode = new id;
                            newNode->setParent(this);
                            _childs.push_back(newNode);
                            newNode->deriving(pos);
                            symbol* newLeaf= new terminal("[");
                            _childs.push_back(newLeaf);
                            if(lexStream[pos+5].type == CONSTANT){
                                symbol* newNode = new nums;
                                newNode->setParent(this);
                                _childs.push_back(newNode);
                                newNode->deriving(pos);
                                if(lexStream[pos+6].type == DIVIDE && Dividers[lexStream[pos+6].numInValidTable].val == "]"){
                                    symbol* newLeaf= new terminal("]");
                                    _childs.push_back(newLeaf);
                                }
                                else{
                                    cout<<"Error: expected ]"<<endl;
                                    return;
                                    }
                            }
                            else{
                                cout<<"Error: expected ]"<<endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}
