#pragma once

#include <string>
#include <iostream>
#include "FireTruck.h"
#include "INamedPerson.h"

class FirefighterBase :public INamedPerson
{
public:
	FirefighterBase(const std::string& name)
		: name(name)
	{
	}

	virtual ~FirefighterBase()
	{
	}

	// 불끄기(ExtinguishFire)
	// 순수 가상 함수
	virtual void ExtinguishFire() = 0;
	virtual void TrainHoseOnFire() {};
	virtual void TurnOnHose(){};

	// 운전 (Drive)
	void Drive(class FireTruck* truckToDrive, const class Point& position)
	{
		// 운전자 확인
		if (truckToDrive->GetDriver() != this)
		{
			return;
		}

		// 이동
		truckToDrive->Drive(truckToDrive, position);
	}

	// Getter/Setter
	virtual std::string GetName() const override { return name; }
	void SetName(const std::string& name)
	{
		this->name = name;
	}


protected:
	std::string name;
};
