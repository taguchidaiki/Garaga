#pragma once
#include <memory>

//BaseScene��using�̉��Ő錾����Ă��邩��using�̂Ƃ���Ŏg����悤�Ƀv���g�^�C�v�錾
class BaseScene;

using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};

	virtual  unique_Base Update(unique_Base own) = 0;
};

