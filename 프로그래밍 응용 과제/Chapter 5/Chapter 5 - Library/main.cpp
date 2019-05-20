#include <iostream>

#include "TaskManager.h"

using namespace std;

//메모리 해제하는거 기억해라
//LoanInfo 제대로 정렬되는지 봐라

const std::string FILE_DIRECTORY = "C:\\libraryManager.dat";

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
			tskMgr.manageUser(userList, bookList, loanInfoList, isDataChanged);
			break;
		case BOOK:
			tskMgr.manageBook(userList, bookList, loanInfoList, isDataChanged);
			break;
		case LOAN:
			tskMgr.manageLoan(userList, bookList, loanInfoList, isDataChanged);
			break;
		}
	}
	if (isDataChanged)
		ioh.writeFile(FILE_DIRECTORY, userList, bookList, loanInfoList);
	ioh.displayMessage("종료합니다.");
	return 0;
}