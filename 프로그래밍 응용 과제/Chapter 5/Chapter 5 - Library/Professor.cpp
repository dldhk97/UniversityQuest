#include "Professor.h"
#include "IOHandler.h"

Professor::Professor(std::string id, std::string name, std::string department, int userState, std::string major, std::string laboratory)
{
	this->id = id;
	this->name = name;
	this->department = department;
	this->userState = userState;
	this->major = major;
	this->laboratory = laboratory;
}

void Professor::setId(int newId)
{
	std::string newIdStr = "U";
	if (newId < 10)
		newIdStr = newIdStr + "0" + std::to_string(newId);
	else
		newIdStr = newIdStr + std::to_string(newId);
	this->id = newIdStr;
}

void Professor::display()
{
	IOHandler ioh;
	std::string userStateStr = userState == VALID ? "ÀçÁ÷" : "Åð»ç";
	ioh.displayMessageAsCell(id, 6);
	ioh.displayMessageAsCell(name, 6);
	ioh.displayMessageAsCell(department, 6);
	ioh.displayMessageAsCell(userStateStr, 6);
	ioh.displayMessageAsCell(major, 6);
	ioh.displayMessage(laboratory);
}

std::string Professor::to_string()
{
	return std::to_string(PROFESSOR)+ " " + id + " " + name + " " + department + " " + std::to_string(userState) + " " + major + " " + laboratory;
}