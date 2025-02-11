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

	// �Ҳ���(ExtinguishFire)
	// ���� ���� �Լ�
	virtual void ExtinguishFire() = 0;
	virtual void TrainHoseOnFire() {};
	virtual void TurnOnHose(){};

	// ���� (Drive)
	void Drive(class FireTruck* truckToDrive, const class Point& position)
	{
		// ������ Ȯ��
		if (truckToDrive->GetDriver() != this)
		{
			return;
		}

		// �̵�
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
