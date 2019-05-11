#pragma once
#include "Element.h"
#include "Stack.h"
class Formula
{
private:
	Element *postfix;	//연산자 또는 수를 저장할 배열
	int size;			//배열의 크기, 배열 메모리 할당이나 후위표기법 출력 시 사용
public:
	Formula();
	~Formula();

	//후위표기식 변환
	void saveAsPostfix(const std::string infix);	//중위표기식을 후위표기식으로 변환하여 저장하는 뼈대
	int predictSize(const std::string infix);		//중위표기식을 분석하여 size를 계산
	void convert(const std::string infix);			//실질적으로 후위표기식으로 변환

	//후위표기식
	void printPostfix();							//저장된 후위표기식 출력
	int calculate();								//후위표기식을 계산하여 반환

	//연산자 계산
	int processUnaryOperator(int inputA, char symbol);				//부호(단항)연산자 계산
	int processOperator(int inputA, int inputB, char iOperator);	//일반연산자 계산

	//중위표기식 유효성 판단 및 정제
	std::string refineInfix(const std::string infix);						//중위표기식을 정제하는 뼈대
	bool isContainCharacter(const std::string infix);						//숫자, 연산자가 아닌 문자가 있는지 확인
	bool isIncorrectBracket(const std::string infix);						//괄호짝이 틀린지 확인
	std::string processWhitespace(const std::string infix);					//공백을 지움
	std::string processSign(const std::string infix);						//+,-가 부호인지 판단하여 #,~로 대체
	bool isIncorrectOperator(const std::string infix);						//연산자가 잘못 쓰이는지 판단

	//유틸리티
	bool isOperator(char iChar);					//연산자인지 판단
	bool isPureOperator(char iChar);				//부호연산자가 아닌 순수한 연산자인지 판단
	int getPriority(char iOperator);				//연산자의 우선순위를 반환
};

