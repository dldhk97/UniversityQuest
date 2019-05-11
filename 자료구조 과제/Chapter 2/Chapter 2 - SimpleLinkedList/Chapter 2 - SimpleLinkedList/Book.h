#pragma once
#include <iostream>
class Book
{
private:
	std::string title;		//책의 제목
	std::string num;		//책의 번호
public:

	//setter
	std::string getTitle();
	std::string getNum();
	//getter
	void setTitle(std::string iTitle);
	void setNum(std::string iNum);
	
};

