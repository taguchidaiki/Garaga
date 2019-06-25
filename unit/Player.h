#pragma once
#include "Obj.h"
class Player :
	public Obj
{
public:
	Player();
	Player(Vector2  pos, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id);
	~Player();

	//�������z�֐��u����
	void Draw(void) override;
	UNIT_ID GetUnitType(void) override;

	//�֐��u����

private:
	bool Init(void);
};

