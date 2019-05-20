#pragma once

#include "Book.h"

class IOHandler;

class TextBook : public Book
{
private:
	std::string detailedSubject;
public:
	TextBook(std::string id, std::string title, std::string publisher, Date* publicationDate, int bookState, std::string detailedSubject);

	virtual void display();
	virtual std::string to_string();
};

