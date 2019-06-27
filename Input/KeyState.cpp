#include "KeyState.h"



KeyState::KeyState()
{
}


KeyState::~KeyState()
{
}

void KeyState::Update(void)
{
	GetHitKeyStateAll(_buf);
}

void KeyState::GetState(void)
{

}
