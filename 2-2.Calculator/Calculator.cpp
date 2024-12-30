#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

int Calculator::Add(int _n1, int _n2)
{
	mAddNum++;
	return _n1 + _n2;
}

float Calculator::Divide(int _n1, int _n2)
{
	mDivideNum++;
	return _n1 / _n2;
}

int Calculator::Substract(int _n1, int _n2)
{
	mSubstractNum++;
	return _n1 - _n2;
}

int Calculator::Multiply(int _n1, int _n2)
{
	mMultiplyNum++;
	return _n1 * _n2;
}

void Calculator::ShowOperationCount()
{
	std::cout << "µ¡¼À: " << mAddNum <<
		" »¬¼À: " << mSubstractNum <<
		" °ö¼À: " << mMultiplyNum <<
		" ³ª´°¼À: " << mDivideNum << "\n";

}
