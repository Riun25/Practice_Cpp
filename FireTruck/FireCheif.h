#pragma once

#include "FireFighterBase.h"

class FireChief : public FirefighterBase
{
public:
	FireChief(const std::string& name, FirefighterBase* numberOne = nullptr)
		: FirefighterBase(name), numberOne(numberOne)
	{

	}

	void TellFirefighterToExtinguishFire(FirefighterBase* colleague)
	{
		colleague->ExtinguishFire();
	}

	// ÀçÁ¤ÀÇ
	virtual void ExtinguishFire() override
	{
		if (numberOne)
		{
			TellFirefighterToExtinguishFire(numberOne);
		}
	}

	const FirefighterBase* GetNumberOne() const { return numberOne; }
	void SetNumberOne(FirefighterBase* numberone) { this->numberOne = numberone; }

private:
	FirefighterBase* numberOne = nullptr;
};