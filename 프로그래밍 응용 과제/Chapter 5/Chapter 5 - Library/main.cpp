#include <iostream>

#include "TaskManager.h"

using namespace std;

//�Ϸ�//
//1. �޸� �����ϴ°� ����ض�
//2. LoanInfo ����� ���ĵǴ��� ����

//�ؾ��� ��//
//1. ��ü���� �����丵
//2. IOHandler���� �޴��� readFile, writeFile �����丵
//3. TaskManager �����丵
//4. �������� include ����

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
	ioh.displayMessage("[SYS]�����մϴ�.");
	return 0;
}