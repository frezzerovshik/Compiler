#pragma once
#include "symbol.h"
class stmts : public symbol
{
    vector<symbol*> _childs;
public:
    void deriving(int pos);
	stmts();
	~stmts();
};

