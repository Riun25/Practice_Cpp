#include "Bank.h"


class Bank;

int main()
{
	Bank bank = Bank();

	char selectNum[2] = {};
	char name[100] = {};
	int money = 0;
	int accountID = 20241224;

	while (*selectNum != 'q' && *selectNum != 'Q')
	{
		std::cout << "\n���Ͻô� �۾��� �������ּ���.(Q : ����)\n\
	1. ���� ���� 2. �Ա� 3. ��� 4. ��ü �� �ܾ� Ȯ��\n\n";
		std::cin >> selectNum;

		if (selectNum[1] != '\0')
		{
			std::cout << "1~4������ ���ڸ� �Է��ϰų� Q�� �Է��ϼ���.\n";
			continue;
		}

		if (*selectNum > '0' && *selectNum < '5')
		{
			switch (*selectNum)
			{
			case '1':
			{
				std::cout << "���� ������ �����߽��ϴ�. �̸��� �Է����ּ���.\n";
				std::cin >> name;
				std::cout << "�Ա��� �ݾ��� �Է����ּ���.\n";
				std::cin >> money;
				std::cout << "� ���¸� �����Ͻðڽ��ϱ�?\n1. �Ϲ� ���� 2. �ſ� ��� ���� 3. ��� ����\n";
				std::cin >> selectNum;
				if (*selectNum > '0' && *selectNum < '3')
				{

				}
				bank.CreateAccount(*selectNum, accountID, name, money);
				++accountID;
			}
			break;
			case '2':
			{
				std::cout << "�Ա��� �����߽��ϴ�. �̸��� �Է����ּ���.\n";
				std::cin >> name;
				std::cout << "�Ա��� �ݾ��� �Է����ּ���.\n";
				std::cin >> money;
				bank.Deposit(name, money);
			}
			break;
			case '3':
			{
				std::cout << "����� �����߽��ϴ�. �̸��� �Է����ּ���.\n";
				std::cin >> name;
				std::cout << "����� �ݾ��� �Է����ּ���.\n";
				std::cin >> money;
				bank.Withdraw(name, money);
			}
			break;
			case '4':
			{
				std::cout << "��ü ���� �ܾ��� Ȯ���մϴ�.\n";
				bank.Inquire();
			}
			break;
			default:
				break;
			}
		}
	}

	std::cout << "�̿��� �ּż� �����մϴ�.\n";


	return 0;
}