#pragma once
#include "Obj.h"
class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 pos);
	~Enemy();

	//純粋仮想関数置き場
	void Draw(void) override;

	//関数置き場


private:
	
};

