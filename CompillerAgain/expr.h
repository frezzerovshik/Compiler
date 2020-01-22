#pragma once
#include "symbol.h"
class expr : public symbol{

public:

	void deriving(int pos);
	expr();
	~expr();
};

