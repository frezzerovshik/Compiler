#pragma once
#include "symbol.h"
class boolean :
	public symbol
{
public:

	void deriving(int pos);
	boolean();
	~boolean();
};

