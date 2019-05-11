#include "List.h"

//Initializer

//last를 NULL로, size를 0으로 초기화합니다.
List::List()
{
	last = NULL;
	size = 0;
}

//Getter

//last노드의 주소값을 반환합니다.
Node *List::getLast()
{
	return last;
}

//Node Control

//노드를 제목순으로 넣습니다.
void List::addNodeBySort(Node *iNode)
{
	if (size <= 0)	//크기가 0 이하면 입력받은 노드를 last노드로 설정합니다.
	{
		last = iNode;
		iNode->setNextNode(iNode);	//처음이기 때문에 last노드의 다음노드는 last로 지정합니다.
		size++;						//크기를 하나 올립니다.
		return;
	}

	Node *indexNode = last;			//탐색할 노드, 인덱스 노드입니다.
	Node *previousNode = last;		//인덱스 노드의 이전(앞) 노드입니다.
	do
	{
		previousNode = indexNode;				//이전 노드를 설정합니다.
		indexNode = indexNode->getNextNode();	//인덱스노드를 다음노드로 바꿉니다.

		int difference = iNode->getBookTitle().compare(indexNode->getBookTitle());		//입력받은 노드(iNode)와 탐색할노드(indexNode)의 책 제목을 비교합니다.

		if (difference < 0)						//입력받은 노드의 책 제목이 탐색할 노드의 책 제목보다 사전순으로 빠른경우
		{
			if (size == 1)						//만약 기존 list에 들어있던 노드가 last밖에 없는 경우, 입력받은 노드는 첫번째 노드가 됩니다.
			{
				iNode->setNextNode(last);		//입력받은 노드의 다음노드를 last노드로 설정합니다.
				last->setNextNode(iNode);		//last노드의 다음노드를 입력받은노드로 설정합니다.
				size++;							//크기를 증가시킵니다.
				return;
			}
												//기존 list에 들어있는 노드가 1개보다 많은 경우
			previousNode->setNextNode(iNode);	//이전 노드와 현재노드를 연결시켜줍니다.
			iNode->setNextNode(indexNode);		//현재노드와 인덱스노드를 연결시켜줍니다.
			size++;								//크기를 증가시킵니다.
			return;
		}
	} while (indexNode != last);				//한바퀴 쭉 돌았으면 탐색을 종료합니다.

												//한바퀴를 돌았는데 노드가 삽입되지 않은 경우 입력받은 노드가 last가 됩니다.
	iNode->setNextNode(last->getNextNode());	//입력받은 노드의 다음노드를 last의 다음노드(첫번째 노드)로 설정합니다.
	last->setNextNode(iNode);					//last 노드의 다음노드를 입력받은 노드로 설정합니다.
	last = iNode;								//last 노드를 입력받은 노드로 설정합니다.
	size++;										//크기를 증가시킵니다.
}

//책 번호로 노드를 탐색하여 삭제합니다.
void List::removeNodeByNum(string iBookNum)
{
	if (size <= 0)								//삭제하려는데 List가 비어있으면 그만둡니다.
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return;
	}
		
	bool isDeleted = false;
	Node *indexNode = last;
	Node *previousNode = last;
	do
	{
		previousNode = indexNode;					//이전 노드를 이전의 탐색한 노드로 합니다.
		indexNode = indexNode->getNextNode();		//이번에 탐색할 노드를 갱신합니다.
		if (indexNode->getBookNum() == iBookNum)	//탐색한 노드의 책 번호가 삭제할 책 번호와 같다면
		{
			if (indexNode == last)					//탐색한(삭제할) 노드가 만약 last라면
			{
				if (last->getNextNode() != NULL)	//탐색한(삭제할) 노드(last)의 다음 노드가 존재한다면
				{
					last = previousNode;			//last를 이전노드로 설정합니다.
					last->setNextNode(indexNode->getNextNode());	//이전노드와 탐색한노드의 다음노드를 연결합니다.
				}
				else								//탐색한(삭제할) 노드(last)의 다음 노드가 존재하지 않는다면, 즉 size = 1
				{
					last = NULL;					//last를 NULL로 설정
				}
				indexNode->setNextNode(NULL);		//탐색한(삭제할) 노드의 다음노드를 NULL로 합니다.
				isDeleted = true;					//현재 indexNode가 삭제할 대상입니다.
				break;
			}
			else									//탐색한(삭제할) 노드가 last가 아니라면
			{
				previousNode->setNextNode(indexNode->getNextNode());	//이전노드와 탐색한(삭제할) 노드의 다음노드를 연결시켜줍니다.
				indexNode->setNextNode(NULL);							//탐색한(삭제할) 노드의 다음노드를 NULL로 합니다.
				isDeleted = true;										//현재 indexNode가 삭제할 대상입니다.
				break;
			}
		}
	} while (indexNode != last);					//한바퀴 쭉 돌았으면 탐색을 종료합니다.

	if (isDeleted)									//삭제할 노드가 존재한다면(삭제할 노드는 indexNode입니다)
	{
		cout << '\n' << indexNode->getBookTitle()  << " [" << indexNode->getBookNum()<< "]을(를) 삭제했습니다.\n\n";
		delete indexNode;							//메모리 해제
		size--;										//크기를 줄입니다.
	}
	else											//삭제할 노드가 존재하지 않음
	{
		cout << '\n' << iBookNum <<"에 해당되는 책을 찾을 수 없습니다.\n\n";
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

//사용자에게 책의 번호를 입력받아 노드를 찾은 후 삭제합니다.
void List::removeBook()
{
	string tempBookNum;
	cout << "도서번호를 입력하세요 : ";
	cin >> tempBookNum;

	this->removeNodeByNum(tempBookNum);				//책 번호로 탐색하여 삭제합니다.
}

//노드를 처음부터 last까지 출력합니다.
void List::print()
{
	if (size <= 0)		//리스트가 비어있을 때
	{
		cout << "\n리스트가 비어있습니다!\n\n";
		return;
	}
		
	Node *indexNode = last;							//인덱스노드를 last로 설정하고
	
	cout << '\n';
	do
	{
		indexNode = indexNode->getNextNode();		//(처음에 last로 되어있기 때문에) 다음노드(처음엔 첫노드)로 인덱스노드를 바꿉니다.
		cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";	//출력
	} while (indexNode != last);					//한바퀴 다 돌았으면 종료
	cout << '\n';
}

//파일에 노드를 순차적으로 저장합니다.
void List::saveFile(string filePath)
{
	ofstream writeFile(filePath);
	if (writeFile.is_open())				//파일이 열려있다면
	{
		if (size <= 0)						//list가 비어있다면 공백 저장
		{
			cout << "\n빈 리스트를 저장합니다!\n\n";
			writeFile << "";
			return;
		}

		Node *indexNode = last;

		cout << '\n';
		do
		{
			indexNode = indexNode->getNextNode();		//(처음에 last로 되어있기 때문에) 다음노드(처음엔 첫노드)로 인덱스노드를 바꿉니다.
			writeFile << indexNode->getBookNum() << " " << indexNode->getBookTitle() << '\n';		//현재노드 정보 쓰기
		} while (indexNode != last);					//한바퀴 다 돌았으면 종료
		writeFile.close();
	}
	else
	{
		cout << "[ERROR] 파일이 없습니다!\n";
		cout << "기존의 파일이 열려있거나 사라진 것 같습니다!\n";
	}
}

//Control Memory

void List::deleteMemory()
{
	if (size <= 0)		//list의 크기가 0이하이면(비어있으면) 삭제할 메모리가 없기때문에 중단합니다.
		return;
	do
	{
		Node *tempNode = last;		//tempNode에 원래 last를 저장합니다.
		last = last->getNextNode();	//last를 다음노드로 옮깁니다.
		delete tempNode;			//원래 last를 삭제합니다.
		size--;						//크기를 하나 줄입니다.
	} while (size > 0);				//크기가 0이하면 종료
}