#pragma once

// Ŭ���� ����
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

