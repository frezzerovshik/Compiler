#pragma once
#include "symbol.h"
class unary : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	unary();
	~unary();
};

