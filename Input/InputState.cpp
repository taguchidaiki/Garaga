#include "InputState.h"

InputState::InputState()
{
	_state[INPUT_ID::LEFT]	= { 1,0 };
	_state[INPUT_ID::RIGHT] = { 1,0 };
	_state[INPUT_ID::UP]	= { 1,0 };
	_state[INPUT_ID::DOWN]	= { 1,0 };
	_state[INPUT_ID::BTN_1] = { 1,0 };
	_state[INPUT_ID::BTN_2] = { 1,0 };
	_state[INPUT_ID::BTN_3] = { 1,0 };
	_state[INPUT_ID::BTN_4] = { 1,0 };
}


InputState::~InputState()
{
}

const KeyMap & InputState::state(void) const
{
	return _state;
}

bool InputState::state(const KeyMap& state)
{
	_state = state;
	return true;
}

bool InputState::state(INPUT_ID id, const KeyPair & keyData)
{
	if (_state.find(id) == _state.end())
	{
		return false;
	}
	_state.at(id) = keyData;
	return true;
}

const KeyPair InputState::state(INPUT_ID id)const
{
	//[]‚ğg‚¤‚Æ‚È‚©‚Á‚½‚Æ‚«‚ÉV‚µ‚­ì‚Á‚Ä‚µ‚Ü‚¤‚©‚ç––”ö‚Ìconst‚ªg‚¦‚È‚¢
	if (_state.find(id) == _state.end())
	{
		//std::initializer_list
		return {0,0};
	}

	return _state.at(id);
}
