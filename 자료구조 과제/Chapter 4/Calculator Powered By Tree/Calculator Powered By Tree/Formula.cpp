#include "Formula.h"

///////////////
//�⺻ ������//
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
//����ǥ��� ��ȯ//
///////////////////
void Formula::saveAsPostfix(const std::string infix)
{
	std::string refinedInfix = refineInfix(infix);		//����ǥ��� ����
	size = predictSize(refinedInfix);					//���� �����ڸ� ���� �޸� ����
	postfix = new Term[size];							//���� �����ڸ� ������ �޸� �Ҵ�
	convert(refinedInfix);								//����ǥ������� ����
}

//�Է¹��� ����ǥ����� �м��Ͽ� ��� ���� �����ڰ� �ʿ����� �ջ��Ͽ� ��ȯ
int Formula::predictSize(const std::string infix)
{
	int predictedSize = 0;
	bool continuous = false;

	for (int i = 0; i < infix.length(); i++)
	{
		if ('0' <= infix[i] && infix[i] <= '9')		//�����ϰ�� ���Ӽ��� ����
		{
			continuous = true;
		}
		else if (isOperator(infix[i]))	//�������ΰ��
		{
			if (continuous)				//���� ���� �����ϰ��
			{
				predictedSize++;		//���ڵ��� ����Ǿ��ϴ� �뷮���� �ϳ� �ø�
				continuous = false;		//���Ӽ� �ʱ�ȭ
			}
			predictedSize++;			//�����ڰ� ����Ǿ��ϴ� �뷮�� �ϳ� �ø�
		}
	}
	predictedSize++;					//���������� �����ؾ��ϴ� �뷮�� �ϳ� �ø�
	return predictedSize;
}

//����ǥ����� ����ǥ������� �ٲپ� ����
void Formula::convert(const std::string infix)
{
	Stack<char> operatorStack;
	int resultArrIndex = 0;
	int numCount = 0;

	for (int i = 0; i < infix.length(); i++)
	{
		if ('0' <= infix[i] && infix[i] <= '9')		//���ڶ�� ���ӵ� �� ������ �ٷ� �߰����� �ʴ´�.
		{
			numCount++;
			continue;
		}
		//���ڰ� �ȳ��°��
		if (0 < numCount)							//���ӵǴ� ���ڰ� ������ �迭�� �߰��Ѵ�.
		{
			std::string num = infix.substr(i - numCount, numCount);
			postfix[resultArrIndex++].setData(num);
			numCount = 0;
		}

		if (infix[i] == '(')				//���°�ȣ�� �����ڽ��ÿ� push
		{
			operatorStack.push('(');
		}
		else if (infix[i] == ')')			//�ݴ°�ȣ�� �����ڽ��ÿ��� ���°�ȣ�� ���ö����� ������ÿ� pop
		{
			while (operatorStack.peek() != '(')
			{
				postfix[resultArrIndex++].setData(operatorStack.pop());
			}
			operatorStack.pop();			//�����ڽ����� ( ��ȣ ������
		}
		else								//�������϶�
		{
			if (!operatorStack.isEmpty())	//�ڽ��� �켱�������� ���� �����ڰ� top���ö����� �����ڸ� pop, �ٸ� ~,#�� ���� �����Ѵ�.
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
	if (0 < numCount)					//���ӵǴ� ���ڰ� �־����� �迭�� �߰��Ѵ�.
	{
		std::string num = infix.substr(infix.length() - numCount, numCount);
		postfix[resultArrIndex++].setData(num);
	}
	while (!operatorStack.isEmpty())	//�����ڽ����� ��������ʴٸ� ���������ڸ� ��� ������ÿ��� pop
	{
		postfix[resultArrIndex++].setData(operatorStack.pop());
	}
}

//////////////
//����ǥ���//
//////////////

//����ǥ��� ���
void Formula::printPostfix()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << postfix[i].getStrValue() << " ";
	}
}

///////////////
//������ ���//
///////////////

//��ȣ ������ ���
int Formula::processUnaryOperator(int inputA, char symbol)
{
	if (symbol == '~')
		return -inputA;
	else
		return inputA;
}
//A,B,�����ڸ� ������ �������� ����
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
//����ǥ��� ��ȿ�� �Ǵ� �� ����//
//////////////////////////////////

//����ǥ����� ��ȿ���� Ȯ���ϰ�, �������� �� ���������� ��ȣ���� �Ǵ��Ͽ� ��ü �� ��ȯ
std::string Formula::refineInfix(const std::string infix)
{
	std::string refinedInfix;
	char exceptionCode;
	if (isContainCharacter(infix))						//�������� ���� üũ
	{
		exceptionCode = '0';
		throw std::exception(&exceptionCode);
	}
	if (isIncorrectBracket(infix))						//�������� ��ȣ�� üũ
	{
		exceptionCode = '1';
		throw std::exception(&exceptionCode);
	}
	refinedInfix = processWhitespace(infix);			//��������
	if (refinedInfix.length() <= 0)						//���������ߴµ� ���� ������
	{
		exceptionCode = '4';
		throw std::exception(&exceptionCode);
	}
	refinedInfix = processSign(refinedInfix);			//��ȣó��
	if (isIncorrectOperator(refinedInfix))				//�������� ������ üũ
	{
		exceptionCode = '2';
		throw std::exception(&exceptionCode);
	}
	return refinedInfix;
}

//���ڿ� �ʿ��� Ư����ȣ�� ������ ���ڰ� ������ true��ȯ
bool Formula::isContainCharacter(const std::string infix)
{
	for (int i = 0; i < infix.length(); i++)
	{
		if (!(('0' <= infix[i] && infix[i] <= '9') || isOperator(infix[i]) || infix[i] == '(' || infix[i] == ')' || infix[i] == ' '))	//����,������,��ȣ,�����̸� ���, �ƴϸ� ����ó��
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

//��ȣ���� �ȸ����� true ��ȯ
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

//���� ����
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
//��ȣ���� ���������� �Ǵ��ϰ� ��ȯ�ؼ� ����
std::string Formula::processSign(const std::string infix)
{
	std::string resultStr = infix;
	char sign;
	for (int i = 0; i < resultStr.length(); i++)
	{
		if (resultStr[i] == '+' || resultStr[i] == '-')		//�̹� ���ڰ� + �Ǵ� - ���
		{
			if (resultStr[i] == '+')		//��ȣ�� �°� ��ü���� ����
				sign = '#';
			else
				sign = '~';

			if (i == 0)		//�� �տ��ִ� ���� ��ȣ�̹Ƿ�, ��ȣ�� ��ü
			{
				resultStr[i] = sign;
				continue;
			}
			else if (isOperator(resultStr[i - 1]) || resultStr[i - 1] == '(')	//���� ���ڰ� �����ڰų� ���°�ȣ ��� �̹� ���ڴ� ��ȣ
			{
				resultStr[i] = sign;
				continue;
			}
		}
	}
	return resultStr;
}

//�����ڰ� �ùٸ��� ���Ǵ��� Ȯ��
bool Formula::isIncorrectOperator(const std::string infix)
{
	if (isPureOperator(infix[0]))		//ù��° �����ڰ� �����������ΰ��(��ȣ,���ڰ� �ƴ�)
	{
		return true;
	}
	for (int i = 1; i < infix.length(); i++)
	{
		if (isPureOperator(infix[i]) && isPureOperator(infix[i - 1]))		//�����ڰ� �������� �ִ°�� ex /*, *+, -+
		{
			return true;
		}
		else if (isPureOperator(infix[i]) && isOperator(infix[i - 1]))	//������ �տ� ��ȣ�� �ִ°�� ex #*,~/,#/...
		{
			return true;
		}
		else if (isPureOperator(infix[i - 1]) && infix[i] == ')')	//������ �ڿ� �ݴ� ��ȣ�� �ִ°�� ex *), +), -)
		{
			return true;
		}
		else if ('0' < infix[i - 1] && infix[i - 1] < '9' && infix[i] == '(')	//���� �ڿ� ��ȣ�� ���� ��� ex 24(, 13(, ...
		{
			return true;
		}
		else if ('0' < infix[i] && infix[i] < '9' && infix[i - 1] == ')')	//�ݴ� ��ȣ�ڿ� ���ڰ� ���� ��� ex (~)24, (~)13, ...
		{
			return true;
		}
	}
	if (isOperator(infix[infix.length() - 1]))		//���� �������� �����ڰ� �ִ� ���
	{
		return true;
	}
	return false;
}

////////////
//��ƿ��Ƽ//
////////////

//���ڸ� �Է¹޾� �������̸� true��, �ƴϸ� false�� ��ȯ
bool Formula::isOperator(char iChar)
{
	return getPriority(iChar) != -1 ? true : false;
}
//���ڸ� �Է¹޾� ��ȣ�� �ƴ� ���� �������̸� true��, �ƴϸ� false�� ��ȯ
bool Formula::isPureOperator(char iChar)
{
	if (iChar == '#' || iChar == '~')
		return false;
	return getPriority(iChar) != -1 ? true : false;
}
//�����ڸ� �Է¹޾� �켱������ ��ȯ
int Formula::getPriority(char iOperator)
{
	if (iOperator == '~' || iOperator == '#')		//����
		return 4;
	else if (iOperator == '^')						//����
		return 3;
	else if (iOperator == '*' || iOperator == '/' || iOperator == '%')	//��������
		return 2;
	else if (iOperator == '+' || iOperator == '-')		//��������
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