#pragma once
#include "symbol.h"
class while_stmt : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	while_stmt();
	~while_stmt();
};

