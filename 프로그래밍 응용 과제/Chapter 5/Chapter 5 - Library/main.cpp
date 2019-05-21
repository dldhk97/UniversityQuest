#include <iostream>
#include "TaskManager.h"

using namespace std;

const std::string FILE_DIRECTORY = "C:\\LibraryManager.dat";

int main()
{
	TaskManager tskMgr;
	IOHandler ioh;
	int selectedOption;
	bool isDataChanged = false;
	List<User> userList;
	List<Book> bookList;
	List<LoanInfo> loanInfoList;
	Menu menuManager;

	ioh.readFile(FILE_DIRECTORY, userList, bookList, loanInfoList);

	while (1)
	{
		selectedOption = menuManager.getMenu(MAIN);					//���θ޴� �ҷ���
		if (selectedOption == EXIT)
			break;

		switch (selectedOption)
		{
		case USER:
			while (selectedOption != EXIT)							//EXIT�� �ƴҶ����� �ݺ�
			{
				selectedOption = menuManager.getMenu(USER);			//���� �޴� ���
				tskMgr.userMenuAction(selectedOption, userList, bookList, loanInfoList, isDataChanged);		//���θ޴� �� ������ �޴��� ����
			}
			break;
		case BOOK:
			while (selectedOption != EXIT)
			{
				selectedOption = menuManager.getMenu(BOOK);
				tskMgr.bookMenuAction(selectedOption, userList, bookList, loanInfoList, isDataChanged);
			}
			break;
		case LOAN:
			while (selectedOption != EXIT)
			{
				selectedOption = menuManager.getMenu(LOAN);
				tskMgr.loanMenuAction(selectedOption, userList, bookList, loanInfoList, isDataChanged);
			}
			break;
		}
	}

	if (isDataChanged)
		ioh.writeFile(FILE_DIRECTORY, userList, bookList, loanInfoList);

	ioh.displayMessage("[SYS]�����մϴ�.");
	return 0;
}