#include <iostream>

#include "DoublyList.h"

using namespace std;

int main()
{
	DoublyList newList;
	int userInput;
	while (1)
	{
		cout << "1. ��� �߰�\n";
		cout << "2. ��� ����\n";
		cout << "3. ����Ʈ ���\n";
		cout << "4. ����\n";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			cin >> userInput;
			newList.insertNode(new Node(userInput));
			break;
		case 2:
			cin >> userInput;
			newList.deleteNode(userInput);
			break;
		case 3:
			newList.print();
			break;
		case 4:
			return 0 ;
		}
	}
	return 0;
}