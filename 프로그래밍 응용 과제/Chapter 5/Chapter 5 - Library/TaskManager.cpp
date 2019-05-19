#include "TaskManager.h"

void TaskManager::manageUser(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
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
			changeUserState(userList, bookList, loanInfoList);
			break;
		case DISPLAYUSERS:
			userList.insertionSort();
			displayUserList(userList);
			break;
		}
	}
}
void TaskManager::manageBook(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
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
			changeBookState(userList, bookList, loanInfoList);
			break;
		case DISPLAYBOOKS:
			bookList.insertionSort();
			displayBookList(bookList);
			break;
		}
	}
}
void TaskManager::manageLoan(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
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
			loanBook(userList, bookList, loanInfoList);
			break;
		case RETURNBOOK:
			returnBook(bookList, loanInfoList);
			break;
		case DISPLAYHISTORY:
			displayLoanHistory(userList, bookList, loanInfoList);
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
			int newId = userList.getLastId(typeid(Student).name());
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
			int newId = userList.getLastId(typeid(Professor).name());
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
void TaskManager::changeUserState(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	if (userList.getSize() <= 0)
	{
		ioh.displayMessage("����� ����� ����ֽ��ϴ�.");
		return;
	}
	std::string id = ioh.getString("������ �������� ID �Է� :");
	int index = userList.findDataById(id);
	if (index == NOT_FOUND)
	{
		ioh.displayMessage("�������� ã�� �� �����ϴ�.");
		return;
	}
	User* currentUser = userList.getData(index);
	if (loanInfoList.findDataByLoanerId(id) != NOT_FOUND)
	{
		List<LoanInfo> loannedList;
		ioh.displayMessage(currentUser->getName() + "��(��) �뿩���� å�� �����մϴ�.");
		for (int i = 0; i < loanInfoList.getSize(); i++)
		{
			if (loanInfoList.getData(i)->getLoanerId() == id)
				loannedList.insertData(new LoanInfo(loanInfoList.getData(i)));
		}
		displayLoanHistory(userList, bookList, loannedList);
		return;
	}
	if (currentUser->getUserState() == VALID)
	{
		currentUser->setUserState(INVALID);
		ioh.displayMessage("����Ǿ����ϴ�.");
	}
	else
	{
		ioh.displayMessage("�̹� ��Ȱ��ȭ�� �������Դϴ�.");
	}
	return;
}
void TaskManager::displayUserList(List<User>& userList)
{
	IOHandler ioh;
	ioh.displayMessage("==================================================");
	ioh.displayMessage("ID \t���� \t�а� \t���� \t���� \t������ \t�г� \t���� \t����ó");
	ioh.displayMessage("--------------------------------------------------");
	int size = userList.getSize();
	for (int i = 0; i < size; i++)
	{
		ioh.displayUser(userList.getData(i));
	}
	ioh.displayMessage("==================================================");
}

void TaskManager::insertBook(List<Book>& bookList)
{
	IOHandler ioh;

	switch (ioh.getBookType())
	{
	case MAGAZINE:
	{
		Magazine* newMagazine;
		newMagazine = ioh.getMagazine();
		if (newMagazine->getId() == "NOT_FOUND")
		{
			int newId = bookList.getLastId(typeid(Magazine).name());
			std::string newIdStr = "M";
			if (newId < 10)
				newIdStr = newIdStr + "0" + std::to_string(newId);
			else
				newIdStr = newIdStr + std::to_string(newId);
			newMagazine->setId(newIdStr);
		}
		bookList.insertData(newMagazine);
		break;
	}
	case TEXTBOOK:
	{
		TextBook* newTextBook;
		newTextBook = ioh.getTextBook();
		if (newTextBook->getId() == "NOT_FOUND")
		{
			int newId = bookList.getLastId(typeid(TextBook).name());
			std::string newIdStr = "B";
			if (newId < 10)
				newIdStr = newIdStr + "0" + std::to_string(newId);
			else
				newIdStr = newIdStr + std::to_string(newId);
			newTextBook->setId(newIdStr);
		}
		bookList.insertData(newTextBook);
		break;
	}
	}
}
void TaskManager::changeBookState(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	if (bookList.getSize() <= 0)
	{
		ioh.displayMessage("���� ����� ����ֽ��ϴ�.");
		return;
	}
	std::string id = ioh.getString("������ ������ ID �Է� :");
	int index = bookList.findDataById(id);
	if (index == NOT_FOUND)
	{
		ioh.displayMessage("������ ã�� �� �����ϴ�.");
		return;
	}
	Book* currentBook = bookList.getData(index);
	if (currentBook->getBookState() == LOANABLE)
	{
		currentBook->setBookState(INLOANBLE);
		ioh.displayMessage("����Ǿ����ϴ�.");
	}
	else if (currentBook->getBookState() == LOANING)
	{
		ioh.displayMessage(currentBook->getTitle() + "��(��) �������� å�Դϴ�.");
		List<LoanInfo> loannedList;
		for (int i = 0; i < loanInfoList.getSize(); i++)
		{
			if (loanInfoList.getData(i)->getId() == id)
				loannedList.insertData(new LoanInfo(loanInfoList.getData(i)));
		}
		displayLoanHistory(userList, bookList, loannedList);
		return;
	}
	else
	{
		ioh.displayMessage("�̹� ���� �Ұ����� å�Դϴ�.");
	}
	return;
}
void TaskManager::displayBookList(List<Book>& bookList)
{
	IOHandler ioh;
	ioh.displayMessage("==================================================");
	ioh.displayMessage("ID \t������ \t���ǻ� \t���ǳ⵵ \t���� \t\t��/ȣ \t��������");
	ioh.displayMessage("--------------------------------------------------");
	int size = bookList.getSize();
	for (int i = 0; i < size; i++)
	{
		ioh.displayBook(bookList.getData(i));
	}
	ioh.displayMessage("==================================================");
}

void TaskManager::loanBook(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	if (userList.getSize() <= 0 || bookList.getSize() <= 0)
	{
		ioh.displayMessage("����� ��� �Ǵ� ���� ����� ����ֽ��ϴ�.");
		return;
	}

	User* loaner = ioh.findDataById("������ ID :", userList);
	if (loaner == nullptr)
		return;
	Book* targetBook = ioh.findDataById("���� ID :", bookList);
	if (targetBook == nullptr)
		return;

	if (loaner->getUserState() == INVALID)
	{
		ioh.displayMessage(loaner->getName() + "��(��) ��ȿ�� ����ڰ� �ƴմϴ�.");
		return;
	}
	else if (targetBook->getBookState() == LOANING)
	{
		ioh.displayMessage(targetBook->getTitle() + "��(��) " + loaner->getName() + "���� �̹� �������Դϴ�.");
		return;
	}
	else if (targetBook->getBookState() == INLOANBLE)
	{
		ioh.displayMessage(targetBook->getTitle() + "��(��) ����Ұ� �����Դϴ�.");
		return;
	}
	std::string loanedDate = ioh.getString("������ :");
	LoanInfo* newLoanInfo = new LoanInfo("NOT_FOUND", loaner->getId(), targetBook->getId(), loanedDate, "NOT_FOUND", "NOT_FOUND");
	if (newLoanInfo->getId() == "NOT_FOUND")
	{
		int newSerial = loanInfoList.getLastId(typeid(LoanInfo).name());
		newLoanInfo->setSerial(std::to_string(newSerial));
	}
	loanInfoList.insertData(newLoanInfo);
	targetBook->setBookState(LOANING);
	ioh.displayMessage(targetBook->getTitle() + "��(��) " + loaner->getName() + "���� ����Ǿ����ϴ�.");

}
void TaskManager::returnBook(List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	Book* targetBook = ioh.findDataById("���� ID :", bookList);
	if (targetBook == nullptr)
		return;
	std::string returnDate = ioh.getString("�ݳ��� :");
	LoanInfo* targetLoanInfo = loanInfoList.getData(loanInfoList.findDataById(targetBook->getId()));
	targetLoanInfo->setReturnDate(returnDate);
	targetLoanInfo->setPeriod("�Ⱓ�� ����ؾߵȴ�");				//debug!!!!!!!!!!! �Ⱓ ���!?
	targetBook->setBookState(LOANABLE);
	ioh.displayMessage(targetBook->getTitle() + "��(��) �ݳ��Ǿ����ϴ�.");
}
void TaskManager::displayLoanHistory(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	ioh.displayMessage("==================================================");
	ioh.displayMessage("���� \t������ \t������ \t������ \t\t�ݳ��� \t\t����Ⱓ");
	ioh.displayMessage("--------------------------------------------------");
	int size = loanInfoList.getSize();
	for (int i = 0; i < size; i++)
	{
		LoanInfo* targetLoanInfo = loanInfoList.getData(i);
		User* loanner = userList.getData(userList.findDataById(targetLoanInfo->getLoanerId()));
		Book* targetBook = bookList.getData(bookList.findDataById(targetLoanInfo->getId()));
		ioh.displayLoanInfo(loanner, targetBook, targetLoanInfo);
		ioh.displayMessage("");
	}
	ioh.displayMessage("==================================================");
}