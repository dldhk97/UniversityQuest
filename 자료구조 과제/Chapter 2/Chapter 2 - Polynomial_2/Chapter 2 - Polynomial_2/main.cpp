#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial poly1, poly2, resultPoly;
	
	cout << "첫번째 다항식을 계수-지수 쌍으로 입력하세요.(지수가 0으로 입력되면 종료)\n";
	poly1.makeNewPolynomial();
	cout << "두번째 다항식을 계수-지수 쌍으로 입력하세요.(지수가 0으로 입력되면 종료)\n";
	poly2.makeNewPolynomial();

	resultPoly = poly1 * poly2;

	cout << "두 다항식의 곱은 : ";
	resultPoly.print();

	return 0;
}