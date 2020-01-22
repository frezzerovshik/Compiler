#pragma once
#include "symbol.h"
class for_stmt : public symbol{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	for_stmt();
	~for_stmt();
};

