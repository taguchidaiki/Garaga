#pragma once
#include <memory>
#include <Scene/BaseScene.h>

#define lpSceneMng SceneMng::GetInstance()

using DrawQueT = std::tuple<int, int, int>;		//<グラフィックハンドル、x座標、y座標>

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
	//専用のデストラクタ
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

	//描画用のリスト
	std::vector<DrawQueT> _drawList;

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
	//継承のオーバーロードをしつつ、ユニークポインタでゲームシーンの生成
	unique_Base _activeScene;
};

