#include "KeyState.h"



KeyState::KeyState()
{
	/*for (auto key : INPUT_ID())
	{
		_keyMap.emplace_back(key);
	}*/
}


KeyState::~KeyState()
{
}

void KeyState::Update(void)
{
	SetOld();
	GetHitKeyStateAll(_buf);
	for (auto key : INPUT_ID())
	{
		state(key, _buf[_keyTbl[static_cast<int>(key)]]);

		//ÅõÅõ[] = _buf[ëŒâûÉLÅ[]
		//std::vector<char>
	}
	state(INPUT_ID::LEFT, _buf[KEY_INPUT_LEFT]);
	state(INPUT_ID::RIGHT, _buf[KEY_INPUT_RIGHT]);
	state(INPUT_ID::UP, _buf[KEY_INPUT_UP]);
	state(INPUT_ID::DOWN, _buf[KEY_INPUT_DOWN]);
}
