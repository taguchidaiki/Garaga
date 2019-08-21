#include "Enemy.h"
#include "EnemyMove.h"
#include <stdlib.h>

Enemy::Enemy()
{
	
}

Enemy::Enemy(STATUS& state, Vector2D& endPos, int count)
{
	TRACE("エネミー生成\n");
	animCnt(count);
	Obj::Init(state);
	Init(endPos);
}


Enemy::~Enemy()
{
	TRACE("エネミー削除\n");
}

void Enemy::Draw(void)
{
	DrawRotaGraph(_state.trns.pos.x + _state.divSize.x / 2, _state.trns.pos.y + _state.divSize.y / 2,
		1.0, PI / 2,
		IMAGE_ID(_state.imageName)[_state.id], true);
}

void Enemy::Update(void)
{
	int oldOrder = _mOrder.second;
	if (DestroyProc())
	{
		return; 
	}

	/*if (std::get<0>(_mOrder.first) == MOV_PTN::LINE)
	{
		resetCnt();
	}*/

	_state.trns.mov = (*_moveCtl).Update(_state.trns,_mOrder);
	_state.trns.pos += _state.trns.mov;

	if (std::get<0>(_mOrder.first) != MOV_PTN::LATERAL)
	{
		_angle = atan2(_state.trns.mov.y, _state.trns.mov.x) + (90.0 * PI / 180);
	}
	else if (std::get<0>(_mOrder.first) == MOV_PTN::LATERAL)
	{
		_angle = atan2(_state.trns.mov.y, _state.trns.mov.x);
	}
	
	if (_mOrder.second < _moveVec.size() && oldOrder != _mOrder.second)
	{
		_mOrder.first = _moveVec[_mOrder.second];
	}

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

bool Enemy::Init(Vector2D& endPos)
{
	AnimVector data;
	data.reserve(2);
	//data.push_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	//data.emplace_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	data.emplace_back(IMAGE_ID("kyara")[_state.id], 30);
	data.emplace_back(IMAGE_ID("kyara")[_state.id + 1], 60);
	SetAnim(ANIM::NORMAL, data);
	
	data.reserve(6);
	for (int i = 0; i < 5; ++i)
	{
		data.emplace_back(IMAGE_ID("enblast")[i], 30 * (i + 1));
	}
	data.emplace_back(-1, 180);
	SetAnim(ANIM::BLAST, data);

	MoveInfo mData;
	mData = MoveInfo(MOV_PTN::SIGMOID,_state.trns.pos, {250,179}, 4.5);
	SetMove(mData);

	mData = MoveInfo(MOV_PTN::SIGMOID, { 250,179 }, {125, 358}, 4.5);
	SetMove(mData);

	mData = MoveInfo(MOV_PTN::CYCLONE, { 125,358 }, { 125, 269.5 }, 1.0);
	SetMove(mData);

	mData = MoveInfo(MOV_PTN::LINE, { 125,269.5 }, endPos, 0.0);
	SetMove(mData);

	mData = MoveInfo(MOV_PTN::LATERAL, { 0.5,0 }, { 1.5,0 }, 0.0);
	SetMove(mData);

	_mOrder.second = 0;
	_mOrder.first = _moveVec[_mOrder.second];

	_moveCtl = std::make_unique<EnemyMove>();

	return true;
}
