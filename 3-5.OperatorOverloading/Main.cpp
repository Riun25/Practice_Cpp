#include "Vector2.h"

// ������ �����ε�
// ���� �����Ͼ
//std::ostream& operator<<(std::ostream& _os, const Vector2 _vector)
//{
//	_os << "(" << _vector.GetX() << "," << _vector.GetY() << ")\n";
//	return _os;
//}


int main()
{
	//Vector2 position(4.0f, 4.0f);
	//Vector2 speed(0.5f, 0.5f);

	//// Vector2 result = position.Multply(speed);
	//Vector2 result = position * speed;
	//// Vector2 result = position.operator*(speed);
	//result[0];

	//std::cout << position << "\n";
	//std::cout << speed << "\n";
	//std::cout << result << "\n";


	Vector2 position1 = Vector2(3.0f, 1.0f);
	Vector2 position2 = Vector2(3.0f, 1.0f);
	Vector2 position3 = Vector2(5.0f, 10.0f);

	if (position1 == position2)
	{
		std::cout << "position1�� position2�� ����.\n";
	}
	else
	{
		std::cout << "position1�� position2�� �ٸ���.\n";
	}

	if (position2 != position3)
	{
		std::cout << "position2�� position3�� �ٸ���.\n";
	}
	else
	{
		std::cout << "position2�� position3�� ����.\n";
	}

	Vector2 position = Vector2(4.0f, 3.0f);
	Vector2 direction = Vector2(1.0f, 1.0f);
	position += direction;
	std::cout << position << "\n";

	std::cin.get();
}