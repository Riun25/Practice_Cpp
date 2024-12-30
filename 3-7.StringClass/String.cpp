#pragma once
#include "String.h"

String::String(const char* _string)
{
    // ���� Ȯ��
    mLength = _string == nullptr ? 1 : static_cast<int>(strlen(_string));

    // ���� �Ҵ� �� ���ڿ� ����
    mData = new char[mLength + 1];

    if (_string != nullptr)
    {
        strcpy_s(mData, mLength + 1, _string);
    }
}

String::String(const String& _other)
{
    mLength = _other.mLength;
    mData = new char[mLength + 1];
    strcpy_s(mData, mLength + 1, _other.mData);
}

String::~String()
{
    // �޸� ����
    delete[] mData;
    mData = nullptr;
}

String& String::operator=(const String& _other)
{
    // ������ data ����
    delete[] mData;

    mLength = _other.mLength;
    mData = new char[mLength + 1];
    strcpy_s(mData, mLength + 1, _other.mData);

    return *this;
}

bool String::operator==(const String& _other)
{
    // ���ڿ� �� C ���̺귯�� �Լ�
    return strcmp(mData, _other.mData) == 0;
}

bool String::operator!=(const String& _other)
{
    //return strcmp(mData, _other.mData) != 0;
    return !(*this == _other);
}

const int String::Length() const
{
    return mLength;
}

const char* String::Data() const
{
    return mData;
}

std::ostream& operator<<(std::ostream& _os, const String& _string)
{
    _os << _string.mData;
    return _os;
}
