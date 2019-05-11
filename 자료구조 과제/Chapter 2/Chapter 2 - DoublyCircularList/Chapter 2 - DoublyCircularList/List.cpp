#include "List.h"

//Initializer

//�������Դϴ�.
List::List()
{
	head = new Node();		//���� ��� ��� ����
	size = 0;
}

List::~List()
{
	if (isEmpty())		//list�� ũ�Ⱑ 0�����̸�(���������) ������ �޸𸮰� ���⶧���� �ߴ��մϴ�.
		return;
	size++;				//���������� �����ؾߵǱ� ������ �ѹ��� ������ �ؾ���
	do
	{
		Node *tempNode = head;		//tempNode�� ���� head�� �����մϴ�.
		head = head->getNextNode();	//last�� �������� �ű�ϴ�.
		delete tempNode;			//���� last�� �����մϴ�.
		size--;						//ũ�⸦ �ϳ� ���Դϴ�.
	} while (!isEmpty());			//����Ʈ�� ��� ����
}

//Getter

//���� ��� ����� �ּҰ��� ��ȯ�մϴ�.
Node *List::getHead()
{
	return head;
}

//Node Control

//��带 ��������� �ֽ��ϴ�.
void List::addNodeBySort(Node *iNode)
{
	if (isEmpty())						//����Ʈ�� ����ִٸ� 0 ���ϸ� �Է¹��� ��带 ù��° ���� �����մϴ�.
	{
		head->setNextNode(iNode);		//��������� ������带 ���� ���� ����
		iNode->setNextNode(head);		//ó���̱� ������ ���� ����� �������� head�� �����մϴ�.
		head->setPreviousNode(iNode);	//��������� ������带 ���� ���� ����
		iNode->setPreviousNode(head);	//���� ����� ������带 ���� ���� ����
		size++;							//ũ�⸦ �ϳ� �ø��ϴ�.
		return;
	}

	Node *indexNode = head;			//Ž���� ���, �ε��� ����Դϴ�.
	do
	{
		indexNode = indexNode->getNextNode();	//�ε�����带 �������� �ٲߴϴ�.

		int difference = iNode->getBookTitle().compare(indexNode->getBookTitle());		//�Է¹��� ���(iNode)�� Ž���ҳ��(indexNode)�� å ������ ��

		if (difference < 0)						//�Է¹��� ����� å ������ Ž���� ����� å ���񺸴� ���������� �������
		{
			if (size == 1)						//���� ���� list�� ����ִ� ��尡 �ϳ��ۿ� ���� ���, �Է¹��� ���� ù��° ��尡 �ǰ�, �������ִ� ���� �ι�°���� ���������� ��.
			{
				iNode->setNextNode(indexNode);
				indexNode->setPreviousNode(iNode);
				iNode->setPreviousNode(head);
				head->setNextNode(iNode);

				size++;
				return;
			}
			//���� list�� ����ִ� ��尡 1������ ���� ��� ���� ����� next��带 �ڽ�����, ���� ����� previous��带 �ڽ�����, �ڽ��� previous,next��嵵 ����
			indexNode->getPreviousNode()->setNextNode(iNode);
			iNode->setPreviousNode(indexNode->getPreviousNode());
			indexNode->setPreviousNode(iNode);
			iNode->setNextNode(indexNode);

			size++;
			return;
		}
	} while (indexNode != head->getPreviousNode());	//�ѹ��� �� �������� Ž���� ����

	//�ѹ��� ���Ҵµ��� �ȵ����� �̹���尡 ���������

	head->getPreviousNode()->setNextNode(iNode);
	iNode->setPreviousNode(head->getPreviousNode());
	iNode->setNextNode(head);
	head->setPreviousNode(iNode);

	size++;
}

//å ��ȣ�� ��带 Ž���Ͽ� �����մϴ�.
void List::removeNodeByNum(string iBookNum)
{
	if (isEmpty())							//�����Ϸ��µ� List�� ��������� �׸��Ӵϴ�.
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return;
	}

	Node *targetNode = this->findNodeByBookData(iBookNum, "num");		//������ȣ�� Ž���Ͽ� �����ϸ� �����͸� ��ȯ�ϰ�, �ƴ� ��� NULL�� ��ȯ�մϴ�.

	if (targetNode == NULL)
	{
		cout << '\n' << iBookNum << "�� �ش�Ǵ� å�� ã�� �� �����ϴ�.\n\n";
		return;
	}

	if (targetNode == head->getNextNode())				//�����尡 ��� ����(ù��°)�� ���
	{
		if (size > 1)									//�������� ������带 �̾��ش�.
		{
			head->setNextNode(targetNode->getNextNode());
			targetNode->getNextNode()->setPreviousNode(head);
		}
		else											//������ۿ� ���°��
		{
			head->setNextNode(NULL);
			head->setPreviousNode(NULL);
		}
	}
	else												//�����尡 ù��°�� �ƴѰ�� �յڳ�带 �̾��ش�.
	{
		targetNode->getNextNode()->setPreviousNode(targetNode->getPreviousNode());
		targetNode->getPreviousNode()->setNextNode(targetNode->getNextNode());

	}
	std::cout << '\n' << targetNode->getBookTitle() << " [" << targetNode->getBookNum() << "] �� ���������� �����Ǿ����ϴ�.\n\n";
	delete targetNode;		//�޸� ����
	size--;
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
		else if (indexNode == head->getPreviousNode())	//���������� �Դµ��� ��ã���� NULL������ ��ȯ
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

	cout << tempBookTitle << " [" << tempBookNum << "] ��(��) ���������� �ԷµǾ����ϴ�.\n\n";
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
//��带 startNode���� ������ ������ ������� ����մϴ�.
void List::print(Node *startNode)
{
	if (isEmpty())							//����Ʈ�� ������� ��
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return;
	}

	Node *indexNode = startNode;							//�ε�����带 head�� �����ϰ�

	cout << '\n';
	while (true)
	{
		cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";	//���
		if (indexNode->getNextNode() == head)		//������尡 head�̸� ���� �ѹ��� �������Ƿ�
			break;
		indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
	}
	cout << '\n';
}

//'(4) ������ �������� ��ü ���'�� ���� �޼ҵ��Դϴ�. ������������ ù��°������ ����մϴ�.
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
		indexNode = head->getNextNode();

	while (true)
	{
		std::cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";		//������ ���� ���
		if (indexNode->getPreviousNode() == head)		//������尡 head�̸� ����
			break;
		indexNode = indexNode->getPreviousNode();		//������尡 ������ Ž����带 �������� ����

	}
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
	if (startNode == head->getNextNode())		//���� ������ ù��°�� ���
	{
		if (size == 1)								//����Ʈ�� ��尡 �ϳ��ۿ� ������ ��������� �ڱ��ڽ��� ����ϰ� ��
			endNode = head->getNextNode();
		else										//����Ʈ�� ��尡 �� ������ ��������� ���������
			endNode = head->getPreviousNode();
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

		if (indexNode == head->getPreviousNode())		//�����尡 ����������̸� �ѹ������Ƽ� �������� head
			indexNode = head->getNextNode();
		else
			indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
	}
	std::cout << '\n';
}

//���Ͽ� ��带 ���������� �����մϴ�.
void List::saveFile(string filePath)
{
	ofstream writeFile(filePath);
	if (writeFile.is_open())				//������ �����ִٸ�
	{
		if (isEmpty())						//list�� ����ִٸ� ���� ����
		{
			cout << "\n�� ����Ʈ�� �����մϴ�!\n\n";
			writeFile << "";
			return;
		}

		Node *indexNode = head;

		cout << '\n';
		do
		{
			indexNode = indexNode->getNextNode();		//(ó���� head�� �Ǿ��ֱ� ������) �������(ó���� ù���)�� �ε�����带 �ٲߴϴ�.
			writeFile << indexNode->getBookNum() << " " << indexNode->getBookTitle() << '\n';		//������ ���� ����
		} while (indexNode != head->getPreviousNode());	//�ѹ��� �� �������� ����
		writeFile.close();
	}
	else
	{
		cout << "[ERROR] ������ �����ϴ�!\n";
		cout << "������ ������ �����ְų� ����� �� �����ϴ�!\n";
	}
}


//Utility

bool List::isEmpty()
{
	return size <= 0;
}