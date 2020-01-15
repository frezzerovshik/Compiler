#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stack>
#define KEY_WORD 1 //ключевые слова
#define IDENT 2 //идентификаторы
#define DIVIDE 3 //разделители
#define CONSTANT 4 //константы
#define NOT_IN_TABLE -2
using namespace std;
typedef int TYPE_LEX;
typedef struct KW {
	KW() {};
	KW(string line, int num);
	string val;
	int num;
	bool operator==(KW obj);
}KW;
typedef struct CONST {
	CONST() {};
	CONST(string line, int num);
	string val;
	int numberConst;
	bool operator==(CONST obj);
}CONST;
typedef struct DIVIDER {
	string val;
	int numDiv;
	bool operator==(DIVIDER obj);
}DIV;
typedef struct ID {
	ID() {};
	ID(string line , int num);
	string val;
	int numId;
	bool operator==(ID obj);
}ID;
typedef struct LEX {
	LEX() {};
	LEX(TYPE_LEX type, int num);
	TYPE_LEX type;
	int numInValidTable;
}LEX;
