#pragma once
#include "Entity.h"

// Entity Ŭ������ �θ�� ����
class Player : public Entity
{
public:
	Player(const char* _name);
	~Player();

private:
	char* mName;
};

