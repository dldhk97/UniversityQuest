//IOHandler.cpp
#include "IOHandler.h"

int IOHandler::getMenu()
{
	int userInput;
	while (true)
	{
		cout << "====================================================" << '\n';
		cout << "1) 부품 추가" << '\n';
		cout << "2) 부품 삭제" << '\n';
		cout << "3) 부품 출력" << '\n';
		cout << "4) 종료" << "\n";
		cout << "====================================================" << '\n';
		cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
		{
			return userInput;
		}
		cout << "잘못된 입력입니다." << '\n';
	}

}
Component IOHandler::getComponent()
{
	string serialNumber, model, componentName, price, manufacturer;

	serialNumber = getString("일련번호 입력: ");
	model = getString("사용되는 차종 입력: ");
	componentName = getString("부품명 입력: ");
	price = getString("가격 입력: ");
	manufacturer = getString("제조사명 입력: ");

	Component newComponent(-1, serialNumber, model, componentName, price, manufacturer);
	return newComponent;
}
void IOHandler::printComponent(Component iComponent)
{
	cout << "ID :" << iComponent.getId() << '\n';
	cout << "일련번호 :" << iComponent.getSerialNumber() << '\n';
	cout << "사용되는 차종 :" << iComponent.getModel() << '\n';
	cout << "부품명 :" << iComponent.getComponentName() << '\n';
	cout << "가격 :" << iComponent.getPrice() << "\n";
	cout << "제조사명 :" << iComponent.getManufacturer() << "\n\n";
}

void IOHandler::printMessage(string Message)
{
	cout << Message << '\n';
}

int IOHandler::getInt(string message)
{
	int value;
	cout << message;
	cin >> value;
	cin.ignore();
	return value;
}

string IOHandler::getString(string message)
{
	string value;
	cout << message;
	cin >> value;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
	}
	return value;
}

bool IOHandler::readFile(ComponentList &iList, int argc, char *argv[])
{
	if (argc == 1)
		return false;

	ifstream openFile(argv[1]);
	if (openFile.is_open())
	{
		string line;
		string tempArr[6];
		int saveIndex, previousIndex;

		while (getline(openFile, line))
		{
			saveIndex = 0;
			previousIndex = 0;
			for (int i = 0; i < line.length() ; i++)
			{
				if (line[i] == ' ' || i == line.length() - 1)
				{
					if (i == line.length() - 1)
						i++;
					string tempStr = line.substr(previousIndex, i - previousIndex);
					tempArr[saveIndex++] = tempStr;
					previousIndex = i + 1;
				}
			}
			iList.insertComponent(Component(stoi(tempArr[0]), tempArr[1], tempArr[2], tempArr[3], tempArr[4], tempArr[5]));
		}
		openFile.close();
		return true;
	}
	return false;
}

void IOHandler::saveFile(ComponentList &iList, char *argv[])
{
	ofstream writeFile(argv[1]);
	if (writeFile.is_open())				//파일이 열려있다면
	{
		if (iList.getSize() <= 0)			//list가 비어있다면 공백 저장
		{
			writeFile << "";
			cout << "빈 목록을 저장하였습니다." << "\n";
			return;
		}

		for (int i = 0; i < iList.getSize(); i++)
		{
			writeFile << iList.getComponent(i).getId() << " " << iList.getComponent(i).getSerialNumber() << " "
				<< iList.getComponent(i).getModel() << " " << iList.getComponent(i).getComponentName() << " " 
				<< iList.getComponent(i).getPrice() << " " << iList.getComponent(i).getManufacturer() << "\n";
		}
		writeFile.close();
		cout << "부품 목록을 저장하였습니다." << "\n";
	}
	else
	{
		cout << "파일을 저장할 수 없습니다." << "\n";
	}
}