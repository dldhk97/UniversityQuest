//Book.h
#pragma once
#include <iostream>
#include "Date.h"

class Magazine;

enum BookType {MAGAZINE = 21, TEXTBOOK};
enum BookState {LOANABLE = 100001, LOANING, INLOANBLE};

class Book
{
protected:
	std::string id, title, publisher;
	Date* publicationDate;
	int bookState;
public:
	//Initializer
	~Book();
	//Getter
	std::string getId();
	int getBookState();
	std::string getTitle();

	//Setter
	virtual void setId(int newId);
	void setBookState(int bookState);

	//Display
	virtual void display();
	
	//Compare
	int getPriority();
	bool compare(Book* book);

	//Write
	virtual std::string to_string();
};

