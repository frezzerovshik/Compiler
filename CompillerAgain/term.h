#pragma once
#include "symbol.h"
class term : public symbol{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	term();
	~term();
};

