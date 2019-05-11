#pragma once
#include <string>
class Book
{
private:
	std::string bookNum;
	std::string bookTitle;
public:
	Book();
	Book(std::string iBookNum, std::string iBookTitle);

	void setTitle(std::string iBookTitle);
	std::string getTitle();
	void setNum(std::string iBookNum);
	std::string getNum();

};

