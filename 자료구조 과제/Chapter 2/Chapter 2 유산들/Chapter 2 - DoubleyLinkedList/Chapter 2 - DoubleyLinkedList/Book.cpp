#include "Book.h"

Book::Book()
{
}

Book::Book(std::string iBookNum, std::string iBookTitle)
{
	this->bookNum = iBookNum;
	this->bookTitle = iBookTitle;
}

void Book::setTitle(std::string iBookTitle)
{
	this->bookTitle = iBookTitle;
}
std::string Book::getTitle()
{
	return this->bookTitle;
}
void Book::setNum(std::string iBookNum)
{
	this->bookNum = iBookNum;
}
std::string Book::getNum()
{
	return this->bookNum;
}