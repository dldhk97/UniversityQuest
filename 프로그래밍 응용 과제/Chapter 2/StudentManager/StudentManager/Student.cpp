//Student.cpp
#include "Student.h"

Student::Student()
{

}

Student::Student(int iId, string iName, string iDepartment, string iPhoneNum, string iAddress)
{
	id = iId;					//�й�
	name = iName;				//����
	department = iDepartment;	//�а�
	phoneNum = iPhoneNum;		//��ȭ��ȣ
	address = iAddress;			//�ּ�
}

int Student::getId()
{
	return id;
}
string Student::getName()
{
	return name;
}
string Student::getDepartment()
{
	return department;
}
string Student::getPhoneNum()
{
	return phoneNum;
}
string Student::getAddress()
{
	return address;
}