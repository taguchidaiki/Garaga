#include "GameScene.h"



GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	//ƒ[ƒJƒ‹‚É‚ ‚éunique_Base‚ÌŠ—LŒ ‚ğ“n‚µ‚Ä‚ ‚°‚é
	return std::move(own);
}

SCN_ID GameScene::GetScnID(void)
{
	return _id;
}
