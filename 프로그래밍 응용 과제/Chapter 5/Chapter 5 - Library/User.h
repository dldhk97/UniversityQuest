#pragma once

#include <iostream>

enum UserType {STUDENT = 11, PROFESSOR};
enum UserState { VALID = 1001, INVALID };

class User
{
protected:
	std::string id, name, department;
	int userState;
public:
	//Getter
	std::string getId();
	int getUserState();

	//Setter
	void setId(std::string id);
	void setUserState(int userState);

	//Display
	virtual void display();
};

