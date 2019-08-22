#pragma once
#include "Obj.h"

class EnemyMove;

//<�����̏��,���̍s���ԍ�>
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

	//�������z�֐��u����
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;

	//�֐��u����


private:
	bool Init(Vector2D& endPos, int standTime);
	
	std::unique_ptr<EnemyMove> _moveCtl;
	MoveOrder _mOrder;
};

