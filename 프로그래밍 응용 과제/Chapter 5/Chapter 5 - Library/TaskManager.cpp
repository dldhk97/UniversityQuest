#include "TaskManager.h"

void TaskManager::manageUser(List<User>& userList)
{
	IOHandler ioh;
	int userInput;
	while (1)
	{
		userInput = ioh.getMenu(USERMENU);
		if (userInput == EXIT)
			break;
		switch (userInput)
		{
		case INSERTUSER:
			insertUser(userList);
			break;
		case CHANGESTATE:
			changeUserState(userList);
			break;
		case DISPLAYUSERS:
			displayUserList(userList);
			break;
		}
	}
}
void TaskManager::manageBook(List<Book>& bookList)
{
	IOHandler ioh;
	int userInput;
	while (1)
	{
		userInput = ioh.getMenu(BOOKMENU);
		if (userInput == EXIT)
			break;
		switch (userInput)
		{
		case INSERTBOOK:
			insertBook(bookList);
			break;
		case CHANGESTATE:
			changeBookState(bookList);
			break;
		case DISPLAYBOOKS:
			displayBookList(bookList);
			break;
		}
	}
}
void TaskManager::manageLoan(List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	int userInput;
	while (1)
	{
		userInput = ioh.getMenu(LOANMENU);
		if (userInput == EXIT)
			break;
		switch (userInput)
		{
		case LOANBOOK:
			loanBook(loanInfoList);
			break;
		case RETURNBOOK:
			returnBook(loanInfoList);
			break;
		case DISPLAYHISTORY:
			displayLoanHistory(loanInfoList);
			break;
		}
	}
}

void TaskManager::insertUser(List<User>& userList)
{
	IOHandler ioh;

	switch (ioh.getUserType())
	{
	case STUDENT:
	{
		Student* newStudent;
		newStudent = ioh.getStudent();
		if (newStudent->getId() == "NOT_FOUND")
		{
			int newId = userList.increaseAndGetLastId();
			std::string newIdStr = "F";
			if (newId < 10)
				newIdStr = newIdStr + "0" + std::to_string(newId);
			else
				newIdStr = newIdStr + std::to_string(newId);
			newStudent->setId(newIdStr);
		}
		userList.insertData(newStudent);
		break;
	}
	case PROFESSOR:
	{
		Professor* newProfessor;
		newProfessor = ioh.getProfessor();
		if (newProfessor->getId() == "NOT_FOUND")
		{
			int newId = userList.increaseAndGetLastId();
			std::string newIdStr = "U";
			if (newId < 10)
				newIdStr = newIdStr + "0" + std::to_string(newId);
			else
				newIdStr = newIdStr + std::to_string(newId);
			newProfessor->setId(newIdStr);
		}
		userList.insertData(newProfessor);
		break;
	}
	}
}
void TaskManager::changeUserState(List<User>& userList)
{
	IOHandler ioh;
	if (userList.getSize() <= 0)
	{
		ioh.displayMessage("사용자 목록이 비어있습니다.");
		return;
	}
	std::string id = ioh.getString("삭제할 구성원의 ID 입력 :");
	int index = userList.findData(id);
	if (index == NOT_FOUND)
	{
		ioh.displayMessage("구성원을 찾을 수 없습니다.");
		return;
	}
	User* currentUser = userList.getData(index);
	//조건이 추가되어야한다. 이 구성원이 책을 대여중인지 아닌지. 대여중이라면 알려주기도 해야한다.//debug!!!!!!!!!!!!
	if (currentUser->getUserState() == VALID)
	{
		currentUser->setUserState(INVALID);
		ioh.displayMessage("변경되었습니다.");
	}
	else
	{
		ioh.displayMessage("이미 비활성화된 구성원입니다.");
	}
	return;

}
void TaskManager::displayUserList(List<User>& userList)
{
	IOHandler ioh;
	int size = userList.getSize();
	for (int i = 0; i < size; i++)
	{
		ioh.displayUser(userList.getData(i));
	}
}

void TaskManager::insertBook(List<Book>& bookList)
{

}
void TaskManager::changeBookState(List<Book>& bookList)
{

}
void TaskManager::displayBookList(List<Book>& bookList)
{

}

void TaskManager::loanBook(List<LoanInfo>& loanInfoList)
{

}
void TaskManager::returnBook(List<LoanInfo>& loanInfoList)
{

}
void TaskManager::displayLoanHistory(List<LoanInfo>& loanInfoList)
{

}