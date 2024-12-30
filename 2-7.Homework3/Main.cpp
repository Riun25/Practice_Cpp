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
		std::cout << "\n원하시는 작업을 선택해주세요.(Q : 종료)\n\
	1. 계좌 개설 2. 입금 3. 출금 4. 전체 고객 잔액 확인\n\n";
		std::cin >> selectNum;

		if (selectNum[1] != '\0')
		{
			std::cout << "1~4까지의 숫자를 입력하거나 Q만 입력하세요.\n";
			continue;
		}

		if (*selectNum > '0' && *selectNum < '5')
		{
			switch (*selectNum)
			{
			case '1':
			{
				std::cout << "계좌 개설을 선택했습니다. 이름을 입력해주세요.\n";
				std::cin >> name;
				std::cout << "입금할 금액을 입력해주세요.\n";
				std::cin >> money;
				std::cout << "어떤 계좌를 개설하시겠습니까?\n1. 일반 계좌 2. 신용 우대 계좌 3. 기부 계좌\n";
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
				std::cout << "입금을 선택했습니다. 이름을 입력해주세요.\n";
				std::cin >> name;
				std::cout << "입금할 금액을 입력해주세요.\n";
				std::cin >> money;
				bank.Deposit(name, money);
			}
			break;
			case '3':
			{
				std::cout << "출금을 선택했습니다. 이름을 입력해주세요.\n";
				std::cin >> name;
				std::cout << "출금할 금액을 입력해주세요.\n";
				std::cin >> money;
				bank.Withdraw(name, money);
			}
			break;
			case '4':
			{
				std::cout << "전체 고객의 잔액을 확인합니다.\n";
				bank.Inquire();
			}
			break;
			default:
				break;
			}
		}
	}

	std::cout << "이용해 주셔서 감사합니다.\n";


	return 0;
}