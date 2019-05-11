#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace std;

//다항식을 사용자에게 입력받아 만드는 메소드입니다.
//계수가 0일때, 지수가 0일때 예외처리와 입력을 담당합니다.
Polynomial makeNewPolynomial(Polynomial target)
{
	while (true)
	{
		int numCoe, numIdx;					//numCoe = 계수, numIdx = 지수
		cin >> numCoe >> numIdx;

		if (numCoe != 0)						//계수가 0이면 무시한다.
			target.addItem(numCoe, numIdx);	//0이 아니면 배열에 항목 추가

		if (numIdx == 0)					//지수가 0인 경우 입력 종료
			break;
	}
	return target;
}

//다항식을 출력하는 메소드입니다.
//출력 시 다양한 예외들을 처리합니다.
void printPolynomial(Polynomial target)
{
	for (int i = 0; i < target.getSize(); i = i + 2)
	{
		string coe, idx;
		if (target.getCoe(i) == -1)		//계수가 -1인 경우
			coe = "-";
		else if (target.getCoe(i) == 1)	//계수가 1인 경우
			if (target.getIdx(i) == 0)	//지수가 0인 경우
				coe = "1";
			else
				coe = "";
		else
			coe = to_string(target.getCoe(i));

		if (target.getIdx(i) == 0)	//지수가 0인 경우
			idx = "";
		else if (target.getIdx(i) == 1)	//지수가 1인 경우
			idx = "x";
		else
			idx = "x^" + to_string(target.getIdx(i));

		cout << coe << idx;
		if (i + 2 < target.getSize())		//마지막 출력이 아닌 경우
			cout << " + ";
	}
}

int main()
{
	Polynomial input1, input2, result;

	cout << "첫번째 다항식을 계수-지수 쌍으로 입력하세요.(지수가 0으로 입력되면 종료)\n";
	input1 = makeNewPolynomial(input1);
	cout << "두번째 다항식을 계수-지수 쌍으로 입력하세요.(지수가 0으로 입력되면 종료)\n";
	input2 = makeNewPolynomial(input2);

	result = input1 * input2;
	cout << "두 다항식의 곱은 : ";
	printPolynomial(result);

	input1.deleteMemory();
	input2.deleteMemory();
	result.deleteMemory();

	return 0;
}