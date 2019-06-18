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
	DrawGraph(300, 200, image[0], true);
}
