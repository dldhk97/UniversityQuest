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
	ioh.displayMessageAsCell(id, 6);
	ioh.displayMessageAsCell(title, 6);
	ioh.displayMessageAsCell(publisher, 6);
	ioh.displayMessageAsCell(publicationDate->to_string(), 11);
	ioh.displayMessageAsCell("", 6);
	ioh.displayMessageAsCell(bookStateStr, 9);
	ioh.displayMessageAsCell("", 6);
	ioh.displayMessageAsCell(detailedSubject, 6);
	ioh.displayMessage("");
}

std::string TextBook::to_string()
{
	return std::to_string(TEXTBOOK) + " " + id + " " + title + " " + publisher + " " + publicationDate->to_string() + " " + std::to_string(bookState) + " " + detailedSubject;
}