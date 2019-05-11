#include "Figures.h"

//Initializer

Figures::Figures()
{

}
Figures::Figures(int iMaxSize)			//������, �ִ�ũ�� ���� �� �����迭 �Ҵ�
{
	capacity = iMaxSize;
	circleArr = new Circle[capacity];
	size = -1;
}
Figures::~Figures()
{
	delete[] circleArr;					//�迭�� �ִ� ��� ��ü(����)�� ���� �Ҹ��� ȣ��
}

//Methods

void Figures::addFigure()
{
	if (size + 1 >= capacity)			//�ִ� ������ �ʰ��Ϸ� �� ��
	{
		printExceptionMsg(1);
		return;
	}
	circleArr[++size].setData();
	return;
}
void Figures::removeFigure()
{
	if (isEmpty())						//�迭�� ��������� ����
	{
		printExceptionMsg(0);
		return;
	}

	std::string inputId;				//����ڿ��� ID �Է¹���
	std::cout << "������ ������ ID�� �Է��ϼ��� : ";
	std::cin >> inputId;

	for (int i = 0; i <= size; i++)		//����Ž��
	{
		if (circleArr[i].getId() == inputId)	//����ڰ� ã�� ID�� �����ϸ�
		{
			for (int j = i; j < size; j++)		//������ ���� ��ġ���� ��ĭ�� ��� ������.
				circleArr[j] = circleArr[j + 1];
			std::cout << "ID : " << inputId << "�� �����Ǿ����ϴ�.\n";
			circleArr[size--].~Circle();			//�迭 ��������ġ�� �����Ͱ� ���������� �Ҹ��� ȣ��
			return;
		}
	}
	std::cout << "������ ������ ã�� ���߽��ϴ�.\n";	//����Ž�� �� �����͸� ã�� ������ ��
}
void Figures::printAll()
{
	if (isEmpty())		//�迭�� ��������� ����
	{
		printExceptionMsg(0);
		return;
	}
	for (int i = 0; i <= size; i++)	//�Ⱥ�������� ��ü���
		circleArr[i].print();
}

//Utility

bool Figures::isEmpty()			//�迭�� ��������� TRUE, �ƴϸ� FALSE ��ȯ
{
	return size > -1 ? false : true;
}
void Figures::printExceptionMsg(int iCase)	//�޼��� ��� �޼ҵ�
{
	std::string exceptionMsg;
	switch (iCase)
	{
	case 0:
		exceptionMsg = "������ �ϳ��� �����ϴ�.\n";
		break;
	case 1:
		exceptionMsg = "������ ������ �� �߰��� �� �����ϴ�.\n";
		break;
	}
	std::cout << "[SYSTEM] : " << exceptionMsg << '\n';
}