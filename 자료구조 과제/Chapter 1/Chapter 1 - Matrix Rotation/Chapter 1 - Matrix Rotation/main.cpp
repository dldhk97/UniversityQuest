#include <iostream>
#include <string>
#include "head.h"

using namespace std;

const int arr_size = 4;							//nxn�迭�� ũ�⸦ �����մϴ�.

int main()
{
	int **arr = new int*[arr_size];				//2���� ���� �迭 ����, �޸� �Ҵ�
	for (int i = 0; i < arr_size; i++)
		arr[i] = new int[arr_size];

	int max_length = -1;						//�Է°��� ���� �ִ밪
	cout << "����� ä�� " << arr_size * arr_size << "���� ���� �Է��Ͻʽÿ�. : \n";		//����ڿ��� �迭�� ���� �Է¹޽��ϴ�.
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			cin >> arr[i][j];
			int this_length = to_string(arr[i][j]).length();								//�Է°��� �ִ񰪺��� ũ�� �ִ밪���� �����մϴ�.
			if (this_length > max_length)
				max_length = this_length;
		}
	}
	
	cout << "��������Դϴ�.\n";				//���� �迭 ǥ��
	print_arr(arr, arr_size, max_length);

	cout << "�������� 90�� ȸ��.\n";			//90�� �ð�������� ȸ���մϴ�.
	rotate_90_clockwise(arr, arr_size);
	print_arr(arr, arr_size, max_length);

	rotate_90_revese_clockwise(arr, arr_size);	//ȸ����Ų ����� ����Ǿ��� ������ �ݽð�������� ���� ����ġ���׽��ϴ�.

	cout << "�������� 90�� ȸ��.\n";			//90�� �ݽð�������� ȸ���մϴ�.
	rotate_90_revese_clockwise(arr, arr_size);
	print_arr(arr, arr_size, max_length);

	for (int i = 0; i < arr_size; i++)			//�޸� ����
		delete[] arr[i];
	delete[] arr;

	return 0;
}