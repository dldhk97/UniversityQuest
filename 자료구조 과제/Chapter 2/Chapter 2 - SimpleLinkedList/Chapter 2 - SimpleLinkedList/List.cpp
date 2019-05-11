#include "List.h"

//Initializer

//last�� NULL��, size�� 0���� �ʱ�ȭ�մϴ�.
List::List()
{
	last = NULL;
	size = 0;
}

//Getter

//last����� �ּҰ��� ��ȯ�մϴ�.
Node *List::getLast()
{
	return last;
}

//Node Control

//��带 ��������� �ֽ��ϴ�.
void List::addNodeBySort(Node *iNode)
{
	if (size <= 0)	//ũ�Ⱑ 0 ���ϸ� �Է¹��� ��带 last���� �����մϴ�.
	{
		last = iNode;
		iNode->setNextNode(iNode);	//ó���̱� ������ last����� �������� last�� �����մϴ�.
		size++;						//ũ�⸦ �ϳ� �ø��ϴ�.
		return;
	}

	Node *indexNode = last;			//Ž���� ���, �ε��� ����Դϴ�.
	Node *previousNode = last;		//�ε��� ����� ����(��) ����Դϴ�.
	do
	{
		previousNode = indexNode;				//���� ��带 �����մϴ�.
		indexNode = indexNode->getNextNode();	//�ε�����带 �������� �ٲߴϴ�.

		int difference = iNode->getBookTitle().compare(indexNode->getBookTitle());		//�Է¹��� ���(iNode)�� Ž���ҳ��(indexNode)�� å ������ ���մϴ�.

		if (difference < 0)						//�Է¹��� ����� å ������ Ž���� ����� å ���񺸴� ���������� �������
		{
			if (size == 1)						//���� ���� list�� ����ִ� ��尡 last�ۿ� ���� ���, �Է¹��� ���� ù��° ��尡 �˴ϴ�.
			{
				iNode->setNextNode(last);		//�Է¹��� ����� ������带 last���� �����մϴ�.
				last->setNextNode(iNode);		//last����� ������带 �Է¹������� �����մϴ�.
				size++;							//ũ�⸦ ������ŵ�ϴ�.
				return;
			}
												//���� list�� ����ִ� ��尡 1������ ���� ���
			previousNode->setNextNode(iNode);	//���� ���� �����带 ��������ݴϴ�.
			iNode->setNextNode(indexNode);		//������� �ε�����带 ��������ݴϴ�.
			size++;								//ũ�⸦ ������ŵ�ϴ�.
			return;
		}
	} while (indexNode != last);				//�ѹ��� �� �������� Ž���� �����մϴ�.

												//�ѹ����� ���Ҵµ� ��尡 ���Ե��� ���� ��� �Է¹��� ��尡 last�� �˴ϴ�.
	iNode->setNextNode(last->getNextNode());	//�Է¹��� ����� ������带 last�� �������(ù��° ���)�� �����մϴ�.
	last->setNextNode(iNode);					//last ����� ������带 �Է¹��� ���� �����մϴ�.
	last = iNode;								//last ��带 �Է¹��� ���� �����մϴ�.
	size++;										//ũ�⸦ ������ŵ�ϴ�.
}

//å ��ȣ�� ��带 Ž���Ͽ� �����մϴ�.
void List::removeNodeByNum(string iBookNum)
{
	if (size <= 0)								//�����Ϸ��µ� List�� ��������� �׸��Ӵϴ�.
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return;
	}
		
	bool isDeleted = false;
	Node *indexNode = last;
	Node *previousNode = last;
	do
	{
		previousNode = indexNode;					//���� ��带 ������ Ž���� ���� �մϴ�.
		indexNode = indexNode->getNextNode();		//�̹��� Ž���� ��带 �����մϴ�.
		if (indexNode->getBookNum() == iBookNum)	//Ž���� ����� å ��ȣ�� ������ å ��ȣ�� ���ٸ�
		{
			if (indexNode == last)					//Ž����(������) ��尡 ���� last���
			{
				if (last->getNextNode() != NULL)	//Ž����(������) ���(last)�� ���� ��尡 �����Ѵٸ�
				{
					last = previousNode;			//last�� �������� �����մϴ�.
					last->setNextNode(indexNode->getNextNode());	//�������� Ž���ѳ���� ������带 �����մϴ�.
				}
				else								//Ž����(������) ���(last)�� ���� ��尡 �������� �ʴ´ٸ�, �� size = 1
				{
					last = NULL;					//last�� NULL�� ����
				}
				indexNode->setNextNode(NULL);		//Ž����(������) ����� ������带 NULL�� �մϴ�.
				isDeleted = true;					//���� indexNode�� ������ ����Դϴ�.
				break;
			}
			else									//Ž����(������) ��尡 last�� �ƴ϶��
			{
				previousNode->setNextNode(indexNode->getNextNode());	//�������� Ž����(������) ����� ������带 ��������ݴϴ�.
				indexNode->setNextNode(NULL);							//Ž����(������) ����� ������带 NULL�� �մϴ�.
				isDeleted = true;										//���� indexNode�� ������ ����Դϴ�.
				break;
			}
		}
	} while (indexNode != last);					//�ѹ��� �� �������� Ž���� �����մϴ�.

	if (isDeleted)									//������ ��尡 �����Ѵٸ�(������ ���� indexNode�Դϴ�)
	{
		cout << '\n' << indexNode->getBookTitle()  << " [" << indexNode->getBookNum()<< "]��(��) �����߽��ϴ�.\n\n";
		delete indexNode;							//�޸� ����
		size--;										//ũ�⸦ ���Դϴ�.
	}
	else											//������ ��尡 �������� ����
	{
		cout << '\n' << iBookNum <<"�� �ش�Ǵ� å�� ã�� �� �����ϴ�.\n\n";
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

//����ڿ��� å�� ��ȣ�� �Է¹޾� ��带 ã�� �� �����մϴ�.
void List::removeBook()
{
	string tempBookNum;
	cout << "������ȣ�� �Է��ϼ��� : ";
	cin >> tempBookNum;

	this->removeNodeByNum(tempBookNum);				//å ��ȣ�� Ž���Ͽ� �����մϴ�.
}

//��带 ó������ last���� ����մϴ�.
void List::print()
{
	if (size <= 0)		//����Ʈ�� ������� ��
	{
		cout << "\n����Ʈ�� ����ֽ��ϴ�!\n\n";
		return;
	}
		
	Node *indexNode = last;							//�ε�����带 last�� �����ϰ�
	
	cout << '\n';
	do
	{
		indexNode = indexNode->getNextNode();		//(ó���� last�� �Ǿ��ֱ� ������) �������(ó���� ù���)�� �ε�����带 �ٲߴϴ�.
		cout << indexNode->getBookTitle() << " [" << indexNode->getBookNum() << "]\n";	//���
	} while (indexNode != last);					//�ѹ��� �� �������� ����
	cout << '\n';
}

//���Ͽ� ��带 ���������� �����մϴ�.
void List::saveFile(string filePath)
{
	ofstream writeFile(filePath);
	if (writeFile.is_open())				//������ �����ִٸ�
	{
		if (size <= 0)						//list�� ����ִٸ� ���� ����
		{
			cout << "\n�� ����Ʈ�� �����մϴ�!\n\n";
			writeFile << "";
			return;
		}

		Node *indexNode = last;

		cout << '\n';
		do
		{
			indexNode = indexNode->getNextNode();		//(ó���� last�� �Ǿ��ֱ� ������) �������(ó���� ù���)�� �ε�����带 �ٲߴϴ�.
			writeFile << indexNode->getBookNum() << " " << indexNode->getBookTitle() << '\n';		//������ ���� ����
		} while (indexNode != last);					//�ѹ��� �� �������� ����
		writeFile.close();
	}
	else
	{
		cout << "[ERROR] ������ �����ϴ�!\n";
		cout << "������ ������ �����ְų� ����� �� �����ϴ�!\n";
	}
}

//Control Memory

void List::deleteMemory()
{
	if (size <= 0)		//list�� ũ�Ⱑ 0�����̸�(���������) ������ �޸𸮰� ���⶧���� �ߴ��մϴ�.
		return;
	do
	{
		Node *tempNode = last;		//tempNode�� ���� last�� �����մϴ�.
		last = last->getNextNode();	//last�� �������� �ű�ϴ�.
		delete tempNode;			//���� last�� �����մϴ�.
		size--;						//ũ�⸦ �ϳ� ���Դϴ�.
	} while (size > 0);				//ũ�Ⱑ 0���ϸ� ����
}