#pragma once

#include <iostream>
#include "User.h"
#include "Book.h"

class IOHandler;

class LoanInfo
{
private:
	std::string serial, loanerId, bookId, loanedDate, returnDate, period;		//bookId가 getId에 반환된다. Serial은 getSerial으로 반환된다.
public:
	LoanInfo(LoanInfo* loanInfo);
	LoanInfo(std::string serial, std::string loanerId, std::string bookId, std::string loanedDate, std::string returnDate, std::string period);

	//Getter
	std::string getId();
	std::string getSerial();
	std::string getReturnDate();
	std::string getLoanerId();

	//Setter
	void setSerial(std::string Serial);
	void setReturnDate(std::string returnDate);
	void setPeriod(std::string period);

	//Display
	void display(User* user, Book* book);

	//Compare
	bool compare(Book* currentBook, Book* targetBook, LoanInfo* targetLoanInfo);
};

