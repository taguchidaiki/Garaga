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
	bool AddEne(STATUS status);

	std::vector<shared_Obj> _objList;
};

