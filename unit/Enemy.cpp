#include "Enemy.h"


Enemy::Enemy()
{
	
}

Enemy::Enemy(Vector2 pos, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	_pos = pos;
	Obj::Init(imageName, fileName, divSize, divCnt, id);
}


Enemy::~Enemy()
{
}

void Enemy::Draw(void)
{
	DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[_id], true);
}

UNIT_ID Enemy::GetUnitType(void)
{
	return UNIT_ID::ENEMY;
}

bool Enemy::Init(void)
{
	return true;
}
