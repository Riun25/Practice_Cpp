#include <iostream>

// int Ÿ�� �� �ٲٱ�
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

// ���ø�
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