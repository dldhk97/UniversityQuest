//Magazine.cpp
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
void Magazine::setId(int newId)
{
	std::string newIdStr = "M";
	if (newId < 10)
		newIdStr = newIdStr + "0" + std::to_string(newId);
	else
		newIdStr = newIdStr + std::to_string(newId);
	this->id = newIdStr;
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
	ioh.displayShortMessage(id, 6);
	ioh.displayShortMessage(title, 12);
	ioh.displayShortMessage(publisher, 12);
	ioh.displayShortMessage(publicationDate->to_string(), 11);
	ioh.displayShortMessage("", 6);
	ioh.displayShortMessage(bookStateStr, 9);
	ioh.displayMessage(volume);
}
//Write
std::string Magazine::to_string()
{
	return std::to_string(MAGAZINE) + " " + id + " " + title + " " + publisher + " " + publicationDate->to_string() + " " + std::to_string(bookState) + " " + volume;
}