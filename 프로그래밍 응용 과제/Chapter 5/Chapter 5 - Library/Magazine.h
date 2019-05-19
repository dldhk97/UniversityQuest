#pragma once

#include "Book.h"

class IOHandler;

class Magazine : public Book
{
private:
	std::string volume;
public:
	Magazine(std::string id, std::string title, std::string publisher, std::string publicationDate, int bookState, std::string volume);

	virtual void display();
};

