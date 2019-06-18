#include "Enemy.h"


Enemy::Enemy()
{
	//LoadDivGraph("image/char.png", 10 * 10, 10, 10, 30, 32, image, true);
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
