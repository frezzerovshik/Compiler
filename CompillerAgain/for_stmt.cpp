#include "for_stmt.h"
#include "terminal.h"
#include "stmts.h"
#include "eob.h"
#include "type.hpp"
#include "id.hpp"
#include "nums.hpp"
#include "compare.h"
#include "unary.h"

for_stmt::for_stmt(){
	//Empty implementation
}


for_stmt::~for_stmt(){
	//Empty implementation
}
//<for_stmt>:: = FOR(<type> <id> = <const>; <id> <compare> <const>; <unary>< id>) DO <stmts>< eob> 

void for_stmt::deriving(int pos) {
	if (KeyWords[lexStream[pos].numInValidTable].val == "FOR") {
		symbol* newLeaf = new terminal("FOR");
		_childs.push_back(newLeaf);
		if (lexStream[pos + 1].type == DIVIDE && Dividers[lexStream[pos + 1].numInValidTable].val == "(") {
			symbol* newLeaf = new terminal("(");
			_childs.push_back(newLeaf);
			if (lexStream[pos + 2].type == KEY_WORD && (KeyWords[lexStream[pos + 2].numInValidTable].val == "integer" || KeyWords[lexStream[pos + 2].numInValidTable].val == "bool")) {
				symbol* newNode = new type;
				newNode->setParent(this);
				_childs.push_back(newNode);
				newNode->deriving(pos + 2);
				if (lexStream[pos + 3].type == IDENT) {
					symbol* newNode = new id;
					newNode->setParent(this);
					_childs.push_back(newNode);
					newNode->deriving(pos + 3);
					if (lexStream[pos + 4].type == DIVIDE && Dividers[lexStream[pos + 4].numInValidTable].val == "=") {
						symbol* newLeaf = new terminal("=");
						_childs.push_back(newLeaf);
						if (lexStream[pos + 5].type == CONSTANT) {
							symbol* newNode = new nums;
							newNode->setParent(this);
							_childs.push_back(newNode);
							newNode->deriving(pos + 5);
							if (lexStream[pos + 6].type == DIVIDE && Dividers[lexStream[pos + 6].numInValidTable].val == ";") {
								symbol* newLeaf = new terminal(";");
								_childs.push_back(newLeaf);
								if (lexStream[pos + 7].type == IDENT) {
									symbol* newNode = new id;
									newNode->setParent(this);
									_childs.push_back(newNode);
									newNode->deriving(pos + 7);
									if ((lexStream[pos + 8].type == DIVIDE) && (Dividers[lexStream[pos + 8].numInValidTable].val == ">" || Dividers[lexStream[pos + 8].numInValidTable].val == "<" || Dividers[lexStream[pos + 8].numInValidTable].val == "=" || Dividers[lexStream[pos + 8].numInValidTable].val == "!")) {
										symbol* newNode = new compare;
										newNode->setParent(this);
										_childs.push_back(newNode);
										newNode->deriving(pos + 8);
										if (lexStream[pos + 9].type == CONSTANT) {
											symbol* newNode = new nums;
											newNode->setParent(this);
											_childs.push_back(newNode);
											newNode->deriving(pos + 9);
											if (lexStream[pos + 10].type == DIVIDE && Dividers[lexStream[pos + 10].numInValidTable].val == ";") {
												symbol* newLeaf = new terminal(";");
												_childs.push_back(newLeaf);
												if ((lexStream[pos + 11].type == DIVIDE && lexStream[pos + 12].type == DIVIDE) && ((Dividers[lexStream[pos + 11].numInValidTable].val == "+" && Dividers[lexStream[pos + 12].numInValidTable].val == "+") || (Dividers[lexStream[pos + 11].numInValidTable].val == "-" && Dividers[lexStream[pos + 12].numInValidTable].val == "-"))) {
													symbol* newNode = new unary;
													newNode->setParent(this);
													_childs.push_back(newNode);
													newNode->deriving(pos + 11);
													if (lexStream[pos + 13].type == IDENT) {
														symbol* newNode = new id;
														newNode->setParent(this);
														_childs.push_back(newNode);
														newNode->deriving(pos + 13);
														if (lexStream[pos + 14].type == DIVIDE && Dividers[lexStream[pos + 14].numInValidTable].val == ")") {
															symbol* newLeaf = new terminal(")");
															_childs.push_back(newLeaf);
															if (lexStream[pos + 15].type == KEY_WORD && KeyWords[lexStream[pos + 15].numInValidTable].val == "DO") {
																int index = pos + 16;
																int startOfLasStatement{};
																while ((lexStream[index].type == KEY_WORD && KeyWords[lexStream[index].numInValidTable].val != "END") ) {
																	startOfLasStatement = index;
																	index++;
																}
																symbol* newLeaf = new terminal("DO");
																_childs.push_back(newLeaf);
																symbol* newNode = new stmts;
																newNode->setParent(this);
																_childs.push_back(newNode);
																newNode->deriving(pos + 16);
																symbol* newEob = new eob;
																newEob->setParent(this);
																_childs.push_back(newEob);
																newEob->deriving(index + 1);
															}
															else {
																cout << "Error : expected DO" << endl;
																return;
															}
														}
														else {
															cout << "Error:expected )" << endl;
															return;
														}
													}
													else {
														cout << "Expected unary" << endl;
														return;
													}
												}
												else {
													cout << "Error: expected unary" << endl;
													return;
												}
											}
											else {
												cout << "Error:expected semicolon" << endl;
												return;
											}
										}
										else {
											cout << "Error : expected constant" << endl;
											return;
										}
									}
									else {
										cout << "Error : expected compare" << endl;
										return;
									}
								}
								else {
									cout << "Error : expected identifier" << endl;
									return;
								}
							}
							else {
								cout << "Error:expected semicolon" << endl;
								return;
							}
						}
						else {
							cout << "Error : non-constant" << endl;
							return;
						}
					}
					else {
						cout << "Error : expected '='" << endl;
						return;
					}
				}
				else {
					cout << "Error: expected identifier " << endl;
					return;
				}
			}
			else {
				cout << "Error : expected type" << endl;
				return;
			}
		}
		else {
			cout << "Error: expected '('" << endl;
			return;
		}
	}
	else {
		cout << "Error : unexpected symbol in for_stmt" << endl;
		return;
	}
}