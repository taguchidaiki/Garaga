#pragma once
#include "BaseScene.h"
class GameClear :
	public BaseScene
{
public:
	GameClear();
	~GameClear();

	unique_Base Update(unique_Base own)override;
	SCN_ID GetScnID(void)const override;
};

