#pragma once
#include "Obj.h"

class EnemyMove;

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
	Enemy(STATUS state);
	~Enemy();

	//純粋仮想関数置き場
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;


	//関数置き場

private:
	bool Init(void);
	
	std::unique_ptr<EnemyMove> _moveCtl;


};

