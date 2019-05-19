#pragma once

#include "Book.h"

class IOHandler;

class TextBook : public Book
{
private:
	std::string detailedSubject;
public:
	TextBook(std::string id, std::string title, std::string publisher, std::string publicationDate, int bookState, std::string detailedSubject);

	virtual void display();
};

