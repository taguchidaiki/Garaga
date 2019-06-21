#pragma once
#include <memory>
#include <Scene/BaseScene.h>

#define lpSceneMng SceneMng::GetInstance()

constexpr int SCREEN_SIZE_X = 800;
constexpr int SCREEN_SIZE_Y = 600;

class SceneMng
{
public:
	
	static SceneMng&GetInstance(void)
	{
		return (*s_Instance);
	}

	void Run(void);

	int SysInit(void);

private:
	//��p�̃f�X�g���N�^
	struct SceneMngDeleter
	{
		void operator()(SceneMng *sceneMng)const
		{
			delete sceneMng;
		}
	};

	SceneMng();
	~SceneMng();

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
	//�p���̃I�[�o�[���[�h�����A���j�[�N�|�C���^�ŃQ�[���V�[���̐���
	unique_Base _activeScene;
};

