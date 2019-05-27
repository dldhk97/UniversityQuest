//TaskManager.cpp
#include "TaskManager.h"

void TaskManager::userMenuAction(int selectedOption, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	if (selectedOption == EXIT)
		return;
	switch (selectedOption)
	{
	case INSERTUSER:
		insertUser(userList);
		isDataChanged = true;
		break;
	case CHANGESTATE:
		changeUserState(userList, bookList, loanInfoList, isDataChanged);
		break;
	case DISPLAYUSERS:
		userList.insertionSort();
		displayUserList(userList);
		break;
	}
}
void TaskManager::bookMenuAction(int selectedOption, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	if (selectedOption == EXIT)
		return;
	switch (selectedOption)
	{
	case INSERTBOOK:
		insertBook(bookList);
		isDataChanged = true;
		break;
	case CHANGESTATE:
		changeBookState(userList, bookList, loanInfoList, isDataChanged);
		break;
	case DISPLAYBOOKS:
		bookList.insertionSort();
		displayBookList(bookList);
		break;
	}
}
void TaskManager::loanMenuAction(int selectedOption, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	if (selectedOption == EXIT)
		return;
	switch (selectedOption)
	{
	case LOANBOOK:
		loanBook(userList, bookList, loanInfoList, isDataChanged);
		break;
	case RETURNBOOK:
		returnBook(bookList, loanInfoList);
		isDataChanged = true;
		break;
	case DISPLAYHISTORY:
		loanInfoList.insertionSort(bookList);
		displayLoanHistory(userList, bookList, loanInfoList);
		break;
	}
}

void TaskManager::insertUser(List<User>& userList)
{
	IOHandler ioh;
	User* newUser = nullptr;
	switch (ioh.getUserType())
	{
		case PROFESSOR:
		{
			newUser = ioh.getProfessor();
			break;
		}
		case STUDENT:
		{
			newUser = ioh.getStudent();
			break;
		}
	}
	if (newUser->getId() == "NOT_FOUND")
		newUser->setId(userList.getLastId(typeid(*newUser).name()));
	userList.insertData(newUser);
}
void TaskManager::changeUserState(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	IOHandler ioh;
	if (userList.isEmpty())
	{
		ioh.displayMessage("[SYS]����� ����� ����ֽ��ϴ�.");
		return;
	}

	std::string id = ioh.getString("������ �������� ID �Է� :");
	User* currentUser = userList.findDataById(id);
	if (currentUser == nullptr)
	{
		ioh.displayMessage("[SYS]�������� ã�� �� �����ϴ�.");
		return;
	}

	//�ش����ڰ� �뿩���� å ����
	List<LoanInfo> loannedList;
	for (int i = 0; i < loanInfoList.getSize(); i++)
	{
		if (loanInfoList.getData(i)->getLoanerId() == id && loanInfoList.getData(i)->getReturnDate() == nullptr)
			loannedList.insertData(new LoanInfo(loanInfoList.getData(i)));
	}
	if (loannedList.isEmpty() == false)
	{
		ioh.displayMessage("[SYS]" + currentUser->getName() + "��(��) �뿩���� å�� �����մϴ�. �뿩���� å ����� �Ʒ��� �����ϴ�.");
		loannedList.insertionSort(bookList);
		displayLoanHistory(userList, bookList, loannedList);
		return;
	}

	if (currentUser->getUserState() == INVALID)
	{
		ioh.displayMessage("[SYS]�̹� ��Ȱ��ȭ�� �������Դϴ�.");
	}
	else
	{
		currentUser->setUserState(INVALID);
		ioh.displayMessage("[SYS]" + currentUser->getName() + "��(��) ��Ȱ��ȭ �Ǿ����ϴ�.");
		isDataChanged = true;
	}
	return;
}
void TaskManager::displayUserList(List<User>& userList)
{
	IOHandler ioh;
	ioh.displayMessage("======================================================================================");
	ioh.displayMessage("ID \t���� \t�а� \t\t���� \t���� \t\t������ \t�г� \t���� \t����ó");
	ioh.displayMessage("--------------------------------------------------------------------------------------");
	int size = userList.getSize();
	for (int i = 0; i < size; i++)
	{
		ioh.displayUser(userList.getData(i));
	}
	ioh.displayMessage("======================================================================================");
}

void TaskManager::insertBook(List<Book>& bookList)
{
	IOHandler ioh;
	Book* newBook = nullptr;
	switch (ioh.getBookType())
	{
		case MAGAZINE:
		{
			newBook = ioh.getMagazine();
			break;
		}
		case TEXTBOOK:
		{
			newBook = ioh.getTextBook();
			break;
		}
	}
	if (newBook->getId() == "NOT_FOUND")
		newBook->setId(bookList.getLastId(typeid(*newBook).name()));
	bookList.insertData(newBook);
}
void TaskManager::changeBookState(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	IOHandler ioh;
	if (bookList.isEmpty())
	{
		ioh.displayMessage("[SYS]���� ����� ����ֽ��ϴ�.");
		return;
	}

	std::string id = ioh.getString("������ ������ ID �Է� :");
	Book* currentBook = bookList.findDataById(id);
	if (currentBook == nullptr)
	{
		ioh.displayMessage("[SYS]������ ã�� �� �����ϴ�.");
		return;
	}
	
	if (currentBook->getBookState() == LOANING)
	{
		ioh.displayMessage("[SYS]" + currentBook->getTitle() + "��(��) �뿩���� å�Դϴ�.");
		List<LoanInfo> loannedList;
		loannedList.insertData(new LoanInfo(findCurrnetLoanInfo(currentBook, bookList, loanInfoList)));
		displayLoanHistory(userList, bookList, loannedList);
		return;
	}
	else if (currentBook->getBookState() == INLOANBLE)
	{
		ioh.displayMessage("[SYS]�̹� ���� �Ұ����� å�Դϴ�.");
	}
	else
	{
		currentBook->setBookState(INLOANBLE);
		ioh.displayMessage("[SYS]����Ǿ����ϴ�.");
		isDataChanged = true;
	}
	return;
}
void TaskManager::displayBookList(List<Book>& bookList)
{
	IOHandler ioh;
	ioh.displayMessage("================================================================================================");
	ioh.displayMessage("ID \t������ \t\t���ǻ� \t\t���ǳ⵵ \t\t���� \t\t��/ȣ \t��������");
	ioh.displayMessage("------------------------------------------------------------------------------------------------");
	int size = bookList.getSize();
	for (int i = 0; i < size; i++)
	{
		ioh.displayBook(bookList.getData(i));
	}
	ioh.displayMessage("================================================================================================");
}

void TaskManager::loanBook(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	IOHandler ioh;
	if (userList.isEmpty() || bookList.isEmpty())
	{
		ioh.displayMessage("[SYS]����� ��� �Ǵ� ���� ����� ����ֽ��ϴ�.");
		return;
	}
	//User*
	User* loaner = userList.findDataById(ioh.getString("������ ID:"));
	if (loaner == nullptr)
	{
		ioh.displayMessage("[SYS]�ش� ����ڸ� ã�� �� �����ϴ�.");
		return;
	}
		
	if (loaner->getUserState() == INVALID)
	{
		ioh.displayMessage("[SYS]" + loaner->getName() + "��(��) ��� ������ ������Դϴ�.");
		return;
	}
	
	Book* targetBook = bookList.findDataById(ioh.getString("���� ID:"));
	if (targetBook == nullptr)
	{
		ioh.displayMessage("[SYS]�ش� ������ ã�� �� �����ϴ�.");
		return;
	}
	if (targetBook->getBookState() == LOANING)
	{
		User* anotherLoaner = findCurrentLoaner(targetBook, userList, loanInfoList);
		ioh.displayMessage("[SYS]" + targetBook->getTitle() + "��(��) " + anotherLoaner->getName() + "���� �̹� �������Դϴ�.");
		return;
	}
	else if (targetBook->getBookState() == INLOANBLE)
	{
		ioh.displayMessage("[SYS]" + targetBook->getTitle() + "��(��) ����Ұ� �����Դϴ�.");
		return;
	}
	Date* loanedDate = ioh.getDate("������ :");
	LoanInfo* newLoanInfo = new LoanInfo("NOT_FOUND", loaner->getId(), targetBook->getId(), loanedDate, nullptr, NOT_FOUND);
	if (newLoanInfo->getSerial() == "NOT_FOUND")
	{
		int newSerial = loanInfoList.getLastId(typeid(LoanInfo).name());
		newLoanInfo->setSerial(std::to_string(newSerial));
	}
	loanInfoList.insertData(newLoanInfo);
	targetBook->setBookState(LOANING);

	ioh.displayMessage("[SYS]" + targetBook->getTitle() + "��(��) " + loaner->getName() + "���� ����Ǿ����ϴ�.");
	isDataChanged = true;
}
void TaskManager::returnBook(List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;

	Book* targetBook = bookList.findDataById(ioh.getString("���� ID :"));
	if (targetBook == nullptr)
	{
		ioh.displayMessage("[SYS]�ش� ������ ã�� �� �����ϴ�.");
		return;
	}
	if (targetBook->getBookState() != LOANING)
	{
		ioh.displayMessage("[SYS]�ش� ������ �뿩������ �ʽ��ϴ�.");
		return;
	}
	Date* returnDate = ioh.getDate("�ݳ��� :");
	LoanInfo* targetLoanInfo = findCurrnetLoanInfo(targetBook, bookList, loanInfoList);

	targetLoanInfo->setReturnDate(returnDate);
	targetLoanInfo->setPeriod(returnDate->totalDays() - targetLoanInfo->getLoanedDate()->totalDays() + 1);
	targetBook->setBookState(LOANABLE);

	ioh.displayMessage("[SYS]" + targetBook->getTitle() + "��(��) �ݳ��Ǿ����ϴ�.");
}
void TaskManager::displayLoanHistory(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	ioh.displayMessage("========================================================================================");
	ioh.displayMessage("���� \t������ \t\tID \t������ \tID \t������ \t\t�ݳ��� \t\t����Ⱓ");
	ioh.displayMessage("----------------------------------------------------------------------------------------");
	int size = loanInfoList.getSize();
	for (int i = 0; i < size; i++)
	{
		LoanInfo* targetLoanInfo = loanInfoList.getData(i);
		User* loanner = userList.findDataById(targetLoanInfo->getLoanerId());
		Book* targetBook = bookList.findDataById(targetLoanInfo->getBookId());
		ioh.displayLoanInfo(loanner, targetBook, targetLoanInfo);
	}
	ioh.displayMessage("========================================================================================");
}
//Utility
//å�� ���� �뿩�� ã��
User* TaskManager::findCurrentLoaner(Book* targetBook, List<User>& userList, List<LoanInfo>& loanInfoList)
{
	for (int i = 0; i < loanInfoList.getSize(); i++)
	{
		if (loanInfoList.getData(i)->getBookId() == targetBook->getId() && loanInfoList.getData(i)->getReturnDate() == nullptr)
		{
			return userList.findDataById(loanInfoList.getData(i)->getLoanerId());
		}
	}
	return nullptr;
}
//å�� ���� �뿩���� ã�� (�ݳ��Ϸ� ����)
LoanInfo* TaskManager::findCurrnetLoanInfo(Book* targetBook, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	for (int i = 0; i < loanInfoList.getSize(); i++)
	{
		if (loanInfoList.getData(i)->getBookId() == targetBook->getId() && loanInfoList.getData(i)->getReturnDate() == nullptr)
		{
			return loanInfoList.getData(i);
		}
	}
	return nullptr;
}
