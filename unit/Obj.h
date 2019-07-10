#pragma once
#include <DxLib.h>
#include <string>
#include <memory>
#include <common/ImageMng.h>
#include <common/VECTOR2.h>
#include <_DebugConOut.h>
#include <_DebugGraph.h>

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
	NORMAL,		//�ʏ�
	EX,			//����
	BLAST,		//���S
	MAX
};

class Obj;

using unique_Obj = std::unique_ptr<Obj>;
using shared_Obj = std::shared_ptr<Obj>;
//first = �摜��ID, second = �t���[����;
using AnimVector = std::vector<std::pair<int, int>>;

constexpr float PI = 3.1415926535897932384626433832795f;

class Obj
{
public:
	Obj();
	virtual ~Obj();

	//�������z�֐��u����
	virtual void Draw(void);
	virtual UNIT_ID GetUnitType(void) = 0;
	virtual void Update(void) = 0;

	//�֐��u����
	void Init(std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt,int id);
	void Draw(int id);
	const Vector2 pos(void)const;
	bool pos(const Vector2 pos);
	const ANIM animKey(void) const;
	bool animKey(const ANIM _animKey);
	bool resetCnt(void);
	bool isAlive(void);
	bool isDeath(void);
	bool isAnimEnd(void);


protected:
	bool SetAnim(const ANIM key, AnimVector &data);
	bool DestroyProc(void);

	Vector2 _pos;
	std::string _imageName;
	Vector2 _divSize;
	Vector2 _divCnt;
	bool _alive;
	bool _death;
	int _id;

private:
	std::map<ANIM,AnimVector> _animMap;
	ANIM _animKey;
	int _animFlame;
	int _animCnt;
};

