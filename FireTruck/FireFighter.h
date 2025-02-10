#pragma once

#include <string>
#include <iostream>
#include "FireTruck.h"

class Firefighter
{
public:
	Firefighter(const std::string& name)
		: name(name)
	{
	}

	virtual ~Firefighter()
	{
	}

	// �Ҳ���(ExtinguishFire)
	virtual void ExtinguishFire()
	{
		std::cout << name << " �ҹ���� ���� ���� ����!\n";
	}

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
	const std::string GetName() const { return name; }
	void SetName(const std::string& name)
	{
		this->name = name;
	}

private:
	std::string name;
};
