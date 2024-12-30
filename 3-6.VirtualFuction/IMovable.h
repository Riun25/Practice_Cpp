#pragma once

class IMovable
{
public:
	virtual void Move(int _xAmount, int _yAmount) = 0;
};