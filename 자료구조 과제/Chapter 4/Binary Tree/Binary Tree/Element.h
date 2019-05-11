#pragma once

#include <string>

class Element
{
private:
	int value;
public:
	Element();
	Element(int iValue);
	~Element();

	int getValue();
	void setValue(int iValue);

	friend std::ostream &operator << (std::ostream &os, const Element &elem);
};

