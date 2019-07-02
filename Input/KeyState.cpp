#include "KeyState.h"

KeyState::KeyState()
{
	try
	{
		FILE *file;
		fopen_s(&file,"data/key.dat","r");

		fclose(file);
	}
	catch(...)
	{

	}
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
		TRACE("設定キー%d\n", _confID);
		_confID = begin(INPUT_ID());
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
	for (auto key : INPUT_ID())
	{
		state(key, 0);
	}

	for (int key = 0; key < sizeof(_buf)/sizeof(_buf[0]); key++)
	{
		if ((_buf[key]) && (_lastKeyID != key) && (key != KEY_INPUT_F1) && (key != KEY_INPUT_DELETE))
		{
			_keyCon[static_cast<int>(_confID)] = key;
			_lastKeyID = key;
			++_confID;
			TRACE("設定キー%d\n", _confID);
			if (_confID == end(INPUT_ID()))
			{
				TRACE("キーコンフィグ終了");
				func = &KeyState::RefKeyData;
			}
			break;
		}
	}
}
