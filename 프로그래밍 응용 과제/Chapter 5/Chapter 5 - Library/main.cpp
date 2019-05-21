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
		selectedOption = menuManager.getMenu(MAIN);					//메인메뉴 불러옴
		if (selectedOption == EXIT)
			break;

		switch (selectedOption)
		{
		case USER:
			while (selectedOption != EXIT)							//EXIT가 아닐때까지 반복
			{
				selectedOption = menuManager.getMenu(USER);			//세부 메뉴 출력
				tskMgr.userMenuAction(selectedOption, userList, bookList, loanInfoList, isDataChanged);		//세부메뉴 중 선택한 메뉴로 동작
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

	ioh.displayMessage("[SYS]종료합니다.");
	return 0;
}