#pragma once
#include "Obj.h"
class Player :
	public Obj
{
public:
	Player();
	Player(Vector2  pos);
	~Player();

	void Draw(void);


private:
	int image[100];
};

