#include "KeyConfig.h"



KeyConfig::KeyConfig()
{
	TRACE("%d\n", GetScnID());
	TRACE("KeyConfig\n");
}


KeyConfig::~KeyConfig()
{
}

unique_Base KeyConfig::Update(unique_Base own)
{
	ClsDrawScreen();

	

	ScreenFlip();
	return std::move(own);
}

SCN_ID KeyConfig::GetScnID(void)
{
	return SCN_ID::CONFIG;
}
