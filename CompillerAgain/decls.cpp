#include "decls.h"
#include "decl.hpp"


decls::decls(){
	//Empty implementation
}
decls::~decls(){
	//Empty implementation
}
// <decls>::=<decls><decl> | <decl>
// <decl>::=<type><loc>;
// <loc>::=<loc>[<nums>] | <id>
void decls::deriving(int pos) {
	int startForNewDecls = pos;
	int index = pos;
    int indexLastDeclStarts{};
	bool declMoreThanOne = false;
    bool flagSemicolon = false;
	int counterDecls = 0;
	while (declMoreThanOne == false) {
        indexLastDeclStarts = index;
		if (lexStream[index].type == KEY_WORD && (KeyWords[lexStream[index].numInValidTable].val == "integer" || KeyWords[lexStream[index].numInValidTable].val == "bool")) {
			if (lexStream[index + 1].type == IDENT) {
				if (((lexStream[index + 2].type == DIVIDE && Dividers[lexStream[index + 2].numInValidTable].val == "[") && (lexStream[index + 3].type == CONSTANT) && (lexStream[index + 4].type == DIVIDE && Dividers[lexStream[index + 4].numInValidTable].val == "]")) || (lexStream[index + 2].type == DIVIDE && Dividers[lexStream[index + 2].numInValidTable].val == ";")) {
                    if(Dividers[lexStream[index + 2].numInValidTable].val == ";"){
                        flagSemicolon = true;
                    }else{
                        flagSemicolon = false;
                    }
					if (counterDecls > 1) {
						declMoreThanOne = true;
					}
					else {
						counterDecls++;
                        flagSemicolon == false? index += 5 : index+=2;
					}
				}
			}
		}
	}
	if (declMoreThanOne == false) {
		if (counterDecls == 1) {
			symbol* newNode = new decl;
			newNode->setParent(this);
			_childs.push_back(newNode);
			newNode->deriving(pos);
		}
		else {
			cout << "Error" << endl;
			return;
		}
	}
    else{
        symbol* newDecl = new decl;
        newDecl->setParent(this);
        _childs.push_back(newDecl);
        newDecl->deriving(indexLastDeclStarts);
        symbol* newDecls = new decls;
        newDecls->setParent(this);
        _childs.push_back(newDecls);
        newDecls->deriving(pos);
    }

}
