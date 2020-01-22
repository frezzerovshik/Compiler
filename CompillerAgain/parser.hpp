//
//  parser.hpp
//  Compiller
//
//  Created by Артем Шарапов on 23.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//
#pragma once
#include "typedef.hpp"
#include "table.h"
class parser {
	ifstream input;
	vector<string> charStream;
	string bufferFindingConstant;
	string bufFindingIdentifier; 
	enum state {STATEMENT_START,STATEMENT_ERROR,STATEMENT_DIVIDER,STATEMENT_UNDERSCORE,   STATEMENT_ID, STATEMENT_CONST, STATEMENT_FINAL };
	bool getCharStream();

	


	void makeKeyWordLex(int i);
	void makeDivLex(int i);
	void makeConstLex(CONST newConst);
	void makeIdLex(ID newId);

	ID makeNewId();
	CONST makeNewConst();

public:
	table<KW> KeyWords;
	table<CONST> Constants;
	table<DIVIDER> Dividers;
	table<ID> Identifiers;

	vector<LEX> lexStream;
	parser();
	~parser();
	bool isInAlphapet(int index);
	bool isKeyWord(string cmp);
	bool isDivider(int index);
	bool isDivider(string cmp);
	bool isDigit(int index);
	bool isUnderscore(int index);
	bool isEndif(string cmp);
	bool isEndf(string cmp);
	bool isFunc(string cmp);
	bool isLastChar(int i);
	void printLexStream();
	void printTableId();
	void printTableConst();
	void parsing();
};
