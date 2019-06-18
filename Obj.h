#pragma once
#include <DxLib.h>
#include <string>
#include <common/ImageMng.h>
#include "VECTOR2.h"

class Obj
{
public:
	Obj();
	virtual ~Obj();

	//ƒˆ‰¼‘zŠÖ”’u‚«ê
	virtual void Draw(void) = 0;

	//ŠÖ”’u‚«ê
	void Init(std::string imageName, Vector2 divSize, Vector2 divCnt,int id);
	void Draw(int id);

protected:
	Vector2 _pos;
	std::string _imageName;
	Vector2 _divSize;
	Vector2 _divCnt;
	int _id;
};

