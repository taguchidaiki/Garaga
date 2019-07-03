#include "GameScene.h"
#include "GameClear.h"
#include <common/SceneMng.h>
#include <unit/Player.h>
#include <unit/Enemy.h>


GameScene::GameScene()
{
	Init();
}


GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	

	if (CheckHitKey(KEY_INPUT_F5))
	{
		return std::make_unique<GameClear>();
	}

	for (auto obj : _objList)
	{
		obj->Update();
	}
	
	Draw();

	//ƒ[ƒJƒ‹‚É‚ ‚éunique_Base‚ÌŠ—LŒ ‚ð“n‚µ‚Ä‚ ‚°‚é
	return std::move(own);
}

void GameScene::Draw(void)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();

	SetDrawScreen(_ghGameScreen);

	ClsDrawScreen();
	//shared_ptr‚Å‚Ìfor•¶‚Ì‘‚«•û
	for (auto obj : _objList)
	{
		obj->Obj::Draw();
	}

	//unique_ptr‚Å‚Ìfor•¶‚Ì‘‚«•û
	/*for (auto itr = _objList.begin(); itr != _objList.end(); ++itr)
	{
		(*itr)->Draw();
	}*/

	/*for (auto& obj : _objList)
	{
		obj->Draw();
	}*/
	lpSceneMng.AddDrawQue({ _ghGameScreen,lpSceneMng.gameScreenPos.x,lpSceneMng.gameScreenPos.y });

	SetDrawScreen(ghBuffer);

}

SCN_ID GameScene::GetScnID(void)
{
	return SCN_ID::GAME;
}

bool GameScene::Init(void)
{
	
	TRACE("%d\n", GetScnID());
	TRACE("GameScene\n");

	_ghGameScreen = MakeScreen(lpSceneMng.gameScreenSize.x, lpSceneMng.gameScreenSize.y, true);
	ImageMng::GetInstance().GetID("kyara", "image/char.png", { 30,32 }, { 10,10 });

	_objList.emplace_back(new Player({ 0,200 }, "kyara", "image/char.png", { 30,32 }, { 10,10 }, OBJ_PLAYER));
	_objList.emplace_back(new Enemy({ 60,200 }, "kyara", "image/char.png", { 30,32 }, { 10,10 }, OBJ_ENEMY_START));

	return true;
}
