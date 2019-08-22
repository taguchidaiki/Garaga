#include "GameScene.h"
#include <algorithm>
#include <random>
#include <time.h>
#include "GameClear.h"
#include <common/SceneMng.h>
#include <unit/Player.h>
#include <unit/Enemy.h>
#include <unit/Shot.h>


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

	if (_createTimer >= 150 && _count < 40)
	{
		CreateFom();
		_createTimer = 0;
		
	}

	for (auto obj : _objList)
	{
		obj->Update();
	}

	std::sort(_objList.begin(), _objList.end(), [](const shared_Obj& obj1, const shared_Obj& obj2) {return (*obj1).GetUnitType() > (*obj2).GetUnitType(); });

	auto itr = std::find_if(_objList.begin(), _objList.end(), [](shared_Obj& obj) {return (*obj).GetUnitType() == UNIT_ID::PLAYER; });
	auto itr2 = std::find_if(_objList.begin(), _objList.end(), [](shared_Obj& obj) {return (*obj).GetUnitType() == UNIT_ID::ENEMY; });
	if (itr != _objList.end()
		&& itr2 != _objList.end())
	{
		for (auto shot = (*itr)->listBegin().begin()/*std::find_if(_objList.begin(), _objList.end(), [](shared_Obj& obj) {return (*obj).GetUnitType() == UNIT_ID::SHOT; })*/;
			shot != (*itr)->listBegin().end();
			shot++)
		{
			for (auto enemy = itr2/*std::find_if(_objList.begin(), _objList.end(), [](shared_Obj& obj) {return (*obj).GetUnitType() == UNIT_ID::ENEMY; })*/;
				(*enemy)->GetUnitType() == UNIT_ID::ENEMY;
				enemy++)
			{
				if (RectVsRect((*shot)->state(),(*enemy)->state(),(*shot)->isAlive(),(*enemy)->isAlive()))
				{
					(*shot)->callDeath();
					(*enemy)->callDeath();
				}
			}
		}
	}

	_objList.erase(std::remove_if(_objList.begin(), 
								  _objList.end(), 
								  [](shared_Obj& obj) {return (*obj).isDeath();}),
				   _objList.end());
	
	Draw();

	_createTimer++;
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
	/*for (auto obj : _objList)
	{
		obj->Obj::Draw();
	}*/

	for (auto obj : _objList)
	{
		obj->Draw();
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

	_count = 0;
	_createTimer = 0;
	_ghGameScreen = MakeScreen(lpSceneMng.gameScreenSize.x, lpSceneMng.gameScreenSize.y, true);

	ImageMng::GetInstance().GetID("kyara", "image/char.png", { 30,32 }, { 10,10 });
	ImageMng::GetInstance().GetID("enblast", "image/en_blast.png", { 64,64 }, { 5,1 });
	ImageMng::GetInstance().GetID("plblast", "image/pl_blast.png", { 64, 64}, { 4, 1});

	FILE *file;

	if (fopen_s(&file, "data/firstPos.csv", "r") == 0)
	{
		for (int i = 0; i < 6; ++i)
		{
			fscanf_s(file, "%lf,%lf",
				&_addPList[i].x,
				&_addPList[i].y);
		}
	}
	fclose(file);

	if (fopen_s(&file, "data/endPos.csv", "r") == 0)
	{
		for (int i = 0; i < 40; ++i)
		{
			fscanf_s(file, "%lf,%lf,%d",
				&_endList[i].first.x,
				&_endList[i].first.y,
				&_endList[i].second);
		}
	}
	fclose(file);

	AddPlayer();
	srand((unsigned int)time(NULL));
	_input = std::make_unique<KeyState>();
	
	return true;
}

bool GameScene::AddPlayer()
{
	FILE *file;
	STATUS _status;
	if (fopen_s(&file, "data/playerState.csv", "r") != 0)
	{
		return false;
	}
	fscanf_s(file, "%lf,%lf,%lf,%lf,%f,%d,%[^,],%[^,],%d,%d,%d,%d",
		&_status.trns.pos.x,
		&_status.trns.pos.y,
		&_status.trns.mov.x,
		&_status.trns.mov.y,
		&_status.trns.speed,
		&_status.id,
		_status.imageName.c_str(), 10,
		_status.fileName.c_str(), 20,
		&_status.divSize.x,
		&_status.divSize.y,
		&_status.divCnt.x,
		&_status.divCnt.y);

	fclose(file);
	_objList.emplace_back(new Player(_status));
	return true;
}

bool GameScene::AddEne(Vector2D endPos, int movTime)
{
	FILE *file;
	STATUS _status;
	int count = 0;
	if (!_objList.empty())
	{
		count = _objList.back()->animCnt();
	}
	if (fopen_s(&file, "data/enemyState.csv", "r") != 0)
	{
		return false;
	}
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

	_status.trns.pos = endPos;
	_status.id = _endList[_count].second;

	_objList.emplace_back(new Enemy(_status, _endList[_count].first, count, movTime));
	_count++;
	return true;
}

bool GameScene::CreateFom()
{
	int movTime = 0;
	Vector2D pos = _addPList[rand() % 6];
	for (int i = 0; i < 3; i++)
	{
		if (_count < 40)
		{
			AddEne(pos, movTime);
		}
		movTime += 15;
	}
	return true;
}

bool GameScene::RectVsRect(STATUS stateA, STATUS stateB, bool flagA, bool flagB)
{
	Vector2D posCenA = Vector2D(stateA.trns.pos.x + stateA.divSize.x / 2, stateA.trns.pos.y + stateA.divSize.y / 2);
	Vector2D posCenB = Vector2D(stateB.trns.pos.x + stateB.divSize.x / 2, stateB.trns.pos.y + stateB.divSize.y / 2);
	if (flagA == false) return false;
	if (flagB == false) return false;
	if ((posCenA.x - stateA.divSize.x / 2 < posCenB.x + stateB.divSize.x / 2)
		&& (posCenA.x + stateA.divSize.x / 2 > posCenB.x - stateB.divSize.x / 2)
		&& (posCenA.y - stateA.divSize.y / 2 < posCenB.y + stateB.divSize.y / 2)
		&& (posCenA.y + stateA.divSize.y / 2 > posCenB.y - stateB.divSize.y / 2))
	{
		return true;
	}
	return false;
}
