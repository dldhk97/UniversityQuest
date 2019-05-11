#include "Book.h"
#include <iostream>

using namespace std;

Book::Book() {}

Book::Book(string iBookNum, string iBookTitle)
{
	this->setNum(iBookNum);
	this->setTitle(iBookTitle);
}

std::string Book::getTitle()
{
	return this->title;
}
void Book::setTitle(std::string input)
{
	this->title = input;
}

std::string Book::getNum()
{
	return this->num;
}
void Book::setNum(std::string input)
{
	this->num = input;
}

Book Book::operator=(Book target)
{
	this->num = target.num;
	this->title = target.title;
	return target;
}