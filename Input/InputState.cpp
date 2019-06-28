#include "InputState.h"

InputState::InputState()
{
	/*_state[INPUT_ID::LEFT]	= { 1,0 };
	_state[INPUT_ID::RIGHT] = { 1,0 };
	_state[INPUT_ID::UP]	= { 1,0 };
	_state[INPUT_ID::DOWN]	= { 1,0 };
	_state[INPUT_ID::BTN_1] = { 1,0 };
	_state[INPUT_ID::BTN_2] = { 1,0 };
	_state[INPUT_ID::BTN_3] = { 1,0 };
	_state[INPUT_ID::BTN_4] = { 1,0 };*/
	//_state.try_emplace(INPUT_ID::LEFT,(0,1));
	//���������X�g���g����
	//_state.try_emplace(INPUT_ID::LEFT, KeyPair{ 0,1 });
	//first�����݂̒l�Asecond���ߋ��̒l�ɐݒ�
	for (auto id : INPUT_ID())
	{
		_state.try_emplace(id, KeyPair{ 0,1 });
	}
}


InputState::~InputState()
{
}

const KeyMap & InputState::state(void)const
{
	return _state;
}

const KeyPair InputState::state(INPUT_ID id)const
{
	//[]���g���ƂȂ������Ƃ��ɐV��������Ă��܂����疖����const���g���Ȃ�
	//if (_state.find(id) == _state.end())
	//{
	//	//std::initializer_list
	//	return {0,0};
	//}
	//return _state.at(id);
	try
	{
		return _state.at(id);
	}
	catch (...)
	{
		//AST();
	}
	return { 0,0 };
}

bool InputState::state(INPUT_ID id, int data)
{
	if (_state.find(id) == _state.end())
	{
		return false;
	}
	_state[id].first = data;
	return true;
}

void InputState::SetOld(void)
{
	for (auto id : INPUT_ID())
	{
		try 
		{
			_state[id].second = _state[id].first;
		}
		catch (...)
		{
			//AST();
			_state.emplace(id, KeyPair{ 0,1 });
		}
	}
}
