#include "Shot.h"

Shot::Shot(Vector2D pos)
{
	TRACE("ショット生成\n");
	_state.trns.pos = pos;
	_state.trns.mov = {0,-1};
	_state.trns.speed = 5;
	_state.id = 0;
	_state.imageName = "shot";
	_state.fileName = "image/shot.png";
	_state.divSize = {3,8};
	_state.divCnt = {2,1};
	Obj::Init(_state.imageName, _state.fileName, _state.divSize, _state.divCnt, _state.id);
}


Shot::~Shot()
{
	TRACE("ショット削除\n");
}

void Shot::Draw(void)
{
	if (_animMap.size() == 0)
	{
		DrawRotaGraph(_state.trns.pos.x + _state.divSize.x / 2, _state.trns.pos.y + _state.divSize.y / 2,
			1.0, _angle,
			IMAGE_ID(_state.imageName)[_state.id], true);
	}
	else
	{
		DrawRotaGraph(_state.trns.pos.x + _state.divSize.x / 2, _state.trns.pos.y + _state.divSize.y / 2,
			1.0, _angle,
			_animMap[_animKey][_animFlame].first, true);

		if (_animCnt >= _animMap[_animKey][_animFlame].second)
		{
			if (_animMap[_animKey][_animFlame].first != -1)
			{
				_animFlame++;
			}

			if (_animFlame >= _animMap[_animKey].size())
			{
				_animCnt = 0;
				_animFlame = 0;
			}
		}
		_animCnt++;
	}
}

void Shot::Update(void)
{
	_state.trns.pos += _state.trns.mov * _state.trns.speed;
	_angle = atan2(_state.trns.mov.y, _state.trns.mov.x) + (90.0 * PI / 180);

	if (_state.trns.pos.y <= 0)
	{
		_death = true;
	}
}

UNIT_ID Shot::GetUnitType(void)
{
	return UNIT_ID::SHOT;
}
