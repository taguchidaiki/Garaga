#pragma once
#include <DxLib.h>
#include <map>
#include <vector>
#include "INPUT_ID.h"
#include <_DebugConOut.h>


using KeyPair = std::pair<int, int>;
using KeyMap = std::map<INPUT_ID, KeyPair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();

	//�������z�֐��u����
	virtual void Update(void) = 0;

	//�֐��u����
	const KeyMap& state(void)const;
	const KeyPair state(INPUT_ID id)const;

	bool state(INPUT_ID id, int data);
	void SetOld(void);

private:
	KeyMap _state;
};

