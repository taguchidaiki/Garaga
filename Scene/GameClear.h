#pragma once
#include "BaseScene.h"
class GameClear :
	public BaseScene
{
public:
	GameClear();
	~GameClear();

	unique_Base Update(unique_Base own)override;
	void Draw(void);
	SCN_ID GetScnID(void)override;

private:
	void Init(void);
};

