#pragma once

class Vector2
{
public:
	int x;
	int y;

	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	Vector2(int x, int y) : x(x), y(y)
	{
	}
};
