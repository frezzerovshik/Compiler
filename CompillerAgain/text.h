#pragma once
#include "symbol.h"
class text : public symbol{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	text();
	~text();
};

