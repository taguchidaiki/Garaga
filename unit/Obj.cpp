#include "Obj.h"


Obj::Obj()
{
}


Obj::~Obj()
{
}

void Obj::Draw(void)
{
	DrawRotaGraph(_state.trns.pos.x + _state.divSize.x / 2, _state.trns.pos.y + _state.divSize.y / 2,
				  1.0, PI / 2 * 180,
				  _animMap[_animKey][_animFlame].first, true);
	//DrawGraph(_pos.x, _pos.y, _animMap[_animKey][_animFlame].first, true);
	
	//_dbgDrawBox(_state.trns.pos.x, _state.pos.trns.y, _state.trns.pos.x + _state.divSize.x, _state.trns.pos.y + _state.divSize.y, 0x00ff00, true);
	_dbgDrawPixel(_state.trns.pos.x, _state.trns.pos.y, 0xffffff);
	//_dbgDrawFormatString(_pos.x, _pos.y - 10,0xff0000, "%d,%d", _pos.x, _pos.y);

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

void Obj::Init(std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	ImageMng::GetInstance().GetID(imageName, fileName, divSize, divCnt);
	/*_state.imageName = imageName;
	_state.divSize = divSize;
	_state.divCnt = divCnt;
	_state.id = id;*/
	_alive = true;
	_death = false;
}

void Obj::Init(STATUS state)
{
	ImageMng::GetInstance().GetID(state.imageName, state.fileName, state.divSize, state.divCnt);
	_state = state;
	_alive = true;
	_death = false;
}

void Obj::Draw(int id)
{
	DrawRotaGraph(_state.trns.pos.x + _state.divSize.x / 2, _state.trns.pos.y + _state.divSize.y / 2,
		1.0, PI / 2 * 180,
		IMAGE_ID(_state.imageName)[id], true);
	//DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[id], true);
}

template<typename T>
const Vector2Temple<T> Obj::pos(void) const
{
	return _state.pos;
}

template<typename T>
bool Obj::pos(const Vector2Temple<T> pos)
{
	_state.pos = pos;
	return true;
}

const ANIM Obj::animKey(void) const
{
	return _animKey;
}

bool Obj::animKey(const ANIM _animKey)
{
	if ((_animKey < ANIM::NORMAL) || (ANIM::MAX < _animKey))
	{
		return false;
	}

	resetCnt();

	this->_animKey = _animKey;
	return true;
}

bool Obj::resetCnt(void)
{
	_animCnt = 0;
	return true;
}

bool Obj::isAlive(void)
{
	return _alive;
}

bool Obj::isDeath(void)
{
	return _death;
}

bool Obj::isAnimEnd(void)
{
	//findチェックとsizeのチェックを忘れずに

	if (_animMap[_animKey][_animFlame].first == -1)
	{
		return true;
	}
	return false;
}

bool Obj::SetAnim(const ANIM key, AnimVector& data)
{
	/*if (_animMap.find(key) == _animMap.end())
	{
	_animMap[key] = data;
	return true;
	}
	return false;*/
	return _animMap.try_emplace(key, std::move(data)).second;
}

bool Obj::DestroyProc(void)
{
	if (_alive)
	{
		return false;
	}

	if (isAnimEnd())
	{
		_death = true;
	}

	return true;
}
