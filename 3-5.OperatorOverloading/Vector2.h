#pragma once
#include <iostream>


class Vector2
{
public:
	Vector2();
	Vector2(float _x = 0.0f, float _y = 0.0f);
	~Vector2();

	// 더하기
	Vector2 Add(const Vector2& _other);

	// 곱하기
	Vector2 Multply(const Vector2& _other);

	// 연산자 오버로딩
	// 특별한 함수
	Vector2 operator+(const Vector2& _other);

	Vector2 operator*(const Vector2& _other);
	float operator[](int _index);

	// 비교 연산자
	bool operator==(const Vector2& _other);
	bool operator!=(const Vector2& _other);

	Vector2 operator+=(const Vector2& _other);


	// Getter/Setter
	float GetX() const;
	float GetY() const;

	friend std::ostream& operator<<(std::ostream& _os, const Vector2 _vector)
	{
		_os << "(" << _vector.GetX() << "," << _vector.GetY() << ")\n";
		return _os;
	}

private:
	float mX;
	float mY;
};

