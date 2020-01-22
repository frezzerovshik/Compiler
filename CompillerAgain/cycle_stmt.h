#pragma once
#include "symbol.h"
class cycle_stmt : public symbol{

public:

	cycle_stmt();
	~cycle_stmt();
	void deriving(int pos);
};

