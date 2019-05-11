//TaskManager.cpp
#include "TaskManager.h"

void TaskManager::insertStudent(StudentList &iList)
{
	IOHandler ioh;
	if (iList.getSize() >= iList.getCapacity())
	{
		iList.resize(iList.getCapacity() * 2);
	}

	Student newStudent = ioh.getStudent();

	int index = iList.findStudent(newStudent.getId());
	if (index != NOT_FOUND)
	{
		ioh.printMessage("ID 중복입니다.");
		return;
	}
	iList.insertStudent(newStudent);
}
void TaskManager::deleteStudent(StudentList &iList)
{
	IOHandler ioh;
	if (iList.getSize() <= 0)
	{
		ioh.printMessage("등록된 학생이 없습니다.");
		ioh.printMessage("학생을 삭제할 수 없습니다.");
		return;
	}

	int id = ioh.getInt("삭제할 학생의 학번 입력 :");
	int index = iList.findStudent(id);
	if (index == NOT_FOUND)
	{
		ioh.printMessage("학생을 찾을 수 없습니다.");
		return;
	}

	iList.deleteStudent(index);
	ioh.printMessage("삭제되었습니다.");

	if (iList.getSize() <= iList.getCapacity() / STANDARD_WASTE_MEMORY)
	{
		iList.resize(iList.getCapacity() / 2);
	}
}
void TaskManager::printStudent(StudentList &iList)
{
	IOHandler ioh;
	int size = iList.getSize();
	for (int i = 0; i < size; i++)
	{
		Student std = iList.getStudent(i);
		ioh.printStudent(std);
	}
}

void TaskManager::insertionSort(StudentList &iList)
{
	int i, j;
	int size = iList.getSize();
	Student temp;

	for (i = 0; i < size; i++)
	{
		j = i;
		while (j > 0 && iList.getStudent(j - 1).getId() > iList.getStudent(j).getId())
		{
			temp = iList.getStudent(j - 1);
			iList.setStudent(j - 1, iList.getStudent(j));
			iList.setStudent(j, temp);
			j--;
		}
	}

}