#pragma once

class Polynomial
{
private:
	int *arr;			//���� ���� ������ �迭, ¦������ ���(Coe), Ȧ������ ����(Idx)�� ���ϴ�.
	int size;			//�迭�� ���� �뷮
	int capacity;		//�迭�� �ִ� �뷮
public:
	Polynomial();			//�������Դϴ�.
	void deleteMemory();	//�޸𸮸� �����մϴ�.

	//getter
	int getSize();			//�迭�� ���� �뷮�� �˾Ƴ��ϴ�.
	int getCoe(int index);	//Ư�� ��ġ�� ���� ����� �˾Ƴ��ϴ�.
	int getIdx(int index);	//Ư�� ��ġ�� ���� ������ �˾Ƴ��ϴ�.

	//Methods
	void addItem(int coe, int idx);	//����� ������ �Է¹޾� ���ο� ���� ���մϴ�.
	void removeItem(int idx);		//������ �Է¹޾� �ش�Ǵ� ���� �����մϴ�.
	void resizeCapacity(int iCapacity);	//ũ�⸦ �Է¹޾� �迭�� �ִ�뷮�� �������մϴ�.

	//Operators
	Polynomial operator+(Polynomial target);	//���� �������Դϴ�.
	Polynomial operator*(Polynomial target);	//���� �������Դϴ�.
};

