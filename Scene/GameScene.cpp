#include "GameScene.h"



GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	//ローカルにあるunique_Baseの所有権を渡してあげる
	return std::move(own);
}

SCN_ID GameScene::GetScnID(void)
{
	return _id;
}
