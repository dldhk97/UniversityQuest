#include "TaskManager.h"

using namespace std;

int main()
{
	TaskManager tskMgr;
	string userInput;
	Formula postfix;
	BinaryTree<Term> formulaTree;

	while (true)
	{
		tskMgr.getInfix(userInput);
		if (cin.fail())									//�Է��� �޴µ� ���������� ���� �ʱ�ȭ
		{
			cin.ignore();
			cin.clear();
			continue;
		}
		if (userInput == "quit")
			break;
		try
		{
			tskMgr.saveAsPostfix(userInput, postfix);
			tskMgr.printAsPostfix(postfix);
			tskMgr.saveAsTree(postfix, formulaTree);
			tskMgr.printAsPreorder(formulaTree);
			tskMgr.printAsTree(formulaTree);
			tskMgr.printRoot(formulaTree);
		}
		catch (std::exception exceptionCode)
		{
			tskMgr.printException(*exceptionCode.what());
		}
	}
	return 0;
}