//
//  main.cpp
//  Compiller
//
//  Created by ����� ������� on 23.11.2019.
//  Copyright � 2019 ����� �������. All rights reserved.
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
������ ������ �������� ���������
if(lexStream[pos].type == DIVIDE && lexStream[pos + 1].type == DIVIDE){ // ������ �������� - ���������, ����������� �� ������� � ��������� �����(�������)
	if((Dividers[lexStream[pos].numInValidTable].val == Dividers[lexStream[pos+1].numInValidTable].val) && (( Dividers[lexStream[pos+1].numInValidTable].val == "+" &&  Dividers[lexStream[pos].numInValidTable].val == "+") || (Dividers[lexStream[pos+1].numInValidTable].val == "-" &&  Dividers[lexStream[pos].numInValidTable].val == "-"))){//���������, ���������� �� ��� ����������� ��� ��� � �������� �� ��� ��������
		//���� ��, �� ������� � ������� - ������ ����� ������� ��� <unary> ��� ��� ��������� + � + ��� ��� ��������� - � -, ������ - ��� ����� �������� � ����� ����� ���� ��� ���������
		symbol* newLeafFirstPart = new terminal(lexStream[pos].numInValidTable].val);//������� ������ �������� � �������� � ���� ��������
		symbol* newLeafSecondPart = new terminal(lexStream[pos + 1].numInValidTable].val);//���������� ������� ������
		//��������� � �����
		_childs.push_back(newLeafFirstPart);
		_childs.push_back(newLeafSecondPart);
	}
	else{//���� ����������� �������� ��������� ������������, ������� ������
		cout<<"Error : invalid operator"<<endl;
		return;
	}
}
else{//���� �� ������� �������� - ������� ������
	cout<<"Error : expexted unary operator"<<endl;
	return 0;
}

*/