#include "Polynomial.h"

const int defaultCapacity = 16;		//�⺻ �뷮�� �����մϴ�.

Polynomial::Polynomial()
{
	capacity = defaultCapacity;		//�ʱ� �뷮�� �����մϴ�.
	arr = new Term[capacity];		//���� ������ �迭�� �Ҵ��մϴ�.
	size = 0;						//��������Ƿ� ����ũ�⸦ 0���� �մϴ�.
}

Polynomial::~Polynomial()
{
	delete[] arr;
}

//getter

int Polynomial::getSize()
{
	return size;
}
int Polynomial::getCoe(int index)
{
	return arr[index].getCoe();
}
int Polynomial::getIdx(int index)
{
	return arr[index].getIdx();
}

//Methods

//���׽� ���ο� ���� ���ϴ� �޼ҵ��Դϴ�. (ex. �� : x^2 + 1, coe = 3, idx = 1 -> x^2 + 3x + 1)
//���� ����� 0�̵Ǹ� ���� �����ϱ⵵ �ϸ�, ������ ������ �������� ������ ���� ���� �߰��մϴ�.
//����� ���Ҷ� �ߺ�, ����, �߰��� ��� ó���մϴ�.
void Polynomial::addTerm(int coe, int idx)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getIdx() == idx)			//�����߰��� ���� ������ ������ �Ŀ� �����ϸ�
		{
			int sumCoe = arr[i].getCoe() + coe;
			if (sumCoe == 0)			//�����߰��� ���� ����� ��������� ���� 0�̸�
			{
				removeTerm(idx);		//������ ����
			}
			else
			{
				arr[i].setCoe(sumCoe);		//���� 0�� �ƴϸ� ���Ѱ��� ����� �ִ´�.
			}
			return;
		}
	}

	//�����߰��� ���� ������ ������ �Ŀ� �������� ������

	if (size + 1 > capacity)			//�迭�� �����Ű����� Ȯ��
	{
		capacity = capacity * 2;		//���� �ִ�뷮�� 2��� Ȯ��
		resizeCapacity(capacity);
	}

	arr[size].setCoe(coe);				//��� ����
	arr[size].setIdx(idx);				//���� ����
	size = size + 1;					//����ϳ�, �����ϳ��� ��������Ƿ� ������ ����
}

//���׽Ŀ� �����ϴ� ������ ���� �޼ҵ��Դϴ�.
//������ ������ �Է��ϸ� �ش� ���׽� ���ο� �ش� ������ �����ϸ� �����մϴ�.
//addTerm �޼ҵ� ���� �� ������� ������ �� 0�� ������ ��� �� �޼ҵ尡 ȣ��˴ϴ�.
void Polynomial::removeTerm(int idx)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getIdx() == idx)					//������ ������ ã������
		{
			arr[i].setIdx(NULL);				//������ ���� ����κ� ����
			arr[i].setCoe(NULL);				//������ ���� �����κ� ����

			for (int j = i; j < size - 1; j++)	//������ �κ��� ������ �� ������ ���� ��ĭ�� ����.
			{
				arr[j] = arr[j + 1];
			}
			break;
		}
	}
	size = size - 1;		//���� �ϳ� ���������Ƿ� ������ ����

	if (size < capacity / 2 && size > defaultCapacity)			//�޸𸮰� �����ϰ� ���Ǵ��� üũ�ϰ�, �ִ�뷮�� ������ ���δ�.
	{
		capacity = capacity / 2;
		resizeCapacity(capacity);
	}
}

//���׽Ŀ� �����Ҵ�� �迭�� �ִ�뷮(Capacity)�� �������մϴ�.
//������ �����ϰ��� �ϴ� ũ�⸦ �Է��ϸ� �ӽù迭�� ���� �迭�� ���������մϴ�.
//���� ���� �迭�� ũ�⸦ ���Ҵ��ϰ�, �ٽ� �ӽù迭���� ���������մϴ�.
void Polynomial::resizeCapacity(int iCapacity)	//�뷮�� iCapacity�� �����Ѵ�.
{
	Term *tempArr = new Term[size];				//�ӽù迭�� ����迭�� ����
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	delete[] arr;
	arr = new Term[iCapacity];					//�����迭 �뷮Ȯ���Ͽ� ���Ҵ�

	for (int i = 0; i < size; i++)				//�ӽù迭�� �ִ� ���� ����(��������)
	{
		arr[i] = tempArr[i];
	}

	delete[] tempArr;							//�ӽù迭 �޸� ����
}

//Operators

//���׽� ������ ������ �����ϴ� �޼ҵ��Դϴ�.
//���׽İ� ���׽��� �־����� ������ �������� ���Ͽ�
//������ ū ������ �����Ͽ� ���������δ� ������������ ���׽��� ��������ϴ�.
Polynomial Polynomial::operator+(Polynomial target)
{
	Polynomial result;
	int thisStartPoint = 0;								//this ���׽� �� ���� ������ ����
	int targetStartPoint = 0;							//target ���׽� �� �̹� ���� ������ ����

	if (this->size == 0)								//a = b + c �� b Ȥ�� c�� ����ִٸ� �������� �״�� �����.
	{
		for (int i = 0; i < target.size; i++)		//b�� �״�� ���
		{
			result.addTerm(target.getCoe(i), target.getIdx(i));
		}
		return result;
	}
	else if (target.size == 0)							//c�� �״�� ���
	{
		for (int i = 0; i < this->size; i++)
		{
			result.addTerm(this->getCoe(i), this->getIdx(i));
		}
		return result;
	}

	for (int i = thisStartPoint; i < this->size; i++)			//�� ���׽��� �� �������� ���ε��� ���Ѵ�.
	{															//��� �� ���׽��� ������ �� ũ�ٸ� addTerm�� ȣ���Ͽ� ������ ū ���� result ���׽Ŀ� ���Ѵ�.
		for (int j = targetStartPoint; j < target.size; j++)	//������� ���� �̹� ���Ͽ��� ������ Ž����󿡼� �����Ѵ�(thisStartPoint = i + 1 or targetStartPoint = j + 1)
		{
			if (this->getIdx(i) > target.getIdx(j))
			{
				result.addTerm(this->getCoe(i), this->getIdx(i));
				thisStartPoint = i + 1;
				break;												//this ���׽��� for���� �ܺο� �ֱ� ������ break�� ���� for���� �����Ű��, this���׽��� ���� ������ ���ؾ��Ѵ�.
			}
			else
			{
				result.addTerm(target.getCoe(j), target.getIdx(j));	//target���׽��� ������ �� ū ��쿡�� result ���׽Ŀ� ���ϰ� �� ���� Ž����󿡼� �����Ѵ�.
				targetStartPoint = j + 1;							//target���׽��� for���� ���ο� �ֱ� ������ break�� ���� �ʿ䰡 ����.
			}
		}
	}

	if (targetStartPoint < target.size)								//�� 2�� for���� ����Ǿ��ٸ� �����Ե� ¦�� �¾� ��� ������ ó���Ǿ��� ���� ������, �ƴ� ��쵵 �ֱ� ������
	{																//���� ���� ���׽��� ������ ��� result ���׽Ŀ� ������� �Ѵ�.
		for (int i = targetStartPoint; i < target.size; i++)		//c�� ������ �� c�� ���������� ��� result�� �ִ´�.
		{
			result.addTerm(target.getCoe(i), target.getIdx(i));

		}
	}
	else if (thisStartPoint < this->size)							//b�� �������� b�� ���������� ��� result�� �ִ´�.
	{
		for (int i = thisStartPoint; i < this->size; i++)
		{
			result.addTerm(this->getCoe(i), this->getIdx(i));

		}
	}
	return result;
}

//���׽� ������ ������ �����ϴ� �޼ҵ��Դϴ�.
//���������δ� ���׽��� ��������� ���ϰ�, ���������� ���Ͽ� �̰��� ���ο� ���׽����� ����ϴ�.
//result��� ���׽Ŀ� ���ο� ���׽��� ��� �������ν� ������ �����մϴ�.
Polynomial Polynomial::operator*(Polynomial target)
{
	Polynomial result;

	for (int i = 0; i < this->size; i++)
	{
		Polynomial tempPolynomial;
		for (int j = 0; j < target.size; j++)
		{
			int tempCoe = this->getCoe(i) * target.getCoe(j);
			int tempIdx = this->getIdx(i) + target.getIdx(j);
			tempPolynomial.addTerm(tempCoe, tempIdx);
		}
		result = result + tempPolynomial;
	}
	return result;
}

//UserControl

//���׽��� ����ڿ��� �Է¹޾� ����� �޼ҵ��Դϴ�.
//����� 0�϶�, ������ 0�϶� ����ó���� �Է��� ����մϴ�.
void Polynomial::makeNewPolynomial()
{
	while (true)
	{
		int numCoe, numIdx;					//numCoe = ���, numIdx = ����
		std::cin >> numCoe >> numIdx;

		if (numCoe != 0)						//����� 0�̸� �����Ѵ�.
			this->addTerm(numCoe, numIdx);	//0�� �ƴϸ� �迭�� �׸� �߰�

		if (numIdx == 0)					//������ 0�� ��� �Է� ����
			break;
	}
}

//���׽��� ����ϴ� �޼ҵ��Դϴ�.
//��� �� �پ��� ���ܵ��� ó���մϴ�.
void Polynomial::print()
{
	if (size == 0)						//������� 0�ΰ��
	{
		std::cout << '0' << '\n';
		return;
	}
	for (int i = 0; i < this->getSize(); i++)
	{
		std::string coe, idx;
		if (this->getCoe(i) == -1)
			if (this->getIdx(i) == 0)	//����� -1�ε� ������ 0�ΰ�� -1�� ǥ��
				coe = "-1";
			else						//����� 1�ε� ������ �����ϸ� -x^n���·� ǥ��
				coe = "-";
		else if (this->getCoe(i) == 1)
			if (this->getIdx(i) == 0)	//����� 1�ε� ������ 0�� ��� 1�� ǥ��
				coe = "1";
			else						//����� 1�ε� ������ �����ϸ� x^n���·� ǥ��
				coe = "";
		else							//����� -1, 0, 1�� �ƴѰ�� �״�� (0�ΰ��� ���׽Ŀ� �����������)
			coe = std::to_string(this->getCoe(i));

		if (this->getIdx(i) == 0)	//������ 0�� ��� n���� ǥ��
			idx = "";
		else if (this->getIdx(i) == 1)	//������ 1�� ��� nx�� ǥ��
			idx = "x";
		else						//������ 0, 1�� �ƴϸ� �״��
			idx = "x^" + std::to_string(this->getIdx(i));

		std::cout << coe << idx;	//�� ���ǹ��鿡 ���� ��ȯ�� �� ���
		if (i + 1 < this->getSize())		//������ ����� �ƴ� ��� + ���
			std::cout << " + ";
	}
}