#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "List.h"
#include "User.h"
#include "Book.h"
#include "LoanInfo.h"
#include "Student.h"
#include "Professor.h"
#include "Magazine.h"
#include "TextBook.h"
#include "Date.h"
#include "FileIO.h"
#include "Menu.h"

enum MenuType {MAIN = 0, USER, BOOK, LOAN, EXIT};
enum UserManage { INSERTUSER = 1, CHANGESTATE, DISPLAYUSERS};
enum BookManage { INSERTBOOK = 1, DISPLAYBOOKS = 3};
enum LoanManage { LOANBOOK = 1, RETURNBOOK, DISPLAYHISTORY};

class IOHandler
{
public:
	//Type Getter
	int getUserType();
	int getBookType();

	//Class Getter
	Student* getStudent();
	Professor* getProfessor();
	Magazine* getMagazine();
	TextBook* getTextBook();

	//Getter
	int getInt(std::string message);
	std::string getString(std::string message);
	Date* getDate(std::string message);

	//Find
	template <typename dataType>
	dataType* findDataById(std::string message, List<dataType>& targetList);

	//Display
	void displayMessage(std::string message);
	void displayMessageAsCell(std::string message, int maxLength);
	void displayUser(User* user);
	void displayBook(Book* book);
	void displayLoanInfo(User* user, Book* book, LoanInfo* loanInfo);

	//File I/O
	bool readFile(const std::string fileDirectory, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);
	bool writeFile(const std::string fileDirectory, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);
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