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
	Enemy(STATUS state, std::pair<Vector2D, float> eArea);
	~Enemy();

	//�������z�֐��u����
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;


	//�֐��u����
	void SetMove(void);

private:
	bool Init(void);
	
	std::unique_ptr<EnemyMove> _moveCtl;

};

