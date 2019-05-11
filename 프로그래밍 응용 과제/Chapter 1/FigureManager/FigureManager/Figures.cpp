#include "Figures.h"

//Initializer

Figures::Figures()
{

}
Figures::Figures(int iMaxSize)			//생성자, 최대크기 지정 및 동적배열 할당
{
	capacity = iMaxSize;
	circleArr = new Circle[capacity];
	size = -1;
}
Figures::~Figures()
{
	delete[] circleArr;					//배열에 있는 모든 객체(도형)에 대해 소멸자 호출
}

//Methods

void Figures::addFigure()
{
	if (size + 1 >= capacity)			//최대 도형수 초과하려 할 때
	{
		printExceptionMsg(1);
		return;
	}
	circleArr[++size].setData();
	return;
}
void Figures::removeFigure()
{
	if (isEmpty())						//배열이 비어있으면 무시
	{
		printExceptionMsg(0);
		return;
	}

	std::string inputId;				//사용자에게 ID 입력받음
	std::cout << "삭제할 도형의 ID를 입력하세요 : ";
	std::cin >> inputId;

	for (int i = 0; i <= size; i++)		//완전탐색
	{
		if (circleArr[i].getId() == inputId)	//사용자가 찾는 ID가 존재하면
		{
			for (int j = i; j < size; j++)		//삭제할 도형 위치에서 한칸씩 당겨 덮어씌운다.
				circleArr[j] = circleArr[j + 1];
			std::cout << "ID : " << inputId << "가 삭제되었습니다.\n";
			circleArr[size--].~Circle();			//배열 마지막위치에 데이터가 남아있으니 소멸자 호출
			return;
		}
	}
	std::cout << "삭제할 도형을 찾지 못했습니다.\n";	//완전탐색 후 데이터를 찾지 못했을 때
}
void Figures::printAll()
{
	if (isEmpty())		//배열이 비어있으면 무시
	{
		printExceptionMsg(0);
		return;
	}
	for (int i = 0; i <= size; i++)	//안비어있으면 전체출력
		circleArr[i].print();
}

//Utility

bool Figures::isEmpty()			//배열이 비어있으면 TRUE, 아니면 FALSE 반환
{
	return size > -1 ? false : true;
}
void Figures::printExceptionMsg(int iCase)	//메세지 출력 메소드
{
	std::string exceptionMsg;
	switch (iCase)
	{
	case 0:
		exceptionMsg = "도형이 하나도 없습니다.\n";
		break;
	case 1:
		exceptionMsg = "도형이 꽉차서 더 추가할 수 없습니다.\n";
		break;
	}
	std::cout << "[SYSTEM] : " << exceptionMsg << '\n';
}