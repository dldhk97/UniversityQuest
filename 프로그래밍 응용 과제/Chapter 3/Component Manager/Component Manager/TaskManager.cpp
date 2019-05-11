//TaskManager.cpp
#include "TaskManager.h"

void TaskManager::insertComponent(ComponentList &iList)
{
	IOHandler ioh;
	Component newComponent = ioh.getComponent();

	int index = iList.findComponent(newComponent.getSerialNumber());
	if (index != NOT_FOUND)
	{
		ioh.printMessage("�Ϸù�ȣ �ߺ��Դϴ�.");
		return;
	}
	iList.insertComponent(newComponent);
}
void TaskManager::deleteComponent(ComponentList &iList)
{
	IOHandler ioh;
	if (iList.getSize() <= 0)
	{
		ioh.printMessage("����� ����ֽ��ϴ�.");
		return;
	}

	int id = ioh.getInt("������ ��ǰ�� ID �Է� :");
	int index = iList.findComponent(id);
	if (index == NOT_FOUND)
	{
		ioh.printMessage("��ǰ�� ã�� �� �����ϴ�.");
		return;
	}

	iList.deleteComponent(index);
	ioh.printMessage("�����Ǿ����ϴ�.");
}
void TaskManager::printComponent(ComponentList &iList)
{
	IOHandler ioh;
	int size = iList.getSize();
	for (int i = 0; i < size; i++)
	{
		Component std = iList.getComponent(i);
		ioh.printComponent(std);
	}
}

void TaskManager::insertionSort(ComponentList &iList)
{
	iList.insertionSort();
}