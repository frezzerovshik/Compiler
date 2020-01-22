#pragma once
#include "symbol.h"
#include "terminal.h"
#include "type.hpp"
#include "id.hpp"

class arg:public symbol{
	bool derived = false;
public:
	void deriving(int pos);
	arg();
	~arg();
};

