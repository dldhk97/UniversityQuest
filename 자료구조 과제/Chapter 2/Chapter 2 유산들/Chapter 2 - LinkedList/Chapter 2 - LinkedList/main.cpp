#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include "Book.h"

using namespace std;

//���Ḯ��Ʈ�� �̿��� å����� �а� ���� ���α׷��Դϴ�.
//cmd�� ȯ�溯���� �ְų� VS�� ����ȯ�溯���� �ؽ�Ʈ���� �־�� �����۵��մϴ�.
//�ؽ�Ʈ���� �ؽ�Ʈ��.txt�� �Ǿ�� �մϴ�(ex : test.txt)
//���࿡ �ؽ�Ʈ�� ��ΰ� ���ԵǾ����� �ʴٸ� �������� ������ ã���ϴ�.


string filePath;
Node *head;
const bool isDebug = false;									//debug�� �����Դϴ�. true�̸� ȯ�溯���� �����ʾƵ� ������ �Ǹ�, �������� �� test.txt�� ã�� �����մϴ�.

void initializePath(int argc, char* argv[])
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

	string fileDirectory = argv[0];							//�Է¹��� ���������� ��ο��� �������ϸ��� ������ ���� ��θ� ���´�.
	fileDirectory.replace(fileDirectory.find_last_of('\\'), fileDirectory.length(), "");
	
	if (isDebug)
		filePath = "test.txt";
	else
		filePath = argv[1];									//�Է¹��� �ؽ�Ʈ ���ϸ��� ����

	if (filePath.find("\\") == -1)							//�Է¹��� ���ϸ� ��ΰ� ���ԵǾ����� �ʴٸ� ���ϸ� �տ� ��θ� �ִ´�. (ex text.txt - > C:\Users\...\test.txt)
	{
		filePath = (string)fileDirectory + "\\" + filePath;
	}
}

void insertNode(Node *newNode)
{
	string headtempBookTitle = head->getBookData().getTitle();
	if (newNode->getBookData().getTitle().compare(headtempBookTitle) < 0)	//��庸�� ���������� ������ ���տ� �ִ´�.
	{
		newNode->insertNodeAtHead(head);
		head = newNode;
	}
	else
	{																		//��庸�� ���������� ������ Ž���ؼ� Ư�� ��ġ�� �ִ´�.
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
		cout << "[ERROR]������ ���µ� �����Ͽ����ϴ�.\n";
		cout << "���, ���ϸ��� ������ Ȯ���� �ֽʽÿ�.\n";
		exit(1);
	}
}

void printMenu()
{
	cout << "��� : ";
	cout << filePath << '\n';
	cout << "==============================\n";
	cout << "(1) �� ���� �Է�\n";
	cout << "(2) ���� ����\n";
	cout << "(3) ������ ������ ��ü ���\n";
	cout << "(4) ���Ͽ� �����ϰ� ����\n";
	cout << "==============================\n";
	cout << "���ϴ� ����� �����ϼ��� : ";
}

void addBook()
{
	string tempBookNum, tempBookTitle;
	cout << "������ȣ�� �������� �Է��ϼ��� : ";
	cin >> tempBookNum >> tempBookTitle;

	Book newBook(tempBookNum, tempBookTitle);
	Node *newNode = new Node(newBook);

	insertNode(newNode);
	cout << tempBookTitle << " [" << tempBookNum << "] ��(��) ���������� �ԷµǾ����ϴ�.\n\n";
	system("pause");
	cout << '\n';
}

void removeBook()
{
	string tempBookNum;
	cout << "������ȣ�� �Է��ϼ��� : ";
	cin >> tempBookNum;

	Node *indexNode = head;
	Node *previousNode = head;
	while (true)
	{
		if (indexNode->getBookData().getNum() == tempBookNum)		//�����Ϸ��� �����
		{
			if (indexNode == head)									//��������� ����̸�
				head = indexNode->getNextNode();					//��� ���� ��带 ���� �Ѵ�.
			else
				previousNode->setNextNode(indexNode->getNextNode());	//��尡 �ƴϸ� ������尡 �����带 �ǳʶپ� ������带 ����Ű���� �Ѵ�.
			cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "] �� ���������� �����Ǿ����ϴ�.\n";
			
			delete indexNode;										//������ �޸� ����
			break;
		}
		else if (indexNode->getNextNode() == NULL)		//Ž���� ������ �ߴµ� ��ã������ ����
		{
			cout << "�ش� ������ ã�� ���߽��ϴ�.\n";
			break;
		}
		previousNode = indexNode;
		indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
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
		cout << indexNode->getBookData().getTitle() << " [" << indexNode->getBookData().getNum() << "]\n";		//������ ���� ���
		if (indexNode->getNextNode() == NULL)		//������尡 NULL�̸� ����
			break;
		indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
		
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
			writeFile << indexNode->getBookData().getNum() << " " << indexNode->getBookData().getTitle() << '\n';		//������ ���� ����
			if (indexNode->getNextNode() == NULL)		//������尡 NULL�̸� ����
				break;
			indexNode = indexNode->getNextNode();		//������尡 ������ Ž����带 �������� ����
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
	cout << "�����մϴ�.\n";

	return 0;
}