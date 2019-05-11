#include <iostream>
#include <string>

void print_arr(int **arr, int arr_size, int max_length)			//nxn 배열의 각 값을 출력합니다.
{
	std::cout << "------------------------------\n";
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			std::cout << arr[i][j];								//배열의 값 출력
			for (int k = 0; k <= max_length - std::to_string(arr[i][j]).length(); k++)			//값의 길이에 알맞게 공백 출력
			{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
	std::cout << "------------------------------\n\n";
}

void rotate_90_clockwise(int **arr, int arr_size)				//결과값을 저장할 배열 메모리 할당
{
	int **result_arr = new int*[arr_size];						//결과값을 저장할 배열 메모리 할당
	for (int i = 0; i < arr_size; i++)
		result_arr[i] = new int[arr_size];

	for (int i = 0; i < arr_size; i++)							//90도 시계 회전시키는 메소드입니다.
	{
		for (int j = 0; j < arr_size; j++)
		{														//이 부분의 코드가 잘 이해가 되지 않는다면, 초기 행렬의 1행의 요소를 마지막 열(3)로 옮긴다고 생각을 하면 됨.
			result_arr[j][arr_size - i - 1] = arr[i][j];		//ex) (0,0)(0,1),(0,2),(0,3) 요소들을 (0,3),(1,3),(2,3),(3,3)로 옮김
		}														//행렬을 회전시킬 때 주의해야 할 점은 기존 배열은 건드리지 않고, 회전된 배열을 따로 만들어주어야 함.
	}

	for (int i = 0; i < arr_size; i++)							//임시배열을 원본배열에 완전복사합니다.
		for (int j = 0; j < arr_size; j++)
			arr[i][j] = result_arr[i][j];

	for (int i = 0; i < arr_size; i++)							//임시 배열 메모리 해제
		delete[] result_arr[i];
	delete[] result_arr;
}

void rotate_90_revese_clockwise(int **arr, int arr_size)		//행렬과 행렬크기를 받아 90도 반시계 회전시킵니다.
{
	int **result_arr = new int*[arr_size];						//결과값을 저장할 배열 메모리 할당
	for (int i = 0; i < arr_size; i++)
		result_arr[i] = new int[arr_size];

	for (int i = 0; i < arr_size; i++)							//90도 반시계 회전시키는 메소드입니다.
	{
		for (int j = 0; j < arr_size; j++)
		{														//이 부분은 초기행렬 1행의 요소를 첫번째 열(0)로 옮긴다고 생각하면 됩니다.
			result_arr[arr_size - j - 1][i] = arr[i][j];		//ex) (0,0)(0,1),(0,2),(0,3) 요소들을 (3,0),(2,0),(1,0),(0,0)으로 이동합니다.
		}														//마찬가지로 행렬을 회전시킬 때 주의해야 할 점은 기존 배열은 건드리지 않고, 회전된 배열을 따로 만들어주어야 합니다.
	}

	for (int i = 0; i < arr_size; i++)							//임시배열을 원본배열에 완전복사합니다.
		for (int j = 0; j < arr_size; j++)
			arr[i][j] = result_arr[i][j];

	for (int i = 0; i < arr_size; i++)							//임시 배열 메모리 해제
		delete[] result_arr[i];
	delete[] result_arr;
}