#pragma once
#include "symbol.h"
class ass : public symbol{
	vector<symbol*> _childs;
public:
	void deriving(int pos);
	ass();
	~ass();
};

