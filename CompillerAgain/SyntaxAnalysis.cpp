#include "SyntaxAnalysis.h"
#include "S.h"

SyntaxAnalysis::SyntaxAnalysis()
{
}


SyntaxAnalysis::~SyntaxAnalysis()
{
}

void SyntaxAnalysis::treeMake() {
	S startSymbol;
	startSymbol.deriving(0);
	cout << "Successful syntax analysis" << endl;
}