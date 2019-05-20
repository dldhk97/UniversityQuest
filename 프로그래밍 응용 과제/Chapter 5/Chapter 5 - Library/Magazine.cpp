#include "Magazine.h"
#include "IOHandler.h"

Magazine::Magazine(std::string id, std::string title, std::string publisher, Date* publicationDate, int bookState, std::string volume)
{
	this->id = id;
	this->title = title;
	this->publisher = publisher;
	this->publicationDate = publicationDate;
	this->bookState = bookState;
	this->volume = volume;
}

void Magazine::display()
{
	IOHandler ioh;
	std::string bookStateStr;
	switch (bookState)
	{
	case LOANABLE:
		bookStateStr = "대출 가능";
		break;
	case LOANING:
		bookStateStr = "대출 중";
		break;
	case INLOANBLE:
		bookStateStr = "대출 불가";
		break;
	}
	ioh.displayMessageAsCell(id, 6);
	ioh.displayMessageAsCell(title, 6);
	ioh.displayMessageAsCell(publisher, 6);
	ioh.displayMessageAsCell(publicationDate->to_string(), 11);
	ioh.displayMessageAsCell("", 6);
	ioh.displayMessageAsCell(bookStateStr, 9);
	ioh.displayMessageAsCell(volume, 6);
	ioh.displayMessage("");
}
//Write
std::string Magazine::to_string()
{
	return std::to_string(MAGAZINE) + " " + id + " " + title + " " + publisher + " " + publicationDate->to_string() + " " + std::to_string(bookState) + " " + volume;
}