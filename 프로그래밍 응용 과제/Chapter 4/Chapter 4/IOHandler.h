#pragma once

#include <iostream>
#include <fstream>
#include "FigureList.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"


enum Menu {INSERT = 1, DELETE, PRINT, EXIT};
enum FigureType {CIRCLE = 11, TRIANGLE, SQUARE};

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

	bool loadFile(FigureList &figureList);
	void saveFile(FigureList &figureList);
};

