//Student.cpp
#include "Student.h"
#include "IOHandler.h"

Student::Student(std::string id, std::string name, std::string department, int userState , std::string year, std::string grade, std::string contact)
{
	this->id = id;
	this->name = name;
	this->department = department;
	this->userState = userState;
	this->year = year;
	this->grade = grade;
	this->contact = contact;
}

void Student::setId(int newId)
{
	std::string newIdStr = "F";
	if (newId < 10)
		newIdStr = newIdStr + "0" + std::to_string(newId);
	else
		newIdStr = newIdStr + std::to_string(newId);
	this->id = newIdStr;
}

void Student::display()
{
	IOHandler ioh;
	std::string userStateStr = userState == VALID ? "����" : "����";
	ioh.displayShortMessage(id, 6);
	ioh.displayShortMessage(name, 6);
	ioh.displayShortMessage(department, 12);
	ioh.displayShortMessage(userStateStr, 6);
	ioh.displayShortMessage("\t\t", 6);
	ioh.displayShortMessage(year, 6);
	ioh.displayShortMessage(grade, 6);
	ioh.displayMessage(contact);
}

std::string Student::to_string()
{
	return std::to_string(STUDENT) + " " + id + " " + name + " " + department + " " + std::to_string(userState) + " " + year + " " + grade + " " + contact;
}