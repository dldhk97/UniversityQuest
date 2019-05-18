#pragma once

#include "Book.h"

class TextBook : public Book
{
private:
	std::string detailedSubject;
public:
	TextBook();
	~TextBook();
};

