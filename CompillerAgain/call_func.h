#pragma once
#include "symbol.h"
class call_func : public symbol{

public:

	void deriving(int pos);
	call_func();
	~call_func();
};

