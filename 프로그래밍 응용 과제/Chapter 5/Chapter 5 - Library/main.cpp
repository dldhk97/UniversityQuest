#include <iostream>

#include "TaskManager.h"

using namespace std;

//�޸� �����ϴ°� ����ض�
//LoanInfo ����� ���ĵǴ��� ����

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
	ioh.displayMessage("�����մϴ�.");
	return 0;
}