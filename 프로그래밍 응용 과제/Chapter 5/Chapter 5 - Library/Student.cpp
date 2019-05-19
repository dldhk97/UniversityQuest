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

void Student::display()
{
	IOHandler ioh;
	std::string userStateStr = userState == VALID ? "ÀçÇÐ" : "Á¹¾÷";
	ioh.displayMessageAsCell(id, 6);
	ioh.displayMessageAsCell(name, 6);
	ioh.displayMessageAsCell(department, 6);
	ioh.displayMessageAsCell(userStateStr, 6);
	ioh.displayMessageAsCell("\t", 6);
	ioh.displayMessageAsCell(year, 6);
	ioh.displayMessageAsCell(grade, 6);
	ioh.displayMessage(contact);
}