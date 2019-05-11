#include <iostream>
#include <string>
#include <fstream>
#include "DNode.h"

using namespace std;

//이중연결리스트를 이용해 책목록을 읽고 쓰는 프로그램입니다.
//cmd로 환경변수를 주거나 VS의 실행환경변수로 텍스트명을 넣어야 정상작동합니다.
//텍스트명은 텍스트명.txt가 되어야 합니다(ex : test.txt)
//만약에 텍스트명에 경로가 포함되어있지 않다면 현재폴더 내에서 찾습니다.

string filePath;
DNode *head;
DNode *tail;
const bool isDebug = false;		//debug용 변수입니다. true이면 환경변수를 넣지않아도 실행이 되며, 같은폴더 내 test.txt를 찾아 동작합니다.

//환경변수로 받은 텍스트파일명을 확인하여 경로가 포함되어있지 않으면 경로를 포함시켜줍니다.
void initializePath(int argc, char *argv[])
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

	string fileDirectory = argv[0];					//입력받은 실행파일의 경로에서 실행파일명을 제외한 폴더 경로만 빼온다.
	fileDirectory.replace(fileDirectory.find_last_of('\\'), fileDirectory.length(), "");

	if (isDebug)
		filePath = "test.txt";
	else
		filePath = argv[1];							//입력받은 텍스트 파일명을 저장

	if (filePath.find("\\") == -1)					//입력받은 파일명에 경로가 포함되어있지 않다면 파일명 앞에 경로를 넣는다. (ex text.txt - > C:\Users\...\test.txt)
	{
		filePath = (string)fileDirectory + "\\" + filePath;
	}
}

//삽입하려는 노드가 헤드보다 사전순으로 빠른지 아닌지 판단합니다.
//또한 head와 tail을 지정하는 역할도 합니다.
void insertNode(DNode *newNode)
{
	string headBookTitle = head->getBookData().getTitle();
	if (newNode->getBookData().getTitle().compare(headBookTitle) < 0)	//헤드보다 사전순으로 빠르면 헤드앞에 넣는다.
	{
		newNode->insertNodeAtHead(head);
		head = newNode;
	}
	else
	{																//헤드보다 사전순으로 느리면 탐색해서 특정 위치에 넣는다.
		DNode *temp = newNode->insertNodeBySort(head);				//만약 넣었는데 이게 tail이라면 tail로 저장한다.
		if (temp != NULL)
			tail = temp;
	}
}

//텍스트를 읽어들여 사전순으로 Node를 생성 및 삽입합니다.
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
			DNode *newNode = new DNode(newBook);

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
		std::cout << "[ERROR]파일을 여는데 실패하였습니다.\n";
		std::cout << "경로, 파일명이 옳은지 확인해 주십시오.\n";
		exit(1);
	}
}

//사용자에게 메뉴를 보여줍니다.
void printMenu()
{
	std::cout << "경로 : ";
	std::cout << filePath << '\n';
	std::cout << "==============================\n";
	std::cout << "(1) 새 도서 입력\n";
	std::cout << "(2) 도서 삭제\n";
	std::cout << "(3) 도서명 순으로 전체 출력\n";
	std::cout << "(4) 도서명 역순으로 전체 출력\n";
	std::cout << "(5) 특정 도서명부터 전체 출력\n";
	std::cout << "(6) 특정 도서명부터 첫 도서명까지 역순 출력\n";
	std::cout << "(7) 파일에 저장하고 종료\n";
	std::cout << "==============================\n";
	std::cout << "원하는 기능을 선택하세요 : ";
}

//'(1) 새 도서 입력'에 대한 메소드입니다.
void addBook()
{
	string tempBookNum, tempBookTitle;
	std::cout << "도서번호와 도서명을 입력하세요 : ";
	cin >> tempBookNum >> tempBookTitle;

	Book newBook(tempBookNum, tempBookTitle);
	DNode *newNode = new DNode(newBook);

	insertNode(newNode);
	std::cout << tempBookTitle << " [" << tempBookNum << "] 이(가) 정상적으로 입력되었습니다.\n\n";
	system("pause");
	std::cout << '\n';
}

//'(2) 도서 삭제'에 대한 메소드입니다.
void removeBook()
{
	string tempBookNum;
	std::cout << "도서번호를 입력하세요 : ";
	cin >> tempBookNum;

	DNode *targetNode = head->findNodeByBookData(tempBookNum, "num");		//도서번호로 탐색하여 존재하면 포인터를 반환하고, 아닌 경우 NULL을 반환합니다.

	if (targetNode == NULL)
	{
		std::cout << "해당 도서를 찾지 못했습니다.\n";
		return;
	}

	if (targetNode->getPreviousNode() == NULL)			//현재노드가 헤드인 경우
	{
		head = targetNode->getNextNode();				//헤드를 현재노드의 다음노드로 변경
		head->setPreviousNode(NULL);					//바뀐헤드의 이전노드를 NULL로 변경
	}
	else if (targetNode->getNextNode() == NULL)			//현재노드가 테일인 경우
	{
		tail = targetNode->getPreviousNode();			//테일을 현재노드의 이전노드로 변경
		tail->setNextNode(NULL);						//바뀐테일의 다음노드를 NULL로 변경
	}
	else
	{
		DNode *tempPreviousNode = targetNode->getPreviousNode();		//현재노드의 이전노드 임시저장
		DNode *tempNextNode = targetNode->getNextNode();				//현재노드의 다음노드 임시저장

		tempPreviousNode->setNextNode(tempNextNode);					//이전노드와 다음노드를
		tempNextNode->setPreviousNode(tempPreviousNode);				//서로 연결시켜준다.
	}
	std::cout << targetNode->getBookData().getTitle() << " [" << targetNode->getBookData().getNum() << "] 이 정상적으로 삭제되었습니다.\n";
	delete targetNode;		//메모리 해제
	system("pause");
	std::cout << '\n';
}

//'(3) 도서명 순으로 전체 출력'에 대한 메소드입니다.
//start노드부터 tail노드까지 출력합니다.
void printBookList(DNode *start)
{
	std::cout << '\n';
	DNode *indexNode = start;
	while (true)
	{
		std::cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "]\n";		//현재노드 정보 출력
		if (indexNode->getNextNode() == NULL)		//다음노드가 NULL이면 종료
			break;
		indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경

	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

//'(5) 특정 도서명부터 전체 출력'에 대한 메소드입니다.
//start노드부터 한 바퀴 돌아 모든 책을 출력합니다.
void printBookListAll(DNode *start)
{
	std::cout << '\n';
	DNode *endNode;
	if (start->getPreviousNode() == NULL)		//특정 도서가 헤드인 경우
	{
		endNode = tail;
	}
	else
	{
		endNode = start->getPreviousNode();
	}
	
	DNode *indexNode = start;
	while (true)
	{
		std::cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "]\n";		//현재노드 정보 출력
		if (indexNode == endNode)	//현재노드가 종료노드라면
			break;

		if (indexNode == tail)		//현재노드가 tail이면 
			indexNode = head;
		else
			indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경

	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

//'(4) 도서명 역순으로 전체 출력'에 대한 메소드입니다. start노드부터 head까지 출력합니다.
//'(6) 특정 도서명부터 첫 도서명까지 역순 출력'에 대한 메소드입니다.
void printBookList_R(DNode *start)
{
	std::cout << '\n';
	DNode *indexNode = start;
	while (true)
	{
		std::cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "]\n";		//현재노드 정보 출력
		if (indexNode->getPreviousNode() == NULL)		//이전노드가 NULL이면 종료
			break;
		indexNode = indexNode->getPreviousNode();		//이전노드가 있으면 탐색노드를 이전노드로 변경

	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

//프로그램이 종료될 때 텍스트파일에 덮어씁니다.
void saveFile()
{
	ofstream writeFile(filePath);
	if (writeFile.is_open())
	{
		DNode *indexNode = head;
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

//프로그램이 종료될 때 head부터 끝까지 노드를 메모리 해제합니다.
void deleteMemory()
{
	DNode *indexNode = head;
	while (true)
	{
		DNode *tempNode = indexNode;
		indexNode = indexNode->getNextNode();
		delete tempNode;
		if (indexNode == NULL)
			break;
	}
}

int main(int argc, char *argv[])
{
	if(isDebug)
		initializePath(2, argv);
	else
		initializePath(argc, argv);

	readFile();

	int consoleInput = -1;
	string stringInput;
	DNode *resultNode;

	while (consoleInput != 7)
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
			printBookList(head);
			break;
		case 4:
			printBookList_R(tail);
			break;
		case 5:
			std::cout << "특정 도서명을 입력하세요 : ";
			cin.ignore();
			getline(cin,stringInput);
			resultNode = head->findNodeByBookData(stringInput,"title");
			if (resultNode == NULL)
				std::cout << "찾으려는 책이 없습니다.\n";
			else
				printBookListAll(resultNode);
			break;
		case 6:
			std::cout << "특정 도서명을 입력하세요 : ";
			cin.ignore();
			getline(cin, stringInput);
			resultNode = head->findNodeByBookData(stringInput, "title");
			if (resultNode == NULL)
				std::cout << "찾으려는 책이 없습니다.\n";
			else
				printBookList_R(resultNode);
			break;
		}
	}

	saveFile();
	deleteMemory();
	std::cout << "종료합니다.\n";
	return 0;
}