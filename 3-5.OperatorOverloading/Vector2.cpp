#include "Vector2.h"

Vector2::Vector2()
	: mX(0.0f), mY(0.0f)
{
}

Vector2::Vector2(float _x, float _y)
	: mX(_x), mY(_y)
{
}

Vector2::~Vector2()
{
}

Vector2 Vector2::Add(const Vector2& _other)
{
	return Vector2(mX + _other.mX, mY + _other.mY);
}

Vector2 Vector2::Multply(const Vector2& _other)
{
	//return Vector2(mX * _other.mX, mY * _other.mY);
	return *this * _other;
}

Vector2 Vector2::operator+(const Vector2& _other)
{
	return Vector2(mX + _other.mX, mY + _other.mY);
}

Vector2 Vector2::operator*(const Vector2& _other)
{
	return Vector2(mX * _other.mX, mY * _other.mY);
	// return this->Multply(_other);
}

float Vector2::operator[](int _idx)
{
	if (_idx == 0)
	{
		return mX;
	}

	else if (_idx == 1)
	{
		return mY;
	}

	return 0.0f;
}

bool Vector2::operator==(const Vector2& _other)
{
	if (mX == _other.mX && mY == _other.mY)
	{
		return true;
	}
	return false;
}

bool Vector2::operator!=(const Vector2& _other)
{
	if (mX != _other.mX || mY != _other.mY)
	{
		return true;
	}
	return false;
}

Vector2 Vector2::operator+=(const Vector2& _other)
{
	mX += _other.mX;
	mY += _other.mY;
	return *this;
}

float Vector2::GetX() const
{
	return mX;
}

float Vector2::GetY() const
{
	return mY;
}
