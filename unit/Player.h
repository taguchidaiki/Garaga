#pragma once
#include "Obj.h"
#include <vector>
#include <Input/KeyState.h>

class Shot;

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2D  pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id);
	Player(STATUS& state);
	~Player();

	//�������z�֐��u����
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;

	//�֐��u����
	bool AddShot();
	
private:
	bool Init(void);
	std::unique_ptr<InputState> _input;
	
};

