#pragma once

#include <iostream>
#include <string>

#include "List.h"
#include "User.h"
#include "Book.h"
#include "LoanInfo.h"
#include "Student.h"
#include "Professor.h"
#include "Magazine.h"
#include "TextBook.h"

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
	Magazine* getMagazine();
	TextBook* getTextBook();

	int getInt(std::string message);
	std::string getString(std::string message);

	//Find
	template <typename dataType>
	dataType* findDataById(std::string message, List<dataType>& targetList);

	//Display
	void displayMessage(std::string message);
	void displayMessageAsCell(std::string message, int maxLength);
	void displayUser(User* user);
	void displayBook(Book* book);
	void displayLoanInfo(User* user, Book* book, LoanInfo* loanInfo);

	//File IO
	bool readFile();
	bool writeFile();
};

template <typename dataType>
dataType* IOHandler::findDataById(std::string message, List<dataType>& targetList)
{
	std::string id;
	int index;
	std::cout << message;
	std::cin >> id;
	index = targetList.findDataById(id);
	if (index == NOT_FOUND)
	{
		std::cout << "해당 ID를 찾을 수 없습니다." << '\n';
		return nullptr;
	}
	dataType* result = targetList.getData(index);
	return result;
}