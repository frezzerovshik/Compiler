#include "terminal.h"



terminal::terminal()
{
	//Empty implementation
	setFlag(true);
}


terminal::~terminal()
{
}

terminal& terminal::operator=(terminal& op) {
	if (&op == this) {
		return *this;
	}
	this->_value = op._value;
	return *this;
}

void terminal::deriving(int pos) {
	//Empty implementation;
}

terminal::terminal(const char *str) {
	_value = str;
	_parent = nullptr;
	setFlag(true);
}
terminal::terminal(string str) {
	_value = str;
	_parent = nullptr;
	setFlag(true);
}