#pragma once
#include "Obj.h"
class Player :
	public Obj
{
public:
	Player();
	Player(Vector2  pos);
	~Player();

	//純粋仮想関数置き場
	void Draw(void) override;

	//関数置き場



private:

};

