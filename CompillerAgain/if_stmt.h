#pragma once
#include "symbol.h"
class if_stmt : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	if_stmt();
	~if_stmt();
};

