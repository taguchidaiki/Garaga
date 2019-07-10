#include "Enemy.h"
#include <stdlib.h>

Enemy::Enemy()
{
	
}

Enemy::Enemy(Vector2 pos, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	TRACE("エネミー生成\n");
	_pos = pos;
	Obj::Init(imageName, fileName, divSize, divCnt, id);
	Init();
}


Enemy::~Enemy()
{
	TRACE("エネミー削除\n");
}

void Enemy::Draw(void)
{
	DrawRotaGraph(_pos.x + _divSize.x / 2, _pos.y + _divSize.y / 2,
		1.0, PI / 2,
		IMAGE_ID(_imageName)[_id], true);
}

void Enemy::Update(void)
{
	if (DestroyProc())
	{
		return; 
	}

	if (rand() % 1200 == 0)
	{
		_alive = false;
		animKey(ANIM::BLAST);
		resetCnt();
	}
	
	if (isAnimEnd())
	{
		_death = true;
	}
	
}

UNIT_ID Enemy::GetUnitType(void)
{
	return UNIT_ID::ENEMY;
}

bool Enemy::Init(void)
{
	AnimVector data;
	data.reserve(2);
	//data.push_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	//data.emplace_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	data.emplace_back(IMAGE_ID("kyara")[_id], 30);
	data.emplace_back(IMAGE_ID("kyara")[_id + 1], 60);
	SetAnim(ANIM::NORMAL, data);
	data.clear();
	data.reserve(6);
	for (int i = 0; i < 5; ++i)
	{
		data.emplace_back(IMAGE_ID("enblast")[i], 30 * (i + 1));
	}
	data.emplace_back(-1, 180);
	SetAnim(ANIM::BLAST, data);
	return true;
}
