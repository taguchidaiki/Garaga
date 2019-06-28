#pragma once
#include "InputState.h"

class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();

	void Update(void)override;

private:
	char _buf[256];
	std::vector<int> _keyMap;
	int _keyTbl[8] = 
	{
		KEY_INPUT_LEFT,
		KEY_INPUT_RIGHT,
		KEY_INPUT_UP,
		KEY_INPUT_DOWN,
		KEY_INPUT_A,
		KEY_INPUT_S,
		KEY_INPUT_Z,
		KEY_INPUT_X
	};
};

