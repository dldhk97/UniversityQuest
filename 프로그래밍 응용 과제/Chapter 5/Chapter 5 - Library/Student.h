#pragma once

#include "User.h"

class IOHandler;

class Student : public User
{
private:
	int year;
	std::string grade, contact;
public:
	Student(std::string id, std::string name, std::string department, int userState, int year, std::string grade, std::string contact);

	virtual void display();
};

