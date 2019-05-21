#include <iostream>

#include "TaskManager.h"

using namespace std;

//�޸� �����ϴ°� ����ض�
//LoanInfo ����� ���ĵǴ��� ����

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
	ioh.displayMessage("�����մϴ�.");
	return 0;
}