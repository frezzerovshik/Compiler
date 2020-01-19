#pragma once
#include "symbol.h"
class factor :
	public symbol
{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	factor();
	~factor();
};

