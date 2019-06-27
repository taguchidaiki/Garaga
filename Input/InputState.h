#pragma once
#include <DxLib.h>
#include <map>

enum class INPUT_ID
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	BTN_1,
	BTN_2,
	BTN_3,
	BTN_4,
	MAX
};

using KeyPair = std::pair<int, int>;
using KeyMap = std::map<INPUT_ID, KeyPair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();

	//ƒˆ‰¼‘zŠÖ”’u‚«ê
	virtual void Update(void) = 0;
	virtual void GetState(void) = 0;

	//ŠÖ”’u‚«ê
	const KeyMap& state(void) const;
	bool state(const KeyMap& state);
	const KeyPair state(INPUT_ID id)const;
	bool state(INPUT_ID id, const KeyPair& keyData);


private:
	KeyMap _state;
};

