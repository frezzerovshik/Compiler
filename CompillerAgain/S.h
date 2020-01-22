#pragma once
#include "symbol.h"

class S : public symbol
{

public:
	vector<symbol*> _childs;
	void deriving(int pos);//implementation in S.cpp
	S();
	~S();
};

