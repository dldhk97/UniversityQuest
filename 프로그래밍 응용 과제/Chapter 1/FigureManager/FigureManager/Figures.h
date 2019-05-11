#pragma once
#include <iostream>
#include <string>
#include "Circle.h"

class Figures
{
private:
	Circle *circleArr;		//도형을 저장할 동적 배열
	int capacity;			//최대크기
	int size;				//실제크기
public:
	//Initializer
	Figures();				//생성자
	Figures(int iMaxSize);	//최대크기 지정 및 생성자
	~Figures();				//소멸자, 동적배열 해제

	//Methods

	void addFigure();		//사용자에게 데이터를 입력받아 하나의 도형을 추가
	void removeFigure();	//사용자에게 ID를 입력받아 동일한 ID의 도형 삭제
	void printAll();		//모든 도형의 정보를 순차적으로 출력

	//Utility

	bool isEmpty();			//동적 배열이 비어있는지 확인
	void printExceptionMsg(int iCase);	//오류 메세지 출력
};

