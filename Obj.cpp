#include "Obj.h"


Obj::Obj()
{
}


Obj::~Obj()
{
}

void Obj::Init(std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	ImageMng::GetInstance().GetID(imageName, fileName, divSize, divCnt);
	_imageName = imageName;
	_divSize = divSize;
	_divCnt = divCnt;
	_id = id;
}

void Obj::Draw(int id)
{
	DrawGraph(_pos.x, _pos.y, IMAGE_ID(_imageName)[id], true);
}
