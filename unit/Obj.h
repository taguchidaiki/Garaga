#pragma once
#include <DxLib.h>
#include <string>
#include <memory>
#include <math.h>
#include <common/ImageMng.h>
#include <common/VECTOR2.h>
#include <_DebugConOut.h>
#include <_DebugGraph.h>

enum class OBJ_ID
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
	NORMAL,		//通常
	EX,			//特殊
	BLAST,		//死亡
	MAX
};

struct TRNS
{
	Vector2D pos;
	Vector2D mov;
	float speed;
};

struct STATUS
{
	TRNS trns;
	std::string imageName;
	std::string fileName;
	Vector2 divSize;
	Vector2 divCnt;
	int id;
};

class Obj;

using unique_Obj = std::unique_ptr<Obj>;
using shared_Obj = std::shared_ptr<Obj>;
//first = 画像のID, second = フレーム数;
using AnimVector = std::vector<std::pair<int, int>>;

constexpr float PI = 3.1415926535897932384626433832795f;

class Obj
{
public:
	Obj();
	virtual ~Obj();

	//純粋仮想関数置き場
	virtual void Draw(void);
	virtual UNIT_ID GetUnitType(void) = 0;
	virtual void Update(void) = 0;

	//関数置き場
	void Init(std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt,int id);
	void Init(STATUS state);
	void Draw(int id);

	template<typename T>
	const Vector2Temple<T> pos(void)const;
	template<typename T>
	bool pos(const Vector2Temple<T> pos);

	const ANIM animKey(void) const;
	bool animKey(const ANIM _animKey);
	bool resetCnt(void);
	bool isAlive(void);
	bool isDeath(void);
	bool isAnimEnd(void);


protected:
	bool SetAnim(const ANIM key, AnimVector &data);
	bool DestroyProc(void);

	STATUS _state;
	bool _alive;
	bool _death;

private:
	std::map<ANIM,AnimVector> _animMap;
	ANIM _animKey;
	int _animFlame;
	int _animCnt;
};

