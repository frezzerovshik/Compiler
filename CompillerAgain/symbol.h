#pragma once
#include <vector>
#include "typedef.hpp"
#include "parser.hpp"

class symbol:public parser{
	symbol *parent;
public:
	virtual void deriving(int pos) = 0;
	void setParent(symbol* ptr);
	symbol* getParent();
	symbol();
	virtual ~symbol();
};

