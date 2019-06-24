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
	ClsDrawScreen();

	if (CheckHitKey(KEY_INPUT_F6))
	{
		return std::make_unique<GameScene>();
	}

	ScreenFlip();
	return std::move(own);
}

SCN_ID GameClear::GetScnID(void)
{
	return SCN_ID::CLEAR;
}
