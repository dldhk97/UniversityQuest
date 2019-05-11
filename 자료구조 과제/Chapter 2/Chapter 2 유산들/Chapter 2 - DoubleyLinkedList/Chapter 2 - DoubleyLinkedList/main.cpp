#include <iostream>
#include <string>
#include <fstream>
#include "DNode.h"

using namespace std;

//���߿��Ḯ��Ʈ�� �̿��� å����� �а� ���� ���α׷��Դϴ�.
//cmd�� ȯ�溯���� �ְų� VS�� ����ȯ�溯���� �ؽ�Ʈ���� �־�� �����۵��մϴ�.
//�ؽ�Ʈ���� �ؽ�Ʈ��.txt�� �Ǿ�� �մϴ�(ex : test.txt)
//���࿡ �ؽ�Ʈ�� ��ΰ� ���ԵǾ����� �ʴٸ� �������� ������ ã���ϴ�.

string filePath;
DNode *head;
DNode *tail;
const bool isDebug = false;		//debug�� �����Դϴ�. true�̸� ȯ�溯���� �����ʾƵ� ������ �Ǹ�, �������� �� test.txt�� ã�� �����մϴ�.

//ȯ�溯���� ���� �ؽ�Ʈ���ϸ��� Ȯ���Ͽ� ��ΰ� ���ԵǾ����� ������ ��θ� ���Խ����ݴϴ�.
void initializePath(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "[ERROR]�Է� �ɼ� ����!\n";
		std::cout << "cmd���� ȯ�溯���� �ְ� �������ּ���!\n";
		std::cout << "ex) C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe text.txt\n\n";
		std::cout << "[TIP]���� ��ο� ���Ⱑ ���Ե��ִٸ� ��θ� \"�� �����ָ� �˴ϴ�!\n";
		std::cout << "ex) \"C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe\" text.txt\n";
		exit(1);
	}

	string fileDirectory = argv[0];					//�Է¹��� ���������� ��ο��� �������ϸ��� ������ ���� ��θ� ���´�.
	fileDirectory.replace(fileDirectory.find_last_of('\\'), fileDirectory.length(), "");

	if (isDebug)
		filePath = "test.txt";
	else
		filePath = argv[1];							//�Է¹��� �ؽ�Ʈ ���ϸ��� ����

	if (filePath.find("\\") == -1)					//�Է¹��� ���ϸ� ��ΰ� ���ԵǾ����� �ʴٸ� ���ϸ� �տ� ��θ� �ִ´�. (ex text.txt - > C:\Users\...\test.txt)
	{
		filePath = (string)fileDirectory + "\\" + filePath;
	}
}

//�����Ϸ��� ��尡 ��庸�� ���������� ������ �ƴ��� �Ǵ��մϴ�.
//���� head�� tail�� �����ϴ� ���ҵ� �մϴ�.
void insertNode(DNode *newNode)
{
	string headBookTitle = head->getBookData().getTitle();
	if (newNode->getBookData().getTitle().compare(headBookTitle) < 0)	//��庸�� ���������� ������ ���տ� �ִ´�.
	{
		newNode->insertNodeAtHead(head);
		head = newNode;
	}
	else
	{																//��庸�� ���������� ������ Ž���ؼ� Ư�� ��ġ�� �ִ´�.
		DNode *temp = newNode->insertNodeBySort(head);				//���� �־��µ� �̰� tail�̶�� tail�� �����Ѵ�.
		if (temp != NULL)
			tail = temp;
	}
}

//�ؽ�Ʈ�� �о�鿩 ���������� Node�� ���� �� �����մϴ�.
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

			if (head == NULL)		//��尡 �������� �ʴ´ٸ� �̹���带 ���� ����
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
		std::cout << "[ERROR]������ ���µ� �����Ͽ����ϴ�.\n";
		std::cout << "���, ���ϸ��� ������ Ȯ���� �ֽʽÿ�.\n";
		exit(1);
	}
}

//����ڿ��� �޴��� �����ݴϴ�.
void printMenu()
{
	std::cout << "��� : ";
	std::cout << filePath << '\n';
	std::cout << "==============================\n";
	std::cout << "(1) �� ���� �Է�\n";
	std::cout << "(2) ���� ����\n";
	std::cout << "(3) ������ ������ ��ü ���\n";
	std::cout << "(4) ������ �������� ��ü ���\n";
	std::cout << "(5) Ư�� ��������� ��ü ���\n";
	std::cout << "(6) Ư�� ��������� ù ��������� ���� ���\n";
	std::cout << "(7) ���Ͽ� �����ϰ� ����\n";
	std::cout << "==============================\n";
	std::cout << "���ϴ� ����� �����ϼ��� : ";
}

//'(1) �� ���� �Է�'�� ���� �޼ҵ��Դϴ�.
void addBook()
{
	string tempBookNum, tempBookTitle;
	std::cout << "������ȣ�� �������� �Է��ϼ��� : ";
	cin >> tempBookNum >> tempBookTitle;

	Book newBook(tempBookNum, tempBookTitle);
	DNode *newNode = new DNode(newBook);

	insertNode(newNode);
	std::cout << tempBookTitle << " [" << tempBookNum << "] ��(��) ���������� �ԷµǾ����ϴ�.\n\n";
	system("pause");
	std::cout << '\n';
}

//'(2) ���� ����'�� ���� �޼ҵ��Դϴ�.
void removeBook()
{
	string tempBookNum;
	std::cout << "������ȣ�� �Է��ϼ��� : ";
	cin >> tempBookNum;

	DNode *targetNode = head->findNodeByBookData(tempBookNum, "num");		//������ȣ�� Ž���Ͽ� �����ϸ� �����͸� ��ȯ�ϰ�, �ƴ� ��� NULL�� ��ȯ�մϴ�.

	if (targetNode == NULL)
	{
		std::cout << "�ش� ������ ã�� ���߽��ϴ�.\n";
		return;
	}

	if (targetNode->getPreviousNode() == NULL)			//�����尡 ����� ���
	{
		head = targetNode->getNextNode();				//��带 �������� �������� ����
		head->setPreviousNode(NULL);					//�ٲ������ ������带 NULL�� ����
	}
	else if (targetNode->getNextNode() == NULL)			//�����尡 ������ ���
	{
		tail = targetNode->getPreviousNode();			//������ �������� �������� ����
		tail->setNextNode(NULL);						//�ٲ������� ������带 NULL�� ����
	}
	else
	{
		DNode *tempPreviousNode = targetNode->getPreviousNode();		//�������� ������� �ӽ�����
		DNode *tempNextNode = targetNode->getNextNode();				//�������� ������� �ӽ�����

		tempPreviousNode->setNextNode(tempNextNode);					//�������� ������带
		tempNextNode->setPreviousNode(tempPreviousNode);				//���� ��������ش�.
	}
	std::cout << targetNode->getBookData().getTitle() << " [" << targetNode->getBookData().getNum() << "] �� ���������� �����Ǿ����ϴ�.\n";
	delete targetNode;		//�޸� ����
	system("pause");
	std::cout << '\n';
}

//'(3) ������ ������ ��ü ���'�� ���� �޼ҵ��Դϴ�.
//start������ tail������ ����մϴ�.
void printBookList(DNode *start)
{
	std::cout << '\n';
	DNode *indexNode = start;
	while (true)
	{
		std::cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "]\n";		//������ ���� ���
		if (indexNode->getNextNode() == NULL)		//������尡 NULL�̸� ����
			break;
		indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����

	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

//'(5) Ư�� ��������� ��ü ���'�� ���� �޼ҵ��Դϴ�.
//start������ �� ���� ���� ��� å�� ����մϴ�.
void printBookListAll(DNode *start)
{
	std::cout << '\n';
	DNode *endNode;
	if (start->getPreviousNode() == NULL)		//Ư�� ������ ����� ���
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
		std::cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "]\n";		//������ ���� ���
		if (indexNode == endNode)	//�����尡 ��������
			break;

		if (indexNode == tail)		//�����尡 tail�̸� 
			indexNode = head;
		else
			indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����

	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

//'(4) ������ �������� ��ü ���'�� ���� �޼ҵ��Դϴ�. start������ head���� ����մϴ�.
//'(6) Ư�� ��������� ù ��������� ���� ���'�� ���� �޼ҵ��Դϴ�.
void printBookList_R(DNode *start)
{
	std::cout << '\n';
	DNode *indexNode = start;
	while (true)
	{
		std::cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "]\n";		//������ ���� ���
		if (indexNode->getPreviousNode() == NULL)		//������尡 NULL�̸� ����
			break;
		indexNode = indexNode->getPreviousNode();		//������尡 ������ Ž����带 �������� ����

	}
	std::cout << '\n';
	system("pause");
	std::cout << '\n';
}

//���α׷��� ����� �� �ؽ�Ʈ���Ͽ� ����ϴ�.
void saveFile()
{
	ofstream writeFile(filePath);
	if (writeFile.is_open())
	{
		DNode *indexNode = head;
		while (true)
		{
			writeFile << indexNode->getBookData().getNum() << " " << indexNode->getBookData().getTitle() << '\n';		//������ ���� ����
			if (indexNode->getNextNode() == NULL)		//������尡 NULL�̸� ����
				break;
			indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
		}
		writeFile.close();
	}
}

//���α׷��� ����� �� head���� ������ ��带 �޸� �����մϴ�.
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
			std::cout << "Ư�� �������� �Է��ϼ��� : ";
			cin.ignore();
			getline(cin,stringInput);
			resultNode = head->findNodeByBookData(stringInput,"title");
			if (resultNode == NULL)
				std::cout << "ã������ å�� �����ϴ�.\n";
			else
				printBookListAll(resultNode);
			break;
		case 6:
			std::cout << "Ư�� �������� �Է��ϼ��� : ";
			cin.ignore();
			getline(cin, stringInput);
			resultNode = head->findNodeByBookData(stringInput, "title");
			if (resultNode == NULL)
				std::cout << "ã������ å�� �����ϴ�.\n";
			else
				printBookList_R(resultNode);
			break;
		}
	}

	saveFile();
	deleteMemory();
	std::cout << "�����մϴ�.\n";
	return 0;
}