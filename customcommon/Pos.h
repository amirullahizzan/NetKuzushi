#pragma once
//CHANGE TO VECTOR2.h instead of Pos.h
struct Vector2
{
	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2(float _x, float _y) : x(_x), y(_y)
	{
	}
	float x;
	float y;

	Vector2 operator +(const Vector2& other)const;
	Vector2& operator +=(const Vector2& other);
	Vector2 operator *(float scalar)const;
	Vector2& operator *=(float scalar);
	Vector2 operator-() const;
	Vector2 operator-(const Vector2& other) const 
	{
		return Vector2(x - other.x, y - other.y);
	}
	float magnitude() const;
	

	// Normalize the vector
	Vector2 normalize() const {
		float mag = magnitude();
		return Vector2(x / mag, y / mag);
	}

	float dot(const Vector2& other) const {
		return x * other.x + y * other.y;
	}

	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 right;
	static const Vector2 left;
};
