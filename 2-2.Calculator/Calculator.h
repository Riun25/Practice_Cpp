#pragma once
#include <iostream>

class Calculator
{
public:
	Calculator();
	~Calculator();

	int Add(int _n1, int _n2);
	float Divide(int _n1, int _n2);
	int Substract(int _n1, int _n2);
	int Multiply(int _n1, int _n2);

	void ShowOperationCount();


private:
	int mAddNum = 0;
	int mDivideNum = 0;
	int mSubstractNum = 0;
	int mMultiplyNum = 0;

	float result = 0;
};

