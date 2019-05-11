//TaskManager.h
#pragma once

#include "ComponentList.h"
#include "IOHandler.h"

class TaskManager
{
public:
	void insertComponent(ComponentList &iList);		//���۷����� List��ü�� �Ѱ��ش�. ���۷����� �ƴϸ� �޼ҵ� ������ List Ŭ���� �����Ǿ� �۾��ǰ� �Ҹ�ȴ�.
	void deleteComponent(ComponentList &iList);
	void printComponent(ComponentList &iList);
	void insertionSort(ComponentList &iList);
};

