#pragma once
#include <Scene/BaseScene.h>
class KeyConfig :
	public BaseScene
{
public:
	KeyConfig();
	~KeyConfig();

	//ƒˆ‰¼‘zŠÖ”’u‚«ê
	unique_Base Update(unique_Base own);
	SCN_ID GetScnID(void);
};

