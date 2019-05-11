//StudentList.h
#pragma once
#include "Student.h"

const int DEFAULT_CAPACITY = 10;
const int NOT_FOUND = -1;

class StudentList
{
private:
	Student *studentArr;
	int size;				//실제크기
	int capacity;			//최대용량

public:
	//Initializer
	StudentList();
	~StudentList();

	//Getter
	Student getStudent(int index);
	int getSize();
	int getCapacity();

	//Setter
	void setStudent(int index, Student newStudent);

	//Control
	void insertStudent(Student newStudent);
	void deleteStudent(int index);
	int findStudent(int id);

	//Utility
	void resize(int newCapacity);
};

