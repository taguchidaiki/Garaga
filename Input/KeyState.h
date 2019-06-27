#pragma once
#include "InputState.h"

class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();

	void Update(void)override;
	const KeyMap& GetState(void)override;

private:
	char _buf[256];

};

