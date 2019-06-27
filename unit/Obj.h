#pragma once
#include <DxLib.h>
#include <string>
#include <memory>
#include <common/ImageMng.h>
#include <common/VECTOR2.h>

enum OBJ_ID
{
	OBJ_PLAYER,
	OBJ_ENEMY_START = 10,
};

enum class UNIT_ID
{
	PLAYER,
	ENEMY,
	MAX
};

enum class ANIM
{
	NORMAL,		//’Êí
	EX,			//“Áê
	MAX
};

class Obj;

using unique_Obj = std::unique_ptr<Obj>;
using shared_Obj = std::shared_ptr<Obj>;
using AnimVector = std::vector<std::pair<int,int>>;

class Obj
{
public:
	Obj();
	virtual ~Obj();

	//ƒˆ‰¼‘zŠÖ”’u‚«ê
	virtual void Draw(void);
	virtual UNIT_ID GetUnitType(void) = 0;

	//ŠÖ”’u‚«ê
	void Init(std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt,int id);
	void Draw(int id);
	const Vector2 pos(void)const;
	bool pos(const Vector2 pos);
	const ANIM animKey(void) const;
	bool animKey(const ANIM _animKey);


protected:
	bool SetAnim(const ANIM key, AnimVector &data);

	Vector2 _pos;
	std::string _imageName;
	Vector2 _divSize;
	Vector2 _divCnt;
	int _id;

private:
	std::map<ANIM,AnimVector> _animMap;
	ANIM _animKey;
	int _animFlame;
	int _animCnt;
};

