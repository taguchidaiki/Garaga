#pragma once
#include <DxLib.h>
#include "VECTOR2.h"

class Obj
{
public:
	Obj();
	virtual ~Obj();

	virtual void Draw(void) = 0;
	void Draw(int id);

protected:
	Vector2 _pos;
};

