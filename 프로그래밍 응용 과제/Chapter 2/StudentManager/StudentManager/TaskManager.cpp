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
		ioh.printMessage("ID �ߺ��Դϴ�.");
		return;
	}
	iList.insertStudent(newStudent);
}
void TaskManager::deleteStudent(StudentList &iList)
{
	IOHandler ioh;
	if (iList.getSize() <= 0)
	{
		ioh.printMessage("��ϵ� �л��� �����ϴ�.");
		ioh.printMessage("�л��� ������ �� �����ϴ�.");
		return;
	}

	int id = ioh.getInt("������ �л��� �й� �Է� :");
	int index = iList.findStudent(id);
	if (index == NOT_FOUND)
	{
		ioh.printMessage("�л��� ã�� �� �����ϴ�.");
		return;
	}

	iList.deleteStudent(index);
	ioh.printMessage("�����Ǿ����ϴ�.");

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