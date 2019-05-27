//Date.cpp
#include "Date.h"

Date::Date(std::string dateStr)
{
	if (10 <= dateStr.length() && dateStr.length() <= 11)		//YYYY.MM.DD. or YYYY.MM.DD or YYYY-MM-DD
	{
		this->year = std::stoi(dateStr.substr(0, 4));
		this->month = std::stoi(dateStr.substr(5, 2));
		this->day = std::stoi(dateStr.substr(8, 2));
	}
	else if (dateStr.length() == 8)								//YYYYMMDD
	{
		this->year = std::stoi(dateStr.substr(0, 4));
		this->month = std::stoi(dateStr.substr(4, 2));
		this->day = std::stoi(dateStr.substr(6, 2));
	}
	else
	{
		this->year = -1;
		this->month = -1;
		this->day = -1;
	}
}

long Date::totalDays()		//1�� 1�� 1�Ϻ��� ���� ��¥������ �� ��
{
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i;
	long total = 0L;		//������� ũ�Ⱑ ��û Ŀ�� �� ����.

	//4�� ���������� ȸ��-100���� ���������� Ƚ��(���)+400���� ���������� Ƚ��
	total = (year - 1) * 365L + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	if (!(year % 4) && year % 100 || !(year % 400)) //������ ���� 2���� �� �� �Ϸ� �߰�
		months[1]++;
	for (i = 0; i < month - 1; i++)
		total += months[i];
	total += day;
	return total;
}

std::string Date::to_string()
{
	if (this == nullptr)
		return "";
	std::string year = std::to_string(this->year);
	std::string month = std::to_string(this->month).length() < 2 ? "0" + std::to_string(this->month) : std::to_string(this->month);
	std::string day = std::to_string(this->day).length() < 2 ? "0" + std::to_string(this->day) : std::to_string(this->day);
	return year + "." + month + "." + day + ".";
}