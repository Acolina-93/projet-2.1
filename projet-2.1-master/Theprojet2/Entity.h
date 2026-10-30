#pragma once
class Entity
{

public:

	
	virtual int GetHP() const = 0;
	virtual int Maxhp() const = 0;
	virtual void deplacement() = 0;

	virtual ~Entity() = default;

};

