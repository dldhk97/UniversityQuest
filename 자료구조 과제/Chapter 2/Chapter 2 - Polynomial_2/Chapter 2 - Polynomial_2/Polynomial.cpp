#include "Polynomial.h"

const int defaultCapacity = 16;		//기본 용량을 설정합니다.

Polynomial::Polynomial()
{
	capacity = defaultCapacity;		//초기 용량을 설정합니다.
	arr = new Term[capacity];		//항을 저장할 배열을 할당합니다.
	size = 0;						//비어있으므로 실제크기를 0으로 합니다.
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

//다항식 내부에 항을 더하는 메소드입니다. (ex. 식 : x^2 + 1, coe = 3, idx = 1 -> x^2 + 3x + 1)
//더한 계수가 0이되면 항을 삭제하기도 하며, 기존에 지수가 존재하지 않으면 새로 항을 추가합니다.
//계수를 더할때 중복, 삭제, 추가를 모두 처리합니다.
void Polynomial::addTerm(int coe, int idx)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getIdx() == idx)			//새로추가할 항의 지수가 기존의 식에 존재하면
		{
			int sumCoe = arr[i].getCoe() + coe;
			if (sumCoe == 0)			//새로추가할 항의 계수와 기존계수의 합이 0이면
			{
				removeTerm(idx);		//아이템 삭제
			}
			else
			{
				arr[i].setCoe(sumCoe);		//합이 0이 아니면 더한값을 계수로 넣는다.
			}
			return;
		}
	}

	//새로추가할 항의 지수가 기존의 식에 존재하지 않으면

	if (size + 1 > capacity)			//배열이 꽉찰거같으면 확장
	{
		capacity = capacity * 2;		//기존 최대용량의 2배로 확장
		resizeCapacity(capacity);
	}

	arr[size].setCoe(coe);				//계수 저장
	arr[size].setIdx(idx);				//지수 저장
	size = size + 1;					//계수하나, 지수하나가 저장됬으므로 사이즈 증가
}

//다항식에 존재하는 항을를 빼는 메소드입니다.
//변수로 지수를 입력하면 해당 다항식 내부에 해당 지수가 존재하면 삭제합니다.
//addTerm 메소드 실행 중 계수끼리 더했을 때 0이 나오는 경우 이 메소드가 호출됩니다.
void Polynomial::removeTerm(int idx)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getIdx() == idx)					//삭제할 지수를 찾았으면
		{
			arr[i].setIdx(NULL);				//삭제할 수의 계수부분 삭제
			arr[i].setCoe(NULL);				//삭제할 수의 지수부분 삭제

			for (int j = i; j < size - 1; j++)	//삭제할 부분을 덮어씌우고 그 이후의 들을 두칸식 당긴다.
			{
				arr[j] = arr[j + 1];
			}
			break;
		}
	}
	size = size - 1;		//항이 하나 삭제됬으므로 사이즈 감소

	if (size < capacity / 2 && size > defaultCapacity)			//메모리가 과다하게 사용되는지 체크하고, 최대용량을 반으로 줄인다.
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
	Term *tempArr = new Term[size];				//임시배열에 현재배열을 저장
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = arr[i];
	}

	delete[] arr;
	arr = new Term[iCapacity];					//기존배열 용량확대하여 재할당

	for (int i = 0; i < size; i++)				//임시배열에 있는 정보 삽입(깊은복사)
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
		for (int i = 0; i < target.size; i++)		//b를 그대로 출력
		{
			result.addTerm(target.getCoe(i), target.getIdx(i));
		}
		return result;
	}
	else if (target.size == 0)							//c를 그대로 출력
	{
		for (int i = 0; i < this->size; i++)
		{
			result.addTerm(this->getCoe(i), this->getIdx(i));
		}
		return result;
	}

	for (int i = thisStartPoint; i < this->size; i++)			//두 다항식의 각 지수별로 따로따로 비교한다.
	{															//어느 한 다항식의 지수가 더 크다면 addTerm을 호출하여 지수가 큰 쪽을 result 다항식에 더한다.
		for (int j = targetStartPoint; j < target.size; j++)	//집어넣은 수는 이미 더하였기 때문에 탐색대상에서 제외한다(thisStartPoint = i + 1 or targetStartPoint = j + 1)
		{
			if (this->getIdx(i) > target.getIdx(j))
			{
				result.addTerm(this->getCoe(i), this->getIdx(i));
				thisStartPoint = i + 1;
				break;												//this 다항식의 for문은 외부에 있기 때문에 break로 내부 for문을 종료시키고, this다항식의 다음 지수를 비교해야한다.
			}
			else
			{
				result.addTerm(target.getCoe(j), target.getIdx(j));	//target다항식의 지수가 더 큰 경우에는 result 다항식에 더하고 이 수를 탐색대상에서 제외한다.
				targetStartPoint = j + 1;							//target다항식의 for문은 내부에 있기 때문에 break를 해줄 필요가 없다.
			}
		}
	}

	if (targetStartPoint < target.size)								//위 2중 for문이 종료되었다면 운좋게도 짝이 맞아 모든 지수가 처리되었을 수도 있지만, 아닌 경우도 있기 때문에
	{																//남은 한쪽 다항식의 수들을 모두 result 다항식에 더해줘야 한다.
		for (int i = targetStartPoint; i < target.size; i++)		//c가 남았을 때 c의 남은수들을 모두 result에 넣는다.
		{
			result.addTerm(target.getCoe(i), target.getIdx(i));

		}
	}
	else if (thisStartPoint < this->size)							//b가 남았을때 b의 남은수들을 모두 result에 넣는다.
	{
		for (int i = thisStartPoint; i < this->size; i++)
		{
			result.addTerm(this->getCoe(i), this->getIdx(i));

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

//다항식을 사용자에게 입력받아 만드는 메소드입니다.
//계수가 0일때, 지수가 0일때 예외처리와 입력을 담당합니다.
void Polynomial::makeNewPolynomial()
{
	while (true)
	{
		int numCoe, numIdx;					//numCoe = 계수, numIdx = 지수
		std::cin >> numCoe >> numIdx;

		if (numCoe != 0)						//계수가 0이면 무시한다.
			this->addTerm(numCoe, numIdx);	//0이 아니면 배열에 항목 추가

		if (numIdx == 0)					//지수가 0인 경우 입력 종료
			break;
	}
}

//다항식을 출력하는 메소드입니다.
//출력 시 다양한 예외들을 처리합니다.
void Polynomial::print()
{
	if (size == 0)						//결과값이 0인경우
	{
		std::cout << '0' << '\n';
		return;
	}
	for (int i = 0; i < this->getSize(); i++)
	{
		std::string coe, idx;
		if (this->getCoe(i) == -1)
			if (this->getIdx(i) == 0)	//계수가 -1인데 지수가 0인경우 -1만 표시
				coe = "-1";
			else						//계수가 1인데 지수가 존재하면 -x^n형태로 표시
				coe = "-";
		else if (this->getCoe(i) == 1)
			if (this->getIdx(i) == 0)	//계수가 1인데 지수가 0인 경우 1만 표시
				coe = "1";
			else						//계수가 1인데 지수가 존재하면 x^n형태로 표시
				coe = "";
		else							//계수가 -1, 0, 1이 아닌경우 그대로 (0인경우는 다항식에 저장되지않음)
			coe = std::to_string(this->getCoe(i));

		if (this->getIdx(i) == 0)	//지수가 0인 경우 n으로 표시
			idx = "";
		else if (this->getIdx(i) == 1)	//지수가 1인 경우 nx로 표시
			idx = "x";
		else						//지수가 0, 1이 아니면 그대로
			idx = "x^" + std::to_string(this->getIdx(i));

		std::cout << coe << idx;	//위 조건문들에 의해 변환된 항 출력
		if (i + 1 < this->getSize())		//마지막 출력이 아닌 경우 + 출력
			std::cout << " + ";
	}
}