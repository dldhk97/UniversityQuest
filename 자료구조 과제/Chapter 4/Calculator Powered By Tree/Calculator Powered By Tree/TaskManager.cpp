#include "TaskManager.h"

void TaskManager::getInfix(std::string &infix)
{
	std::cout << "계산식을 입력하세요 (종료는 quit) : ";
	std::getline(std::cin, infix);
}

void TaskManager::saveAsPostfix(const std::string infix, Formula &postfix)
{
	postfix.saveAsPostfix(infix);			//후위연산자 형태로 Formula 클래스로 저장
}

void TaskManager::saveAsTree(Formula &postfix, BinaryTree<Term> &formulaTree)
{
	formulaTree.calculateAsTree(postfix);	//Formula 클래스를 계산하면서 트리로 저장
}

void TaskManager::printAsPostfix(Formula &postfix)
{
	std::cout << "--- 후위 계산식은 : ";
	postfix.printPostfix();
	std::cout << '\n';
}

void TaskManager::printAsPreorder(BinaryTree<Term> &formulaTree)
{
	std::cout << "--- 전위 계산식은 : ";
	formulaTree.preorder(formulaTree.getRoot());
	std::cout << '\n';
}

void TaskManager::printAsTree(BinaryTree<Term> &formulaTree)
{
	formulaTree.printAsTree(formulaTree.getRoot(), 0, true);
}
void TaskManager::printRoot(BinaryTree<Term> &formulaTree)
{
	std::cout << "---- 결과는 ";
	std::cout << formulaTree.getRoot()->getData().getIntValue();
	std::cout << "\n";
}

void TaskManager::printException(const char exceptionCode)
{
	std::string exceptionMsg;
	switch (exceptionCode)
	{
	case '0':
		exceptionMsg = "문자가 포함된 수식";
		break;
	case '1':
		exceptionMsg = "올바르지 않은 괄호쌍";
		break;
	case '2':
		exceptionMsg = "이해할 수 없는 수식";
		break;
	case '3':
		exceptionMsg = "나누기의 두번째 연산자가 0인 경우가 발생";
		break;
	case '4':
		exceptionMsg = "공백문자만 존재";
		break;
	case '5':
		exceptionMsg = "정수만 입력받을 수 있습니다.";
		break;
	case '6':
		exceptionMsg = "연산자 처리 오류.";
		break;
	case 'A':
		exceptionMsg = "Term에서 연산자를 정수형으로 호출하였습니다.";
		break;
	case 'B':
		exceptionMsg = "Stack이 비어있습니다.";
		break;
	case 'C':
		exceptionMsg = "NULL 포인터에서 getData 하였습니다.";
		break;
	default:
		exceptionMsg = "알 수 없는 오류";
		break;
	}
	std::cout << "[오류] " << exceptionMsg << "\n\n";
}