#pragma once
#include "symbol.h"
class for_stmt : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	for_stmt();
	~for_stmt();
};

