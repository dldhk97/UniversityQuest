//TaskManager.cpp
#include "TaskManager.h"

void TaskManager::insertComponent(ComponentList &iList)
{
	IOHandler ioh;
	Component newComponent = ioh.getComponent();

	int index = iList.findComponent(newComponent.getSerialNumber());
	if (index != NOT_FOUND)
	{
		ioh.printMessage("일련번호 중복입니다.");
		return;
	}
	iList.insertComponent(newComponent);
}
void TaskManager::deleteComponent(ComponentList &iList)
{
	IOHandler ioh;
	if (iList.getSize() <= 0)
	{
		ioh.printMessage("목록이 비어있습니다.");
		return;
	}

	int id = ioh.getInt("삭제할 부품의 ID 입력 :");
	int index = iList.findComponent(id);
	if (index == NOT_FOUND)
	{
		ioh.printMessage("부품을 찾을 수 없습니다.");
		return;
	}

	iList.deleteComponent(index);
	ioh.printMessage("삭제되었습니다.");
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