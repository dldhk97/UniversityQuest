#include <iostream>
#include <string>

void print_arr(int **arr, int arr_size, int max_length)			//nxn �迭�� �� ���� ����մϴ�.
{
	std::cout << "------------------------------\n";
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			std::cout << arr[i][j];								//�迭�� �� ���
			for (int k = 0; k <= max_length - std::to_string(arr[i][j]).length(); k++)			//���� ���̿� �˸°� ���� ���
			{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
	std::cout << "------------------------------\n\n";
}

void rotate_90_clockwise(int **arr, int arr_size)				//������� ������ �迭 �޸� �Ҵ�
{
	int **result_arr = new int*[arr_size];						//������� ������ �迭 �޸� �Ҵ�
	for (int i = 0; i < arr_size; i++)
		result_arr[i] = new int[arr_size];

	for (int i = 0; i < arr_size; i++)							//90�� �ð� ȸ����Ű�� �޼ҵ��Դϴ�.
	{
		for (int j = 0; j < arr_size; j++)
		{														//�� �κ��� �ڵ尡 �� ���ذ� ���� �ʴ´ٸ�, �ʱ� ����� 1���� ��Ҹ� ������ ��(3)�� �ű�ٰ� ������ �ϸ� ��.
			result_arr[j][arr_size - i - 1] = arr[i][j];		//ex) (0,0)(0,1),(0,2),(0,3) ��ҵ��� (0,3),(1,3),(2,3),(3,3)�� �ű�
		}														//����� ȸ����ų �� �����ؾ� �� ���� ���� �迭�� �ǵ帮�� �ʰ�, ȸ���� �迭�� ���� ������־�� ��.
	}

	for (int i = 0; i < arr_size; i++)							//�ӽù迭�� �����迭�� ���������մϴ�.
		for (int j = 0; j < arr_size; j++)
			arr[i][j] = result_arr[i][j];

	for (int i = 0; i < arr_size; i++)							//�ӽ� �迭 �޸� ����
		delete[] result_arr[i];
	delete[] result_arr;
}

void rotate_90_revese_clockwise(int **arr, int arr_size)		//��İ� ���ũ�⸦ �޾� 90�� �ݽð� ȸ����ŵ�ϴ�.
{
	int **result_arr = new int*[arr_size];						//������� ������ �迭 �޸� �Ҵ�
	for (int i = 0; i < arr_size; i++)
		result_arr[i] = new int[arr_size];

	for (int i = 0; i < arr_size; i++)							//90�� �ݽð� ȸ����Ű�� �޼ҵ��Դϴ�.
	{
		for (int j = 0; j < arr_size; j++)
		{														//�� �κ��� �ʱ���� 1���� ��Ҹ� ù��° ��(0)�� �ű�ٰ� �����ϸ� �˴ϴ�.
			result_arr[arr_size - j - 1][i] = arr[i][j];		//ex) (0,0)(0,1),(0,2),(0,3) ��ҵ��� (3,0),(2,0),(1,0),(0,0)���� �̵��մϴ�.
		}														//���������� ����� ȸ����ų �� �����ؾ� �� ���� ���� �迭�� �ǵ帮�� �ʰ�, ȸ���� �迭�� ���� ������־�� �մϴ�.
	}

	for (int i = 0; i < arr_size; i++)							//�ӽù迭�� �����迭�� ���������մϴ�.
		for (int j = 0; j < arr_size; j++)
			arr[i][j] = result_arr[i][j];

	for (int i = 0; i < arr_size; i++)							//�ӽ� �迭 �޸� ����
		delete[] result_arr[i];
	delete[] result_arr;
}