#include "Formula.h"

using namespace std;

int main()
{
	string userInput;
	Formula newFormula;

	while (true)
	{
		cout << "������ �Է��ϼ��� (����� quit) :";
		getline(cin, userInput);
		if (cin.fail())									//�Է��� �޴µ� ���������� ���� �ʱ�ȭ
		{
			cin.ignore();
			cin.clear();
			continue;
		}
		if (userInput == "quit")
			break;

		try
		{
			newFormula.saveAsPostfix(userInput);		//�Է¹��� ����ǥ����� ����ǥ��� ����
			newFormula.printPostfix();
			cout << "---- ����� " << newFormula.calculate() << "\n\n";
		}
		catch (exception exceptionCode)
		{
			std::string exceptionMsg;
			switch (*exceptionCode.what())
			{
			case '0':
				exceptionMsg = "���ڰ� ���Ե� ����";
				break;
			case '1':
				exceptionMsg = "�ùٸ��� ���� ��ȣ��";
				break;
			case '2':
				exceptionMsg = "������ �� ���� ����";
				break;
			case '3':
				exceptionMsg = "�������� �ι�° �����ڰ� 0�� ��찡 �߻�";
				break;
			case '4':
				exceptionMsg = "���鹮�ڸ� ����";
				break;
			case '5':
				exceptionMsg = "������ �Է¹��� �� �ֽ��ϴ�.";
				break;
			default:
				exceptionMsg = "�� �� ���� ����";
				break;
			}
			cout << "[����] " << exceptionMsg << "\n\n";
		}
	}
	cout << "**** �����մϴ� ****\n";
	return 0;
}