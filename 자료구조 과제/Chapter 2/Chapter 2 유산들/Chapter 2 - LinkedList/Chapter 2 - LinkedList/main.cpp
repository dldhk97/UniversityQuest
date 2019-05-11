#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include "Book.h"

using namespace std;

//연결리스트를 이용해 책목록을 읽고 쓰는 프로그램입니다.
//cmd로 환경변수를 주거나 VS의 실행환경변수로 텍스트명을 넣어야 정상작동합니다.
//텍스트명은 텍스트명.txt가 되어야 합니다(ex : test.txt)
//만약에 텍스트명에 경로가 포함되어있지 않다면 현재폴더 내에서 찾습니다.


string filePath;
Node *head;
const bool isDebug = false;									//debug용 변수입니다. true이면 환경변수를 넣지않아도 실행이 되며, 같은폴더 내 test.txt를 찾아 동작합니다.

void initializePath(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "[ERROR]입력 옵션 없음!\n";
		std::cout << "cmd에서 환경변수를 넣고 실행해주세요!\n";
		std::cout << "ex) C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe text.txt\n\n";
		std::cout << "[TIP]만약 경로에 띄어쓰기가 포함되있다면 경로를 \"로 묶어주면 됩니다!\n";
		std::cout << "ex) \"C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe\" text.txt\n";
		exit(1);
	}

	string fileDirectory = argv[0];							//입력받은 실행파일의 경로에서 실행파일명을 제외한 폴더 경로만 빼온다.
	fileDirectory.replace(fileDirectory.find_last_of('\\'), fileDirectory.length(), "");
	
	if (isDebug)
		filePath = "test.txt";
	else
		filePath = argv[1];									//입력받은 텍스트 파일명을 저장

	if (filePath.find("\\") == -1)							//입력받은 파일명에 경로가 포함되어있지 않다면 파일명 앞에 경로를 넣는다. (ex text.txt - > C:\Users\...\test.txt)
	{
		filePath = (string)fileDirectory + "\\" + filePath;
	}
}

void insertNode(Node *newNode)
{
	string headtempBookTitle = head->getBookData().getTitle();
	if (newNode->getBookData().getTitle().compare(headtempBookTitle) < 0)	//헤드보다 사전순으로 빠르면 헤드앞에 넣는다.
	{
		newNode->insertNodeAtHead(head);
		head = newNode;
	}
	else
	{																		//헤드보다 사전순으로 느리면 탐색해서 특정 위치에 넣는다.
		newNode->insertNodeBySort(head);
	}
}

void readFile()
{
	ifstream openFile(filePath);
	if (openFile.is_open())
	{
		string line;

		while (getline(openFile, line))
		{
			string tempBookNum, tempBookTitle;
			tempBookNum = line.substr(0, line.find(' '));
			tempBookTitle = line.substr(line.find(' ') + 1, line.length());

			Book newBook(tempBookNum, tempBookTitle);
			Node *newNode = new Node(newBook);

			if (head == NULL)		//헤드가 존재하지 않는다면 이번노드를 헤드로 지정
			{
				head = newNode;
			}
			else
			{
				insertNode(newNode);
			}
		}
		openFile.close();
	}
	else
	{
		cout << "[ERROR]파일을 여는데 실패하였습니다.\n";
		cout << "경로, 파일명이 옳은지 확인해 주십시오.\n";
		exit(1);
	}
}

void printMenu()
{
	cout << "경로 : ";
	cout << filePath << '\n';
	cout << "==============================\n";
	cout << "(1) 새 도서 입력\n";
	cout << "(2) 도서 삭제\n";
	cout << "(3) 도서명 순으로 전체 출력\n";
	cout << "(4) 파일에 저장하고 종료\n";
	cout << "==============================\n";
	cout << "원하는 기능을 선택하세요 : ";
}

void addBook()
{
	string tempBookNum, tempBookTitle;
	cout << "도서번호와 도서명을 입력하세요 : ";
	cin >> tempBookNum >> tempBookTitle;

	Book newBook(tempBookNum, tempBookTitle);
	Node *newNode = new Node(newBook);

	insertNode(newNode);
	cout << tempBookTitle << " [" << tempBookNum << "] 이(가) 정상적으로 입력되었습니다.\n\n";
	system("pause");
	cout << '\n';
}

void removeBook()
{
	string tempBookNum;
	cout << "도서번호를 입력하세요 : ";
	cin >> tempBookNum;

	Node *indexNode = head;
	Node *previousNode = head;
	while (true)
	{
		if (indexNode->getBookData().getNum() == tempBookNum)		//삭제하려는 노드라면
		{
			if (indexNode == head)									//삭제대상이 헤드이면
				head = indexNode->getNextNode();					//헤드 다음 노드를 헤드로 한다.
			else
				previousNode->setNextNode(indexNode->getNextNode());	//헤드가 아니면 이전노드가 현재노드를 건너뛰어 다음노드를 가르키도록 한다.
			cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "] 이 정상적으로 삭제되었습니다.\n";
			
			delete indexNode;										//현재노드 메모리 해제
			break;
		}
		else if (indexNode->getNextNode() == NULL)		//탐색을 끝까지 했는데 못찾았으면 종료
		{
			cout << "해당 도서를 찾지 못했습니다.\n";
			break;
		}
		previousNode = indexNode;
		indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경
	}
	system("pause");
	cout << '\n';
}

void printBookList()
{
	cout << '\n';
	Node *indexNode = head;
	while(true)
	{
		cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "]\n";		//현재노드 정보 출력
		if (indexNode->getNextNode() == NULL)		//다음노드가 NULL이면 종료
			break;
		indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경
		
	}
	cout << '\n';
	system("pause");
	cout << '\n';
}

void saveFile()
{
	ofstream writeFile(filePath);
	if (writeFile.is_open()) 
	{
		Node *indexNode = head;
		while (true)
		{
			writeFile << indexNode->getBookData().getNum() << " " << indexNode->getBookData().getTitle() << '\n';		//현재노드 정보 쓰기
			if (indexNode->getNextNode() == NULL)		//다음노드가 NULL이면 종료
				break;
			indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경
		}
		writeFile.close();
	}
}

void deleteMemory()
{
	Node *indexNode = head;
	while (true)
	{
		Node *tempNode = indexNode;
		indexNode = indexNode->getNextNode();
		delete tempNode;
		if (indexNode == NULL)
			break;
	}
}

int main(int argc, char* argv[])
{
	if (isDebug)
		initializePath(2, argv);
	else
	initializePath(argc, argv);

	readFile();

	int consoleInput = -1;
	while (consoleInput != 4)
	{
		printMenu();
		cin >> consoleInput;

		switch (consoleInput)
		{
		case 1:
			addBook();
			break;
		case 2:
			removeBook();
			break;
		case 3:
			printBookList();
			break;
		}

	}
	saveFile();
	deleteMemory();
	cout << "종료합니다.\n";

	return 0;
}