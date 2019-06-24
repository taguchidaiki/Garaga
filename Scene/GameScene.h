#pragma once
#include "BaseScene.h"
#include <list>
#include <unit/Obj.h>

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();

	unique_Base Update(unique_Base own)override;
	SCN_ID GetScnID(void)override;

private:
	std::list<shared_Obj> _objList;
};

