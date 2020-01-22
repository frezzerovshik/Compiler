#pragma once
#include <vector>
#include "typedef.hpp"
#include "parser.hpp"

class symbol:public parser{
	symbol *parent;
	bool flag;
	
public:
	vector<symbol*> _childs;
	bool isTerminal();
	virtual void deriving(int pos) = 0;
	void setParent(symbol* ptr);
	symbol* getParent();
	string _value;
	symbol();
	virtual ~symbol();
	void setFlag(bool fl) { flag = fl; }
	bool getFlag() { return flag; }
};

