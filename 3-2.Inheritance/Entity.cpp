// ��� ����
#include <iostream>
#include "Entity.h"

// Header <-> CPP ���� ��ȯ ����Ű
// Ctrl + K | Ctrl + O

Entity::Entity() : mX(0), mY(0)
{
	std::cout << "Entity() called\n";
}

Entity::~Entity()
{
	std::cout << "~Entity() called\n";
}

void Entity::Move(int _xAmount, int _yAmount)
{
	mX += _xAmount;
	mY += _yAmount;
}