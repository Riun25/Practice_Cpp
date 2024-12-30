#include <iostream>
#include "Player.h"

Player::Player(const char* _name)
	: IEntity()
{
	// 동적 할당 및 설정
	size_t length = strlen(_name);

	// 동적 할당
	this->mName = new char[length + 1];

	// 문자열 복사
	strcpy_s(this->mName, length + 1, _name);

}

Player::~Player()
{
	// 메모리 해제
	if (mName != nullptr)
	{
		delete[] mName;
	}

}
