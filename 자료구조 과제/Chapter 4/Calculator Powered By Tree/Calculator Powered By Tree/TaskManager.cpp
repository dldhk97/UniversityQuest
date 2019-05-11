#include "TaskManager.h"

void TaskManager::getInfix(std::string &infix)
{
	std::cout << "������ �Է��ϼ��� (����� quit) : ";
	std::getline(std::cin, infix);
}

void TaskManager::saveAsPostfix(const std::string infix, Formula &postfix)
{
	postfix.saveAsPostfix(infix);			//���������� ���·� Formula Ŭ������ ����
}

void TaskManager::saveAsTree(Formula &postfix, BinaryTree<Term> &formulaTree)
{
	formulaTree.calculateAsTree(postfix);	//Formula Ŭ������ ����ϸ鼭 Ʈ���� ����
}

void TaskManager::printAsPostfix(Formula &postfix)
{
	std::cout << "--- ���� ������ : ";
	postfix.printPostfix();
	std::cout << '\n';
}

void TaskManager::printAsPreorder(BinaryTree<Term> &formulaTree)
{
	std::cout << "--- ���� ������ : ";
	formulaTree.preorder(formulaTree.getRoot());
	std::cout << '\n';
}

void TaskManager::printAsTree(BinaryTree<Term> &formulaTree)
{
	formulaTree.printAsTree(formulaTree.getRoot(), 0, true);
}
void TaskManager::printRoot(BinaryTree<Term> &formulaTree)
{
	std::cout << "---- ����� ";
	std::cout << formulaTree.getRoot()->getData().getIntValue();
	std::cout << "\n";
}

void TaskManager::printException(const char exceptionCode)
{
	std::string exceptionMsg;
	switch (exceptionCode)
	{
	case '0':
		exceptionMsg = "���ڰ� ���Ե� ����";
		break;
	case '1':
		exceptionMsg = "�ùٸ��� ���� ��ȣ��";
		break;
	case '2':
		exceptionMsg = "������ �� ���� ����";
		break;
	case '3':
		exceptionMsg = "�������� �ι�° �����ڰ� 0�� ��찡 �߻�";
		break;
	case '4':
		exceptionMsg = "���鹮�ڸ� ����";
		break;
	case '5':
		exceptionMsg = "������ �Է¹��� �� �ֽ��ϴ�.";
		break;
	case '6':
		exceptionMsg = "������ ó�� ����.";
		break;
	case 'A':
		exceptionMsg = "Term���� �����ڸ� ���������� ȣ���Ͽ����ϴ�.";
		break;
	case 'B':
		exceptionMsg = "Stack�� ����ֽ��ϴ�.";
		break;
	case 'C':
		exceptionMsg = "NULL �����Ϳ��� getData �Ͽ����ϴ�.";
		break;
	default:
		exceptionMsg = "�� �� ���� ����";
		break;
	}
	std::cout << "[����] " << exceptionMsg << "\n\n";
}