//Component.h
#pragma once
#include <string>

using namespace std;

class Component
{
private:
	int id;
	string serialNumber, model, componentName, price, manufacturer;
public:
	Component();
	Component(int iId, string iSerialNumber, string iModel, 
		string iComponentName, string iPrice, string iManufacturer);

	int getId();
	string getSerialNumber();
	string getModel();
	string getComponentName();
	string getPrice();
	string getManufacturer();

	void setId(int iId);
};

