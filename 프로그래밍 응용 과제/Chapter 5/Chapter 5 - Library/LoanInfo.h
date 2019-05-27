//LoanInfo.h
#pragma once
#include "User.h"
#include "Book.h"

class IOHandler;

class LoanInfo
{
private:
	std::string serial, loanerId, bookId;
	Date* loanedDate;
	Date* returnDate;
	int period;
public:
	//Initializer
	LoanInfo(LoanInfo* loanInfo);
	LoanInfo(std::string serial, std::string loanerId, std::string bookId, Date* loanedDate, Date* returnDate, int period);
	~LoanInfo();

	//Getter
	std::string getBookId();
	std::string getSerial();
	Date* getLoanedDate();
	Date* getReturnDate();
	std::string getLoanerId();

	//Setter
	void setSerial(std::string serial);
	void setReturnDate(Date* returnDate);
	void setPeriod(int period);

	//Display
	void display(User* user, Book* book);

	//Compare
	bool compare(Book* currentBook, Book* targetBook, LoanInfo* targetLoanInfo);

	//Write
	std::string to_string();
};

