#include <iostream>
#include <string>
#include "head.h"

using namespace std;

const int arr_size = 4;							//nxn배열의 크기를 정의합니다.

int main()
{
	int **arr = new int*[arr_size];				//2차원 동적 배열 선언, 메모리 할당
	for (int i = 0; i < arr_size; i++)
		arr[i] = new int[arr_size];

	int max_length = -1;						//입력값의 길이 최대값
	cout << "행렬을 채울 " << arr_size * arr_size << "개의 값을 입력하십시오. : \n";		//사용자에게 배열의 값을 입력받습니다.
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			cin >> arr[i][j];
			int this_length = to_string(arr[i][j]).length();								//입력값이 최댓값보다 크면 최대값으로 저장합니다.
			if (this_length > max_length)
				max_length = this_length;
		}
	}
	
	cout << "원본행렬입니다.\n";				//원본 배열 표시
	print_arr(arr, arr_size, max_length);

	cout << "우측으로 90도 회전.\n";			//90도 시계방향으로 회전합니다.
	rotate_90_clockwise(arr, arr_size);
	print_arr(arr, arr_size, max_length);

	rotate_90_revese_clockwise(arr, arr_size);	//회전시킨 행렬은 저장되었기 때문에 반시계방향으로 돌려 원위치시켰습니다.

	cout << "좌측으로 90도 회전.\n";			//90도 반시계방향으로 회전합니다.
	rotate_90_revese_clockwise(arr, arr_size);
	print_arr(arr, arr_size, max_length);

	for (int i = 0; i < arr_size; i++)			//메모리 해제
		delete[] arr[i];
	delete[] arr;

	return 0;
}