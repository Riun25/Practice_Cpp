#include <iostream>

// 함수 선언
void FirstFuction();
void SecondFuction();
void ThirdFuction();

void ThirdFuction()
{
	std::cout << "Entering ThirdFuction()" << std::endl;
	SecondFuction();
	std::cout << "Exiting ThirdFuction()" << std::endl;
}

void SecondFuction()
{
	std::cout << "Entering SecondFuction()" << std::endl;
	FirstFuction();
	std::cout << "Exiting SecondFuction()" << std::endl;
}

void FirstFuction()
{
	std::cout << "Entering FirstFuction()" << std::endl;
	std::cout << "Exiting FirstFuction()" << std::endl;
}

int main()
{
	ThirdFuction();

	return 0;
}