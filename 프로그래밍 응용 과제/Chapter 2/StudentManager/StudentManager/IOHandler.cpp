//IOHandler.cpp
#include "IOHandler.h"

int IOHandler::getMenu()
{
	int userInput;
	while (true)
	{
		cout << "====================================================" << '\n';
		cout << "1) �л� �߰�" << '\n';
		cout << "2) �л� ����" << '\n';
		cout << "3) �л� ���" << '\n';
		cout << "4) ����" << "\n";
		cout << "====================================================" << '\n';
		cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
		{
			return userInput;
		}
		cout << "�߸��� �Է��Դϴ�." << '\n';
	}
	
}
Student IOHandler::getStudent()
{
	int id;
	string name, department, phoneNum, address;
	id = getInt("�й� �Է�: ");
	name = getString("���� �Է�: ");
	department = getString("�а� �Է�: ");
	phoneNum = getString("��ȭ��ȣ �Է�: ");
	address = getString("�ּ� �Է�: ");
	
	Student newStudent(id, name, department, phoneNum, address);
	return newStudent;
}
void IOHandler::printStudent(Student iStudent)
{
	cout << "�й� :" << iStudent.getId() << '\n';
	cout << "���� :" << iStudent.getName() << '\n';
	cout << "�а� :" << iStudent.getDepartment() << '\n';
	cout << "��ȭ��ȣ :" << iStudent.getPhoneNum() << '\n';
	cout << "�ּ� :" << iStudent.getAddress() << "\n\n";
}

void IOHandler::printMessage(string Message)
{
	cout << Message << '\n';
}

int IOHandler::getInt(string message)
{
	int value;
	cout << message;
	cin >> value;
	cin.ignore();
	return value;
}

string IOHandler::getString(string message)
{
	string value;
	cout << message;
	getline(cin,value);
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
	}
	return value;
}