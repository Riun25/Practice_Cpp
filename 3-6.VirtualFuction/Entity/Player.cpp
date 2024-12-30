#include <iostream>
#include "Player.h"

Player::Player(const char* _name)
	: IEntity()
{
	// ���� �Ҵ� �� ����
	size_t length = strlen(_name);

	// ���� �Ҵ�
	this->mName = new char[length + 1];

	// ���ڿ� ����
	strcpy_s(this->mName, length + 1, _name);

}

Player::~Player()
{
	// �޸� ����
	if (mName != nullptr)
	{
		delete[] mName;
	}

}
