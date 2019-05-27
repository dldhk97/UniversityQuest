//User.h
#pragma once
#include <iostream>

class Professor;

enum UserType { PROFESSOR = 11, STUDENT };
enum UserState { VALID = 1001, INVALID };

class User
{
private:
	//Compare
	int getPriority(User* user);
protected:
	std::string id, name, department;
	int userState;
public:
	//Getter
	std::string getId();
	int getUserState();
	std::string getName();

	//Setter
	virtual void setId(int newId);
	void setUserState(int userState);

	//Display
	virtual void display();

	//Compare
	bool compare(User* user);

	//Write
	virtual std::string to_string();
};

