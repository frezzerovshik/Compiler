#pragma once
#include "symbol.h"
class stmt :
	public symbol
{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	stmt();
	~stmt();
};

