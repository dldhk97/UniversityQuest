#include <iostream>
#include "TaskManager.h"

using namespace std;

int main()
{
	TaskManager tskMgr;
	string userInput;
	while (true)
	{
		BinarySearchTree<std::string> newBST;
		std::cout << "문자열들을 입력하세요 (마지막은 0) : ";
		while (true)
		{
			cin >> userInput;
			if (userInput == "0")
			{
				if (newBST.isEmpty())
				{
					std::cout << "종료합니다.\n";
					return 0;
				}
				break;
			}
			tskMgr.insertStringAtBST(userInput, newBST);
		}
		cin.clear();
		cin.ignore();
		tskMgr.printBST(newBST);
	}
	return 0;
}