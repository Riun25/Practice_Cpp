#pragma once

// 클래스 선언
class IEntity
{
public:
	//Entity();
	//~Entity();

	//void Move(int _xAmount, int _yAmount);

	// 순수 가상 함수 (Pure Virtual Fuction)
	// 목적 : 이 함수를 필수적으로 구현하도록 강제함
	virtual const char* GetName() abstract;

	// 가상 함수(virtual 키워드가 추가된 함수)
	//virtual const char* GetName() { return "Entity"; }

//
};

