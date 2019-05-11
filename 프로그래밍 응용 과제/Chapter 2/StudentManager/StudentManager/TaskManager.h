//TaskManager.h
#pragma once

#include "StudentList.h"
#include "ioHandler.h"

const int STANDARD_WASTE_MEMORY = 3;			//최대용량이 실제용량보다 n배 낭비되는 경우 resize하는 기준

class TaskManager
{
public:
	void insertStudent(StudentList &iList);		//레퍼런스로 List자체를 넘겨준다. 레퍼런스가 아니면 메소드 내에서 List 클론이 생성되어 작업되고 소멸된다.
	void deleteStudent(StudentList &iList);
	void printStudent(StudentList &iList);
	void insertionSort(StudentList &iList);
};

