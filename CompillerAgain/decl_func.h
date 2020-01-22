#pragma once
#include "symbol.h"
class decl_func : public symbol{

public:

	void deriving(int pos);
	decl_func();
	~decl_func();
};

