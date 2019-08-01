#pragma once
#include "Obj.h"

class EnemyMove;

//<�����̏��,���̍s���ԍ�>
using MoveOrder = std::pair<MoveInfo, int>;

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
	Enemy(STATUS state);
	~Enemy();

	//�������z�֐��u����
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;

	//�֐��u����


private:
	bool Init(void);
	
	std::unique_ptr<EnemyMove> _moveCtl;
	MoveOrder _mOrder;
	

};

