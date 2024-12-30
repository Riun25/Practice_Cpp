#pragma once
#include <iostream>
#include "IMovable.h"
#include "Entity.h"

// Entity 클래스를 부모로 지정
// 미들웨어 (운영체제 위에서 동작하는 프로그램)
class Player : public IEntity//, public IMovable // 다중상속 : 여러 부모를 가짐
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

