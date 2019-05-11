//StudentList.cpp
#include "StudentList.h"

//Initializer
StudentList::StudentList()
{
	capacity = DEFAULT_CAPACITY;
	size = 0;
	studentArr = new Student[capacity];
}

StudentList::~StudentList()
{
	if (studentArr != NULL)
	{
		delete[] studentArr;
	}
}

//Getter
Student StudentList::getStudent(int index)
{
	return studentArr[index];
}
int StudentList::getSize()
{
	return size;
}
int StudentList::getCapacity()
{
	return capacity;
}

//Setter
void StudentList::setStudent(int index, Student newStudent)
{
	studentArr[index] = newStudent;
}

//Control
void StudentList::insertStudent(Student newStudent)
{
	studentArr[size++] = newStudent;
}
void StudentList::deleteStudent(int index)
{
	studentArr[index] = studentArr[size - 1];
	size--;
}
int StudentList::findStudent(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (studentArr[i].getId() == id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

//Utility
void StudentList::resize(int newCapacity)
{
	if (newCapacity < DEFAULT_CAPACITY)
	{
		return;
	}

	Student *tempArr = new Student[size];
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = studentArr[i];
	}
	delete[] studentArr;

	studentArr = new Student[newCapacity];
	for (int i = 0; i < size; i++)
	{
		studentArr[i] = tempArr[i];
	}

	delete[] tempArr;
	capacity = newCapacity;
}
