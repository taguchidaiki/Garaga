#include "Player.h"


Player::Player()
{

}

Player::Player(Vector2 pos,std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	_pos = pos;
	Obj::Init(imageName, fileName, divSize, divCnt, id);
	Init();
	TRACE("%f,%f\n", pos.x,pos.y);
}


Player::~Player()
{
}

void Player::Draw(void)
{
	DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[_id], true);
}

void Player::Update(void)
{
	(*_input).Update();
	if ((*_input).state(INPUT_ID::LEFT).second)
	{
		_pos.x -= 2;
	}
	if ((*_input).state(INPUT_ID::RIGHT).second)
	{
		_pos.x += 2;
	}
	if ((*_input).state(INPUT_ID::UP).second)
	{
		_pos.y -= 2;
	}
	if ((*_input).state(INPUT_ID::DOWN).second)
	{
		_pos.y += 2;
	}
}

UNIT_ID Player::GetUnitType(void)
{
	return UNIT_ID::PLAYER;
}

bool Player::Init(void)
{
	AnimVector data;
	data.reserve(2);
	//data.push_back(std::make_pair(IMAGE_ID("ƒLƒƒƒ‰")[0], 30));
	//data.emplace_back(std::make_pair(IMAGE_ID("ƒLƒƒƒ‰")[0], 30));
	data.emplace_back(IMAGE_ID("kyara")[0], 30);
	data.emplace_back(IMAGE_ID("kyara")[1], 60);
	SetAnim(ANIM::NORMAL, data);

	data.reserve(1);
	data.emplace_back(IMAGE_ID("kyara")[0], 60);
	SetAnim(ANIM::EX, data);

	_input = std::make_unique<KeyState>();

	return true;
}
