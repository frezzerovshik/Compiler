#pragma once
#include "symbol.h"
class block : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	block();
	~block();
};

