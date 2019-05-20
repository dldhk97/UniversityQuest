#pragma once

#include <iostream>
#include <string>

class Date
{
private:
	int year, month, day;
public:
	Date(std::string dateStr);
	
	int totalDays();
	std::string to_string();
};

