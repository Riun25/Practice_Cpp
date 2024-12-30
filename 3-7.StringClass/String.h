#pragma once
#include <iostream>

// ���� �����غ��� ���ڿ� Ŭ����
// MFC - UI
class String
{
public:
	// �Ϲ� ������
	String(const char* _string = nullptr);

	// ���� ������
	String(const String& _other);

	// �Ҹ���
	~String();

	// ������ �����ε�
	friend std::ostream& operator<<(std::ostream& _os, const String& _string);

	// ���� ������
	String& operator=(const String& _other);

	// �� ������
	bool operator==(const String& _other);
	bool operator!=(const String& _other);

	// Getter
	const int Length() const;
	const char* Data() const;

private:
	int mLength;	// ���ڿ� ����
	char* mData;	// ���ڿ� �����ϴ� ����(�����/�����̳�/Container)
};

