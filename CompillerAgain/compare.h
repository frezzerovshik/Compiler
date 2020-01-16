#pragma once
#include "symbol.h"
class compare : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	compare();
	~compare();
};

