#pragma once

#include "User.h"

class IOHandler;

class Professor : public User
{
private:
	std::string major, laboratory;
public:
	Professor(std::string id, std::string name, std::string department, int userState, std::string major, std::string laboratory);

	virtual void display();
	virtual std::string to_string();
};

