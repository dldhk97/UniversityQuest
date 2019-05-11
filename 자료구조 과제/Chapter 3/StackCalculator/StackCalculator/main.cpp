#include "Formula.h"

using namespace std;

int main()
{
	string userInput;
	Formula newFormula;

	while (true)
	{
		cout << "계산식을 입력하세요 (종료는 quit) :";
		getline(cin, userInput);
		if (cin.fail())									//입력을 받는데 실패했으면 버퍼 초기화
		{
			cin.ignore();
			cin.clear();
			continue;
		}
		if (userInput == "quit")
			break;

		try
		{
			newFormula.saveAsPostfix(userInput);		//입력받은 중위표기식을 후위표기로 저장
			newFormula.printPostfix();
			cout << "---- 결과는 " << newFormula.calculate() << "\n\n";
		}
		catch (exception exceptionCode)
		{
			std::string exceptionMsg;
			switch (*exceptionCode.what())
			{
			case '0':
				exceptionMsg = "문자가 포함된 수식";
				break;
			case '1':
				exceptionMsg = "올바르지 않은 괄호쌍";
				break;
			case '2':
				exceptionMsg = "이해할 수 없는 수식";
				break;
			case '3':
				exceptionMsg = "나누기의 두번째 연산자가 0인 경우가 발생";
				break;
			case '4':
				exceptionMsg = "공백문자만 존재";
				break;
			case '5':
				exceptionMsg = "정수만 입력받을 수 있습니다.";
				break;
			default:
				exceptionMsg = "알 수 없는 오류";
				break;
			}
			cout << "[오류] " << exceptionMsg << "\n\n";
		}
	}
	cout << "**** 종료합니다 ****\n";
	return 0;
}