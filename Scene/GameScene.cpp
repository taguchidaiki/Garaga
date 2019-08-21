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
	
	if ((*_input).state(INPUT_ID::ENTER).first && !(*_input).state(INPUT_ID::ENTER).second && _count < 40)
	{
		AddEne();
		_count++;
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

	FILE *file;

	fopen_s(&file, "data/firstPos.csv", "r");
	for (int i = 0; i < 6; ++i)
	{
		fscanf_s(file, "%lf,%lf",
			&_addPList[i].x,
			&_addPList[i].y);
	}
	fclose(file);

	fopen_s(&file, "data/endPos.csv", "r");
	for (int i = 0; i < 40; ++i)
	{
		fscanf_s(file, "%lf,%lf",
			&_endList[i].x,
			&_endList[i].y);
	}

	fclose(file);

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

bool GameScene::AddEne()
{
	FILE *file;
	STATUS _status;
	int count = 0;
	if (!_objList.empty())
	{
		count = _objList.back()->animCnt();
	}
	fopen_s(&file, "data/enemyState.csv", "r");
	fscanf_s(file, "%lf,%lf,%lf,%lf,%f,%d,%[^,],%[^,],%d,%d,%d,%d",
		&_status.trns.pos.x,
		&_status.trns.pos.y,
		&_status.trns.mov.x,
		&_status.trns.mov.y,
		&_status.trns.speed,
		&_status.id,
		_status.imageName.c_str(),10,
		_status.fileName.c_str(), 20,
		&_status.divSize.x,
		&_status.divSize.y,
		&_status.divCnt.x,
		&_status.divCnt.y);

	fclose(file);
	_objList.emplace_back(new Enemy(_status, _endList[_count], count));
	return false;
}
