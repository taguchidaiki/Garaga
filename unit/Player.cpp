#include "Player.h"


Player::Player()
{

}

Player::Player(Vector2 pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	_state.pos = pos;
	_state.speed = speed;
	Obj::Init(imageName, fileName, divSize, divCnt, id);
	Init();
	TRACE("プレイヤーー生成\n");
}

Player::Player(STATUS state)
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
	DrawGraph(_state.pos.x, _state.pos.y, IMAGE_ID(_state.imageName)[_state.id], true);
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
		_state.pos.x -= 2;
	}
	if ((*_input).state(INPUT_ID::RIGHT).second)
	{
		_state.pos.x += 2;
	}
	if ((*_input).state(INPUT_ID::UP).second)
	{
		_state.pos.y -= 2;
	}
	if ((*_input).state(INPUT_ID::DOWN).second)
	{
		_state.pos.y += 2;
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
