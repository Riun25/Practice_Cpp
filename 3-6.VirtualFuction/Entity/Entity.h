#pragma once

// Ŭ���� ����
class IEntity
{
public:
	//Entity();
	//~Entity();

	//void Move(int _xAmount, int _yAmount);

	// ���� ���� �Լ� (Pure Virtual Fuction)
	// ���� : �� �Լ��� �ʼ������� �����ϵ��� ������
	virtual const char* GetName() abstract;

	// ���� �Լ�(virtual Ű���尡 �߰��� �Լ�)
	//virtual const char* GetName() { return "Entity"; }

//
};

