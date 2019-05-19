#pragma once

#include <iostream>

class Magazine;

enum BookType {MAGAZINE = 21, TEXTBOOK};
enum BookState {LOANABLE = 100001, LOANING, INLOANBLE};

class Book
{
protected:
	std::string id, title, publisher, publicationDate;
	int bookState;
public:
	//Getter
	std::string getId();
	int getBookState();
	std::string getTitle();

	//Setter
	void setId(std::string id);
	void setBookState(int bookState);

	//Display
	virtual void display();
	
	//Compare
	int getPriority();
	bool compare(Book* book);
};

