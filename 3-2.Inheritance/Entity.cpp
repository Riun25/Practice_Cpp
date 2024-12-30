// 헤더 포함
#include <iostream>
#include "Entity.h"

// Header <-> CPP 파일 전환 단축키
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