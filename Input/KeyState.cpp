#include "KeyState.h"



KeyState::KeyState()
{
	_buf[KEY_INPUT_LEFT]	= INPUT_ID::LEFT;
	_buf[KEY_INPUT_RIGHT]	= INPUT_ID::RIGHT;
	_buf[KEY_INPUT_UP]		= INPUT_ID::UP;
	_buf[KEY_INPUT_DOWN]	= INPUT_ID::DOWN;
	_buf[KEY_INPUT_A]		= INPUT_ID::BTN_1;
	_buf[KEY_INPUT_S]		= INPUT_ID::BTN_2;
	_buf[KEY_INPUT_Z]		= INPUT_ID::BTN_3;
	_buf[KEY_INPUT_X]		= INPUT_ID::BTN_4;
}


KeyState::~KeyState()
{
}

void KeyState::Update(void)
{
	GetHitKeyStateAll(_buf);

	for (auto& keyData : state())
	{
		int i = 0;
	}
}

void KeyState::GetState(void)
{

}
