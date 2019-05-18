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
	ioh.displayMessage(id + '\t' + name + '\t' + department + '\t' + userStateStr + '\t' + major + '\t' + laboratory);
}