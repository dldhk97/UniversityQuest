//Magazine.h
#pragma once
#include "Book.h"

class IOHandler;

class Magazine : public Book
{
private:
	std::string volume;
public:
	Magazine(std::string id, std::string title, std::string publisher, Date* publicationDate, int bookState, std::string volume);

	virtual void setId(int newId);

	virtual void display();
	virtual std::string to_string();
};

