#pragma once
#include <Scene/BaseScene.h>
class KeyConfig :
	public BaseScene
{
public:
	KeyConfig();
	~KeyConfig();

	//�������z�֐��u����
	unique_Base Update(unique_Base own);
	SCN_ID GetScnID(void);
};

