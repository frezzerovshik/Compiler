#pragma once
#include "symbol.h"
class boolean :
	public symbol
{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	boolean();
	~boolean();
};

