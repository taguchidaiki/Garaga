#include "Enemy.h"
#include <stdlib.h>

Enemy::Enemy()
{
	
}

Enemy::Enemy(Vector2 pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	TRACE("エネミー生成\n");
	_status.pos = pos;
	_status.speed = speed;
	_goal = { 0,0 };
	Obj::Init(imageName, fileName, divSize, divCnt, id);
	Init();
}

Enemy::Enemy(STATUS status)
{
	_status = status;
	
	Init();
}


Enemy::~Enemy()
{
	TRACE("エネミー削除\n");
}

void Enemy::Draw(void)
{
	DrawRotaGraph(_status.pos.x + _status.divSize.x / 2, _status.pos.y + _status.divSize.y / 2,
		1.0, PI / 2,
		IMAGE_ID(_status.imageName)[_status.id], true);
}

void Enemy::Update(void)
{
	if (DestroyProc())
	{
		return; 
	}

	(this->*_actTbl[static_cast<int>(_actMode)])();
	
	/*if (rand() % 1200 == 0)
	{
		_alive = false;
		animKey(ANIM::BLAST);
	}*/
	
}

UNIT_ID Enemy::GetUnitType(void)
{
	return UNIT_ID::ENEMY;
}

int Enemy::Idle(void)
{
	return 0;
}

int Enemy::Move(void)
{
	//直線移動の実装
	//ゴール地点から現在地点までの方向を正規化してあげて
	//posにスピード*方向を加算すればその方向に向かう
	_status.mov = Normalize(Vector2(_goal - _status.pos));

	_status.pos += _status.pos * _status.speed;

	return 0;
}

bool Enemy::Init(void)
{
	AnimVector data;
	data.reserve(2);
	//data.push_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	//data.emplace_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	data.emplace_back(IMAGE_ID("kyara")[_status.id], 30);
	data.emplace_back(IMAGE_ID("kyara")[_status.id + 1], 60);
	SetAnim(ANIM::NORMAL, data);
	//data.clear();
	
	data.reserve(6);
	for (int i = 0; i < 5; ++i)
	{
		data.emplace_back(IMAGE_ID("enblast")[i], 30 * (i + 1));
	}
	data.emplace_back(-1, 180);
	SetAnim(ANIM::BLAST, data);

	_actTbl[static_cast<int>(ENE_ACT::IDLE)] = &Enemy::Idle;
	_actTbl[static_cast<int>(ENE_ACT::MOVE)] = &Enemy::Move;

	_actMode = ENE_ACT::MOVE;
	return true;
}
