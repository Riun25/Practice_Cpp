#pragma once

#include "FireFighterBase.h"

// ���� �ҹ��
class TraineeFirefigter : public FirefighterBase
{
public:
	TraineeFirefigter(const std::string& name, bool hoseTrainedOnFire = false)
		:FirefighterBase(name), hoseTrainedOnFire(hoseTrainedOnFire)
	{

	}
	~TraineeFirefigter() {}

	virtual void ExtinguishFire() override
	{
		std::cout << name << " �ҹ���� ���� ���� ����!\n";
		TrainHoseOnFire();
		TurnOnHose();
	}

	// ��� �Լ�(�޼ҵ�)
protected:
	// ȣ�� �ѱ�(��)
	virtual void TurnOnHose() override
	{
		if (hoseTrainedOnFire)
		{
			FirefighterBase::TurnOnHose();
			std::cout << "���� ������ �ֽ��ϴ�.\n";
		}
		else
		{
			std::cout << "���� ������ ������ Ƣ�� �ֽ��ϴ�.\n";
		}
	}

	// ȣ�� ����
	virtual void TrainHoseOnFire() override
	{
		hoseTrainedOnFire = true;
		FirefighterBase::TrainHoseOnFire();
	}

private:
	// ȣ���� �ҿ� ��Ȯ�ϰ� ���صǴ��� ���θ� ����
	bool hoseTrainedOnFire = false;
};