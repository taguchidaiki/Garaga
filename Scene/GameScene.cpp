#include "GameScene.h"
#include "GameClear.h"
#include <unit/Player.h>
#include <unit/Enemy.h>


GameScene::GameScene()
{
	TRACE("%d\n",GetScnID());
	TRACE("GameScene\n");

	ImageMng::GetInstance().GetID("kyara", "image/char.png", { 30,32 }, { 10,10 });
	ImageMng::GetInstance().GetID("background", "image/frame.png");
	
	_objList.emplace_back(new Player({ 300,200 }, "kyara", "image/char.png", { 30,32 }, { 10,10 }, OBJ_PLAYER));
	_objList.emplace_back(new Enemy({ 500,200 }, "kyara", "image/char.png", { 30,32 }, { 10,10 }, OBJ_ENEMY_START));
	
}


GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	ClsDrawScreen();

	if (CheckHitKey(KEY_INPUT_F5))
	{
		return std::make_unique<GameClear>();
	}

	//shared_ptr�ł�for���̏�����
	for (auto obj : _objList)
	{
		obj->Draw();
	}

	//unique_ptr�ł�for���̏�����
	/*for (auto itr = _objList.begin(); itr != _objList.end(); ++itr)
	{
		(*itr)->Draw();
	}*/

	/*for (auto& obj : _objList)
	{
		obj->Draw();
	}*/

	DrawGraph(0, 0, IMAGE_ID("background")[0], true);

	ScreenFlip();

	//���[�J���ɂ���unique_Base�̏��L����n���Ă�����
	return std::move(own);
}

SCN_ID GameScene::GetScnID(void)
{
	return SCN_ID::GAME;
}
