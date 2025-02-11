#pragma once

#include <vector>
#include <string>
#include "INamedPerson.h"
#include <iostream>

class FireStation
{

public:
	// ��� �Լ�
	void ClockIn(INamedPerson* staffMember)
	{
		// �̹� ����ߴ��� Ȯ��
		bool contains = false;
		for (INamedPerson* staff : clockedInStaff)
		{
			if (staff == staffMember)
			{
				contains = true;
				break;
			}
		}

		//
		if (!contains)
		{
			clockedInStaff.emplace_back(staffMember);
		}
	}

	// �⼮ Ȯ�� �Լ�
	void RollCall()
	{
		for (INamedPerson* staff : clockedInStaff)
		{
			std::cout << staff->GetName() << "\n";
		}
	}

private:
	// ���� ���� ����
	std::vector<INamedPerson*> clockedInStaff;
};