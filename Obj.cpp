#include "Obj.h"



Obj::Obj()
{
}


Obj::~Obj()
{
}

void Obj::Draw(int id)
{
	DrawGraph(_pos.x, _pos.y, id, true);
}
