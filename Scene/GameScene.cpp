#include "GameScene.h"



GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	//���[�J���ɂ���unique_Base�̏��L����n���Ă�����
	return std::move(own);
}

SCN_ID GameScene::GetScnID(void)
{
	return _id;
}
