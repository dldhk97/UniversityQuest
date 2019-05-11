//Student.h
#pragma once
#include <string>

using namespace std;

class Student
{
private:
	int id;
	string name, department, phoneNum, address;
public:
	Student();		//������ Student �迭���� �ȵ�.
	Student(int iId, string iName, string iDepartment, string iPhoneNum, string iAddress);

	int getId();
	string getName();
	string getDepartment();
	string getPhoneNum();
	string getAddress();
};

