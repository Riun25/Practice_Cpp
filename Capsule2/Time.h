#pragma once
#include <iostream>
class Time
{
public:

	Time(int _hour)
		:mHour(_hour)
	{
	}

	Time(int _hour, int _min)
		:mHour(_hour), mMin(_min)
	{
	}

	Time(int _hour, int _min, int _sec)
		:mHour(_hour), mMin(_min), mSec(_sec)
	{
	}

	void ShowTime()
	{
		std::cout << "[" << mHour << "시 " << mMin << "분 " << mSec << "초]\n";
	}

	void ShowTimeInSeconds()
	{
		std::cout << mHour * 3600 + mMin * 60 + mSec << "초\n";
	}

private:
	int mHour = 0;
	int mMin = 0;
	int mSec = 0;
};
