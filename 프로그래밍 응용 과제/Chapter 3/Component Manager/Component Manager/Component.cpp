//Component.cpp
#include "Component.h"

Component::Component()
{

}

Component::Component(int iId, string iSerialNumber, string iModel, string iComponentName, string iPrice, string iManufacturer)
{
	id = iId;						//ID
	serialNumber = iSerialNumber;	//일련번호
	model = iModel;					//차종
	componentName = iComponentName;	//부품명
	price = iPrice;					//가격
	manufacturer = iManufacturer;	//제조사명
}

int Component::getId()
{
	return id;
}
string Component::getSerialNumber()
{
	return serialNumber;
}
string Component::getModel()
{
	return model;
}
string Component::getComponentName()
{
	return componentName;
}
string Component::getPrice()
{
	return price;
}
string Component::getManufacturer()
{
	return manufacturer;
}

void Component::setId(int iId)
{
	id = iId;
}