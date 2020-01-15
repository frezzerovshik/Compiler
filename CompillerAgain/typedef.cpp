#include "typedef.hpp"

bool KW::operator==(KW obj) {
	if (this->val == obj.val)
		return true;
	else
		return false;
}
bool DIVIDER::operator==(DIVIDER obj) {
	if (this->val == obj.val)
		return true;
	else
		return false;
}
bool CONST::operator==(CONST obj) {
	if (this->val == obj.val)
		return true;
	else
		return false;
}
bool ID::operator==(ID obj) {
	if (this->val == obj.val)
		return true;
	else
		return false;
}
ID::ID(string line , int num) {
	this->val = line;
	this->numId = num;
}
CONST::CONST(string line, int num) {
	this->val = line;
	this->numberConst = num;
}
LEX::LEX(TYPE_LEX type, int num) {
	this->numInValidTable = num;
	this->type = type;
}
KW::KW(string line, int num) {
	this->val = line;
	this->num = num;
}