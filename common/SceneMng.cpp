#include <DxLib.h>
#include "SceneMng.h"
#include <unit/Player.h>
#include <unit/Enemy.h>
#include <common/ImageMng.h>
#include <Scene/GameScene.h>


std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

void SceneMng::Run(void)
{
	SysInit();
	//�p���̃I�[�o�[���[�h�����A���j�[�N�|�C���^�ŃQ�[���V�[���̐���
	_activeScene = std::make_unique<GameScene>();
	//activeScene(new GameScene);
	while ((ProcessMessage() == 0) && (CheckHitKey(KEY_INPUT_ESCAPE)) == 0)
	{
		//activeScene�̏��L���������̃R�s�[���ɓn���āA���̕Ԃ�l��main���̃��j�[�N�|�C���^�ɓn���Ă�����
		_activeScene = _activeScene->Update(std::move(_activeScene));
	}
}

int SceneMng::SysInit(void)
{
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	SetWindowText("1701320_�c����M");
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	return 0;
}

SceneMng::SceneMng()
{
}


SceneMng::~SceneMng()
{
}