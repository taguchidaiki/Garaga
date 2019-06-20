#include "Player.h"
#include "_DebugConOut.h"



Player::Player()
{

}

Player::Player(Vector2 pos)
{
	_pos = pos;
	TRACE("%f,%f", pos.x,pos.y);
}


Player::~Player()
{
}

void Player::Draw(void)
{
	DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[_id], true);
}
