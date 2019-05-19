#include <iostream>

#include "TaskManager.h"

using namespace std;

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
			tskMgr.manageUser(userList);
			break;
		case BOOKMENU:
			tskMgr.manageBook(bookList);
			break;
		case LOANMENU:
			tskMgr.manageLoan(loanInfoList);
			break;
		}
	}
	return 0;
}