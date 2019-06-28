#include "Enemy.h"


Enemy::Enemy()
{
	
}

Enemy::Enemy(Vector2 pos, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	_pos = pos;
	Obj::Init(imageName, fileName, divSize, divCnt, id);
	Init();
}


Enemy::~Enemy()
{
}

void Enemy::Draw(void)
{
	DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[_id], true);
}

void Enemy::Update(void)
{
}

UNIT_ID Enemy::GetUnitType(void)
{
	return UNIT_ID::ENEMY;
}

bool Enemy::Init(void)
{
	AnimVector data;
	data.reserve(2);
	//data.push_back(std::make_pair(IMAGE_ID("ƒLƒƒƒ‰")[0], 30));
	//data.emplace_back(std::make_pair(IMAGE_ID("ƒLƒƒƒ‰")[0], 30));
	data.emplace_back(IMAGE_ID("kyara")[_id], 30);
	data.emplace_back(IMAGE_ID("kyara")[_id + 1], 60);
	SetAnim(ANIM::NORMAL, data);
	return true;
}
