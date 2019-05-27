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
		ioh.displayMessage("[SYS]사용자 목록이 비어있습니다.");
		return;
	}

	std::string id = ioh.getString("변경할 구성원의 ID 입력 :");
	User* currentUser = userList.findDataById(id);
	if (currentUser == nullptr)
	{
		ioh.displayMessage("[SYS]구성원을 찾을 수 없습니다.");
		return;
	}

	//해당사용자가 대여중인 책 조사
	List<LoanInfo> loannedList;
	for (int i = 0; i < loanInfoList.getSize(); i++)
	{
		if (loanInfoList.getData(i)->getLoanerId() == id && loanInfoList.getData(i)->getReturnDate() == nullptr)
			loannedList.insertData(new LoanInfo(loanInfoList.getData(i)));
	}
	if (loannedList.isEmpty() == false)
	{
		ioh.displayMessage("[SYS]" + currentUser->getName() + "이(가) 대여중인 책이 존재합니다. 대여중인 책 목록은 아래와 같습니다.");
		loannedList.insertionSort(bookList);
		displayLoanHistory(userList, bookList, loannedList);
		return;
	}

	if (currentUser->getUserState() == INVALID)
	{
		ioh.displayMessage("[SYS]이미 비활성화된 구성원입니다.");
	}
	else
	{
		currentUser->setUserState(INVALID);
		ioh.displayMessage("[SYS]" + currentUser->getName() + "이(가) 비활성화 되었습니다.");
		isDataChanged = true;
	}
	return;
}
void TaskManager::displayUserList(List<User>& userList)
{
	IOHandler ioh;
	ioh.displayMessage("======================================================================================");
	ioh.displayMessage("ID \t성명 \t학과 \t\t상태 \t전공 \t\t연구실 \t학년 \t학점 \t연락처");
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
		ioh.displayMessage("[SYS]도서 목록이 비어있습니다.");
		return;
	}

	std::string id = ioh.getString("변경할 도서의 ID 입력 :");
	Book* currentBook = bookList.findDataById(id);
	if (currentBook == nullptr)
	{
		ioh.displayMessage("[SYS]도서를 찾을 수 없습니다.");
		return;
	}
	
	if (currentBook->getBookState() == LOANING)
	{
		ioh.displayMessage("[SYS]" + currentBook->getTitle() + "은(는) 대여중인 책입니다.");
		List<LoanInfo> loannedList;
		loannedList.insertData(new LoanInfo(findCurrnetLoanInfo(currentBook, bookList, loanInfoList)));
		displayLoanHistory(userList, bookList, loannedList);
		return;
	}
	else if (currentBook->getBookState() == INLOANBLE)
	{
		ioh.displayMessage("[SYS]이미 대출 불가능한 책입니다.");
	}
	else
	{
		currentBook->setBookState(INLOANBLE);
		ioh.displayMessage("[SYS]변경되었습니다.");
		isDataChanged = true;
	}
	return;
}
void TaskManager::displayBookList(List<Book>& bookList)
{
	IOHandler ioh;
	ioh.displayMessage("================================================================================================");
	ioh.displayMessage("ID \t도서명 \t\t출판사 \t\t출판년도 \t\t상태 \t\t권/호 \t세부주제");
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
		ioh.displayMessage("[SYS]사용자 목록 또는 도서 목록이 비어있습니다.");
		return;
	}
	//User*
	User* loaner = userList.findDataById(ioh.getString("구성원 ID:"));
	if (loaner == nullptr)
	{
		ioh.displayMessage("[SYS]해당 사용자를 찾을 수 없습니다.");
		return;
	}
		
	if (loaner->getUserState() == INVALID)
	{
		ioh.displayMessage("[SYS]" + loaner->getName() + "은(는) 사용 중지된 사용자입니다.");
		return;
	}
	
	Book* targetBook = bookList.findDataById(ioh.getString("도서 ID:"));
	if (targetBook == nullptr)
	{
		ioh.displayMessage("[SYS]해당 도서를 찾을 수 없습니다.");
		return;
	}
	if (targetBook->getBookState() == LOANING)
	{
		User* anotherLoaner = findCurrentLoaner(targetBook, userList, loanInfoList);
		ioh.displayMessage("[SYS]" + targetBook->getTitle() + "은(는) " + anotherLoaner->getName() + "에게 이미 대출중입니다.");
		return;
	}
	else if (targetBook->getBookState() == INLOANBLE)
	{
		ioh.displayMessage("[SYS]" + targetBook->getTitle() + "은(는) 대출불가 도서입니다.");
		return;
	}
	Date* loanedDate = ioh.getDate("대출일 :");
	LoanInfo* newLoanInfo = new LoanInfo("NOT_FOUND", loaner->getId(), targetBook->getId(), loanedDate, nullptr, NOT_FOUND);
	if (newLoanInfo->getSerial() == "NOT_FOUND")
	{
		int newSerial = loanInfoList.getLastId(typeid(LoanInfo).name());
		newLoanInfo->setSerial(std::to_string(newSerial));
	}
	loanInfoList.insertData(newLoanInfo);
	targetBook->setBookState(LOANING);

	ioh.displayMessage("[SYS]" + targetBook->getTitle() + "이(가) " + loaner->getName() + "에게 대출되었습니다.");
	isDataChanged = true;
}
void TaskManager::returnBook(List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;

	Book* targetBook = bookList.findDataById(ioh.getString("도서 ID :"));
	if (targetBook == nullptr)
	{
		ioh.displayMessage("[SYS]해당 도서를 찾을 수 없습니다.");
		return;
	}
	if (targetBook->getBookState() != LOANING)
	{
		ioh.displayMessage("[SYS]해당 도서는 대여중이지 않습니다.");
		return;
	}
	Date* returnDate = ioh.getDate("반납일 :");
	LoanInfo* targetLoanInfo = findCurrnetLoanInfo(targetBook, bookList, loanInfoList);

	targetLoanInfo->setReturnDate(returnDate);
	targetLoanInfo->setPeriod(returnDate->totalDays() - targetLoanInfo->getLoanedDate()->totalDays() + 1);
	targetBook->setBookState(LOANABLE);

	ioh.displayMessage("[SYS]" + targetBook->getTitle() + "이(가) 반납되었습니다.");
}
void TaskManager::displayLoanHistory(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	ioh.displayMessage("========================================================================================");
	ioh.displayMessage("구분 \t도서명 \t\tID \t대출자 \tID \t대출일 \t\t반납일 \t\t대출기간");
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
//책의 현재 대여자 찾기
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
//책의 현재 대여정보 찾기 (반납완료 제외)
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
