#pragma once

#include "IOHandler.h"

class TaskManager
{
public:
	void manageUser(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);
	void manageBook(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);
	void manageLoan(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);

	void insertUser(List<User>& userList);
	void changeUserState(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);
	void displayUserList(List<User>& userList);

	void insertBook(List<Book>& bookList);
	void changeBookState(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);
	void displayBookList(List<Book>& bookList);

	void loanBook(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);
	void returnBook(List<Book>& bookList, List<LoanInfo>& loanInfoList);
	void displayLoanHistory(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList);
};

