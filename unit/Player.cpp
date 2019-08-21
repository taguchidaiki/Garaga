#include "Player.h"
#include "Shot.h"


Player::Player()
{

}

Player::Player(Vector2D pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	_state.trns.pos = pos;
	_state.trns.speed = speed;
	Obj::Init(imageName, fileName, divSize, divCnt, id);
	Init();
	TRACE("プレイヤーー生成\n");
}

Player::Player(STATUS& state)
{
	TRACE("プレイヤーー生成\n");
	Obj::Init(state);
	Init();
}


Player::~Player()
{
	TRACE("プレイヤー削除\n");
}

void Player::Draw(void)
{
	//DrawGraph(_state.trns.pos.x, _state.trns.pos.y, IMAGE_ID(_state.imageName)[_state.id], true);

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

	/*DrawRotaGraph(_state.trns.pos.x + _state.divSize.x / 2, _state.trns.pos.y + _state.divSize.y / 2,
				  1.0, PI / 2 * 180,
				  _animMap[_animKey][_animFlame].first, true);*/
				  //DrawGraph(_pos.x, _pos.y, _animMap[_animKey][_animFlame].first, true);

				  //_dbgDrawBox(_state.trns.pos.x, _state.pos.trns.y, _state.trns.pos.x + _state.divSize.x, _state.trns.pos.y + _state.divSize.y, 0x00ff00, true);
	_dbgDrawPixel(_state.trns.pos.x, _state.trns.pos.y, 0xffffff);
	//_dbgDrawFormatString(_pos.x, _pos.y - 10,0xff0000, "%d,%d", _pos.x, _pos.y);

	for (auto itr : _shotList)
	{
		(*itr).Draw();
	}
}

void Player::Update(void)
{
	(*_input).Update();

	if (DestroyProc())
	{
		return;
	}

	if ((*_input).state(INPUT_ID::LEFT).second)
	{
		_state.trns.pos.x -= _state.trns.speed;
	}
	if ((*_input).state(INPUT_ID::RIGHT).second)
	{
		_state.trns.pos.x += _state.trns.speed;
	}

	if ((*_input).state(INPUT_ID::BTN_1).first && !(*_input).state(INPUT_ID::BTN_1).second)
	{
		AddShot();
	}

	for (auto itr: _shotList)
	{
		(*itr).Update();
	}

	auto itr = _shotList.begin();
	while (itr != _shotList.end())
	{
		if (!(*itr)->isAlive())
		{
			itr = _shotList.erase(itr);
		}
		else
		{
			itr++;
		}
	}
	/*if (rand() % 120 == 0)
	{
		_alive = false;
		animKey(ANIM::BLAST);
		resetCnt();
	}*/
}

UNIT_ID Player::GetUnitType(void)
{
	return UNIT_ID::PLAYER;
}

bool Player::Init(void)
{
	AnimVector data;
	data.reserve(2);
	//data.push_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	//data.emplace_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	data.emplace_back(IMAGE_ID("kyara")[0], 30);
	data.emplace_back(IMAGE_ID("kyara")[1], 60);
	SetAnim(ANIM::NORMAL, data);

	data.reserve(1);
	data.emplace_back(IMAGE_ID("kyara")[0], 60);
	SetAnim(ANIM::EX, data);

	data.reserve(5);
	for (int i = 0; i < 4; ++i)
	{
		data.emplace_back(IMAGE_ID("plblast")[i], 30 * (i + 1));
	}
	data.emplace_back(-1, 150);
	SetAnim(ANIM::BLAST, data);

	_input = std::make_unique<KeyState>();

	return true;
}

bool Player::AddShot()
{
	_shotList.emplace_back(new Shot(Vector2D(_state.trns.pos.x + _state.divSize.x / 2,_state.trns.pos.y)));
	return true;
}


