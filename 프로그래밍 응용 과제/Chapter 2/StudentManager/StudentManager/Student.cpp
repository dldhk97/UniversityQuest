//Student.cpp
#include "Student.h"

Student::Student()
{

}

Student::Student(int iId, string iName, string iDepartment, string iPhoneNum, string iAddress)
{
	id = iId;					//학번
	name = iName;				//성명
	department = iDepartment;	//학과
	phoneNum = iPhoneNum;		//전화번호
	address = iAddress;			//주소
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