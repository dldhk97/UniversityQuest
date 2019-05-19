#pragma once

#include <iostream>
#include <string>

#include "List.h"
#include "User.h"
#include "Book.h"
#include "LoanInfo.h"
#include "Student.h"
#include "Professor.h"

enum MenuType {MAINMENU = 0, USERMENU, BOOKMENU, LOANMENU, EXIT};
enum UserManage { INSERTUSER = 1, CHANGESTATE, DISPLAYUSERS};
enum BookManage { INSERTBOOK = 1, DISPLAYBOOKS = 3};
enum LoanManage { LOANBOOK = 1, RETURNBOOK, DISPLAYHISTORY};

class IOHandler
{
public:
	//Menu
	int getMenu(int menuType);

	//Utility
	int getUserType();
	int getBookType();

	//Getter
	Student* getStudent();
	Professor* getProfessor();

	int getInt(std::string message);
	std::string getString(std::string message);

	//Display
	void displayMessage(std::string message);
	void displayUser(User* user);

	//File IO
	bool readFile();
	bool writeFile();
};

