#pragma once

#include "FireFighter.h"

class FireChief : public Firefighter
{
public:
	FireChief(const std::string& name, Firefighter* numberOne = nullptr)
		: Firefighter(name), numberOne(numberOne)
	{

	}

	void TellFirefighterToExtinguishFire(Firefighter* colleague)
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

	const Firefighter* GetNumberOne() const { return numberOne; }
	void SetNumberOne(Firefighter* numberone) { this->numberOne = numberone; }

private:
	Firefighter* numberOne = nullptr;
};