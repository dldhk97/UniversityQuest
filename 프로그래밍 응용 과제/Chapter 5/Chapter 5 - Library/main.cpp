#include <iostream>

#include "TaskManager.h"

using namespace std;

//메모리 해제하는거 기억해라

int main()
{
	TaskManager tskMgr;
	IOHandler ioh;
	int userInput;
	List<User> userList;
	List<Book> bookList;
	List<LoanInfo> loanInfoList;

	while (1)
	{
		userInput = ioh.getMenu(MAINMENU);
		if (userInput == EXIT)
			break;

		switch (userInput)
		{
		case USERMENU:
			tskMgr.manageUser(userList, bookList, loanInfoList);
			break;
		case BOOKMENU:
			tskMgr.manageBook(userList, bookList, loanInfoList);
			break;
		case LOANMENU:
			tskMgr.manageLoan(userList, bookList, loanInfoList);
			break;
		}
	}
	return 0;
}