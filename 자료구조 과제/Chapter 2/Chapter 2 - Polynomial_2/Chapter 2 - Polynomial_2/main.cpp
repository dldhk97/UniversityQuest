#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial poly1, poly2, resultPoly;
	
	cout << "ù��° ���׽��� ���-���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)\n";
	poly1.makeNewPolynomial();
	cout << "�ι�° ���׽��� ���-���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)\n";
	poly2.makeNewPolynomial();

	resultPoly = poly1 * poly2;

	cout << "�� ���׽��� ���� : ";
	resultPoly.print();

	return 0;
}