#pragma once

#include <iostream>

enum BookType {MAGAZINE = 21, TEXTBOOK};
enum BookState {LOANABLE = 100001, LOANING, INLOANBLE};

class Book
{
private:
	std::string id, title, publisher, publicationDate;
	int bookState;
public:
	Book();
	~Book();
};

