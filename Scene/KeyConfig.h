#pragma once
#include <Scene/BaseScene.h>
class KeyConfig :
	public BaseScene
{
public:
	KeyConfig();
	~KeyConfig();

	//純粋仮想関数置き場
	unique_Base Update(unique_Base own);
	SCN_ID GetScnID(void);
};

