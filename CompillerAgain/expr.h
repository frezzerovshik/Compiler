#pragma once
#include "symbol.h"
class expr : public symbol{
	vector<symbol* > _childs;
public:
	void deriving(int pos);
	expr();
	~expr();
};

