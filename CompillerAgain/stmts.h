#pragma once
#include "symbol.h"
class stmts : public symbol
{

public:
	vector<symbol*> _childs;
    void deriving(int pos);
	stmts();
	~stmts();
};

