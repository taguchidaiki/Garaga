#pragma once
#include "Obj.h"

class EnemyMove;

//<動きの情報,今の行動番号>
using MoveOrder = std::pair<MoveInfo, int>;

enum class ENE_VAL
{
	BUG = 10,
	BUTF = 20,
	CAP = 30,
	MAX
};


class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(STATUS& state, Vector2D& endPos, int count,int standTime);
	~Enemy();

	//純粋仮想関数置き場
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;

	//関数置き場


private:
	bool Init(Vector2D& endPos, int standTime);
	
	std::unique_ptr<EnemyMove> _moveCtl;
	MoveOrder _mOrder;
};

