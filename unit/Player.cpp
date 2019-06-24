#include "Player.h"
#include "_DebugConOut.h"



Player::Player()
{

}

Player::Player(Vector2 pos,std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	_pos = pos;
	Init(imageName, fileName, divSize, divCnt, id);
	TRACE("%f,%f\n", pos.x,pos.y);
}


Player::~Player()
{
}

void Player::Draw(void)
{
	DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[_id], true);
}

UNIT_ID Player::GetUnitType(void)
{
	return UNIT_ID::PLAYER;
}
