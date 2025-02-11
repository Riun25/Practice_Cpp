#pragma once

#include "FireFighterBase.h"

class Firefighter : public FirefighterBase
{
public:
	Firefighter(const std::string& name)
		: FirefighterBase(name)
	{
	}

	virtual ~Firefighter()
	{
	}

	// �Ҳ���(ExtinguishFire)
	// ���� ���� �Լ�
	virtual void ExtinguishFire() override
	{
		std::cout << name << " �ҹ���� ���� ���� ����!\n";
		TrainHoseOnFire();
		TurnOnHose();
	}

	// ��� �Լ�(�޼ҵ�)
protected:
	// ȣ�� �ѱ�(��)
	virtual void TurnOnHose()
	{
		std::cout << "���� ������ �ֽ��ϴ�.\n";
	}

	// ȣ�� ����
	virtual void TrainHoseOnFire()
	{
		std::cout << "ȣ���� ���� �߻��� ���� �ܳ��ϰ� �ֽ��ϴ�.\n";
	}
};
