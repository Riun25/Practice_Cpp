#pragma once
#include "Point.h"

class Circle
{
public:
	Circle(int _x, int _y, float _radius);
	~Circle();

	void ShowData();

private:
	Point* pPoint;

	float mRadius;

	float CalculateWidth(int _radius);
};

