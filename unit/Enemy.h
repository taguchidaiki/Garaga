#pragma once
#include "Obj.h"
class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(Vector2 pos, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id);
	~Enemy();

	//ƒˆ‰¼‘zŠÖ”’u‚«ê
	void Draw(void) override;
	UNIT_ID GetUnitType(void) override;


	//ŠÖ”’u‚«ê


private:
	bool Init(void);
};

