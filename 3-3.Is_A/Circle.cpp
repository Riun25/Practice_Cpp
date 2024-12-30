#include <iostream>
#include "Circle.h"

Circle::Circle(int _x, int _y, float _radius)
	:mRadius(_radius)
{
	pPoint = new Point(_x, _y);
}

Circle::~Circle()
{
}

void Circle::ShowData()
{
	std::cout << "�߽���ǥ: (" << pPoint->GetPosX() << ", " << pPoint->GetPosY() << ")\n������: "
		<< mRadius << "\n���� ����: " << CalculateWidth(mRadius);
}

float Circle::CalculateWidth(int _radius)
{
	return _radius * _radius * 3.141592f;
}
