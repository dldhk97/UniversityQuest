int recursion_fibo(int input)									//����Լ��� �Ǻ���ġ ���� ���մϴ�.
{
	if (input == 0) return 0;
	if (input == 1) return 1;
	return recursion_fibo(input - 1) + recursion_fibo(input - 2);
}

int repeat_fibo(int input)										//�ݺ��Լ��� �Ǻ���ġ ���� ���մϴ�.
{
	if (input == 1) return 0;									//ù��° �Ǻ���ġ ���� ���Ϸ����� ��� 0�� ��ȯ�մϴ�.
	if (input == 2) return 1;									//�ι�° �Ǻ���ġ ���� ���Ϸ����� ��� 1�� ��ȯ�մϴ�.

	int previous_num_1 = 0;										//Pn-2�� �����ϴ� �����Դϴ�.
	int previous_num_2 = 1;										//Pn-1�� �����ϴ� �����Դϴ�.

	for (int i = 0; i < input - 2; i++)							//ù��°�� �ι�° �Ǻ���ġ ���� ���Ϸ����ϴ� 2���� ���� �����մϴ�.
	{
		int temp = previous_num_2;								//�ӽ� ������ Pn-1���� �����س����ϴ�.
		previous_num_2 = previous_num_1 + previous_num_2;		//���ο� ���� Pn-1�� �����մϴ�. (�̰��� ������ ����� Pn-1�̸�, ���� ���� �Ǻ���ġ���̱⵵ �մϴ�)
		previous_num_1 = temp;									//���ο� Pn-2�� ������ Pn-1������ �����մϴ�. (�̰��� ������ ����� Pn-2�Դϴ�)
	}															//��, A, B, C ---> A(������), B, C, D(�� �Ǻ���ġ��)
	return previous_num_2;
}