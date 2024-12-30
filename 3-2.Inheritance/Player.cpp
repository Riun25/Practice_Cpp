#include <iostream>
#include "Player.h"

Player::Player(const char* _name)
	: Entity()
{
	std::cout << "Player() called\n";

	// ���� �Ҵ� �� ����
	size_t length = strlen(_name);

	// ���� �Ҵ�
	this->mName = new char[length + 1];

	// ���ڿ� ����
	strcpy_s(this->mName, length + 1, _name);

}

Player::~Player()
{
	std::cout << "~Player() called\n";

	// �޸� ����
	if (mName != nullptr)
	{
		delete[] mName;
	}

}
