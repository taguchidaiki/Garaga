#pragma once
#include <memory>
#include <Scene/BaseScene.h>

#define lpSceneMng SceneMng::GetInstance()

using DrawQueT = std::tuple<int, int, int>;		//<�O���t�B�b�N�n���h���Ax���W�Ay���W>

enum class DRAW_QUE
{
	IMAGE,
	X,
	Y
};

class SceneMng
{
public:
	
	static SceneMng&GetInstance(void)
	{
		return (*s_Instance);
	}

	void Run(void);

	bool AddDrawQue(DrawQueT dQue);

	const Vector2 screenSize;
	const Vector2 gameScreenSize;
	const Vector2 gameScreenPos;

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

	bool SysInit(void);
	void Draw(void);

	//�`��p�̃��X�g
	std::vector<DrawQueT> _drawList;

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
	//�p���̃I�[�o�[���[�h�����A���j�[�N�|�C���^�ŃQ�[���V�[���̐���
	unique_Base _activeScene;
};

