#include "DonationAccount.h"


DonationAccount::DonationAccount(int _id, char* _name, int _balance)
	:Account(_id, _name, _balance), mDonation(0)
{
	mAccountType = ACCOUNT_TYPE::DONATION;
	int tempDonation = static_cast<int>(_balance * 0.01f);
	mDonation += tempDonation;
	mBalance += (_balance - tempDonation);
}

DonationAccount::~DonationAccount()
{
}

void DonationAccount::SetBalance(int _money, bool _isIn)
{
	if (_money < 0)
	{
		std::cout << "�ݾ��� 0 �̻��� ���ڸ� �Է°����մϴ�.\n";
	}

	if (_isIn == true)
	{
		int tempDonation = static_cast<int>(_money * 0.01f);
		mDonation += tempDonation;
		mBalance += (_money - tempDonation);
	}
	else
	{
		if (mBalance - _money < 0)
		{
			std::cout << "�ܾ��� �����մϴ�.\n";
		}
		else
		{
			mBalance -= _money;
		}
	}
}

void DonationAccount::PrintAll()
{
	std::cout << "��ID: " << mID << " �� �̸�: " << mName << " �ܾ�: " << mBalance <<
		" ��αݾ� : " << mDonation << "\n";
}