#pragma once
#include "symbol.h"
class while_stmt : public symbol{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	while_stmt();
	~while_stmt();
};

