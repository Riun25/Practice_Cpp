#pragma once

#include <string>

// �߻� Ŭ���� (�������̽�)
class INamedPerson
{
public:
	// ���� ���� �Լ�
	virtual std::string GetName() const = 0;
};