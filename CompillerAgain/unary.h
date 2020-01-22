#pragma once
#include "symbol.h"
class unary : public symbol{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	unary();
	~unary();
};

