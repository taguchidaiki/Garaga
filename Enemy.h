#pragma once
#include "Obj.h"
class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 pos);
	~Enemy();

	void Draw(void);


private:
	int image[100];
};

