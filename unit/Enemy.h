#pragma once
#include "Obj.h"
class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 pos, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id);
	~Enemy();

	//純粋仮想関数置き場
	void Draw(void) override;
	UNIT_ID GetUnitType(void) override;


	//関数置き場


private:
	bool Init(void);
};

