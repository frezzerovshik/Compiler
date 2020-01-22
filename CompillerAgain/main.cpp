//
//  main.cpp
//  Compiller
//
//  Created by јртем Ўарапов on 23.11.2019.
//  Copyright © 2019 јртем Ўарапов. All rights reserved.
//

#include <iostream>
#include "parser.hpp"
//#include <Curses.h>
#include <Windows.h>
#include <locale>
#include "SyntaxAnalysis.h"
int main(int argc, const char * argv[]) {
	setlocale(LC_ALL, "Rus");
	parser a;
	SyntaxAnalysis b;
	a.parsing();
	b.treeMake();
	system("pause");
	return 0;
}
/*
ѕример поиска унарного оператора
if(lexStream[pos].type == DIVIDE && lexStream[pos + 1].type == DIVIDE){ // ѕерва€ проверка - провер€ем, разделители ли текущий и следующий токен(лексема)
	if((Dividers[lexStream[pos].numInValidTable].val == Dividers[lexStream[pos+1].numInValidTable].val) && (( Dividers[lexStream[pos+1].numInValidTable].val == "+" &&  Dividers[lexStream[pos].numInValidTable].val == "+") || (Dividers[lexStream[pos+1].numInValidTable].val == "-" &&  Dividers[lexStream[pos].numInValidTable].val == "-"))){//ѕровер€ем, одинаковые ли эти разделители или нет и €вл€ютс€ ли они унарными
		//≈сли да, то смотрим в правило - права€ часть правила дл€ <unary> или два терминала + и + или два терминала - и -, значит - нам нужно добавить в детей этого узла два терминала
		symbol* newLeafFirstPart = new terminal(lexStream[pos].numInValidTable].val);//создаем первый терминал и передаем в него значение
		symbol* newLeafSecondPart = new terminal(lexStream[pos + 1].numInValidTable].val);//аналогично верхней строке
		//добавл€ем в детей
		_childs.push_back(newLeafFirstPart);
		_childs.push_back(newLeafSecondPart);
	}
	else{//если конструкци€ унарного оператора неправильна€, выводим ошибку
		cout<<"Error : invalid operator"<<endl;
		return;
	}
}
else{//если не унарный оператор - выводим ошибку
	cout<<"Error : expexted unary operator"<<endl;
	return 0;
}

*/