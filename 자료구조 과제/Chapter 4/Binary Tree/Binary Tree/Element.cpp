#include "Element.h"

Element::Element()
{
}

Element::Element(int iValue)
{
	value = iValue;
}

Element::~Element()
{
}

int Element::getValue()
{
	return value;
}
void Element::setValue(int iValue)
{
	value = iValue;
}

std::ostream &operator << (std::ostream &os, const Element &elem)
{
	os << elem.value;
	return os;
}