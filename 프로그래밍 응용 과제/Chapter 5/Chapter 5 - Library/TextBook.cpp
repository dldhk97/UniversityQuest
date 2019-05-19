#include "TextBook.h"
#include "IOHandler.h"

TextBook::TextBook(std::string id, std::string title, std::string publisher, std::string publicationDate, int bookState, std::string detailedSubject)
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
		bookStateStr = "���� ����";
		break;
	case LOANING:
		bookStateStr = "���� �� ";
		break;
	case INLOANBLE:
		bookStateStr = "���� �Ұ�";
		break;
	}
	ioh.displayMessageAsCell(id, 6);
	ioh.displayMessageAsCell(title, 6);
	ioh.displayMessageAsCell(publisher, 6);
	ioh.displayMessageAsCell(publicationDate, 6);
	ioh.displayMessageAsCell("", 6);
	ioh.displayMessageAsCell(bookStateStr, 9);
	ioh.displayMessageAsCell("", 6);
	ioh.displayMessageAsCell(detailedSubject, 6);
	ioh.displayMessage("");
}