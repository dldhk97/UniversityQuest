#include "List.h"

//Initializer

//head, tail을 NULL로, size를 0으로 초기화합니다.
List::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

//Getter

//head노드의 주소값을 반환합니다.
Node *List::getHead()
{
	return head;
}
//tail노드의 주소값을 반환합니다.
Node *List::getTail()
{
	return tail;
}

//Node Control

//노드를 제목순으로 넣습니다.
void List::addNodeBySort(Node *iNode)
{
	if (isEmpty())	//크기가 0 이하면 입력받은 노드를 head로 설정합니다.
	{
		head = iNode;
		size++;							//크기를 하나 올립니다.
		return;
	}

	Node *indexNode = head;
	while (true)
	{
		std::string thisBookTitle = iNode->getBookTitle();
		std::string indexBookTitle = indexNode->getBookTitle();
		int comparedDifference = thisBookTitle.compare(indexBookTitle);	//넣으려는 노드의 책 이름이 탐색할노드보다 앞서면 0보다 작고, 아니면 0보다 크다.

		if (comparedDifference < 0)					//넣으려는 노드의 책이름이 탐색한 책의 이름보다 사전순으로 앞서면 그 앞에다 넣는다.
		{
			if (indexNode->getPreviousNode() == NULL)		//indexNode앞에 넣으려는데 indexNode노드가 head라면 헤드앞에 넣는다.
			{
				Node *tempNode = head;						//헤드가 가르키는 노드를 임시저장하고
				head = iNode;								//헤드가 iNode노드를 가르키게 한다.

				iNode->setNextNode(tempNode);				//iNode노드의 다음노드는 이전 헤드 노드로 한다.
				iNode->setPreviousNode(NULL);				//iNode노드의 이전 노드는 NULL처리한다.(iNode가 헤드이므로)
				tempNode->setPreviousNode(iNode);			//이전 헤드 노드의 이전 노드는 iNode노드이다.
			}
			else											//indexNode앞에 넣으려는데 indexNode가 헤드가 아닌경우
			{
				indexNode->getPreviousNode()->setNextNode(iNode);	//indexNode노드의 이전 노드의 다음노드를 iNode노드로 한다.
				iNode->setPreviousNode(indexNode->getPreviousNode());//iNode노드의 이전노드를 indexNode노드의 이전노드로 한다.
				iNode->setNextNode(indexNode);						//iNode 노드의 다음 노드는 indexNode노드이다.
				indexNode->setPreviousNode(iNode);					//indexNode노드의 이전 노드를 iNode노드로 한다.
			}
			size++;
			break;
		}
		else if (indexNode->getNextNode() == NULL)	//마지막까지 왔는데도 못 넣었다면 얘가 마지막 노드(tail)임.
		{
			tail = iNode;
			indexNode->setNextNode(iNode);
			iNode->setPreviousNode(indexNode);
			iNode->setNextNode(NULL);
			size++;
			break;
		}
		indexNode = indexNode->getNextNode();		//탐색할노드를 다음노드로 바꾼다.
	}
}

//책 번호로 노드를 탐색하여 삭제합니다.
void List::removeNodeByNum(string iBookNum)
{
	if (isEmpty())								//삭제하려는데 List가 비어있으면 그만둡니다.
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return;
	}

	Node *targetNode = this->findNodeByBookData(iBookNum, "num");		//도서번호로 탐색하여 존재하면 포인터를 반환하고, 아닌 경우 NULL을 반환합니다.

	if (targetNode == NULL)
	{
		std::cout << "\n해당 도서를 찾지 못했습니다.\n\n";
		return;
	}

	if (targetNode->getPreviousNode() == NULL)			//현재노드가 헤드인 경우
	{
		if (size > 1)	
		{
			head = targetNode->getNextNode();				//헤드를 현재노드의 다음노드로 변경
			head->setPreviousNode(NULL);					//바뀐헤드의 이전노드를 NULL로 변경
			targetNode->setNextNode(NULL);
		}
	}
	else if (targetNode->getNextNode() == NULL)			//현재노드가 테일인 경우
	{
		tail = targetNode->getPreviousNode();			//테일을 현재노드의 이전노드로 변경
		tail->setNextNode(NULL);						//바뀐테일의 다음노드를 NULL로 변경
	}
	else
	{
		Node *tempPreviousNode = targetNode->getPreviousNode();		//현재노드의 이전노드 임시저장
		Node *tempNextNode = targetNode->getNextNode();				//현재노드의 다음노드 임시저장

		tempPreviousNode->setNextNode(tempNextNode);					//이전노드와 다음노드를
		tempNextNode->setPreviousNode(tempPreviousNode);				//서로 연결시켜준다.
	}
	std::cout << '\n' << targetNode->getBookTitle() << " [" << targetNode->getBookNum() << "] 이 정상적으로 삭제되었습니다.\n\n";
	delete targetNode;		//메모리 해제
	size--;
	system("pause");
	std::cout << '\n';
}

Node *List::findNodeByBookData(string iBookData, string dataType)
{
	if (isEmpty())								//삭제하려는데 List가 비어있으면 그만둡니다.
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return NULL;
	}

	Node *indexNode = head;
	std::string indexBookData;

	while (true)
	{
		if (dataType == "num")		//검색할 데이터가 책의 번호면
		{
			indexBookData = indexNode->getBookNum();
		}
		else						//검색할 데이터가 책의 제목이면
		{
			indexBookData = indexNode->getBookTitle();
		}

		if (indexBookData == iBookData)					//찾으려는 책 정보와 동일하면
		{
			return indexNode;
		}
		else if (indexNode->getNextNode() == NULL)			//마지막까지 왔는데도 못찾으면 NULL포인터 반환
		{
			return NULL;
		}
		indexNode = indexNode->getNextNode();		//탐색할노드를 다음노드로 바꾼다.
	}
}

//User Control

//파일을 한줄씩 읽어 List에 Node를 추가하는 메소드입니다.
void List::readFile(string filePath)
{
	ifstream openFile(filePath);
	if (openFile.is_open())				//파일이 정상적으로 열렸을 때
	{
		string line;

		while (getline(openFile, line))	//한줄씩 읽습니다.
		{
			string tempBookNum, tempBookTitle;
			tempBookNum = line.substr(0, line.find(' '));					//처음부터 첫번째 공백이 나올때까지를 번호로 판단하여 저장합니다.
			tempBookTitle = line.substr(line.find(' ') + 1, line.length());	//첫번째 공백 다음부터 마지막까지 제목으로 판단하여 저장합니다.

			this->addNodeBySort(new Node(tempBookNum, tempBookTitle));		//List에 Node를 새로만들어 추가합니다.
		}
		openFile.close();													//파일을 다 읽어들였으므로 파일을 닫습니다.
	}
	else																	//파일이 열리지 않은 경우
	{
		cout << "[ERROR]파일을 여는데 실패하였습니다.\n";
		cout << "경로, 파일명이 옳은지 확인해 주시고, 파일이 존재하는지 확인해주세요.\n\n";
		cout << "[TIP]입력 변수가 텍스트파일명만으로 이루어져있는데도 안열리시면 경로를 포함하면 정상적으로 열립니다.\n";
		cout << "ex) C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe C:\\Users\\Administrator\\source\\LinkedList\\Debug\\text.txt\n\n";
		cout << "[TIP]만약 경로에 띄어쓰기가 포함되있다면 경로를 \"로 묶어주면 됩니다!\n";
		cout << "ex) \"C:\\Users\\Administrator\\source\\LinkedList\\Debug\\Linked List.exe\" text.txt\n";
		exit(1);
	}
}

//'(1) 새 도서 입력'에 대한 메소드입니다.
//사용자에게 책의 번호와 제목을 입력받아 노드를 하나 추가합니다.
void List::addBook()
{
	string tempBookNum, tempBookTitle;
	cout << "도서번호와 도서명을 입력하세요 : ";
	cin >> tempBookNum;				//책 번호 입력받기
	cin.ignore();
	getline(cin, tempBookTitle);	//책 제목 입력받기(책 제목의 길이와 상관없이 입력받기 위해 getline으로 받습니다)

	this->addNodeBySort(new Node(tempBookNum, tempBookTitle));		//노드를 새로 만들어 리스트에 삽입합니다.

	cout << '\n' <<  tempBookTitle << " [" << tempBookNum << "] 이(가) 정상적으로 입력되었습니다.\n\n";
	system("pause");
	cout << '\n';
}

//'(2) 도서 삭제'에 대한 메소드입니다.
//사용자에게 책의 번호를 입력받아 노드를 찾은 후 삭제합니다.
void List::removeBook()
{
	string tempBookNum;
	cout << "도서번호를 입력하세요 : ";
	cin >> tempBookNum;

	this->removeNodeByNum(tempBookNum);				//책 번호로 탐색하여 삭제합니다.
}

//'(3) 도서명 순으로 전체 출력'에 대한 메소드입니다.
//노드를 startNode부터 tail까지 순서대로 출력합니다.
void List::print(Node *startNode)
{
	if (isEmpty())		//리스트가 비어있을 때
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return;
	}

	Node *indexNode = startNode;							//인덱스노드를 last로 설정하고

	cout << '\n';
	while(true)
	{
		cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";	//출력
		if (indexNode->getNextNode() == NULL)		//다음노드가 NULL이면 종료
			break;
		indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경
	}
	cout << '\n';
	system("pause");
	cout << '\n';
}

//'(4) 도서명 역순으로 전체 출력'에 대한 메소드입니다. tail부터 head까지 출력합니다.
//'(6) 특정 도서명부터 첫 도서명까지 역순 출력'에 대한 메소드입니다.
void List::printR(Node *startNode)
{
	if (isEmpty())		//리스트가 비어있을 때
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return;
	}

	std::cout << '\n';
	Node *indexNode = startNode;
	
	if (size == 1)				//리스트에 노드가 하나밖에 없으면 무한루프에 빠짐.
		indexNode = head;

	while (true)
	{
		std::cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";		//현재노드 정보 출력
		if (indexNode->getPreviousNode() == NULL)		//이전노드가 NULL이면 종료
			break;
		indexNode = indexNode->getPreviousNode();		//이전노드가 있으면 탐색노드를 이전노드로 변경

	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

// '(5) 특정 도서명부터 전체 출력'에 대한 메소드입니다.
//start노드부터 한 바퀴 돌아 모든 책을 출력합니다.
void List::printAll(Node *startNode)
{
	if (isEmpty())		//리스트가 비어있을 때
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return;
	}

	std::cout << '\n';
	Node *endNode;
	if (startNode->getPreviousNode() == NULL)		//특정 도서가 헤드인 경우 마지막은 tail
	{
		if (size == 1)								//리스트에 노드가 하나밖에없으면
			endNode = head;
		else
			endNode = tail;
	}
	else
	{
		endNode = startNode->getPreviousNode();		//헤드가 아닌 경우 마지막은 자기앞노드
	}

	Node *indexNode = startNode;
	while (true)
	{
		std::cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";		//현재노드 정보 출력
		if (indexNode == endNode)	//현재노드가 종료노드라면
			break;

		if (indexNode == tail)		//현재노드가 tail이면 한바퀴돌아서 다음노드는 head
			indexNode = head;
		else
			indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경
	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

//파일에 노드를 순차적으로 저장합니다.
void List::saveFile(string filePath)
{
	ofstream writeFile(filePath);
	if (writeFile.is_open())
	{
		if (isEmpty())						//list가 비어있다면 공백 저장
		{
			cout << "\n빈 리스트를 저장합니다!\n\n";
			writeFile << "";
			return;
		}

		Node *indexNode = head;
		while (true)
		{
			writeFile << indexNode->getBookNum() << " " << indexNode->getBookTitle() << '\n';		//현재노드 정보 쓰기
			if (indexNode->getNextNode() == NULL)		//다음노드가 NULL이면 종료
				break;
			indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경
		}
		writeFile.close();
	}
	else
	{
		cout << "[ERROR] 파일이 없습니다!\n";
		cout << "기존의 파일이 열려있거나 사라진 것 같습니다!\n";
	}
}

//Utility
bool List::isEmpty()							//리스트가 비어있는지 확인합니다.
{
	return size <= 0;
}

//Control Memory

void List::deleteMemory()
{
	if (isEmpty())		//list의 크기가 0이하이면(비어있으면) 삭제할 메모리가 없기때문에 중단합니다.
		return;

	Node *indexNode = head;
	while (true)
	{
		Node *tempNode = indexNode;
		indexNode = indexNode->getNextNode();

		delete tempNode;
		size--;

		if (indexNode == NULL)
			break;
	}
}