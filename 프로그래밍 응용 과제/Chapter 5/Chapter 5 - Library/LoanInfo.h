#pragma once

#include <iostream>

class LoanInfo
{
private:
	int serial;
	std::string loanerId, bookId;
	std::string loanedDate, returnDate;
public:
	LoanInfo();
	~LoanInfo();
};

