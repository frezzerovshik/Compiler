#include "parser.hpp"
//#pragma mark - êîíñòðóêòîð
parser::parser() {
	input.open("main.txt");
	ifstream tKW("keywords.txt");
	ifstream tDV("dividers.txt");
	KW tempKW;
	DIV tempDV;
	int num = 0;
	while (getline(tKW, tempKW.val)) {
		tempKW.num = num;
		num++;
		KeyWords += tempKW;
	}
	num = 0;
	while (getline(tDV, tempDV.val)) {
		tempDV.numDiv = num;
		num++;
		Dividers += tempDV;
	}
	tKW.close();
	tDV.close();
}
parser::~parser() {
	input.close();
}
//#pragma mark - ñîçäàíèå ïîòîêà òåðìèíàëüíûõ ñèìâîëîâ
	bool parser::getCharStream() {
		setlocale(LC_ALL, "Rus");
		char c;//Пузырек для считывания файла посимвольно
		string buffer;//Строка, в которую будет собран текст программы
		//Считыывание файла посимвольно и сохранение в буфере-строке
		int start{}, end{};
		bool next = true;
		bool flag = false;
		do {
			input >> c;
			buffer += c;
		} while (!input.eof());

		do {
			for (int i = 0; i < buffer.size(); ++i) {
				if (buffer[i] == '/' && buffer[i + 1] == '/') {
					cout << "Ошибка" << endl;
					return false;
				}
				if (buffer[i] == '/' && buffer[i + 1] == '*') {
					start = i;
					continue;
				}
				if (buffer[i] == '*' && buffer[i + 1] == '/') {
					end = i;
					flag = true;
					break;
				}
			}
			if (flag) {
				buffer.erase(start, end - start + 2);
				flag = false;
			}
			else {
				next = false;
			}
			
		} while (next);
		
		for (int i = 0; i < buffer.size(); ++i) {
			string temp;
			temp += buffer[i];
			charStream.push_back(temp);
		}
		return true;
}

bool parser::isDivider(int index) {
	bool answer = false;
	for (int i = 0; i < Dividers.size(); ++i) {
		if (charStream[index] == Dividers[i].val) {
			answer = true;
			break;
		}
	}
	return answer;
}
bool parser::isKeyWord(string cmp) {
	bool answer = false;
	for (int i = 0; i < KeyWords.size(); ++i) {
		if (cmp == KeyWords[i].val) {
			answer = true;
			break;
		}
	}
	return answer;
}
bool parser::isInAlphapet(int index) {
	bool answer = false;
	ifstream in("alphabet.txt");
	string tmp;
	vector<string> dictionary;
	do {
		getline(in, tmp);
		dictionary.push_back(tmp);
	} while (!in.eof());

	for (int j = 0; j < dictionary.size(); ++j) {
		if (charStream[index] == dictionary[j]) {
			answer = true;
			break;
		}
	}
	in.close();
	return answer;
}
bool parser::isDigit(int index) {
	bool answer = false;
	ifstream in("digits.txt");
	string tmp;
	vector<string> dictionary;
	while (getline(in, tmp))
		dictionary.push_back(tmp);

	for (int i = 0; i < dictionary.size(); ++i) {
		if (charStream[index] == dictionary[i]) {
			answer = true;
			break;
		}
	}
	return answer;
}
bool parser::isUnderscore(int index) {
	if (charStream[index] == "_")
		return true;
	else
		return false;
}

void parser::makeKeyWordLex(int i) {
	LEX newLex(KEY_WORD, i);
	lexStream.push_back(newLex);
}
void parser::makeDivLex(int i) {
	LEX newLex(DIVIDE, i);
	lexStream.push_back(newLex);
}
void parser::makeConstLex(CONST newConst) {
	LEX newLex(CONSTANT, newConst.numberConst);
	lexStream.push_back(newLex);
}
void parser::makeIdLex(ID newId) {
	LEX newLex(IDENT, newId.numId);
	lexStream.push_back(newLex);
}

ID parser::makeNewId() {
	ID newId(bufFindingIdentifier, Identifiers.size());
	if (Identifiers.isInTable(bufFindingIdentifier) == NOT_IN_TABLE)
		Identifiers += newId;
	else
		newId.numId = Identifiers.isInTable(newId.val);
	return newId;
}
CONST parser::makeNewConst() {
	CONST newConst(bufferFindingConstant, Constants.size());
	if (Constants.isInTable(bufferFindingConstant) == NOT_IN_TABLE)
		Constants += newConst;
	else
		newConst.numberConst = Constants.isInTable(newConst.val);
	return newConst;
}
bool parser::isEndif(string cmp) {
	bool answer = false;
	if (cmp == "ENDIF")
		answer = true;
	return answer;
}
bool parser::isLastChar(int i) {
	bool answer = false;
	if (i  == charStream.size()-2)
		answer = true;
	return answer;
}
bool parser::isEndf(string cmp) {
	bool answer = false;
	if (cmp == "ENDF")
		answer = true;
	return answer;
}
bool parser::isFunc(string cmp) {
	bool answer = false;
	if (cmp == "FUNC")
		answer = true;
	return answer;
}
void parser::parsing() {
	enum state iter = STATEMENT_START;
	if (getCharStream() == false) {
		return;
	}
	if (isInAlphapet(0)) {
		bufFindingIdentifier.erase();
		iter = STATEMENT_ID;
	}
	if (isDigit(0)) {
		bufferFindingConstant.erase();
		iter = STATEMENT_CONST;
	}
	if (isDivider(0))
		iter = STATEMENT_DIVIDER;
	if (isUnderscore(0)) {
		bufFindingIdentifier.erase();
		iter = STATEMENT_UNDERSCORE;
	}
	for (int i = 0; i < charStream.size() ; ++i) {
		switch (iter) {
		case STATEMENT_ID: {
			bufFindingIdentifier += charStream[i];
			string tmp = bufFindingIdentifier;
			if (isKeyWord(bufFindingIdentifier) && !isEndf(tmp + charStream[i + 1]) && !isEndif(tmp + charStream[i + 1] + charStream[i + 2])) {
				makeKeyWordLex(KeyWords.isInTable(bufFindingIdentifier));

				if (isInAlphapet(i + 1)) {
					bufFindingIdentifier.erase();
					continue;
				}
				if (isUnderscore(i + 1)) {
					bufFindingIdentifier.erase();
					iter = STATEMENT_UNDERSCORE;
					continue;
				}
				if (isDigit(i + 1)) {
					bufferFindingConstant.erase();
					iter = STATEMENT_CONST;
					continue;
				}
				if (isDivider(i + 1)) {
					iter = STATEMENT_DIVIDER;
					continue;
				}
				if (isLastChar(i)) {
					iter = STATEMENT_FINAL;
					continue;
				}
				if (!isInAlphapet(i + 1) && !isDigit(i + 1) && !isUnderscore(i + 1) && !isDivider(i + 1)) {
					iter = STATEMENT_ERROR;
					continue;
					break;
				}
			}
			else {
				if (isDivider(i + 1)) {
					makeIdLex(makeNewId());
					iter = STATEMENT_DIVIDER;
					continue;
				}
				if (isUnderscore(i + 1)) {
					iter = STATEMENT_UNDERSCORE;
					continue;
				}
				if (isInAlphapet(i + 1) || isDigit(i + 1)) {
					continue;
				}
				if (isLastChar(i)) {
					iter = STATEMENT_FINAL;
					continue;
				}
				if (!isInAlphapet(i + 1) && !isDigit(i + 1) && !isUnderscore(i + 1) && !isDivider(i + 1)) {
					iter = STATEMENT_ERROR;
					continue;
					break;
				}
			}
			break;
		}
		case STATEMENT_CONST: {
			bufferFindingConstant += charStream[i];
			if (isDigit(i + 1))
				continue;
			else {
				makeConstLex(makeNewConst());
			}
			if (isDivider(i + 1))
				iter = STATEMENT_DIVIDER;
			if (isUnderscore(i + 1)) {
				bufFindingIdentifier.erase();
				iter = STATEMENT_UNDERSCORE;
			}
			if (isInAlphapet(i + 1)) {
				bufFindingIdentifier.erase();
				iter = STATEMENT_ID;
			}
			if (isLastChar(i)) {
				iter = STATEMENT_FINAL;
				continue;
			}
			if (!isInAlphapet(i + 1) && !isDigit(i + 1) && !isUnderscore(i + 1) && !isDivider(i + 1)) {
				iter = STATEMENT_ERROR;
				continue;
				break;
			}
			break;
		}
		case STATEMENT_UNDERSCORE: {
			bufFindingIdentifier += charStream[i];
			if (isUnderscore(i + 1))
				continue;
			if (isInAlphapet(i + 1) || isDigit(i + 1))
				iter = STATEMENT_ID;
			if (isDivider(i + 1))
				iter = STATEMENT_DIVIDER;
			if (isLastChar(i)) {
				iter = STATEMENT_FINAL;
				continue;
			}
			if (!isInAlphapet(i + 1) && !isDigit(i + 1) && !isUnderscore(i + 1) && !isDivider(i + 1)) {
				iter = STATEMENT_ERROR;
				continue;
				break;
			}
			break;
		}
		case STATEMENT_DIVIDER: {
			makeDivLex(Dividers.isInTable(charStream[i]));
			if (isInAlphapet(i + 1)) {
				bufFindingIdentifier.erase();
				iter = STATEMENT_ID;
			}
			if (isDigit(i + 1)) {
				bufferFindingConstant.erase();
				iter = STATEMENT_CONST;
			}
			if (isUnderscore(i + 1)) {
				bufFindingIdentifier.erase();
				iter = STATEMENT_UNDERSCORE;
			}
			if (isLastChar(i)) {
				iter = STATEMENT_FINAL;
				continue;
			}
			if (!isInAlphapet(i + 1) && !isDigit(i + 1) && !isUnderscore(i + 1) && !isDivider(i + 1)) {
				iter = STATEMENT_ERROR;
				continue;
				break;
			}
			break;
		}
		case STATEMENT_ERROR: {
			cout << "Ошибка!" << endl;
			return;
			break;
		}
		case STATEMENT_FINAL: {
			//cout << "Входная цепочка прошла анализ успешно" << endl << endl;
			break;
		}
		default: {
			cout << "Ошибка" << endl;
			return;
			break;
		}
		}
	}

}

void parser::printLexStream() {
	for (int i = 0; i < lexStream.size(); ++i) {
		string temp;
		switch (lexStream[i].type) {
		case 1:
			temp = "Key Word";
			break;
		case 2:
			temp = "Identifier";
			break;
		case 3:
			temp = "Divider";
			break;
		case 4:
			temp = "Constant";
			break;
		}
		cout << "номер лексемы [" << i << "] " << "Тип лексемы: " << temp << "  Номер в соответствующей таблице: " << lexStream[i].numInValidTable << endl;
	}
	cout << endl;
}
void parser::printTableId() {
	for (int i = 0; i < Identifiers.size(); ++i) {
		cout << "Номер: " << Identifiers[i].numId << "  Значение: " << Identifiers[i].val << endl;
	}
	cout << endl;
}
void parser::printTableConst() {
	for (int i = 0; i < Constants.size(); ++i) {
		cout << "Номер: " << Constants[i].numberConst << "  Значение: " << Constants[i].val << endl;
	}
	cout << endl;
}