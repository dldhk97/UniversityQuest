#include <iostream>
#include <string>
#include <direct.h>		//_getcwd, ���� ������ġ ��ιޱ�, Windows ȯ���� �ƴ϶�� �ּ�ó�� ���ֽʽÿ�.
#include "List.h"

const bool isWindows = true;					// Windows ȯ���� �ƴ϶��(direct.h�� �������� �ʴ� ���) false�� �������ֽʽÿ�.

using namespace std;

//�� ���α׷��� ANSI �ؽ�Ʈ���ϸ� ���� �� �ֽ��ϴ�! UTF-8�ΰ�쿡�� �۾��� �����ϴ�.
/*�� ���־� ��Ʃ��� �׽�Ʈ ȯ�濡�� ifstream oepnFile("������.txt")�� ���� ��� debug.exe�� �ִ� ���� ������ �ؽ�Ʈ������ ã�� ���Ͽ� getcwd�� ����Ͽ����ϴ�.*/

//�ܼ����Ḯ��Ʈ�� �̿��� å����� �а� ���� ���α׷��Դϴ�.
//ó���� ��带 ������� �ʴ� ������ �ȳ��Ǿ��־� ȯ������ �����߽��ϴ�.
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
		std::cout << "[ERROR]�Է� �ɼ� ����!\n";
		std::cout << "cmd���� �Է� ������ �ְ� �������ּ���!\n";
		std::cout << "ex) C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe text.txt\n\n";
		std::cout << "[TIP]���� ��ο� ���Ⱑ ���Ե��ִٸ� ��θ� \"�� �����ָ� �˴ϴ�!\n";
		std::cout << "ex) \"C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe\" text.txt\n";
		exit(1);
	}
	
	string fileDirectory;

	if (isWindows)
	{
		char charDir[1000];									//_getcwd�� �ȵǸ� getcwd�� ��ġ�� �˴ϴ�.
		_getcwd(charDir, 1000);								//�⺻������ cmd�� �����Ѵٰ� �����Ͽ�, getcwd�� �����θ� �޾ƿɴϴ�.	 getcwd�� �������������� �� ������ �ּ�ó�����ֽʽÿ�
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
	cout << "(4) ���Ͽ� �����ϰ� ����\n";
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
	while (consoleInput != 4)
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
			newList.print();
			break;
		}
	}

	newList.saveFile(filePath);							//����Ʈ ������ ������ �ϳ��� ���Ͽ� �����մϴ�.
	newList.deleteMemory();								//����Ʈ ������ ������ �ϳ��� �����մϴ�.
	cout << "�����մϴ�.\n";

	
	return 0;
}