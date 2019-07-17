#pragma once
#include "BaseScene.h"
#include <vector>
#include <unit/Obj.h>
#include <Input/KeyState.h>

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();

	unique_Base Update(unique_Base own)override;
	void Draw(void);
	SCN_ID GetScnID(void)override;

private:
	bool Init(void);
	bool AddEne(STATUS status, std::pair<Vector2D, float> eArea);
	std::unique_ptr<InputState> _input;

	Vector2D _addPList[6] = {
	{-30,0},
	{500,0},
	{-30,195},
	{500,195},
	{-30,358},
	{500,358}
	};

	std::pair<Vector2D, float> _endCirList[21];

	std::vector<shared_Obj> _objList;
	int count = 0;
};

