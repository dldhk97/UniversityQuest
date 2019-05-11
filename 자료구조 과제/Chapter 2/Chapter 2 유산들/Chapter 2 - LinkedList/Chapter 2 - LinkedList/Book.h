#pragma once
#include <string>

class Book
{
private:
	std::string title;
	std::string num;
public:
	Book();
	Book(std::string iBookNum, std::string iBookTitle);

	std::string getTitle();
	void setTitle(std::string input);
	std::string getNum();
	void setNum(std::string input);

	Book operator=(Book target);
};

