#pragma once
#include <unit/Obj.h>

class Shot :
	public Obj
{
public:
	Shot(Vector2D pos);
	~Shot();
	
	//ƒˆ‰¼‘zŠÖ”’u‚«ê
	void Draw(void) override;
	void Update(void)override;
	UNIT_ID GetUnitType(void) override;
};

