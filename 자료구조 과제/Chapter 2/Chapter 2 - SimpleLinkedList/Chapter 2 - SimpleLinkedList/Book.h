#pragma once
#include <iostream>
class Book
{
private:
	std::string title;		//å�� ����
	std::string num;		//å�� ��ȣ
public:

	//setter
	std::string getTitle();
	std::string getNum();
	//getter
	void setTitle(std::string iTitle);
	void setNum(std::string iNum);
	
};

