#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace std;

//���׽��� ����ڿ��� �Է¹޾� ����� �޼ҵ��Դϴ�.
//����� 0�϶�, ������ 0�϶� ����ó���� �Է��� ����մϴ�.
Polynomial makeNewPolynomial(Polynomial target)
{
	while (true)
	{
		int numCoe, numIdx;					//numCoe = ���, numIdx = ����
		cin >> numCoe >> numIdx;

		if (numCoe != 0)						//����� 0�̸� �����Ѵ�.
			target.addItem(numCoe, numIdx);	//0�� �ƴϸ� �迭�� �׸� �߰�

		if (numIdx == 0)					//������ 0�� ��� �Է� ����
			break;
	}
	return target;
}

//���׽��� ����ϴ� �޼ҵ��Դϴ�.
//��� �� �پ��� ���ܵ��� ó���մϴ�.
void printPolynomial(Polynomial target)
{
	for (int i = 0; i < target.getSize(); i = i + 2)
	{
		string coe, idx;
		if (target.getCoe(i) == -1)		//����� -1�� ���
			coe = "-";
		else if (target.getCoe(i) == 1)	//����� 1�� ���
			if (target.getIdx(i) == 0)	//������ 0�� ���
				coe = "1";
			else
				coe = "";
		else
			coe = to_string(target.getCoe(i));

		if (target.getIdx(i) == 0)	//������ 0�� ���
			idx = "";
		else if (target.getIdx(i) == 1)	//������ 1�� ���
			idx = "x";
		else
			idx = "x^" + to_string(target.getIdx(i));

		cout << coe << idx;
		if (i + 2 < target.getSize())		//������ ����� �ƴ� ���
			cout << " + ";
	}
}

int main()
{
	Polynomial input1, input2, result;

	cout << "ù��° ���׽��� ���-���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)\n";
	input1 = makeNewPolynomial(input1);
	cout << "�ι�° ���׽��� ���-���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)\n";
	input2 = makeNewPolynomial(input2);

	result = input1 * input2;
	cout << "�� ���׽��� ���� : ";
	printPolynomial(result);

	input1.deleteMemory();
	input2.deleteMemory();
	result.deleteMemory();

	return 0;
}