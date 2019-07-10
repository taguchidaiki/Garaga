#include "Obj.h"


Obj::Obj()
{
}


Obj::~Obj()
{
}

void Obj::Draw(void)
{
	DrawRotaGraph(_pos.x + _divSize.x / 2, _pos.y + _divSize.y / 2,
				  1.0, PI / 2 * 180,
				  _animMap[_animKey][_animFlame].first, true);
	//DrawGraph(_pos.x, _pos.y, _animMap[_animKey][_animFlame].first, true);
	
	_dbgDrawBox(_pos.x, _pos.y, _pos.x + _divSize.x, _pos.y + _divSize.y, 0x00ff00, true);
	//_dbgDrawFormatString(_pos.x, _pos.y - 10,0xff0000, "%d,%d", _pos.x, _pos.y);

	if (_animCnt >= _animMap[_animKey][_animFlame].second)
	{
		_animFlame++;
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
	_imageName = imageName;
	_divSize = divSize;
	_divCnt = divCnt;
	_id = id;
	_alive = true;
	_death = false;
}

void Obj::Draw(int id)
{
	DrawRotaGraph(_pos.x + _divSize.x / 2, _pos.y + _divSize.y / 2,
		1.0, PI / 2 * 180,
		IMAGE_ID(_imageName)[id], true);
	//DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[id], true);
}

const Vector2 Obj::pos(void) const
{
	return _pos;
}

bool Obj::pos(const Vector2 pos)
{
	_pos = pos;
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

	if (!_death)
	{
		return false;
	}

	return true;
}
