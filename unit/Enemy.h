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
	BUG = 1,
	BUTF,
	CAP,
	MAX
};


class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2D pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id);
	Enemy(STATUS state, std::pair<Vector2D, float> eArea);
	~Enemy();

	//純粋仮想関数置き場
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;


	//関数置き場
	//xとyの範囲を0~1に正規化済みのシグモイド曲線の値を返す
	float Sigmoid(float x,float a);
	bool Sigmoid(Vector2D start, Vector2D end, float til);

	bool Cyclone(void);
	bool Cyclone(Vector2D start, Vector2D end);

private:
	bool Init(void);
	int Idle(void);
	int Move(void);
	
	int (Enemy::*_actTbl[static_cast<int>(ENE_ACT::MAX)])(void);
	ENE_ACT _actMode;
	std::pair<Vector2D, float> _goalArea;
	float count;
};

