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

	//純粋仮想関数置き場
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;

	//関数置き場
	bool AddShot();
	
private:
	bool Init(void);
	std::unique_ptr<InputState> _input;
	
};

