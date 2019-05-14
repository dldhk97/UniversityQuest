#include <iostream>
#include "head.h"

using namespace std;

//재귀함수와 반복함수로 피보나치수열의 n번째 수를 구하는 프로그램입니다.
//0을 첫번째 수, 1을 두번째 수로 지정하였습니다. 그래서 4를 입력하면 2가 출력됩니다.
//피보나치수열은 0, 1, ,1 , 2, 3, 5, 8, 13, 21, 34, 55...로 구성됩니다.

int main()
{
	int user_input;

	cout << "이 프로그램은 피보나치수열 중 n번째 수를 구합니다." << '\n' << "(단, 1번째 수의 값이 0이고, 2번째 수의 값이 1인 경우)\n";
	cout << "n을 입력하세요. : ";
	cin >> user_input;

	if (user_input <= 0)
	{
		cout << "n은 0 보다 커야합니다." << '\n';
		return 0;
	}

	cout << "재귀함수 피보나치 결과값 : ";
	cout << recursion_fibo(user_input - 1) << '\n';		//n번째 피보나치 수를 구해야 하기 때문에 user_input -1을 해줍니다. 0이 1번째 피보나치 수이기 때문입니다.

	cout << "반복함수 피보나치 결과값 : ";
	cout << repeat_fibo(user_input) << '\n';

	//[재귀함수와 반복함수의 속도 차이]
	//입력 값(n)이 낮은 경우에는 재귀함수 코드와 반복함수 코드의 속도차이가 많이 나지 않습니다.
	//하지만 입력 값이 36 이상일 때부터 재귀함수로 구현한 코드의 실행속도가 눈에 띄게 감소하게 됩니다.반면, 반복함수 코드경우 속도저하가 거의 일어나지 않습니다.
	//재귀함수 코드가 느린 이유는 시간 복잡도가 O(2n)이기 때문입니다.
	//재귀함수 코드의 수식은 Ai = Ai - 1 + Ai - 2로 표현할 수 있습니다.
	//시간복잡도 표현한 경우 2의 n제곱의 시간복잡도를 가지는데, 이는 n의 상승에 따라 시간소요가 기하급수적으로 상승합니다.
	//또한 재귀함수로 계산할 경우 An - 2, An - 3과 같이 중복되는 계산도 존재합니다.
	//이러한 중복계산 또한 속도를 늦추는 원인이라고 생각합니다.
	//반면 반복함수로 구현한 코드는 for문이 하나 존재하며, 이는 입력 값(n)만큼 작동합니다.때문에 Big - O 계산법으로 시간 복잡도를 계산하면 복잡도는 O(n)이라 할 수 있습니다.
	//또한 중복 계산이 없기 때문에 재귀함수로 구현한 코드보다 빠르게 동작한다고 말할 수 있습니다.
	//결론적으로 재귀함수 코드가 반복함수 코드보다 느린 이유는 알고리즘의 시간 복잡도와 재귀함수 코드의 불필요한 중복 계산 때문입니다.


	//[50번째 피보나치의 수는 왜 예상치 못한 값이 나오는가?]
	//50번째 피보나치 수가 이상하게 출력이 된 이유는 오버플로우 때문입니다. int 자료형으로 표현할 수 없을 정도로 50번째 피보나치 수는 너무 큽니다.
	//Int 자료형은 -2,147,483,648 ~ 2,147,483,647까지의 수만 표현이 가능하기 때문에 47번째 피보나치 수인 1,836,311,903 이후에는 표현범위에서 벗어나 오버플로우가 일어납니다.
	//따라서 50번째 피보나치 수를 정상적으로 표현하려면 int형이 아닌 부동소수점 자료형(double, float)과 같이 표현범위가 더 넓은 자료형을 사용해야만 합니다.

	return 0;
}