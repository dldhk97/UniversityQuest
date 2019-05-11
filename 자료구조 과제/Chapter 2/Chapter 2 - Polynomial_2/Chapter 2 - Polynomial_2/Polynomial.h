#pragma once
#include <iostream>
#include <string>
#include "Term.h"

class Polynomial
{
private:
	Term *arr;			//실제 값을 저장할 배열
	int size;			//배열의 실제 용량
	int capacity;		//배열의 최대 용량
public:
	Polynomial();			//생성자입니다.
	~Polynomial();	//메모리를 해제합니다.

	//getter
	int getSize();			//배열의 실제 용량을 알아냅니다.
	int getCoe(int index);	//특정 위치의 수의 계수를 알아냅니다.
	int getIdx(int index);	//특정 위치의 수의 지수를 알아냅니다.

	//Methods
	void addTerm(int coe, int idx);	//계수와 지수를 입력받아 새로운 수를 더합니다.
	void removeTerm(int idx);		//지수를 입력받아 해당되는 수를 삭제합니다.
	void resizeCapacity(int iCapacity);	//크기를 입력받아 배열의 최대용량을 재조정합니다.

	//Operators
	Polynomial operator+(Polynomial target);	//덧셈 연산자입니다.
	Polynomial operator*(Polynomial target);	//곱셈 연산자입니다.

	//UserControl
	void makeNewPolynomial();		//다항식 클래스에 수를 추가합니다.
	void print();					//다항식을 출력합니다.
};

