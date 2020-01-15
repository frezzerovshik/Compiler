#pragma once
#include "symbol.h"
class decls : public symbol
{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	decls();
	~decls();
};

