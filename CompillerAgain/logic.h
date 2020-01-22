#pragma once
#include "symbol.h"
#include "terminal.h"
class logic:public symbol
{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	logic();
	~logic();
};

