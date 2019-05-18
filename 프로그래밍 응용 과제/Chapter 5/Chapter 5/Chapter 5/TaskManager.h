#pragma once

#include "IOHandler.h"

class TaskManager
{
public:
	void manageUser(List<User>& userList);
	void manageBook(List<Book>& bookList);
	void manageLoan(List<LoanInfo>& loanInfoList);

	void insertUser(List<User>& userList);
	void changeUserState(List<User>& userList);
	void displayUserList(List<User>& userList);

	void insertBook(List<Book>& bookList);
	void changeBookState(List<Book>& bookList);
	void displayBookList(List<Book>& bookList);

	void loanBook(List<LoanInfo>& loanInfoList);
	void returnBook(List<LoanInfo>& loanInfoList);
	void displayLoanHistory(List<LoanInfo>& loanInfoList);

};

