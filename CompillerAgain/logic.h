#pragma once
#include "symbol.h"
#include "terminal.h"
class logic:public symbol
{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	logic();
	~logic();
};

