#pragma once

#include <iostream>
#include "Tree.h"
#include "Element.h"


enum { INSERT = 1, DELETE, PRINT, EXIT };
enum { PREORDER = 11, INORDER = 12, POSTORDER = 13};

class IOHanlder
{
public:
	int getMenu();
	Element getElement();
	int getTourMenu();

	void printMessage(std::string Message);

	int getInt(std::string message);
	std::string getString(std::string message);
};

