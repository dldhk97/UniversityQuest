#pragma once
class Term
{
private:
	int coe;				//항의 계수
	int idx;				//항의 지수
public:
	//getter
	int getCoe();
	void setCoe(int iCoe);
	int getIdx();
	void setIdx(int iIdx);
};

