#pragma once
#include "symbol.h"
class text : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	text();
	~text();
};

