#pragma once

#include "User.h"

class IOHandler;

class Student : public User
{
private:
	std::string grade, contact, year;
public:
	Student(std::string id, std::string name, std::string department, int userState, std::string year, std::string grade, std::string contact);

	virtual void display();
};

