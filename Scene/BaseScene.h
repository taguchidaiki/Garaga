#pragma once
#include <DxLib.h>
#include <memory>
#include <common/ImageMng.h>
#include <_DebugConOut.h>

enum class SCN_ID
{
	GAME,
	CLEAR,
	MAX
};
//BaseScene��using�̉��Ő錾����Ă��邩��using�̂Ƃ���Ŏg����悤�Ƀv���g�^�C�v�錾
class BaseScene;

using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};
	virtual  unique_Base Update(unique_Base own) = 0;
	virtual SCN_ID GetScnID(void) = 0;

};

