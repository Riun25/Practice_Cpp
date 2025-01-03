#include<iostream>

int main()
{
	// Lambda �Լ�(���� �Լ�)
	//[]() {std::cout << "Hello, Lambda!\n"; }();
	auto function = []() {std::cout << "Hello, Lambda!\n"; };

	// ���� �� ����
	auto functionSetReturn = []() -> float
		{
			std::cout << "Hello, Lambda2!\n";
			return 2025;
		};

	// ĸó
	int count = 0;
	auto functionCapture = [&count]()
		{
			count++;
		};

	// �Ű�����
	int count2 = 0;
	auto function4 = [](int& count)
		{
			count++;
		};

	// ȣ��
	function();
	//auto returnValue = function2();

	functionCapture();
	functionCapture();
	functionCapture();
	functionCapture();
	std::cout << "Count: " << count << "\n";

	function4(count2);
	function4(count2);
	function4(count2);
	function4(count2);
	std::cout << "Count2: " << count2 << "\n";

	std::cin.get();
}