//IOHandler.cpp
#include "IOHandler.h"

int IOHandler::getMenu()
{
	int userInput;
	while (true)
	{
		cout << "====================================================" << '\n';
		cout << "1) ��ǰ �߰�" << '\n';
		cout << "2) ��ǰ ����" << '\n';
		cout << "3) ��ǰ ���" << '\n';
		cout << "4) ����" << "\n";
		cout << "====================================================" << '\n';
		cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
		{
			return userInput;
		}
		cout << "�߸��� �Է��Դϴ�." << '\n';
	}

}
Component IOHandler::getComponent()
{
	string serialNumber, model, componentName, price, manufacturer;

	serialNumber = getString("�Ϸù�ȣ �Է�: ");
	model = getString("���Ǵ� ���� �Է�: ");
	componentName = getString("��ǰ�� �Է�: ");
	price = getString("���� �Է�: ");
	manufacturer = getString("������� �Է�: ");

	Component newComponent(-1, serialNumber, model, componentName, price, manufacturer);
	return newComponent;
}
void IOHandler::printComponent(Component iComponent)
{
	cout << "ID :" << iComponent.getId() << '\n';
	cout << "�Ϸù�ȣ :" << iComponent.getSerialNumber() << '\n';
	cout << "���Ǵ� ���� :" << iComponent.getModel() << '\n';
	cout << "��ǰ�� :" << iComponent.getComponentName() << '\n';
	cout << "���� :" << iComponent.getPrice() << "\n";
	cout << "������� :" << iComponent.getManufacturer() << "\n\n";
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
	if (writeFile.is_open())				//������ �����ִٸ�
	{
		if (iList.getSize() <= 0)			//list�� ����ִٸ� ���� ����
		{
			writeFile << "";
			cout << "�� ����� �����Ͽ����ϴ�." << "\n";
			return;
		}

		for (int i = 0; i < iList.getSize(); i++)
		{
			writeFile << iList.getComponent(i).getId() << " " << iList.getComponent(i).getSerialNumber() << " "
				<< iList.getComponent(i).getModel() << " " << iList.getComponent(i).getComponentName() << " " 
				<< iList.getComponent(i).getPrice() << " " << iList.getComponent(i).getManufacturer() << "\n";
		}
		writeFile.close();
		cout << "��ǰ ����� �����Ͽ����ϴ�." << "\n";
	}
	else
	{
		cout << "������ ������ �� �����ϴ�." << "\n";
	}
}