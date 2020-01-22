#pragma once
#include "symbol.h"
class if_stmt : public symbol{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	if_stmt();
	~if_stmt();
};

