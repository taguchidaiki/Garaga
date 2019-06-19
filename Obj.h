#pragma once
#include <DxLib.h>
#include <string>
#include <common/ImageMng.h>
#include <common/VECTOR2.h>

enum OBJ_ID
{
	OBJ_PLAYER,
	OBJ_ENEMY_START = 10,
};

class Obj
{
public:
	Obj();
	virtual ~Obj();

	//純粋仮想関数置き場
	virtual void Draw(void) = 0;

	//関数置き場
	void Init(std::string imageName, Vector2 divSize, Vector2 divCnt,int id);
	void Draw(int id);

protected:
	Vector2 _pos;
	std::string _imageName;
	Vector2 _divSize;
	Vector2 _divCnt;
	int _id;
};

