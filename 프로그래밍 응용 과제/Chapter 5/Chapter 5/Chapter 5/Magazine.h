#pragma once

#include "Book.h"

class Magazine : public Book
{
private:
	int volume;
public:
	Magazine();
	~Magazine();
};

