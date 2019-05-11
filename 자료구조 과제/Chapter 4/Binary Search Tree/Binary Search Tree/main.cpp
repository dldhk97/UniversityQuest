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
		std::cout << "���ڿ����� �Է��ϼ��� (�������� 0) : ";
		while (true)
		{
			cin >> userInput;
			if (userInput == "0")
			{
				if (newBST.isEmpty())
				{
					std::cout << "�����մϴ�.\n";
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