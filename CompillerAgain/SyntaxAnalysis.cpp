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
	//try {
		startSymbol.deriving(0);
		cout << "Successful syntax analysis" << endl;
	//}
	//catch (...) {
		//cout << "Unsuccessful syntax analysis" << endl;
	
	//}
}