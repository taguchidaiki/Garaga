#include "GameClear.h"
#include "GameScene.h"



GameClear::GameClear()
{
	TRACE("%d\n", GetScnID());
	TRACE("GameClear\n");
}


GameClear::~GameClear()
{
}

unique_Base GameClear::Update(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_F6))
	{
		return std::make_unique<GameScene>();
	}
	return std::move(own);
}

SCN_ID GameClear::GetScnID(void)const
{
	return SCN_ID::CLEAR;
}
