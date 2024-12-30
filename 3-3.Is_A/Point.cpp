#pragma once
class Point
{
public:
	Point(int _x, int _y);
	~Point();

	int GetPosX() const { return mX; }
	int GetPosY() const { return mY; }

private:
	int mX;
	int mY;
};

