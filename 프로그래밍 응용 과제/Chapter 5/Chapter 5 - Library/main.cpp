#include <iostream>

#include "TaskManager.h"

using namespace std;

//완료//
//1. 메모리 해제하는거 기억해라
//2. LoanInfo 제대로 정렬되는지 봐라

//해야할 것//
//1. 전체적인 리팩토링
//2. IOHandler에서 메뉴와 readFile, writeFile 리팩토링
//3. TaskManager 리팩토링
//4. 쓸데없는 include 삭제

const std::string FILE_DIRECTORY = "C:\\LibraryManager.dat";

int main()
{
	TaskManager tskMgr;
	IOHandler ioh;
	int userInput;
	bool isDataChanged = false;
	List<User> userList;
	List<Book> bookList;
	List<LoanInfo> loanInfoList;

	ioh.readFile(FILE_DIRECTORY, userList, bookList, loanInfoList);

	while (1)
	{
		userInput = ioh.getMenu(MAIN);
		if (userInput == EXIT)
			break;

		switch (userInput)
		{
		case USER:
			tskMgr.getUserMenu(userList, bookList, loanInfoList, isDataChanged);
			break;
		case BOOK:
			tskMgr.getBookMenu(userList, bookList, loanInfoList, isDataChanged);
			break;
		case LOAN:
			tskMgr.getLoanMenu(userList, bookList, loanInfoList, isDataChanged);
			break;
		}
	}
	if (isDataChanged)
		ioh.writeFile(FILE_DIRECTORY, userList, bookList, loanInfoList);
	ioh.displayMessage("[SYS]종료합니다.");
	return 0;
}