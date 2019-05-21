#include "LoanInfo.h"
#include "IOHandler.h"

//Initializer
LoanInfo::LoanInfo(LoanInfo* loanInfo)										//복사생성자
{
	this->serial = loanInfo->serial;
	this->loanerId = loanInfo->loanerId;
	this->bookId = loanInfo->bookId;
	this->loanedDate = new Date(loanInfo->loanedDate->to_string());			//Date 멤버변수는 포인터가 복사되기 때문에 새로 만들어준다. 새로 만들어주지 않으면 메모리가 복사된 LoanInfo에서 해제되면 원본도 해제됨.
	if (loanInfo->returnDate != nullptr)
		this->returnDate = new Date(loanInfo->returnDate->to_string());		
	else
		this->returnDate = nullptr;
	this->period = loanInfo->period;
}
LoanInfo::LoanInfo(std::string serial, std::string loanerId, std::string bookId, Date* loanedDate, Date* returnDate, int period)
{
	this->serial = serial;
	this->loanerId = loanerId;
	this->bookId = bookId;
	this->loanedDate = loanedDate;
	this->returnDate = returnDate;
	this->period = period;
}
LoanInfo::~LoanInfo()
{
	if (loanedDate != nullptr)
		delete loanedDate;
	if (returnDate != nullptr)
		delete returnDate;
}
//Getter
std::string LoanInfo::getId()
{
	return this->bookId;
}
std::string LoanInfo::getSerial()
{
	return this->serial;
}
Date* LoanInfo::getLoanedDate()
{
	return this->loanedDate;
}
Date* LoanInfo::getReturnDate()
{
	return this->returnDate;
}
std::string LoanInfo::getLoanerId()
{
	return this->loanerId;
}
//Setter
void LoanInfo::setSerial(std::string serial)
{
	this->serial = serial;
}
void LoanInfo::setReturnDate(Date* returnDate)
{
	this->returnDate = returnDate;
}
void LoanInfo::setPeriod(int period)
{
	this->period = period;
}

void LoanInfo::display(User* user, Book* book)
{
	IOHandler ioh;
	std::string bookType = "잡지";
	std::string returnDateStr = returnDate->to_string() == "NOT_FOUND" ? "" : returnDate->to_string();
	std::string periodStr = period == NOT_FOUND ? "" : std::to_string(period);
	if (typeid(*book).name() == typeid(TextBook).name())
		bookType = "전공";
	ioh.displayMessageAsCell(bookType, 6);
	ioh.displayMessageAsCell(book->getTitle(), 12);
	ioh.displayMessageAsCell(book->getId(), 6);
	ioh.displayMessageAsCell(user->getName(), 6);
	ioh.displayMessageAsCell(user->getId(), 6);
	ioh.displayMessageAsCell(loanedDate->to_string(), 11);
	ioh.displayMessageAsCell(returnDateStr, 11);
	ioh.displayMessage(periodStr);
}

//Compare
bool LoanInfo::compare(Book* currentBook, Book* targetBook, LoanInfo* targetLoanInfo)
{
	int currentBookPriority = currentBook->getPriority();			//우선순위 높음 = int값이 낮음		ex) 0(높음) ~ n(낮음)
	int targetBookPriority = targetBook->getPriority();

	if (currentBookPriority < targetBookPriority)
		return true;
	else if (currentBookPriority == targetBookPriority)				//우선순위가 동등하다면 제목으로 비교한다.
		if (currentBook->getTitle() < targetBook->getTitle())
			return true;
		else if (currentBook->getTitle() == targetBook->getTitle())	//제목이 동등하다면 대출일로 비교한다.
			if (this->loanedDate->totalDays() < targetLoanInfo->loanedDate->totalDays())
				return true;
	return false;
}

//Write
std::string LoanInfo::to_string()
{
	bool isReturned = returnDate != nullptr ? true : false;
	if (isReturned)
		return std::to_string(1) + " " + serial + " " + loanerId + " " + bookId + " " + loanedDate->to_string() + " " + returnDate->to_string() + " " + std::to_string(period);
	else
		return std::to_string(NOT_FOUND) + " " + serial + " " + loanerId + " " + bookId + " " + loanedDate->to_string();
}