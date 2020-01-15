#pragma once
#include "symbol.h"
class cycle_stmt : public symbol{
	vector<symbol*> _childs;
public:
	cycle_stmt();
	~cycle_stmt();
	void deriving(int pos);
};

