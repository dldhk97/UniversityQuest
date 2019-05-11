#pragma once
#include <iostream>
#include <string>

const double PIE = 3.14159265359;		//원주율 정의

class Circle
{
private:
	std::string id;				//도형의 ID
	int posX, posY;				//도형의 좌표
	double radius, area;		//도형의 반지름, 면적
public:
	//Initializer

	Circle();					//기본 생성자
	~Circle();					//소멸자

	//Getter,Setter

	void setData();				//도형의 데이터 설정
	std::string getId();		//도형의 ID 반환
	double getArea();			//도형의 면적 반환

	//methods
	void print();				//도형의 정보 출력

};

