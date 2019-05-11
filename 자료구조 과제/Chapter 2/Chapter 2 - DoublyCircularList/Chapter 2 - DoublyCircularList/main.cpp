#include <iostream>
#include <string>
#include <direct.h>		//_getcwd, 현재 폴더위치 경로받기, Windows 환경이 아니라면 주석처리 해주십시오.
#include "List.h"

using namespace std;

const bool isWindows = true;					// Windows 환경이 아니라면(direct.h가 지원되지 않는 경우) false로 변경해주십시오.

//이 프로그램은 ANSI 텍스트파일만 읽을 수 있습니다! UTF-8인경우에는 글씨가 깨집니다.

//이중환형연결리스트를 이용해 책목록을 읽고 쓰는 프로그램입니다.
//cmd로 환경변수를 주거나 VS의 입력 변수로 텍스트명 혹은 텍스트파일 경로를 넣어야 정상작동합니다.
//텍스트명은 텍스트명.txt가 되어야 합니다(ex : test.txt)
//만약에 텍스트명에 경로가 포함되어있지 않다면 현재폴더 내에서 찾습니다.

//파일이 열리는지 안열리는지 체크합니다.
bool isFileExist(string filePath)
{
	ifstream openFile(filePath);
	if (openFile.is_open())			//열린다면 닫아줍니다.
	{
		openFile.close();
		return true;
	}
	return false;
}

//텍스트 파일 경로를 초기화합니다.
//받은 파일명이 ㅇㅇㅇ.txt인 경우 앞에 현재폴더의 경로를 덧붙입니다.
//또한 cmd로 실행했을 때 argv[0]의 값이 경로가 아닌 실행파일명이 되어버리기 때문에 getcwd로 절대경로를 받아 경로로 설정합니다.
//비주얼스튜디오로 실행하면 반대로, getcwd의 값이 유효하지 않고, argv[0]의 값이 유효하기 때문에 argv[0]을 경로로 설정합니다.
string initializePath(int argc, char *argv[], string filePath)
{
	if (argc == 1)		//입력변수가 존재하지 않을때
	{
		cout << "[ERROR]입력 옵션 없음!\n";
		cout << "cmd에서 입력 변수를 넣고 실행해주세요!\n";
		cout << "ex) C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe text.txt\n\n";
		cout << "[TIP]만약 경로에 띄어쓰기가 포함되있다면 경로를 \"로 묶어주면 됩니다!\n";
		cout << "ex) \"C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe\" text.txt\n";
		exit(1);
	}
	string fileDirectory;

	if (isWindows)
	{
		char charDir[1000];									//_getcwd가 안되면 getcwd로 고치면 됩니다.
		_getcwd(charDir, 1000);								//기본적으로 cmd로 실행한다고 가정하여, getcwd로 절대경로를 받아옵니다.
		fileDirectory = charDir;
	}

	filePath = argv[1];									//입력받은 텍스트 파일명(혹은 파일경로)을 저장합니다.

	if (isWindows)
	{
		if (filePath.find("\\") == -1)						//입력변수에 경로가 포함되어있지 않는다면, 파일명 앞에 경로를 넣는다. (ex text.txt - > C:\Users\...\test.txt)
		{
			filePath = (string)fileDirectory + "\\" + filePath;
		}

		if (!isFileExist(filePath))										//경로+텍스트파일이 열리지 않는다면 비주얼스튜디오에서 실행했다고 판단, 따라서 argv[0]이 유효합니다.
		{																//(비주얼스튜디오로 실행하면 getcwd경로가 exe폴더가 있는 위치가 아닌 다른경로로 잡히기 때문입니다.)
			fileDirectory = argv[0];									//argv[0]에서 실행파일명을 제외한 폴더 경로만 빼옵니다.
			fileDirectory.replace(fileDirectory.find_last_of('\\'), fileDirectory.length(), "");
			filePath = (string)fileDirectory + "\\" + argv[1];			//폴더경로와 파일명을 합칩니다.
		}
	}

	return filePath;
}

//경로와 메뉴를 출력하는 메소드입니다.
void printMenu(string filePath)
{
	cout << "경로 : ";
	cout << filePath << '\n';
	cout << "==============================\n";
	cout << "(1) 새 도서 입력\n";
	cout << "(2) 도서 삭제\n";
	cout << "(3) 도서명 순으로 전체 출력\n";
	cout << "(4) 도서명 역순으로 전체 출력\n";
	cout << "(5) 특정 도서명부터 전체 출력\n";
	cout << "(6) 특정 도서명부터 첫 도서명까지 역순 출력\n";
	cout << "(7) 파일에 저장하고 종료\n";
	cout << "==============================\n";
	cout << "원하는 기능을 선택하세요 : ";
}

int main(int argc, char *argv[])
{
	string filePath;
	filePath = initializePath(argc, argv, filePath);		//읽을 파일의 경로를 초기화합니다. (경로 + 파일명)

	List newList;
	newList.readFile(filePath);								//파일을 읽어들입니다.

	int consoleInput = -1;
	string stringInput;
	Node * targetNode;

	while (consoleInput != 7)
	{
		printMenu(filePath);
		cin >> consoleInput;

		if (cin.fail())									//메뉴선택에 긴~값이 들어올때 무한루프방지
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
			std::cout << "특정 도서명을 입력하세요 : ";
			cin.ignore();
			getline(cin, stringInput);
			targetNode = newList.findNodeByBookData(stringInput, "title");
			if (targetNode == NULL)
				std::cout << "\n찾으려는 책이 없습니다.\n\n";
			else
				newList.printAll(targetNode);
			break;
		case 6:
			std::cout << "특정 도서명을 입력하세요 : ";
			cin.ignore();
			getline(cin, stringInput);
			targetNode = newList.findNodeByBookData(stringInput, "title");
			if (targetNode == NULL)
				std::cout << "\n찾으려는 책이 없습니다.\n\n";
			else
				newList.printR(targetNode);
			break;
		}
	}

	newList.saveFile(filePath);							//리스트 내부의 노드들을 하나씩 파일에 저장합니다.
	//newList.deleteMemory();								//리스트 내부의 노드들을 하나씩 삭제합니다.
	cout << "종료합니다.\n";

	return 0;
}