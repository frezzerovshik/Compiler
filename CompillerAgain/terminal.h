#pragma once
#include "symbol.h"

class terminal : public symbol {
	string _value;
	symbol* _parent;
	terminal();
public:
	void deriving(int pos);
	terminal(const char* str);
    terminal(string str);
	terminal& operator=(terminal& op);
	~terminal();
};

