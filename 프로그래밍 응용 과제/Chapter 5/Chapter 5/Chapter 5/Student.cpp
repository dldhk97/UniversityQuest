#include "Student.h"
#include "IOHandler.h"

Student::Student(std::string id, std::string name, std::string department, int userState , int year, std::string grade, std::string contact)
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
	ioh.displayMessage(id + '\t' + name + '\t' + department + '\t' + userStateStr + '\t' + std::to_string(year) + '\t' + grade + '\t' + contact );
}