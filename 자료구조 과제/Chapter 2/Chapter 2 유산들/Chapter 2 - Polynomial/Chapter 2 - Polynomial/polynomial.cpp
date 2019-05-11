#include <iostream>
#include "Polynomial.h"

const int defaultCapacity = 16;		//기본 용량을 설정합니다. 1차원 배열에 계수와 지수 모두 저장되기 때문에 실질적으로 한 수는 배열 2칸을 차지합니다.

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

//다항식에 수를 더하는 메소드입니다.
//다항식 내부의 배열에 직접적으로 관여하며 기본적으로는 계수를 더해주는 역할을 합니다.
//더한 계수가 0이되면 그 지수를 삭제하기도 하며, 기존에 지수가 존재하지 않으면 새로 값을 추가합니다.
//수를 입력할 때 중복, 삭제,추가를 모두 담당합니다.
void Polynomial::addItem(int coe, int idx)
{
	for (int i = 0; i < size; i = i + 2)
	{
		if (arr[i + 1] == idx)			//새로추가할 값의 지수가 기존에 식에 존재하면
		{
			int sumCoe = arr[i] + coe;
			if (sumCoe == 0)			//새로추가할 계소와 기존지수의 합이 0이면
			{
				removeItem(idx);		//아이템 삭제
			}
			else
			{
				arr[i] = sumCoe;		//합이 0이 아니면 더한값을 계수로 넣는다.
			}
			return;
		}
	}

	if (size + 2 > capacity)			//배열이 꽉찰거같으면 확장
	{
		capacity = capacity * 2;
		resizeCapacity(capacity);
	}
	arr[size] = coe;					//짝수에는 계수 저장
	arr[size + 1] = idx;				//홀수에는 지수 저장
	size = size + 2;
}

//다항식에 존재하는 수를 빼는 메소드입니다.
//변수로 지수를 입력하면 해당 다항식 내부에 해당 지수가 존재하면 삭제합니다.
//addItem 메소드 실행 중 계수끼리 더했을 때 0이 나오는 경우 이 메소드가 호출됩니다.
void Polynomial::removeItem(int idx)
{
	for (int i = 0; i < size; i = i + 2)
	{
		if (arr[i + 1] == idx)					//삭제할 지수를 찾았으면
		{
			arr[i] = NULL;
			arr[i + 1] = NULL;
			for (int j = i; j < size - 2; j++)	//삭제할 부분을 덮어씌우고 두칸식 당긴다.
			{
				arr[j] = arr[j + 2];
			}
			break;
		}
	}
	size = size - 2;

	if (size < capacity / 2 && size > defaultCapacity)			//메모리가 과다하게 사용되는지 체크하고, 용량을 필요에 맞게 줄인다.
	{
		capacity = capacity / 2;
		resizeCapacity(capacity);
	}
}

//다항식에 동적할당된 배열의 최대용량(Capacity)를 재조정합니다.
//변수에 변경하고자 하는 크기를 입력하면 임시배열에 기존 배열을 완전복사합니다.
//이후 기존 배열의 크기를 재할당하고, 다시 임시배열에서 완전복사합니다.
void Polynomial::resizeCapacity(int iCapacity)	//용량을 iCapacity로 변경한다.
{
	int *tempArr = new int[size];				//임시배열에 현재배열을 저장
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	delete[] arr;
	arr = new int[iCapacity];					//기존배열 용량확대하여 재할당

	for (int i = 0; i < size; i++)				//임시배열에 있는 정보 삽입
	{
		arr[i] = tempArr[i];
	}

	delete[] tempArr;							//임시배열 메모리 해제
}

//Operators

//다항식 끼리의 덧셈을 구현하는 메소드입니다.
//다항식과 다항식이 주어지면 각자의 지수끼리 비교하여
//지수가 큰 순으로 덧셈하여 최종적으로는 내림차순으로 다항식이 만들어집니다.
Polynomial Polynomial::operator+(Polynomial target)
{
	Polynomial result;
	int thisStartPoint = 0;								//this 다항식 중 넣은 숫자의 지점
	int targetStartPoint = 0;							//target 다항식 중 이미 넣은 숫자의 지점

	if (this->size == 0)								//a = b + c 중 b 혹은 c가 비어있다면 나머지를 그대로 출력함.
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

	for (int i = thisStartPoint; i < this->size; i = i + 2)			//두 다항식의 각 지수별로 따로따로 비교한다.
	{																//어느 한 다항식의 지수가 더 크다면 additem을 호출하여 지수가 큰 쪽을 result 다항식에 더한다.
		for (int j = targetStartPoint; j < target.size; j = j + 2)	//집어넣은 수는 이미 더하였기 때문에 탐색대상에서 제외한다(thisStartPoint = i + 2 or targetStartPoint = j + 2)
		{
			if (this->getIdx(i) > target.getIdx(j))
			{
				result.addItem(this->getCoe(i), this->getIdx(i));
				thisStartPoint = i + 2;
				break;												//this 다항식의 for문은 외부에 있기 때문에 break로 내부 for문을 종료시키고, this다항식의 다음 지수를 비교해야한다.
			}
			else
			{
				result.addItem(target.getCoe(j), target.getIdx(j));	//target다항식의 지수가 더 큰 경우에는 result 다항식에 더하고 이 수를 탐색대상에서 제외한다.
				targetStartPoint = j + 2;							//target다항식의 for문은 내부에 있기 때문에 break를 해줄 필요가 없다.
			}
		}
	}

	if (targetStartPoint < target.size)								//위 2중 for문이 종료되었다면 운좋게도 짝이 맞아 모든 지수가 처리되었을 수도 있지만, 아닌 경우도 있기 때문에
	{																//target과 this 다항식의 남은 수들을 모두 result 다항식에 더해줘야 한다.
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

//다항식 끼리의 곱셈을 구현하는 메소드입니다.
//내부적으로는 다항식의 계수끼리는 곱하고, 지수끼리는 더하여 이것을 새로운 다항식으로 만듭니다.
//result라는 다항식에 새로운 다항식을 계속 더함으로써 곱셈을 구현합니다.
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