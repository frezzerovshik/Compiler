#include "symbol.h"



symbol::symbol()
{
	parent = nullptr;
	this->parsing();
}


symbol::~symbol()
{
	//Empty implementation
}
void symbol::setParent(symbol* ptr) {
	parent = ptr;
}
symbol* symbol::getParent() {
	return parent;
}