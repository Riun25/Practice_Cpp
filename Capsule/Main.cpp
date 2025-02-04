#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main()
{
	Rectangle rectangle = Rectangle(3.f, 4.f);    // 가로, 세로 길이 전달.
	std::cout << "면적: " << rectangle.GetArea() << "\n";
	std::cout << "둘레: " << rectangle.GetSize() << "\n";

	Circle circle = Circle(5.f);                 // 원의 반지름 전달.
	std::cout << "면적: " << circle.GetArea() << "\n";
	std::cout << "둘레: " << circle.GetSize() << "\n";
}

/// 출력 결과.
//면적: 12
//둘레 : 14
//면적 : 78.5
//둘레 : 31.4