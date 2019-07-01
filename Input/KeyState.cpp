#include "KeyState.h"

KeyState::KeyState()
{
	_keyCon.reserve(static_cast<size_t>(end(INPUT_ID())));
	for (auto key : _keyTbl)
	{
		_keyCon.emplace_back(key);
	}
	func = &KeyState::RefKeyData;
}


KeyState::~KeyState()
{
}

void KeyState::Update(void)
{
	SetOld();
	GetHitKeyStateAll(_buf);
	(this->*func)();

}

void KeyState::RefKeyData(void)
{
	if (_buf[KEY_INPUT_F1])
	{
		TRACE("キーコンフィグモード\n");
		func = &KeyState::SetKeyConfig;
	}

	for (auto key : INPUT_ID())
	{
		state(key, _buf[_keyCon[static_cast<int>(key)]]);
	}
	/*state(INPUT_ID::LEFT, _buf[KEY_INPUT_LEFT]);
	state(INPUT_ID::RIGHT, _buf[KEY_INPUT_RIGHT]);
	state(INPUT_ID::UP, _buf[KEY_INPUT_UP]);
	state(INPUT_ID::DOWN, _buf[KEY_INPUT_DOWN]);*/
}

void KeyState::SetKeyConfig(void)
{

}
