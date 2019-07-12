#pragma once
#include "Obj.h"

enum class ENE_ACT
{
	IDLE,
	MOVE,
	MAX
};

enum class ENE_VAL
{
	BUG,
	BUTF,
	CAP,
	MAX
};


class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id);
	Enemy(STATUS state, Vector2 ePos);
	~Enemy();

	//ƒˆ‰¼‘zŠÖ”’u‚«ê
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;


	//ŠÖ”’u‚«ê
	

private:
	bool Init(void);
	int Idle(void);
	int Move(void);
	
	int (Enemy::*_actTbl[static_cast<int>(ENE_ACT::MAX)])(void);
	ENE_ACT _actMode;
	Vector2 _goal;
};

