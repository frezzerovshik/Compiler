#pragma once
#include "symbol.h"
class call_func : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	call_func();
	~call_func();
};

