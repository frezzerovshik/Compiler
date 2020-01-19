#pragma once
#include "symbol.h"
class term : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	term();
	~term();
};

