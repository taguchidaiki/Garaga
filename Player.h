#pragma once
#include "Obj.h"
class Player :
	public Obj
{
public:
	Player();
	Player(Vector2  pos);
	~Player();

	//�������z�֐��u����
	void Draw(void) override;

	//�֐��u����



private:

};

