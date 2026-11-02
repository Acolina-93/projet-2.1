#pragma once
class Vector2
{
public:
	int x;
	int y;
	Vector2 operator+(const Vector2& other) const;
	Vector2& operator=(const Vector2& other);
	bool operator==(const Vector2& other) const;

	Vector2(int x, int y) : x(x), y(y) {}
};

