#include "Pos.h"
#include <cmath>

const Vector2 Vector2::up = { 0.0f,-1.0f };
const Vector2 Vector2::down = { 0.0f,1.0f };
const Vector2 Vector2::right = { 1.0f,0.0f };
const Vector2 Vector2::left = { -1.0f,0.0f };

Vector2 Vector2::operator +(const Vector2& other)const
{
	return Vector2(x + other.x, y + other.y);
}
Vector2& Vector2::operator +=(const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}
Vector2 Vector2::operator *(float scalar)const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2& Vector2::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2 Vector2::operator-() const
{
	return Vector2{ -x, -y };
}

float Vector2::magnitude() const
{
	return sqrt(x * x + y * y);
}
