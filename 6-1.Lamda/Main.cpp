#include<iostream>

int main()
{
	// Lambda 함수(무명 함수)
	//[]() {std::cout << "Hello, Lambda!\n"; }();
	auto function = []() {std::cout << "Hello, Lambda!\n"; };

	// 리턴 값 설정
	auto functionSetReturn = []() -> float
		{
			std::cout << "Hello, Lambda2!\n";
			return 2025;
		};

	// 캡처
	int count = 0;
	auto functionCapture = [&count]()
		{
			count++;
		};

	// 매개변수
	int count2 = 0;
	auto function4 = [](int& count)
		{
			count++;
		};

	// 호출
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