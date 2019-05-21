#include "Menu.h"

std::string Menu::getMenuTitle(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "메인 메뉴";
	case USER:
		return "구성원 관리 메뉴";
	case BOOK:
		return "도서 관리 메뉴";
	case LOAN:
		return "대출 관리 메뉴";
	default:
		return "ERROR";
	}
}
std::string Menu::getOption1(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "구성원 관리";
	case USER:
		return "구성원 추가";
	case BOOK:
		return "도서 추가";
	case LOAN:
		return "도서 대출";
	default:
		return "ERROR";
	}
}
std::string Menu::getOption2(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "도서 관리";
	case USER:
		return "구성원 변경";
	case BOOK:
		return "도서 변경";
	case LOAN:
		return "도서 반납";
	default:
		return "ERROR";
	}
}
std::string Menu::getOption3(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "대출 관리";
	case USER:
		return "구성원 출력";
	case BOOK:
		return "도서 출력";
	case LOAN:
		return "대출/반납 정보 출력";
	default:
		return "ERROR";
	}
}
std::string Menu::getOption4(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "종료";
	case USER:
		return "메인 메뉴";
	case BOOK:
		return "메인 메뉴";
	case LOAN:
		return "메인 메뉴";
	default:
		return "ERROR";
	}
}

int Menu::getMenu(int menuType)
{
	IOHandler ioh;
	
	int userInput;
	while (1)
	{
		std::cout << "====================================================" << '\n';
		std::cout << "<< " << getMenuTitle(menuType) << " >>" << '\n';
		std::cout << "1) " << getOption1(menuType) << '\n';
		std::cout << "2) " << getOption2(menuType) << '\n';
		std::cout << "3) " << getOption3(menuType) << '\n';
		std::cout << "4) " << getOption4(menuType) << "\n";
		std::cout << "====================================================" << '\n';
		userInput = ioh.getInt("입력 :");
		if (USER <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "[SYS]잘못된 입력입니다." << '\n';
	}
}