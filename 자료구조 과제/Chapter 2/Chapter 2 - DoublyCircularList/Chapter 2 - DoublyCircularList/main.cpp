#include <iostream>
#include <string>
#include <direct.h>		//_getcwd, ���� ������ġ ��ιޱ�, Windows ȯ���� �ƴ϶�� �ּ�ó�� ���ֽʽÿ�.
#include "List.h"

using namespace std;

const bool isWindows = true;					// Windows ȯ���� �ƴ϶��(direct.h�� �������� �ʴ� ���) false�� �������ֽʽÿ�.

//�� ���α׷��� ANSI �ؽ�Ʈ���ϸ� ���� �� �ֽ��ϴ�! UTF-8�ΰ�쿡�� �۾��� �����ϴ�.

//����ȯ�����Ḯ��Ʈ�� �̿��� å����� �а� ���� ���α׷��Դϴ�.
//cmd�� ȯ�溯���� �ְų� VS�� �Է� ������ �ؽ�Ʈ�� Ȥ�� �ؽ�Ʈ���� ��θ� �־�� �����۵��մϴ�.
//�ؽ�Ʈ���� �ؽ�Ʈ��.txt�� �Ǿ�� �մϴ�(ex : test.txt)
//���࿡ �ؽ�Ʈ�� ��ΰ� ���ԵǾ����� �ʴٸ� �������� ������ ã���ϴ�.

//������ �������� �ȿ������� üũ�մϴ�.
bool isFileExist(string filePath)
{
	ifstream openFile(filePath);
	if (openFile.is_open())			//�����ٸ� �ݾ��ݴϴ�.
	{
		openFile.close();
		return true;
	}
	return false;
}

//�ؽ�Ʈ ���� ��θ� �ʱ�ȭ�մϴ�.
//���� ���ϸ��� ������.txt�� ��� �տ� ���������� ��θ� �����Դϴ�.
//���� cmd�� �������� �� argv[0]�� ���� ��ΰ� �ƴ� �������ϸ��� �Ǿ������ ������ getcwd�� �����θ� �޾� ��η� �����մϴ�.
//���־�Ʃ����� �����ϸ� �ݴ��, getcwd�� ���� ��ȿ���� �ʰ�, argv[0]�� ���� ��ȿ�ϱ� ������ argv[0]�� ��η� �����մϴ�.
string initializePath(int argc, char *argv[], string filePath)
{
	if (argc == 1)		//�Էº����� �������� ������
	{
		cout << "[ERROR]�Է� �ɼ� ����!\n";
		cout << "cmd���� �Է� ������ �ְ� �������ּ���!\n";
		cout << "ex) C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe text.txt\n\n";
		cout << "[TIP]���� ��ο� ���Ⱑ ���Ե��ִٸ� ��θ� \"�� �����ָ� �˴ϴ�!\n";
		cout << "ex) \"C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe\" text.txt\n";
		exit(1);
	}
	string fileDirectory;

	if (isWindows)
	{
		char charDir[1000];									//_getcwd�� �ȵǸ� getcwd�� ��ġ�� �˴ϴ�.
		_getcwd(charDir, 1000);								//�⺻������ cmd�� �����Ѵٰ� �����Ͽ�, getcwd�� �����θ� �޾ƿɴϴ�.
		fileDirectory = charDir;
	}

	filePath = argv[1];									//�Է¹��� �ؽ�Ʈ ���ϸ�(Ȥ�� ���ϰ��)�� �����մϴ�.

	if (isWindows)
	{
		if (filePath.find("\\") == -1)						//�Էº����� ��ΰ� ���ԵǾ����� �ʴ´ٸ�, ���ϸ� �տ� ��θ� �ִ´�. (ex text.txt - > C:\Users\...\test.txt)
		{
			filePath = (string)fileDirectory + "\\" + filePath;
		}

		if (!isFileExist(filePath))										//���+�ؽ�Ʈ������ ������ �ʴ´ٸ� ���־�Ʃ������� �����ߴٰ� �Ǵ�, ���� argv[0]�� ��ȿ�մϴ�.
		{																//(���־�Ʃ����� �����ϸ� getcwd��ΰ� exe������ �ִ� ��ġ�� �ƴ� �ٸ���η� ������ �����Դϴ�.)
			fileDirectory = argv[0];									//argv[0]���� �������ϸ��� ������ ���� ��θ� ���ɴϴ�.
			fileDirectory.replace(fileDirectory.find_last_of('\\'), fileDirectory.length(), "");
			filePath = (string)fileDirectory + "\\" + argv[1];			//������ο� ���ϸ��� ��Ĩ�ϴ�.
		}
	}

	return filePath;
}

//��ο� �޴��� ����ϴ� �޼ҵ��Դϴ�.
void printMenu(string filePath)
{
	cout << "��� : ";
	cout << filePath << '\n';
	cout << "==============================\n";
	cout << "(1) �� ���� �Է�\n";
	cout << "(2) ���� ����\n";
	cout << "(3) ������ ������ ��ü ���\n";
	cout << "(4) ������ �������� ��ü ���\n";
	cout << "(5) Ư�� ��������� ��ü ���\n";
	cout << "(6) Ư�� ��������� ù ��������� ���� ���\n";
	cout << "(7) ���Ͽ� �����ϰ� ����\n";
	cout << "==============================\n";
	cout << "���ϴ� ����� �����ϼ��� : ";
}

int main(int argc, char *argv[])
{
	string filePath;
	filePath = initializePath(argc, argv, filePath);		//���� ������ ��θ� �ʱ�ȭ�մϴ�. (��� + ���ϸ�)

	List newList;
	newList.readFile(filePath);								//������ �о���Դϴ�.

	int consoleInput = -1;
	string stringInput;
	Node * targetNode;

	while (consoleInput != 7)
	{
		printMenu(filePath);
		cin >> consoleInput;

		if (cin.fail())									//�޴����ÿ� ��~���� ���ö� ���ѷ�������
		{
			cin.clear();
			cin.ignore();
		}

		switch (consoleInput)
		{
		case 1:
			newList.addBook();
			break;
		case 2:
			newList.removeBook();
			break;
		case 3:
			newList.print(newList.getHead()->getNextNode());
			break;
		case 4:
			newList.printR(newList.getHead()->getPreviousNode());
			break;
		case 5:
			std::cout << "Ư�� �������� �Է��ϼ��� : ";
			cin.ignore();
			getline(cin, stringInput);
			targetNode = newList.findNodeByBookData(stringInput, "title");
			if (targetNode == NULL)
				std::cout << "\nã������ å�� �����ϴ�.\n\n";
			else
				newList.printAll(targetNode);
			break;
		case 6:
			std::cout << "Ư�� �������� �Է��ϼ��� : ";
			cin.ignore();
			getline(cin, stringInput);
			targetNode = newList.findNodeByBookData(stringInput, "title");
			if (targetNode == NULL)
				std::cout << "\nã������ å�� �����ϴ�.\n\n";
			else
				newList.printR(targetNode);
			break;
		}
	}

	newList.saveFile(filePath);							//����Ʈ ������ ������ �ϳ��� ���Ͽ� �����մϴ�.
	//newList.deleteMemory();								//����Ʈ ������ ������ �ϳ��� �����մϴ�.
	cout << "�����մϴ�.\n";

	return 0;
}