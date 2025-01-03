#include<iostream>
#include <functional>

void (*functionPointer)();
std::function<void()> newFunctionPointer;
typedef void (*functionPointer2)();
using usingFP = void (*)();

int main()
{
	int count = 0;

	// �Լ� �����͸� ����� ���� ����
	functionPointer = []() {std::cout << "Hello\n"; };
	functionPointer;

	newFunctionPointer = functionPointer;
	newFunctionPointer();

	// �Լ� �����͸� ����� ���� ����2.
	functionPointer2 function2 = []() { std::cout << "Hello\n"; };
	function2();

	newFunctionPointer = function2;
	newFunctionPointer();

	// CPU �ڷḦ GPU���� �ѱ�� -> GPU�� �׸��� -> �����(Backbuffer).
	// Backbuffer: �̹���(Texture2D) -> �׸���


	std::cin.get();
}