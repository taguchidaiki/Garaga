#include "GameScene.h"
#include <algorithm>
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
	(*_input).Update();

	if (CheckHitKey(KEY_INPUT_F5))
	{
		return std::make_unique<GameClear>();
	}
	
	if ((*_input).state(INPUT_ID::ENTER).first && !(*_input).state(INPUT_ID::ENTER).second && count < 21)
	{
		AddEne({ _addPList[rand() % 6] ,
				 {0,0},
				 2,
				 "kyara",
				 "image/char.png",
				 { 30,32 },
				 { 10,10 },
				(rand() % 8 + 5) * 2/*static_cast<int>(OBJ_ID::OBJ_ENEMY_START)*/ },
				 _endCirList[count % 21]);
		count++;
	}
	

	for (auto obj : _objList)
	{
		obj->Update();
	}

	_objList.erase(std::remove_if(_objList.begin(), 
								  _objList.end(), 
								  [](shared_Obj& obj) {return (*obj).isDeath();}),
				   _objList.end());
	
	Draw();

	//ローカルにあるunique_Baseの所有権を渡してあげる
	return std::move(own);
}

void GameScene::Draw(void)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();

	SetDrawScreen(_ghGameScreen);

	ClsDrawScreen();

	_dbgDrawString(0, 0, "ゲームシーン", 0xffffff,false);
	//shared_ptrでのfor文の書き方
	for (auto obj : _objList)
	{
		obj->Obj::Draw();
	}

	//unique_ptrでのfor文の書き方
	/*for (auto itr = _objList.begin(); itr != _objList.end(); ++itr)
	{
		(*itr)->Draw();
	}*/

	/*for (auto& obj : _objList)
	{
		obj->Draw();
	}*/
	lpSceneMng.AddDrawQue({ _ghGameScreen,lpSceneMng.gameScreenPos.x,lpSceneMng.gameScreenPos.y});

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
	ImageMng::GetInstance().GetID("enblast", "image/en_blast.png", { 64,64 }, { 5,1 });
	ImageMng::GetInstance().GetID("plblast", "image/pl_blast.png", { 64, 64}, { 4, 1});

	for (int i = 0; i < 21; ++i)
	{
		_endCirList[i] = { {(float)(40 * (i % 7)) + 100 ,(float)(35 * (i / 7)) + 50},
							1.0f};
	}

	/*_objList.emplace_back(new Player({ { 300,300 },
		{ 0,0 },
		5,
		"char",
		"image/char.png",
		{ 30,32 },
		{10, 10},
		static_cast<int>(OBJ_ID::OBJ_ENEMY_START) }
	));*/

	_input = std::make_unique<KeyState>();
	/*for (int i = 0; i < 9; ++i)
	{
		_objList.emplace_back(new Enemy({(float)(200 + 30 * (i % 3)) ,(float)(50 + ((i / 3) * 32))}, 
										 "kyara", "image/char.png", 
										 { 30,32 }, 
										 { 10,10 }, 
										 OBJ_ENEMY_START));
	}*/

	/*_objList.emplace_back(new Enemy({(float) (200 + 30 * 1), (float)(50 + 32 * 3)},
									  5,
									 "kyara", 
									 "image/char.png",
									 { 30,32 },
									 { 10,10 },
									 OBJ_ENEMY_START));*/
	
	return true;
}

bool GameScene::AddEne(STATUS status, std::pair<Vector2D, float> eArea)
{
	_objList.emplace_back(new Enemy(status, eArea));
	return false;
}
