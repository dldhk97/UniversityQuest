#include "List.h"

//Initializer

//생성자입니다.
List::List()
{
	head = new Node();		//더미 헤드 노드 생성
	size = 0;
}

List::~List()
{
	if (isEmpty())		//list의 크기가 0이하이면(비어있으면) 삭제할 메모리가 없기때문에 중단합니다.
		return;
	size++;				//더미헤드까지 삭제해야되기 때문에 한번더 삭제를 해야함
	do
	{
		Node *tempNode = head;		//tempNode에 원래 head를 저장합니다.
		head = head->getNextNode();	//last를 다음노드로 옮깁니다.
		delete tempNode;			//원래 last를 삭제합니다.
		size--;						//크기를 하나 줄입니다.
	} while (!isEmpty());			//리스트가 비면 종료
}

//Getter

//더미 헤드 노드의 주소값을 반환합니다.
Node *List::getHead()
{
	return head;
}

//Node Control

//노드를 제목순으로 넣습니다.
void List::addNodeBySort(Node *iNode)
{
	if (isEmpty())						//리스트가 비어있다면 0 이하면 입력받은 노드를 첫번째 노드로 설정합니다.
	{
		head->setNextNode(iNode);		//더미헤드의 다음노드를 받은 노드로 설정
		iNode->setNextNode(head);		//처음이기 때문에 받은 노드의 다음노드는 head로 지정합니다.
		head->setPreviousNode(iNode);	//더미헤드의 이전노드를 받은 노드로 설정
		iNode->setPreviousNode(head);	//받은 노드의 이전노드를 더미 헤드로 설정
		size++;							//크기를 하나 올립니다.
		return;
	}

	Node *indexNode = head;			//탐색할 노드, 인덱스 노드입니다.
	do
	{
		indexNode = indexNode->getNextNode();	//인덱스노드를 다음노드로 바꿉니다.

		int difference = iNode->getBookTitle().compare(indexNode->getBookTitle());		//입력받은 노드(iNode)와 탐색할노드(indexNode)의 책 제목을 비교

		if (difference < 0)						//입력받은 노드의 책 제목이 탐색할 노드의 책 제목보다 사전순으로 빠른경우
		{
			if (size == 1)						//만약 기존 list에 들어있던 노드가 하나밖에 없는 경우, 입력받은 노드는 첫번째 노드가 되고, 기존에있던 노드는 두번째이자 마지막노드로 됨.
			{
				iNode->setNextNode(indexNode);
				indexNode->setPreviousNode(iNode);
				iNode->setPreviousNode(head);
				head->setNextNode(iNode);

				size++;
				return;
			}
			//기존 list에 들어있는 노드가 1개보다 많은 경우 앞의 노드의 next노드를 자신으로, 이전 노드의 previous노드를 자신으로, 자신의 previous,next노드도 설정
			indexNode->getPreviousNode()->setNextNode(iNode);
			iNode->setPreviousNode(indexNode->getPreviousNode());
			indexNode->setPreviousNode(iNode);
			iNode->setNextNode(indexNode);

			size++;
			return;
		}
	} while (indexNode != head->getPreviousNode());	//한바퀴 쭉 돌았으면 탐색을 종료

	//한바퀴 돌았는데도 안들어갔으면 이번노드가 마지막노드

	head->getPreviousNode()->setNextNode(iNode);
	iNode->setPreviousNode(head->getPreviousNode());
	iNode->setNextNode(head);
	head->setPreviousNode(iNode);

	size++;
}

//책 번호로 노드를 탐색하여 삭제합니다.
void List::removeNodeByNum(string iBookNum)
{
	if (isEmpty())							//삭제하려는데 List가 비어있으면 그만둡니다.
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return;
	}

	Node *targetNode = this->findNodeByBookData(iBookNum, "num");		//도서번호로 탐색하여 존재하면 포인터를 반환하고, 아닌 경우 NULL을 반환합니다.

	if (targetNode == NULL)
	{
		cout << '\n' << iBookNum << "에 해당되는 책을 찾을 수 없습니다.\n\n";
		return;
	}

	if (targetNode == head->getNextNode())				//현재노드가 헤드 다음(첫번째)인 경우
	{
		if (size > 1)									//더미헤드와 다음노드를 이어준다.
		{
			head->setNextNode(targetNode->getNextNode());
			targetNode->getNextNode()->setPreviousNode(head);
		}
		else											//현재노드밖에 없는경우
		{
			head->setNextNode(NULL);
			head->setPreviousNode(NULL);
		}
	}
	else												//현재노드가 첫번째가 아닌경우 앞뒤노드를 이어준다.
	{
		targetNode->getNextNode()->setPreviousNode(targetNode->getPreviousNode());
		targetNode->getPreviousNode()->setNextNode(targetNode->getNextNode());

	}
	std::cout << '\n' << targetNode->getBookTitle() << " [" << targetNode->getBookNum() << "] 이 정상적으로 삭제되었습니다.\n\n";
	delete targetNode;		//메모리 해제
	size--;
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
		else if (indexNode == head->getPreviousNode())	//마지막까지 왔는데도 못찾으면 NULL포인터 반환
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

	cout << tempBookTitle << " [" << tempBookNum << "] 이(가) 정상적으로 입력되었습니다.\n\n";
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
//노드를 startNode부터 마지막 노드까지 순서대로 출력합니다.
void List::print(Node *startNode)
{
	if (isEmpty())							//리스트가 비어있을 때
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return;
	}

	Node *indexNode = startNode;							//인덱스노드를 head로 설정하고

	cout << '\n';
	while (true)
	{
		cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";	//출력
		if (indexNode->getNextNode() == head)		//다음노드가 head이면 종료 한바퀴 돌았으므로
			break;
		indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경
	}
	cout << '\n';
}

//'(4) 도서명 역순으로 전체 출력'에 대한 메소드입니다. 마지막노드부터 첫번째노드까지 출력합니다.
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
		indexNode = head->getNextNode();

	while (true)
	{
		std::cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";		//현재노드 정보 출력
		if (indexNode->getPreviousNode() == head)		//이전노드가 head이면 종료
			break;
		indexNode = indexNode->getPreviousNode();		//이전노드가 있으면 탐색노드를 이전노드로 변경

	}
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
	if (startNode == head->getNextNode())		//시작 도서가 첫번째인 경우
	{
		if (size == 1)								//리스트에 노드가 하나밖에 없으면 종료시점은 자기자신을 출력하고난 뒤
			endNode = head->getNextNode();
		else										//리스트에 노드가 더 있으면 종료시점은 마지막노드
			endNode = head->getPreviousNode();
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

		if (indexNode == head->getPreviousNode())		//현재노드가 마지막노드이면 한바퀴돌아서 다음노드는 head
			indexNode = head->getNextNode();
		else
			indexNode = indexNode->getNextNode();		//다음노드가 있으면 탐색노드를 다음노드로 변경
	}
	std::cout << '\n';
}

//파일에 노드를 순차적으로 저장합니다.
void List::saveFile(string filePath)
{
	ofstream writeFile(filePath);
	if (writeFile.is_open())				//파일이 열려있다면
	{
		if (isEmpty())						//list가 비어있다면 공백 저장
		{
			cout << "\n빈 리스트를 저장합니다!\n\n";
			writeFile << "";
			return;
		}

		Node *indexNode = head;

		cout << '\n';
		do
		{
			indexNode = indexNode->getNextNode();		//(처음에 head로 되어있기 때문에) 다음노드(처음엔 첫노드)로 인덱스노드를 바꿉니다.
			writeFile << indexNode->getBookNum() << " " << indexNode->getBookTitle() << '\n';		//현재노드 정보 쓰기
		} while (indexNode != head->getPreviousNode());	//한바퀴 다 돌았으면 종료
		writeFile.close();
	}
	else
	{
		cout << "[ERROR] 파일이 없습니다!\n";
		cout << "기존의 파일이 열려있거나 사라진 것 같습니다!\n";
	}
}


//Utility

bool List::isEmpty()
{
	return size <= 0;
}