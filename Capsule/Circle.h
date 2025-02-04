#pragma once
class Circle
{
public:
	Circle(float _radius)
		: mRadius(_radius)
	{
	}

	float GetArea()
	{
		return PI * mRadius * mRadius;
	}

	float GetSize()
	{
		return 2.0f * PI * mRadius;
	}
private:
	float mRadius = 0.0f;
	const float PI = 3.141592f;
};

