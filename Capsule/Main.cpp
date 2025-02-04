#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main()
{
	Rectangle rectangle = Rectangle(3.f, 4.f);    // ����, ���� ���� ����.
	std::cout << "����: " << rectangle.GetArea() << "\n";
	std::cout << "�ѷ�: " << rectangle.GetSize() << "\n";

	Circle circle = Circle(5.f);                 // ���� ������ ����.
	std::cout << "����: " << circle.GetArea() << "\n";
	std::cout << "�ѷ�: " << circle.GetSize() << "\n";
}

/// ��� ���.
//����: 12
//�ѷ� : 14
//���� : 78.5
//�ѷ� : 31.4