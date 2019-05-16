#pragma once

#include <iostream>
#include <fstream>
#include "FigureList.h"

enum Menu {INSERT = 1, DELETE, PRINT, EXIT};

class IOHandler
{
public:
	int getMenu();
	int getInt(std::string message);
	std::string getString(std::string message);

	int getFigureType();
	Circle *getCircle();
	Triangle *getTriangle();
	Square *getSquare();

	void printMessage(std::string message);
	void printFigure(Figure *figure);

	bool loadFile(FigureList &figureList, std::string fileLocation);
	void saveFile(FigureList &figureList, std::string fileLocation);
};

