#pragma once
#include <iostream>
#include <string>

class NameCard
{
public:
	NameCard(const std::string& _name, const std::string& _num, const std::string& _adr, const std::string& _job)
		:mName(_name), mNum(_num), mAdr(_adr), mJob(_job)
	{ }

	void ShowData()
	{
		std::cout << "이    름 : " << mName <<
			"\n전화번호 : " << mNum <<
			"\n주    소 : " << mAdr <<
			"\n직    급 : " << mJob << "\n";
	}

private:
	std::string mName;
	std::string mNum;
	std::string mAdr;
	std::string mJob;
};