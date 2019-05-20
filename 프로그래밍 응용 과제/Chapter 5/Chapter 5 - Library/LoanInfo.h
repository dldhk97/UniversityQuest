#pragma once

#include <iostream>
#include "User.h"
#include "Book.h"
#include "Date.h"

class IOHandler;

class LoanInfo
{
private:
	std::string serial, loanerId, bookId;		//bookId가 getId에 반환된다. Serial은 getSerial으로 반환된다.
	Date* loanedDate;
	Date* returnDate;
	int period;
public:
	LoanInfo(LoanInfo* loanInfo);
	LoanInfo(std::string serial, std::string loanerId, std::string bookId, Date* loanedDate, Date* returnDate, int period);

	//Getter
	std::string getId();
	std::string getSerial();
	Date* getLoanedDate();
	Date* getReturnDate();
	std::string getLoanerId();

	//Setter
	void setSerial(std::string Serial);
	void setReturnDate(Date* returnDate);
	void setPeriod(int period);

	//Display
	void display(User* user, Book* book);

	//Compare
	bool compare(Book* currentBook, Book* targetBook, LoanInfo* targetLoanInfo);

	//Write
	std::string to_string();
};

