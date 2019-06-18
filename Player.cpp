#include "Player.h"



Player::Player()
{
	//LoadDivGraph("image/char.png", 10 * 10, 10, 10, 30, 32, image, true);

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
