#pragma once
#include <iostream>
#include "IMovable.h"
#include "Entity.h"

// Entity Ŭ������ �θ�� ����
// �̵���� (�ü�� ������ �����ϴ� ���α׷�)
class Player : public IEntity//, public IMovable // ���߻�� : ���� �θ� ����
{
public:
	Player(const char* _name);
	~Player();

	virtual const char* GetName() override
	{
		//std::cout << Entity::GetName() << "\n";
		return mName;
	}


private:
	char* mName;
};

