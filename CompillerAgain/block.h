#pragma once
#include "symbol.h"
class block : public symbol{
	symbol* _parent;
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	block();
	~block();
};

