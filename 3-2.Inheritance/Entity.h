#pragma once

// 클래스 선언
class Entity
{
public:
	Entity();
	~Entity();

	void Move(int _xAmount, int _yAmount);

protected:
	int mX;
	int mY;
};

