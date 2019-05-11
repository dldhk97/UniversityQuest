#include <iostream>
#include "Polynomial.h"

const int defaultCapacity = 16;		//�⺻ �뷮�� �����մϴ�. 1���� �迭�� ����� ���� ��� ����Ǳ� ������ ���������� �� ���� �迭 2ĭ�� �����մϴ�.

Polynomial::Polynomial()
{
	capacity = defaultCapacity;
	arr = new int[capacity];
	size = 0;
}

void Polynomial::deleteMemory()
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
	return arr[index];
}
int Polynomial::getIdx(int index)
{
	return arr[index + 1];
}

//Methods

//���׽Ŀ� ���� ���ϴ� �޼ҵ��Դϴ�.
//���׽� ������ �迭�� ���������� �����ϸ� �⺻�����δ� ����� �����ִ� ������ �մϴ�.
//���� ����� 0�̵Ǹ� �� ������ �����ϱ⵵ �ϸ�, ������ ������ �������� ������ ���� ���� �߰��մϴ�.
//���� �Է��� �� �ߺ�, ����,�߰��� ��� ����մϴ�.
void Polynomial::addItem(int coe, int idx)
{
	for (int i = 0; i < size; i = i + 2)
	{
		if (arr[i + 1] == idx)			//�����߰��� ���� ������ ������ �Ŀ� �����ϸ�
		{
			int sumCoe = arr[i] + coe;
			if (sumCoe == 0)			//�����߰��� ��ҿ� ���������� ���� 0�̸�
			{
				removeItem(idx);		//������ ����
			}
			else
			{
				arr[i] = sumCoe;		//���� 0�� �ƴϸ� ���Ѱ��� ����� �ִ´�.
			}
			return;
		}
	}

	if (size + 2 > capacity)			//�迭�� �����Ű����� Ȯ��
	{
		capacity = capacity * 2;
		resizeCapacity(capacity);
	}
	arr[size] = coe;					//¦������ ��� ����
	arr[size + 1] = idx;				//Ȧ������ ���� ����
	size = size + 2;
}

//���׽Ŀ� �����ϴ� ���� ���� �޼ҵ��Դϴ�.
//������ ������ �Է��ϸ� �ش� ���׽� ���ο� �ش� ������ �����ϸ� �����մϴ�.
//addItem �޼ҵ� ���� �� ������� ������ �� 0�� ������ ��� �� �޼ҵ尡 ȣ��˴ϴ�.
void Polynomial::removeItem(int idx)
{
	for (int i = 0; i < size; i = i + 2)
	{
		if (arr[i + 1] == idx)					//������ ������ ã������
		{
			arr[i] = NULL;
			arr[i + 1] = NULL;
			for (int j = i; j < size - 2; j++)	//������ �κ��� ������ ��ĭ�� ����.
			{
				arr[j] = arr[j + 2];
			}
			break;
		}
	}
	size = size - 2;

	if (size < capacity / 2 && size > defaultCapacity)			//�޸𸮰� �����ϰ� ���Ǵ��� üũ�ϰ�, �뷮�� �ʿ信 �°� ���δ�.
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
	int *tempArr = new int[size];				//�ӽù迭�� ����迭�� ����
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	delete[] arr;
	arr = new int[iCapacity];					//�����迭 �뷮Ȯ���Ͽ� ���Ҵ�

	for (int i = 0; i < size; i++)				//�ӽù迭�� �ִ� ���� ����
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
		for (int i = 0; i < target.size; i = i + 2)
		{
			result.addItem(target.getCoe(i), target.getIdx(i));
		}
		return result;
	}
	else if (target.size == 0)
	{
		for (int i = 0; i < this->size == 0; i = i + 2)
		{
			result.addItem(this->getCoe(i), this->getIdx(i));
		}
	}

	for (int i = thisStartPoint; i < this->size; i = i + 2)			//�� ���׽��� �� �������� ���ε��� ���Ѵ�.
	{																//��� �� ���׽��� ������ �� ũ�ٸ� additem�� ȣ���Ͽ� ������ ū ���� result ���׽Ŀ� ���Ѵ�.
		for (int j = targetStartPoint; j < target.size; j = j + 2)	//������� ���� �̹� ���Ͽ��� ������ Ž����󿡼� �����Ѵ�(thisStartPoint = i + 2 or targetStartPoint = j + 2)
		{
			if (this->getIdx(i) > target.getIdx(j))
			{
				result.addItem(this->getCoe(i), this->getIdx(i));
				thisStartPoint = i + 2;
				break;												//this ���׽��� for���� �ܺο� �ֱ� ������ break�� ���� for���� �����Ű��, this���׽��� ���� ������ ���ؾ��Ѵ�.
			}
			else
			{
				result.addItem(target.getCoe(j), target.getIdx(j));	//target���׽��� ������ �� ū ��쿡�� result ���׽Ŀ� ���ϰ� �� ���� Ž����󿡼� �����Ѵ�.
				targetStartPoint = j + 2;							//target���׽��� for���� ���ο� �ֱ� ������ break�� ���� �ʿ䰡 ����.
			}
		}
	}

	if (targetStartPoint < target.size)								//�� 2�� for���� ����Ǿ��ٸ� �����Ե� ¦�� �¾� ��� ������ ó���Ǿ��� ���� ������, �ƴ� ��쵵 �ֱ� ������
	{																//target�� this ���׽��� ���� ������ ��� result ���׽Ŀ� ������� �Ѵ�.
		for (int i = targetStartPoint; i < target.size; i = i + 2)
		{
			result.addItem(target.getCoe(i), target.getIdx(i));

		}
	}
	else if (thisStartPoint < this->size)
	{
		for (int i = thisStartPoint; i < this->size; i = i + 2)
		{
			result.addItem(this->getCoe(i), this->getIdx(i));

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

	for (int i = 0; i < this->size; i = i + 2)
	{
		Polynomial tempPolynomial;
		for (int j = 0; j < target.size; j = j + 2)
		{
			int tempCoe = this->getCoe(i) * target.getCoe(j);
			int tempIdx = this->getIdx(i) + target.getIdx(j);
			tempPolynomial.addItem(tempCoe, tempIdx);
		}
		result = result + tempPolynomial;
	}
	return result;
}