#include <DxLib.h>
#include "SceneMng.h"
#include <unit/Player.h>
#include <unit/Enemy.h>
#include <common/ImageMng.h>
#include <Scene/GameScene.h>
#include <_DebugGraph.h>


std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

void SceneMng::Run(void)
{
	SysInit();
	//継承のオーバーロードをしつつ、ユニークポインタでゲームシーンの生成
	_activeScene = std::make_unique<GameScene>();
	//activeScene(new GameScene);
	while ((ProcessMessage() == 0) && (CheckHitKey(KEY_INPUT_ESCAPE)) == 0)
	{
		_dbgStartGraph;
		_drawList.clear();
		//activeSceneの所有権を引数のコピー側に渡して、その返り値をmain側のユニークポインタに渡してあげる
		_activeScene = _activeScene->Update(std::move(_activeScene));
		AddDrawQue({IMAGE_ID("枠")[0], 0, 0 });
		Draw();
	}
}

bool SceneMng::AddDrawQue(DrawQueT dQue)
{
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue) == -1)
	{
		return false;
	}

	_drawList.emplace_back(dQue);
	return true;
}

bool SceneMng::SysInit(void)
{
	SetGraphMode(screenSize.x, screenSize.y, 16);
	ChangeWindowMode(true);
	SetWindowText("1701320_田口大貴");

	if (DxLib_Init() == -1)
	{
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	SET_IMAGE_ID("枠", "image/frame.png");
	_dbgSetUpGraph(200);

	return true;
}

SceneMng::SceneMng() :screenSize{800,600}, gameScreenSize{500,390}, gameScreenPos{(screenSize.x - gameScreenSize.x)/ 2, (screenSize.y - gameScreenSize.y) / 2 }
{
}


SceneMng::~SceneMng()
{
}

void SceneMng::Draw(void)
{
	_dbgAddScreen;
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();

	for (auto _dQue : _drawList)
	{

		DrawGraph(std::get<static_cast<int>(DRAW_QUE::X)>(_dQue),
				  std::get<static_cast<int>(DRAW_QUE::Y)>(_dQue),
				  std::get<static_cast<int>(DRAW_QUE::IMAGE)>(_dQue),
				  true);
	}

	ScreenFlip();
}
