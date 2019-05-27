//Book.cpp
#include "Book.h"
#include "Magazine.h"

//Initializer
Book::~Book()
{
	if (publicationDate != nullptr)
		delete publicationDate;
}

//Getter
std::string Book::getId()
{
	return this->id;
}
int Book::getBookState()
{
	return this->bookState;
}
std::string Book::getTitle()
{
	return title;
}
//Setter
void Book::setId(int newId)
{
	//this->id = id;
}
void Book::setBookState(int bookState)
{
	this->bookState = bookState;
}
//Display
void Book::display()
{

}
//Compare
int Book::getPriority()
{
	if (typeid(*this).name() == typeid(Magazine).name())
		return MAGAZINE;
	else
		return TEXTBOOK;
}
bool Book::compare(Book* book)
{
	int thisPriority = this->getPriority();
	int targetPriority = book->getPriority();

	if (thisPriority > targetPriority)
		return true;
	else if (thisPriority == targetPriority)
		if (this->getTitle() > book->getTitle())
			return true;
	return false;
}
//Write
std::string Book::to_string()
{
	return "";
}