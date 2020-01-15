#pragma once
#include "symbol.h"

class S : public symbol
{
	vector<symbol*> _childs;
public:
	void deriving(int pos);//implementation in S.cpp
	S();
	~S();
};

