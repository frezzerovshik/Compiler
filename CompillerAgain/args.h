#pragma once
#include "symbol.h"
class args : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	args();
	~args();
};

