#pragma once

#include "FireFighterBase.h"

// 수습 소방관
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
		std::cout << name << " 소방관이 불을 끄고 있음!\n";
		TrainHoseOnFire();
		TurnOnHose();
	}

	// 멤버 함수(메소드)
protected:
	// 호스 켜기(물)
	virtual void TurnOnHose() override
	{
		if (hoseTrainedOnFire)
		{
			FirefighterBase::TurnOnHose();
			std::cout << "불이 꺼지고 있습니다.\n";
		}
		else
		{
			std::cout << "물이 엉뚱한 곳으로 튀고 있습니다.\n";
		}
	}

	// 호스 조준
	virtual void TrainHoseOnFire() override
	{
		hoseTrainedOnFire = true;
		FirefighterBase::TrainHoseOnFire();
	}

private:
	// 호스가 불에 정확하게 조준되는지 여부를 결정
	bool hoseTrainedOnFire = false;
};