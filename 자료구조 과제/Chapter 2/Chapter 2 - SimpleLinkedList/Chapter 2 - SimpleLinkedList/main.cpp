#include <iostream>
#include <string>
#include <direct.h>		//_getcwd, 현재 폴더위치 경로받기, Windows 환경이 아니라면 주석처리 해주십시오.
#include "List.h"

const bool isWindows = true;					// Windows 환경이 아니라면(direct.h가 지원되지 않는 경우) false로 변경해주십시오.

using namespace std;

//이 프로그램은 ANSI 텍스트파일만 읽을 수 있습니다! UTF-8인경우에는 글씨가 깨집니다.
/*제 비주얼 스튜디오 테스트 환경에서 ifstream oepnFile("ㅇㅇㅇ.txt")로 넣을 경우 debug.exe가 있는 폴더 내에서 텍스트파일을 찾지 못하여 getcwd를 사용하였습니다.*/

//단순연결리스트를 이용해 책목록을 읽고 쓰는 프로그램입니다.
//처음에 헤드를 사용하지 않는 구조로 안내되어있어 환형으로 구현했습니다.
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
		std::cout << "[ERROR]입력 옵션 없음!\n";
		std::cout << "cmd에서 입력 변수를 넣고 실행해주세요!\n";
		std::cout << "ex) C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe text.txt\n\n";
		std::cout << "[TIP]만약 경로에 띄어쓰기가 포함되있다면 경로를 \"로 묶어주면 됩니다!\n";
		std::cout << "ex) \"C:\\Users\\Administrator\\source\\LinkedList\\Debug\\LinkedList.exe\" text.txt\n";
		exit(1);
	}
	
	string fileDirectory;

	if (isWindows)
	{
		char charDir[1000];									//_getcwd가 안되면 getcwd로 고치면 됩니다.
		_getcwd(charDir, 1000);								//기본적으로 cmd로 실행한다고 가정하여, getcwd로 절대경로를 받아옵니다.	 getcwd가 지원되지않으면 이 구문을 주석처리해주십시오
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
	cout << "(4) 파일에 저장하고 종료\n";
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
	while (consoleInput != 4)
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
			newList.print();
			break;
		}
	}

	newList.saveFile(filePath);							//리스트 내부의 노드들을 하나씩 파일에 저장합니다.
	newList.deleteMemory();								//리스트 내부의 노드들을 하나씩 삭제합니다.
	cout << "종료합니다.\n";

	
	return 0;
}