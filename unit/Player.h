#pragma once
#include "Obj.h"
#include <Input/KeyState.h>

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2  pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id);
	~Player();

	//�������z�֐��u����
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;

	//�֐��u����

private:
	bool Init(void);
	std::unique_ptr<InputState> _input;
};

