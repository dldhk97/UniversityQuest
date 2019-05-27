//Date.h
#pragma once
#include <iostream>
#include <string>

class Date
{
private:
	int year, month, day;
public:
	Date(std::string dateStr);
	
	long totalDays();
	std::string to_string();
};

