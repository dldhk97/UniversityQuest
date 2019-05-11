//TaskManager.h
#pragma once

#include "ComponentList.h"
#include "IOHandler.h"

class TaskManager
{
public:
	void insertComponent(ComponentList &iList);		//레퍼런스로 List자체를 넘겨준다. 레퍼런스가 아니면 메소드 내에서 List 클론이 생성되어 작업되고 소멸된다.
	void deleteComponent(ComponentList &iList);
	void printComponent(ComponentList &iList);
	void insertionSort(ComponentList &iList);
};

