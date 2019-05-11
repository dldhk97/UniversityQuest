//IOHandler.h
#pragma once

#include "StudentList.h"
#include <iostream>

enum Menu {INSERT = 1, DELETE, PRINT, EXIT};

class IOHandler
{
public:
	int getMenu();
	Student getStudent();
	void printStudent(Student iStudent);
	void printMessage(string Message);

	int getInt(string message);
	string getString(string message);

};

