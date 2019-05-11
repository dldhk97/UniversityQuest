#pragma once
#include "Element.h"
#include "Stack.h"
class Formula
{
private:
	Element *postfix;	//������ �Ǵ� ���� ������ �迭
	int size;			//�迭�� ũ��, �迭 �޸� �Ҵ��̳� ����ǥ��� ��� �� ���
public:
	Formula();
	~Formula();

	//����ǥ��� ��ȯ
	void saveAsPostfix(const std::string infix);	//����ǥ����� ����ǥ������� ��ȯ�Ͽ� �����ϴ� ����
	int predictSize(const std::string infix);		//����ǥ����� �м��Ͽ� size�� ���
	void convert(const std::string infix);			//���������� ����ǥ������� ��ȯ

	//����ǥ���
	void printPostfix();							//����� ����ǥ��� ���
	int calculate();								//����ǥ����� ����Ͽ� ��ȯ

	//������ ���
	int processUnaryOperator(int inputA, char symbol);				//��ȣ(����)������ ���
	int processOperator(int inputA, int inputB, char iOperator);	//�Ϲݿ����� ���

	//����ǥ��� ��ȿ�� �Ǵ� �� ����
	std::string refineInfix(const std::string infix);						//����ǥ����� �����ϴ� ����
	bool isContainCharacter(const std::string infix);						//����, �����ڰ� �ƴ� ���ڰ� �ִ��� Ȯ��
	bool isIncorrectBracket(const std::string infix);						//��ȣ¦�� Ʋ���� Ȯ��
	std::string processWhitespace(const std::string infix);					//������ ����
	std::string processSign(const std::string infix);						//+,-�� ��ȣ���� �Ǵ��Ͽ� #,~�� ��ü
	bool isIncorrectOperator(const std::string infix);						//�����ڰ� �߸� ���̴��� �Ǵ�

	//��ƿ��Ƽ
	bool isOperator(char iChar);					//���������� �Ǵ�
	bool isPureOperator(char iChar);				//��ȣ�����ڰ� �ƴ� ������ ���������� �Ǵ�
	int getPriority(char iOperator);				//�������� �켱������ ��ȯ
};

