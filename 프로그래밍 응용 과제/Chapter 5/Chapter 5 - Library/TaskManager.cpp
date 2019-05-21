#include "TaskManager.h"

void TaskManager::getUserMenu(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	IOHandler ioh;
	int userInput;
	while (1)
	{
		userInput = ioh.getMenu(USER);
		if (userInput == EXIT)
			break;
		switch (userInput)
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
}
void TaskManager::getBookMenu(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	IOHandler ioh;
	int userInput;
	while (1)
	{
		userInput = ioh.getMenu(BOOK);
		if (userInput == EXIT)
			break;
		switch (userInput)
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
}
void TaskManager::getLoanMenu(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	IOHandler ioh;
	int userInput;
	while (1)
	{
		userInput = ioh.getMenu(LOAN);
		if (userInput == EXIT)
			break;
		switch (userInput)
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
}

void TaskManager::insertUser(List<User>& userList)
{
	IOHandler ioh;
	User* newUser = nullptr;
	switch (ioh.getUserType())
	{
		case PROFESSOR:
		{
			Professor* newProfessor;
			newProfessor = ioh.getProfessor();
			newUser = newProfessor;
			break;
		}
		case STUDENT:
		{
			Student* newStudent;
			newStudent = ioh.getStudent();
			newUser = newStudent;
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
	if (userList.getSize() <= 0)
	{
		ioh.displayMessage("사용자 목록이 비어있습니다.");
		return;
	}
	std::string id = ioh.getString("변경할 구성원의 ID 입력 :");
	int index = userList.findDataById(id);
	if (index == NOT_FOUND)
	{
		ioh.displayMessage("구성원을 찾을 수 없습니다.");
		return;
	}
	User* currentUser = userList.getData(index);
	if (loanInfoList.findDataByLoanerId(id) != NOT_FOUND)
	{
		List<LoanInfo> loannedList;
		ioh.displayMessage(currentUser->getName() + "이(가) 대여중인 책이 존재합니다. 대여중인 책 목록은 아래와 같습니다.");
		for (int i = 0; i < loanInfoList.getSize(); i++)
		{
			if (loanInfoList.getData(i)->getLoanerId() == id && loanInfoList.getData(i)->getReturnDate() == nullptr)
				loannedList.insertData(new LoanInfo(loanInfoList.getData(i)));
		}
		loannedList.insertionSort(bookList);
		displayLoanHistory(userList, bookList, loannedList);
		return;
	}
	if (currentUser->getUserState() == VALID)
	{
		currentUser->setUserState(INVALID);
		ioh.displayMessage("변경되었습니다.");
		isDataChanged = true;
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
	ioh.displayMessage("==================================================");
	ioh.displayMessage("ID \t성명 \t학과 \t상태 \t전공 \t연구실 \t학년 \t학점 \t연락처");
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
	Book* newBook = nullptr;
	switch (ioh.getBookType())
	{
		case MAGAZINE:
		{
			Magazine* newMagazine;
			newMagazine = ioh.getMagazine();
			newBook = newMagazine;
			break;
		}
		case TEXTBOOK:
		{
			TextBook* newTextBook;
			newTextBook = ioh.getTextBook();
			newBook = newTextBook;
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
	if (bookList.getSize() <= 0)
	{
		ioh.displayMessage("도서 목록이 비어있습니다.");
		return;
	}
	std::string id = ioh.getString("변경할 도서의 ID 입력 :");
	int index = bookList.findDataById(id);
	if (index == NOT_FOUND)
	{
		ioh.displayMessage("도서를 찾을 수 없습니다.");
		return;
	}
	Book* currentBook = bookList.getData(index);
	if (currentBook->getBookState() == LOANABLE)
	{
		currentBook->setBookState(INLOANBLE);
		ioh.displayMessage("변경되었습니다.");
		isDataChanged = true;
	}
	else if (currentBook->getBookState() == LOANING)
	{
		ioh.displayMessage(currentBook->getTitle() + "은(는) 대출중인 책입니다.");
		List<LoanInfo> loannedList;
		for (int i = 0; i < loanInfoList.getSize(); i++)
		{
			if (loanInfoList.getData(i)->getId() == id && loanInfoList.getData(i)->getReturnDate() == nullptr)
				loannedList.insertData(new LoanInfo(loanInfoList.getData(i)));
		}
		loannedList.insertionSort(bookList);
		displayLoanHistory(userList, bookList, loannedList);
		return;
	}
	else
	{
		ioh.displayMessage("이미 대출 불가능한 책입니다.");
	}
	return;
}
void TaskManager::displayBookList(List<Book>& bookList)
{
	IOHandler ioh;
	ioh.displayMessage("==================================================");
	ioh.displayMessage("ID \t도서명 \t\t출판사 \t\t출판년도 \t\t상태 \t\t권/호 \t세부주제");
	ioh.displayMessage("--------------------------------------------------");
	int size = bookList.getSize();
	for (int i = 0; i < size; i++)
	{
		ioh.displayBook(bookList.getData(i));
	}
	ioh.displayMessage("==================================================");
}

void TaskManager::loanBook(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, bool& isDataChanged)
{
	IOHandler ioh;
	if (userList.getSize() <= 0 || bookList.getSize() <= 0)
	{
		ioh.displayMessage("사용자 목록 또는 도서 목록이 비어있습니다.");
		return;
	}

	User* loaner = ioh.findDataById("구성원 ID :", userList);
	if (loaner == nullptr)
		return;
	if (loaner->getUserState() == INVALID)
	{
		ioh.displayMessage(loaner->getName() + "은(는) 사용 중지된 사용자입니다.");
		return;
	}
	Book* targetBook = ioh.findDataById("도서 ID :", bookList);
	if (targetBook == nullptr)
		return;
	if (targetBook->getBookState() == LOANING)
	{
		std::string anotherLoanerId;
		User* anotherLoaner;
		for (int i = 0; i < loanInfoList.getSize(); i++)
		{
			if (loanInfoList.getData(i)->getId() == targetBook->getId() && loanInfoList.getData(i)->getReturnDate() == nullptr)
			{
				anotherLoanerId = loanInfoList.getData(i)->getLoanerId();
				break;
			}
		}
		anotherLoaner = userList.getData(userList.findDataById(anotherLoanerId));
		ioh.displayMessage(targetBook->getTitle() + "은(는) " + anotherLoaner->getName() + "에게 이미 대출중입니다.");
		return;
	}
	else if (targetBook->getBookState() == INLOANBLE)
	{
		ioh.displayMessage(targetBook->getTitle() + "은(는) 대출불가 도서입니다.");
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
	ioh.displayMessage(targetBook->getTitle() + "이(가) " + loaner->getName() + "에게 대출되었습니다.");
	isDataChanged = true;
}
void TaskManager::returnBook(List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	Book* targetBook = ioh.findDataById("도서 ID :", bookList);
	if (targetBook == nullptr)
		return;
	Date* returnDate = ioh.getDate("반납일 :");
	LoanInfo* targetLoanInfo = loanInfoList.getData(loanInfoList.findLoaningBookById(targetBook->getId()));
	targetLoanInfo->setReturnDate(returnDate);

	int endDays = returnDate->totalDays();
	int startDays = targetLoanInfo->getLoanedDate()->totalDays();
	targetLoanInfo->setPeriod(endDays - startDays + 1);
	targetBook->setBookState(LOANABLE);
	ioh.displayMessage(targetBook->getTitle() + "이(가) 반납되었습니다.");
}
void TaskManager::displayLoanHistory(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	IOHandler ioh;
	ioh.displayMessage("==================================================");
	ioh.displayMessage("구분 \t도서명 \t\tID \t대출자 \tID \t대출일 \t\t반납일 \t\t대출기간");
	ioh.displayMessage("--------------------------------------------------");
	int size = loanInfoList.getSize();
	for (int i = 0; i < size; i++)
	{
		LoanInfo* targetLoanInfo = loanInfoList.getData(i);
		User* loanner = userList.getData(userList.findDataById(targetLoanInfo->getLoanerId()));
		Book* targetBook = bookList.getData(bookList.findDataById(targetLoanInfo->getId()));
		ioh.displayLoanInfo(loanner, targetBook, targetLoanInfo);
	}
	ioh.displayMessage("==================================================");
}