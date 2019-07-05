#include "GameClear.h"
#include "GameScene.h"
#include <common/SceneMng.h>
#include <_DebugGraph.h>



GameClear::GameClear()
{
	Init();
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

	Draw();

	return std::move(own);
}

void GameClear::Draw(void)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();

	SetDrawScreen(_ghGameScreen);
	ClsDrawScreen();

	_dbgDrawString(0, 0, "ÉQÅ[ÉÄÉNÉäÉA", 0xffffff, false);
	lpSceneMng.AddDrawQue({ _ghGameScreen,lpSceneMng.gameScreenPos.x,lpSceneMng.gameScreenPos.y });

	SetDrawScreen(ghBuffer);

}

SCN_ID GameClear::GetScnID(void)
{
	return SCN_ID::CLEAR;
}

void GameClear::Init(void)
{
	TRACE("%d\n", GetScnID());
	TRACE("GameClear\n");

	_ghGameScreen = MakeScreen(lpSceneMng.gameScreenSize.x, lpSceneMng.gameScreenSize.y, true);
}
