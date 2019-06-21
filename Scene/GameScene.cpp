#include "GameScene.h"
#include "GameClear.h"


GameScene::GameScene()
{
	TRACE("%d\n",GetScnID());
	TRACE("GameScene\n");
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
	//���[�J���ɂ���unique_Base�̏��L����n���Ă�����
	return std::move(own);
}

SCN_ID GameScene::GetScnID(void)const
{
	return SCN_ID::GAME;
}
