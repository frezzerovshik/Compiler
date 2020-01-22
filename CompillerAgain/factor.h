#pragma once
#include "symbol.h"
class factor :
	public symbol
{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	factor();
	~factor();
};

