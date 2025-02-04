#pragma once
class Rectangle
{
public:
	Rectangle(float _wide, float _height)
		: mWide(_wide), mHeight(_height)
	{
	}

	float GetArea()
	{
		return mWide * mHeight;
	}

	float GetSize()
	{
		return 2 * (mWide + mHeight);
	}

private:
	float mWide = 0.0f;
	float mHeight = 0.0f;
};

