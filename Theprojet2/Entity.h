#pragma once
class Entity
{

public:

	
	virtual int GetHP() const = 0;
	virtual int Maxhp() const = 0;
	virtual void Move(Vector2 dir) = 0;

	virtual ~Entity() = default;

};

