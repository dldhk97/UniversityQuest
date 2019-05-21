#include "TextBook.h"
#include "IOHandler.h"

TextBook::TextBook(std::string id, std::string title, std::string publisher, Date* publicationDate, int bookState, std::string detailedSubject)
{
	this->id = id;
	this->title = title;
	this->publisher = publisher;
	this->publicationDate = publicationDate;
	this->bookState = bookState;
	this->detailedSubject = detailedSubject;
}
void TextBook::setId(int newId)
{
	std::string newIdStr = "B";
	if (newId < 10)
		newIdStr = newIdStr + "0" + std::to_string(newId);
	else
		newIdStr = newIdStr + std::to_string(newId);
	this->id = newIdStr;
}
void TextBook::display()
{
	IOHandler ioh;
	std::string bookStateStr;
	switch (bookState)
	{
	case LOANABLE:
		bookStateStr = "대출 가능";
		break;
	case LOANING:
		bookStateStr = "대출 중 ";
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
	ioh.displayShortMessage("", 6);
	ioh.displayMessage(detailedSubject);
}

std::string TextBook::to_string()
{
	return std::to_string(TEXTBOOK) + " " + id + " " + title + " " + publisher + " " + publicationDate->to_string() + " " + std::to_string(bookState) + " " + detailedSubject;
}