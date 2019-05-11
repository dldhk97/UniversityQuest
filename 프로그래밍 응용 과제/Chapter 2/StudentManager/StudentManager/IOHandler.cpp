//IOHandler.cpp
#include "IOHandler.h"

int IOHandler::getMenu()
{
	int userInput;
	while (true)
	{
		cout << "====================================================" << '\n';
		cout << "1) 학생 추가" << '\n';
		cout << "2) 학생 삭제" << '\n';
		cout << "3) 학생 출력" << '\n';
		cout << "4) 종료" << "\n";
		cout << "====================================================" << '\n';
		cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
		{
			return userInput;
		}
		cout << "잘못된 입력입니다." << '\n';
	}
	
}
Student IOHandler::getStudent()
{
	int id;
	string name, department, phoneNum, address;
	id = getInt("학번 입력: ");
	name = getString("성명 입력: ");
	department = getString("학과 입력: ");
	phoneNum = getString("전화번호 입력: ");
	address = getString("주소 입력: ");
	
	Student newStudent(id, name, department, phoneNum, address);
	return newStudent;
}
void IOHandler::printStudent(Student iStudent)
{
	cout << "학번 :" << iStudent.getId() << '\n';
	cout << "성명 :" << iStudent.getName() << '\n';
	cout << "학과 :" << iStudent.getDepartment() << '\n';
	cout << "전화번호 :" << iStudent.getPhoneNum() << '\n';
	cout << "주소 :" << iStudent.getAddress() << "\n\n";
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