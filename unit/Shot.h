#pragma once
#include <unit/Obj.h>

class Shot :
	public Obj
{
public:
	Shot(Vector2D pos);
	~Shot();
	
	//純粋仮想関数置き場
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;
};

