#pragma once
#include "BaseScene.h"
#include <vector>
#include <unit/Obj.h>

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
	bool AddEne(STATUS status, Vector2 ePos);
	Vector2 _addPList[6] = {
	{0,0},
	{470,0},
	{0,195},
	{470,195},
	{0,358},
	{470,358}
	};
	Vector2 _endPList[21];

	std::vector<shared_Obj> _objList;
	int count = 0;
};

