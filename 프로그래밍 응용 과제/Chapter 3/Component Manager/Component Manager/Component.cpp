//Component.cpp
#include "Component.h"

Component::Component()
{

}

Component::Component(int iId, string iSerialNumber, string iModel, string iComponentName, string iPrice, string iManufacturer)
{
	id = iId;						//ID
	serialNumber = iSerialNumber;	//�Ϸù�ȣ
	model = iModel;					//����
	componentName = iComponentName;	//��ǰ��
	price = iPrice;					//����
	manufacturer = iManufacturer;	//�������
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