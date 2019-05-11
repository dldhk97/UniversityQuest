#include <iostream>
#include "TaskManager.h"

using namespace std;

int main()
{
	TaskManager<Element> tskMgr;
	
	int size = tskMgr.getSize();
	BinaryTree<Element> newTree(size);
	
	tskMgr.printAsTree(newTree);
	tskMgr.printAsPreorder(newTree);
	tskMgr.printAsInorder(newTree);
	tskMgr.printAsPostorder(newTree);
	tskMgr.printAsLevelorder(newTree);

	return 0;
}