#pragma once

#include "IOHandler.h"

class TaskManager
{
public:
	void userMenuAction(int selectedOption, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged);
	void bookMenuAction(int selectedOption, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged);
	void loanMenuAction(int selectedOption, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged);

	void insertUser(List<User>& userList);
	void changeUserState(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged);
	void displayUserList(List<User>& userList);

	void insertBook(List<Book>& bookList);
	void changeBookState(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged);
	void displayBookList(List<Book>& bookList);

	void loanBook(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged);
	void returnBook(List<Book>& bookList, List<LoanInfo>& loanInfoList);
	void displayLoanHistory(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);

	//Utility
	User* findCurrentLoaner(Book* targetBook, List<User>& userList, List<LoanInfo>& loanInfoList);
	LoanInfo* findCurrnetLoanInfo(Book* targetBook, List<Book>& bookList, List<LoanInfo>& loanInfoList);
};

