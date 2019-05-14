int recursion_fibo(int input)									//재귀함수로 피보나치 수를 구합니다.
{
	if (input == 0) return 0;
	if (input == 1) return 1;
	return recursion_fibo(input - 1) + recursion_fibo(input - 2);
}

int repeat_fibo(int input)										//반복함수로 피보나치 수를 구합니다.
{
	if (input == 1) return 0;									//첫번째 피보나치 수를 구하려고할 경우 0을 반환합니다.
	if (input == 2) return 1;									//두번째 피보나치 수를 구하려고할 경우 1을 반환합니다.

	int previous_num_1 = 0;										//Pn-2을 저장하는 변수입니다.
	int previous_num_2 = 1;										//Pn-1을 저장하는 변수입니다.

	for (int i = 0; i < input - 2; i++)							//첫번째와 두번째 피보나치 수를 구하려고하는 2가지 경우는 제외합니다.
	{
		int temp = previous_num_2;								//임시 변수에 Pn-1값을 저장해놓습니다.
		previous_num_2 = previous_num_1 + previous_num_2;		//새로운 값을 Pn-1에 저장합니다. (이것은 다음에 사용할 Pn-1이며, 새로 구한 피보나치수이기도 합니다)
		previous_num_1 = temp;									//새로운 Pn-2는 이전의 Pn-1값으로 저장합니다. (이것은 다음에 사용할 Pn-2입니다)
	}															//즉, A, B, C ---> A(버려짐), B, C, D(새 피보나치수)
	return previous_num_2;
}