#pragma once
#include "symbol.h"
class eob : public symbol
{
      vector<symbol*> _childs;
public:
    void deriving(int pos);
	eob();
	~eob();
};

