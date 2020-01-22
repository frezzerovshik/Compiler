#pragma once
#include "symbol.h"
class decls : public symbol
{
public:

	void deriving(int pos);
	decls();
	~decls();
};

