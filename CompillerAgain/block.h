#pragma once
#include "symbol.h"
class block : public symbol{

public:

	void deriving(int pos);
	block();
	~block();
};

