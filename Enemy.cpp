#include "Enemy.h"


Enemy::Enemy()
{
	
}

Enemy::Enemy(Vector2 pos)
{
	_pos = pos;
}


Enemy::~Enemy()
{
}

void Enemy::Draw(void)
{
	DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[_id], true);
}
