#pragma once
#include "Obj.h"
class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 pos);
	~Enemy();

	//�������z�֐��u����
	void Draw(void) override;

	//�֐��u����


private:
	
};

