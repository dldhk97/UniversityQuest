#include <iostream>

#include "DoublyList.h"

using namespace std;

int main()
{
	DoublyList newList;
	int userInput;
	while (1)
	{
		cout << "1. 노드 추가\n";
		cout << "2. 노드 삭제\n";
		cout << "3. 리스트 출력\n";
		cout << "4. 종료\n";
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