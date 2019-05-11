#include "Formula.h"

///////////////
//기본 생성자//
///////////////
Formula::Formula()
{
}
Formula::~Formula()
{
	if (postfix != nullptr)
		delete[] postfix;
}

///////////////////
//후위표기식 변환//
///////////////////
void Formula::saveAsPostfix(const std::string infix)
{
	std::string refinedInfix = refineInfix(infix);		//중위표기식 정제
	size = predictSize(refinedInfix);					//수와 연산자를 위한 메모리 측정
	postfix = new Term[size];							//수와 연산자를 저장할 메모리 할당
	convert(refinedInfix);								//후위표기식으로 저장
}

//입력받은 중위표기식을 분석하여 몇개의 수와 연산자가 필요한지 합산하여 반환
int Formula::predictSize(const std::string infix)
{
	int predictedSize = 0;
	bool continuous = false;

	for (int i = 0; i < infix.length(); i++)
	{
		if ('0' <= infix[i] && infix[i] <= '9')		//숫자일경우 지속성을 가짐
		{
			continuous = true;
		}
		else if (isOperator(infix[i]))	//연산자인경우
		{
			if (continuous)				//이전 값이 숫자일경우
			{
				predictedSize++;		//숫자들이 저장되야하니 용량값을 하나 올림
				continuous = false;		//지속성 초기화
			}
			predictedSize++;			//연산자가 저장되야하니 용량값 하나 올림
		}
	}
	predictedSize++;					//마지막값을 저장해야하니 용량값 하나 올림
	return predictedSize;
}

//중위표기식을 후위표기식으로 바꾸어 저장
void Formula::convert(const std::string infix)
{
	Stack<char> operatorStack;
	int resultArrIndex = 0;
	int numCount = 0;

	for (int i = 0; i < infix.length(); i++)
	{
		if ('0' <= infix[i] && infix[i] <= '9')		//숫자라면 연속될 수 있으니 바로 추가하지 않는다.
		{
			numCount++;
			continue;
		}
		//숫자가 안나온경우
		if (0 < numCount)							//연속되던 숫자가 있으면 배열에 추가한다.
		{
			std::string num = infix.substr(i - numCount, numCount);
			postfix[resultArrIndex++].setData(num);
			numCount = 0;
		}

		if (infix[i] == '(')				//여는괄호면 연산자스택에 push
		{
			operatorStack.push('(');
		}
		else if (infix[i] == ')')			//닫는괄호면 연산자스택에서 여는괄호가 나올때까지 결과스택에 pop
		{
			while (operatorStack.peek() != '(')
			{
				postfix[resultArrIndex++].setData(operatorStack.pop());
			}
			operatorStack.pop();			//연산자스택의 ( 괄호 버리기
		}
		else								//연산자일때
		{
			if (!operatorStack.isEmpty())	//자신의 우선순위보다 낮은 연산자가 top에올때까지 연산자를 pop, 다만 ~,#의 경우는 제외한다.
			{
				infix[i];
				while (getPriority(operatorStack.peek()) >= getPriority(infix[i]) && isPureOperator(infix[i]))
				{
					postfix[resultArrIndex++].setData(operatorStack.pop());
				}
			}
			operatorStack.push(infix[i]);
		}
	}
	if (0 < numCount)					//연속되던 숫자가 있었으면 배열에 추가한다.
	{
		std::string num = infix.substr(infix.length() - numCount, numCount);
		postfix[resultArrIndex++].setData(num);
	}
	while (!operatorStack.isEmpty())	//연산자스택이 비어있지않다면 남은연산자를 모두 결과스택에서 pop
	{
		postfix[resultArrIndex++].setData(operatorStack.pop());
	}
}

//////////////
//후위표기식//
//////////////

//후위표기식 출력
void Formula::printPostfix()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << postfix[i].getStrValue() << " ";
	}
}

///////////////
//연산자 계산//
///////////////

//부호 연산자 계산
int Formula::processUnaryOperator(int inputA, char symbol)
{
	if (symbol == '~')
		return -inputA;
	else
		return inputA;
}
//A,B,연산자를 받으면 연산결과를 리턴
int Formula::processOperator(int inputA, int inputB, char iOperator)
{
	int squareResult = 1;
	char exceptionCode;
	switch (iOperator)
	{
	case '^':
		for (int i = 0; i < inputB; i++)
		{
			squareResult *= inputA;
		}
		return squareResult;
	case '*':
		return inputA * inputB;
	case '/':
		if (inputB == 0)
		{
			exceptionCode = '3';
			throw std::exception(&exceptionCode);
		}
		return inputA / inputB;
	case '%':
		if (inputB == 0)
		{
			exceptionCode = '3';
			throw std::exception(&exceptionCode);
		}
		return (int)inputA % (int)inputB;
	case '+':
		return inputA + inputB;
	case '-':
		return inputA - inputB;
	}
	exceptionCode = '6';
	throw std::exception(&exceptionCode);
}

//////////////////////////////////
//중위표기식 유효성 판단 및 정제//
//////////////////////////////////

//중위표기식이 유효한지 확인하고, 공백제거 및 연산자인지 부호인지 판단하여 교체 후 반환
std::string Formula::refineInfix(const std::string infix)
{
	std::string refinedInfix;
	char exceptionCode;
	if (isContainCharacter(infix))						//부적절한 문자 체크
	{
		exceptionCode = '0';
		throw std::exception(&exceptionCode);
	}
	if (isIncorrectBracket(infix))						//부적절한 괄호쌍 체크
	{
		exceptionCode = '1';
		throw std::exception(&exceptionCode);
	}
	refinedInfix = processWhitespace(infix);			//공백제거
	if (refinedInfix.length() <= 0)						//공백제거했는데 식이 없으면
	{
		exceptionCode = '4';
		throw std::exception(&exceptionCode);
	}
	refinedInfix = processSign(refinedInfix);			//부호처리
	if (isIncorrectOperator(refinedInfix))				//부적절한 연산자 체크
	{
		exceptionCode = '2';
		throw std::exception(&exceptionCode);
	}
	return refinedInfix;
}

//숫자와 필요한 특수기호를 제외한 문자가 있으면 true반환
bool Formula::isContainCharacter(const std::string infix)
{
	for (int i = 0; i < infix.length(); i++)
	{
		if (!(('0' <= infix[i] && infix[i] <= '9') || isOperator(infix[i]) || infix[i] == '(' || infix[i] == ')' || infix[i] == ' '))	//숫자,연산자,괄호,공백이면 허용, 아니면 예외처리
		{
			if (infix[i] == '.')
			{
				char exceptionCode = '5';
				throw std::exception(&exceptionCode);
			}
			return true;
		}
	}
	return false;
}

//괄호쌍이 안맞으면 true 반환
bool Formula::isIncorrectBracket(const std::string infix)
{
	Stack<char> bracketStack;
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			bracketStack.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			if (bracketStack.peek() == '(')
				bracketStack.pop();
			else
				return true;
		}
	}
	if (bracketStack.isEmpty())
		return false;
	else
		return true;
}

//공백 제거
std::string Formula::processWhitespace(const std::string infix)
{
	std::string resultStr;
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] != ' ')
			resultStr.push_back(infix[i]);
	}
	return resultStr;
}
//부호인지 연산자인지 판단하고 변환해서 저장
std::string Formula::processSign(const std::string infix)
{
	std::string resultStr = infix;
	char sign;
	for (int i = 0; i < resultStr.length(); i++)
	{
		if (resultStr[i] == '+' || resultStr[i] == '-')		//이번 문자가 + 또는 - 라면
		{
			if (resultStr[i] == '+')		//부호에 맞게 대체문자 지정
				sign = '#';
			else
				sign = '~';

			if (i == 0)		//맨 앞에있는 경우는 부호이므로, 부호로 대체
			{
				resultStr[i] = sign;
				continue;
			}
			else if (isOperator(resultStr[i - 1]) || resultStr[i - 1] == '(')	//이전 문자가 연산자거나 여는괄호 라면 이번 문자는 부호
			{
				resultStr[i] = sign;
				continue;
			}
		}
	}
	return resultStr;
}

//연산자가 올바르게 사용되는지 확인
bool Formula::isIncorrectOperator(const std::string infix)
{
	if (isPureOperator(infix[0]))		//첫번째 연산자가 순수연산자인경우(부호,숫자가 아님)
	{
		return true;
	}
	for (int i = 1; i < infix.length(); i++)
	{
		if (isPureOperator(infix[i]) && isPureOperator(infix[i - 1]))		//연산자가 연속으로 있는경우 ex /*, *+, -+
		{
			return true;
		}
		else if (isPureOperator(infix[i]) && isOperator(infix[i - 1]))	//연산자 앞에 부호가 있는경우 ex #*,~/,#/...
		{
			return true;
		}
		else if (isPureOperator(infix[i - 1]) && infix[i] == ')')	//연산자 뒤에 닫는 괄호가 있는경우 ex *), +), -)
		{
			return true;
		}
		else if ('0' < infix[i - 1] && infix[i - 1] < '9' && infix[i] == '(')	//숫자 뒤에 괄호가 나올 경우 ex 24(, 13(, ...
		{
			return true;
		}
		else if ('0' < infix[i] && infix[i] < '9' && infix[i - 1] == ')')	//닫는 괄호뒤에 숫자가 나올 경우 ex (~)24, (~)13, ...
		{
			return true;
		}
	}
	if (isOperator(infix[infix.length() - 1]))		//수식 마지막에 연산자가 있는 경우
	{
		return true;
	}
	return false;
}

////////////
//유틸리티//
////////////

//문자를 입력받아 연산자이면 true를, 아니면 false를 반환
bool Formula::isOperator(char iChar)
{
	return getPriority(iChar) != -1 ? true : false;
}
//문자를 입력받아 부호가 아닌 순수 연산자이면 true를, 아니면 false를 반환
bool Formula::isPureOperator(char iChar)
{
	if (iChar == '#' || iChar == '~')
		return false;
	return getPriority(iChar) != -1 ? true : false;
}
//연산자를 입력받아 우선순위를 반환
int Formula::getPriority(char iOperator)
{
	if (iOperator == '~' || iOperator == '#')		//단항
		return 4;
	else if (iOperator == '^')						//제곱
		return 3;
	else if (iOperator == '*' || iOperator == '/' || iOperator == '%')	//좌측결합
		return 2;
	else if (iOperator == '+' || iOperator == '-')		//좌측결합
		return 1;
	else
		return -1;
}

Term Formula::getTerm(int index)
{
	return postfix[index];
}

int Formula::getSize()
{
	return size;
}