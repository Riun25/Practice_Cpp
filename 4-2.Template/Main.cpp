#include <iostream>

// int 타입 값 바꾸기
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

// 템플릿
template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	float number1 = 10.4f;
	float number2 = 20.5f;

	Swap<float>(number1, number2);

	std::cout << number1 << " : " << number2 << "\n";

	std::cin.get();
}