#include<iostream>
#include <functional>

void (*functionPointer)();
std::function<void()> newFunctionPointer;
typedef void (*functionPointer2)();
using usingFP = void (*)();

int main()
{
	int count = 0;

	// 함수 포인터를 사용한 람다 저장
	functionPointer = []() {std::cout << "Hello\n"; };
	functionPointer;

	newFunctionPointer = functionPointer;
	newFunctionPointer();

	// 함수 포인터를 사용한 람다 저장2.
	functionPointer2 function2 = []() { std::cout << "Hello\n"; };
	function2();

	newFunctionPointer = function2;
	newFunctionPointer();

	// CPU 자료를 GPU한테 넘기고 -> GPU가 그리기 -> 백버퍼(Backbuffer).
	// Backbuffer: 이미지(Texture2D) -> 그리기


	std::cin.get();
}