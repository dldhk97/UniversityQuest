#include "LoanInfo.h"
#include "IOHandler.h"

LoanInfo::LoanInfo(LoanInfo* loanInfo)
{
	this->serial = loanInfo->serial;
	this->loanerId = loanInfo->loanerId;
	this->bookId = loanInfo->bookId;
	this->loanedDate = loanInfo->loanedDate;
	this->returnDate = loanInfo->returnDate;
	this->period = loanInfo->period;
}

LoanInfo::LoanInfo(std::string serial, std::string loanerId, std::string bookId, std::string loanedDate, std::string returnDate, std::string period)
{
	this->serial = serial;
	this->loanerId = loanerId;
	this->bookId = bookId;
	this->loanedDate = loanedDate;
	this->returnDate = returnDate;
	this->period = period;
}

std::string LoanInfo::getId()
{
	return this->bookId;
}
std::string LoanInfo::getSerial()
{
	return this->serial;
}
std::string LoanInfo::getReturnDate()
{
	return returnDate;
}
std::string LoanInfo::getLoanerId()
{
	return loanerId;
}

void LoanInfo::setSerial(std::string serial)
{
	this->serial = serial;
}
void LoanInfo::setReturnDate(std::string returnDate)
{
	this->returnDate = returnDate;
}
void LoanInfo::setPeriod(std::string period)
{
	this->period = period;
}

void LoanInfo::display(User* user, Book* book)
{
	IOHandler ioh;
	std::string bookType = "잡지";
	std::string returnDateStr = returnDate == "NOT_FOUND" ? "" : returnDate;
	std::string periodStr = period == "NOT_FOUND" ? "" : period;
	if (typeid(*book).name() == typeid(TextBook).name())
		bookType = "전공";
	ioh.displayMessageAsCell(bookType, 6);
	ioh.displayMessageAsCell(book->getTitle(), 6);
	ioh.displayMessageAsCell(user->getName(), 6);
	ioh.displayMessageAsCell(loanedDate, 11);
	ioh.displayMessageAsCell(returnDateStr, 11);
	ioh.displayMessageAsCell(periodStr, 6);
}

//Compare
bool LoanInfo::compare(Book* currentBook, Book* targetBook, LoanInfo* targetLoanInfo)
{
	int currentBookPriority = currentBook->getPriority();
	int targetBookPriority = targetBook->getPriority();

	if (currentBookPriority > targetBookPriority)
		return true;
	else if (currentBookPriority == targetBookPriority)
		if (currentBook->getTitle() > targetBook->getTitle())
			return true;
		else if (currentBook->getTitle() == targetBook->getTitle())
			if (this->loanedDate > targetLoanInfo->loanedDate)
				return true;
	return false;
}