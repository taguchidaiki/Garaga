#include "Player.h"



Player::Player()
{

}

Player::Player(Vector2 pos)
{
	_pos = pos;
}


Player::~Player()
{
}

void Player::Draw(void)
{
	DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[_id], true);
}
