//TaskManager.h
#pragma once

#include "StudentList.h"
#include "ioHandler.h"

const int STANDARD_WASTE_MEMORY = 3;			//�ִ�뷮�� �����뷮���� n�� ����Ǵ� ��� resize�ϴ� ����

class TaskManager
{
public:
	void insertStudent(StudentList &iList);		//���۷����� List��ü�� �Ѱ��ش�. ���۷����� �ƴϸ� �޼ҵ� ������ List Ŭ���� �����Ǿ� �۾��ǰ� �Ҹ�ȴ�.
	void deleteStudent(StudentList &iList);
	void printStudent(StudentList &iList);
	void insertionSort(StudentList &iList);
};

