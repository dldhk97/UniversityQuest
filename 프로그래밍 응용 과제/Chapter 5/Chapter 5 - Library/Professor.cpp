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