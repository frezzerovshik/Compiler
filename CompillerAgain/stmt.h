#pragma once
#include "symbol.h"
class stmt :
	public symbol
{

public:
	vector<symbol*> _childs;
	void deriving(int pos);
	stmt();
	~stmt();
};

