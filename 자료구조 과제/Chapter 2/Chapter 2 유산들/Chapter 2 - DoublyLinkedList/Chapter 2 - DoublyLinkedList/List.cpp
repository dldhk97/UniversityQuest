#include "List.h"

//Initializer

//head, tail�� NULL��, size�� 0���� �ʱ�ȭ�մϴ�.
List::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

//Getter

//head����� �ּҰ��� ��ȯ�մϴ�.
Node *List::getHead()
{
	return head;
}
//tail����� �ּҰ��� ��ȯ�մϴ�.
Node *List::getTail()
{
	return tail;
}

//Node Control

//��带 ��������� �ֽ��ϴ�.
void List::addNodeBySort(Node *iNode)
{
	if (isEmpty())	//ũ�Ⱑ 0 ���ϸ� �Է¹��� ��带 head�� �����մϴ�.
	{
		head = iNode;
		size++;							//ũ�⸦ �ϳ� �ø��ϴ�.
		return;
	}

	Node *indexNode = head;
	while (true)
	{
		std::string thisBookTitle = iNode->getBookTitle();
		std::string indexBookTitle = indexNode->getBookTitle();
		int comparedDifference = thisBookTitle.compare(indexBookTitle);	//�������� ����� å �̸��� Ž���ҳ�庸�� �ռ��� 0���� �۰�, �ƴϸ� 0���� ũ��.

		if (comparedDifference < 0)					//�������� ����� å�̸��� Ž���� å�� �̸����� ���������� �ռ��� �� �տ��� �ִ´�.
		{
			if (indexNode->getPreviousNode() == NULL)		//indexNode�տ� �������µ� indexNode��尡 head��� ���տ� �ִ´�.
			{
				Node *tempNode = head;						//��尡 ����Ű�� ��带 �ӽ������ϰ�
				head = iNode;								//��尡 iNode��带 ����Ű�� �Ѵ�.

				iNode->setNextNode(tempNode);				//iNode����� �������� ���� ��� ���� �Ѵ�.
				iNode->setPreviousNode(NULL);				//iNode����� ���� ���� NULLó���Ѵ�.(iNode�� ����̹Ƿ�)
				tempNode->setPreviousNode(iNode);			//���� ��� ����� ���� ���� iNode����̴�.
			}
			else											//indexNode�տ� �������µ� indexNode�� ��尡 �ƴѰ��
			{
				indexNode->getPreviousNode()->setNextNode(iNode);	//indexNode����� ���� ����� ������带 iNode���� �Ѵ�.
				iNode->setPreviousNode(indexNode->getPreviousNode());//iNode����� ������带 indexNode����� �������� �Ѵ�.
				iNode->setNextNode(indexNode);						//iNode ����� ���� ���� indexNode����̴�.
				indexNode->setPreviousNode(iNode);					//indexNode����� ���� ��带 iNode���� �Ѵ�.
			}
			size++;
			break;
		}
		else if (indexNode->getNextNode() == NULL)	//���������� �Դµ��� �� �־��ٸ� �갡 ������ ���(tail)��.
		{
			tail = iNode;
			indexNode->setNextNode(iNode);
			iNode->setPreviousNode(indexNode);
			iNode->setNextNode(NULL);
			size++;
			break;
		}
		indexNode = indexNode->getNextNode();		//Ž���ҳ�带 �������� �ٲ۴�.
	}
}

//å ��ȣ�� ��带 Ž���Ͽ� �����մϴ�.
void List::removeNodeByNum(string iBookNum)
{
	if (isEmpty())								//�����Ϸ��µ� List�� ��������� �׸��Ӵϴ�.
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return;
	}

	Node *targetNode = this->findNodeByBookData(iBookNum, "num");		//������ȣ�� Ž���Ͽ� �����ϸ� �����͸� ��ȯ�ϰ�, �ƴ� ��� NULL�� ��ȯ�մϴ�.

	if (targetNode == NULL)
	{
		std::cout << "\n�ش� ������ ã�� ���߽��ϴ�.\n\n";
		return;
	}

	if (targetNode->getPreviousNode() == NULL)			//�����尡 ����� ���
	{
		if (size > 1)	
		{
			head = targetNode->getNextNode();				//��带 �������� �������� ����
			head->setPreviousNode(NULL);					//�ٲ������ ������带 NULL�� ����
			targetNode->setNextNode(NULL);
		}
	}
	else if (targetNode->getNextNode() == NULL)			//�����尡 ������ ���
	{
		tail = targetNode->getPreviousNode();			//������ �������� �������� ����
		tail->setNextNode(NULL);						//�ٲ������� ������带 NULL�� ����
	}
	else
	{
		Node *tempPreviousNode = targetNode->getPreviousNode();		//�������� ������� �ӽ�����
		Node *tempNextNode = targetNode->getNextNode();				//�������� ������� �ӽ�����

		tempPreviousNode->setNextNode(tempNextNode);					//�������� ������带
		tempNextNode->setPreviousNode(tempPreviousNode);				//���� ��������ش�.
	}
	std::cout << '\n' << targetNode->getBookTitle() << " [" << targetNode->getBookNum() << "] �� ���������� �����Ǿ����ϴ�.\n\n";
	delete targetNode;		//�޸� ����
	size--;
	system("pause");
	std::cout << '\n';
}

Node *List::findNodeByBookData(string iBookData, string dataType)
{
	if (isEmpty())								//�����Ϸ��µ� List�� ��������� �׸��Ӵϴ�.
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return NULL;
	}

	Node *indexNode = head;
	std::string indexBookData;

	while (true)
	{
		if (dataType == "num")		//�˻��� �����Ͱ� å�� ��ȣ��
		{
			indexBookData = indexNode->getBookNum();
		}
		else						//�˻��� �����Ͱ� å�� �����̸�
		{
			indexBookData = indexNode->getBookTitle();
		}

		if (indexBookData == iBookData)					//ã������ å ������ �����ϸ�
		{
			return indexNode;
		}
		else if (indexNode->getNextNode() == NULL)			//���������� �Դµ��� ��ã���� NULL������ ��ȯ
		{
			return NULL;
		}
		indexNode = indexNode->getNextNode();		//Ž���ҳ�带 �������� �ٲ۴�.
	}
}

//User Control

//������ ���پ� �о� List�� Node�� �߰��ϴ� �޼ҵ��Դϴ�.
void List::readFile(string filePath)
{
	ifstream openFile(filePath);
	if (openFile.is_open())				//������ ���������� ������ ��
	{
		string line;

		while (getline(openFile, line))	//���پ� �н��ϴ�.
		{
			string tempBookNum, tempBookTitle;
			tempBookNum = line.substr(0, line.find(' '));					//ó������ ù��° ������ ���ö������� ��ȣ�� �Ǵ��Ͽ� �����մϴ�.
			tempBookTitle = line.substr(line.find(' ') + 1, line.length());	//ù��° ���� �������� ���������� �������� �Ǵ��Ͽ� �����մϴ�.

			this->addNodeBySort(new Node(tempBookNum, tempBookTitle));		//List�� Node�� ���θ���� �߰��մϴ�.
		}
		openFile.close();													//������ �� �о�鿴���Ƿ� ������ �ݽ��ϴ�.
	}
	else																	//������ ������ ���� ���
	{
		cout << "[ERROR]������ ���µ� �����Ͽ����ϴ�.\n";
		cout << "���, ���ϸ��� ������ Ȯ���� �ֽð�, ������ �����ϴ��� Ȯ�����ּ���.\n\n";
		cout << "[TIP]�Է� ������ �ؽ�Ʈ���ϸ����� �̷�����ִµ��� �ȿ����ø� ��θ� �����ϸ� ���������� �����ϴ�.\n";
		cout << "ex) C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe C:\\Users\\Administrator\\source\\LinkedList\\Debug\\text.txt\n\n";
		cout << "[TIP]���� ��ο� ���Ⱑ ���Ե��ִٸ� ��θ� \"�� �����ָ� �˴ϴ�!\n";
		cout << "ex) \"C:\\Users\\Administrator\\source\\LinkedList\\Debug\\Linked List.exe\" text.txt\n";
		exit(1);
	}
}

//'(1) �� ���� �Է�'�� ���� �޼ҵ��Դϴ�.
//����ڿ��� å�� ��ȣ�� ������ �Է¹޾� ��带 �ϳ� �߰��մϴ�.
void List::addBook()
{
	string tempBookNum, tempBookTitle;
	cout << "������ȣ�� �������� �Է��ϼ��� : ";
	cin >> tempBookNum;				//å ��ȣ �Է¹ޱ�
	cin.ignore();
	getline(cin, tempBookTitle);	//å ���� �Է¹ޱ�(å ������ ���̿� ������� �Է¹ޱ� ���� getline���� �޽��ϴ�)

	this->addNodeBySort(new Node(tempBookNum, tempBookTitle));		//��带 ���� ����� ����Ʈ�� �����մϴ�.

	cout << '\n' <<  tempBookTitle << " [" << tempBookNum << "] ��(��) ���������� �ԷµǾ����ϴ�.\n\n";
	system("pause");
	cout << '\n';
}

//'(2) ���� ����'�� ���� �޼ҵ��Դϴ�.
//����ڿ��� å�� ��ȣ�� �Է¹޾� ��带 ã�� �� �����մϴ�.
void List::removeBook()
{
	string tempBookNum;
	cout << "������ȣ�� �Է��ϼ��� : ";
	cin >> tempBookNum;

	this->removeNodeByNum(tempBookNum);				//å ��ȣ�� Ž���Ͽ� �����մϴ�.
}

//'(3) ������ ������ ��ü ���'�� ���� �޼ҵ��Դϴ�.
//��带 startNode���� tail���� ������� ����մϴ�.
void List::print(Node *startNode)
{
	if (isEmpty())		//����Ʈ�� ������� ��
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return;
	}

	Node *indexNode = startNode;							//�ε�����带 last�� �����ϰ�

	cout << '\n';
	while(true)
	{
		cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";	//���
		if (indexNode->getNextNode() == NULL)		//������尡 NULL�̸� ����
			break;
		indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
	}
	cout << '\n';
	system("pause");
	cout << '\n';
}

//'(4) ������ �������� ��ü ���'�� ���� �޼ҵ��Դϴ�. tail���� head���� ����մϴ�.
//'(6) Ư�� ��������� ù ��������� ���� ���'�� ���� �޼ҵ��Դϴ�.
void List::printR(Node *startNode)
{
	if (isEmpty())		//����Ʈ�� ������� ��
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return;
	}

	std::cout << '\n';
	Node *indexNode = startNode;
	
	if (size == 1)				//����Ʈ�� ��尡 �ϳ��ۿ� ������ ���ѷ����� ����.
		indexNode = head;

	while (true)
	{
		std::cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";		//������ ���� ���
		if (indexNode->getPreviousNode() == NULL)		//������尡 NULL�̸� ����
			break;
		indexNode = indexNode->getPreviousNode();		//������尡 ������ Ž����带 �������� ����

	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

// '(5) Ư�� ��������� ��ü ���'�� ���� �޼ҵ��Դϴ�.
//start������ �� ���� ���� ��� å�� ����մϴ�.
void List::printAll(Node *startNode)
{
	if (isEmpty())		//����Ʈ�� ������� ��
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return;
	}

	std::cout << '\n';
	Node *endNode;
	if (startNode->getPreviousNode() == NULL)		//Ư�� ������ ����� ��� �������� tail
	{
		if (size == 1)								//����Ʈ�� ��尡 �ϳ��ۿ�������
			endNode = head;
		else
			endNode = tail;
	}
	else
	{
		endNode = startNode->getPreviousNode();		//��尡 �ƴ� ��� �������� �ڱ�ճ��
	}

	Node *indexNode = startNode;
	while (true)
	{
		std::cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";		//������ ���� ���
		if (indexNode == endNode)	//�����尡 ��������
			break;

		if (indexNode == tail)		//�����尡 tail�̸� �ѹ������Ƽ� �������� head
			indexNode = head;
		else
			indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

//���Ͽ� ��带 ���������� �����մϴ�.
void List::saveFile(string filePath)
{
	ofstream writeFile(filePath);
	if (writeFile.is_open())
	{
		if (isEmpty())						//list�� ����ִٸ� ���� ����
		{
			cout << "\n�� ����Ʈ�� �����մϴ�!\n\n";
			writeFile << "";
			return;
		}

		Node *indexNode = head;
		while (true)
		{
			writeFile << indexNode->getBookNum() << " " << indexNode->getBookTitle() << '\n';		//������ ���� ����
			if (indexNode->getNextNode() == NULL)		//������尡 NULL�̸� ����
				break;
			indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
		}
		writeFile.close();
	}
	else
	{
		cout << "[ERROR] ������ �����ϴ�!\n";
		cout << "������ ������ �����ְų� ����� �� �����ϴ�!\n";
	}
}

//Utility
bool List::isEmpty()							//����Ʈ�� ����ִ��� Ȯ���մϴ�.
{
	return size <= 0;
}

//Control Memory

void List::deleteMemory()
{
	if (isEmpty())		//list�� ũ�Ⱑ 0�����̸�(���������) ������ �޸𸮰� ���⶧���� �ߴ��մϴ�.
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