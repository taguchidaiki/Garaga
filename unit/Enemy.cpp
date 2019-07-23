#include "Enemy.h"
#include <stdlib.h>

Enemy::Enemy()
{
	
}

Enemy::Enemy(Vector2D pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	TRACE("エネミー生成\n");
	_state.pos = pos;
	_state.speed = speed;
	Obj::Init(imageName, fileName, divSize, divCnt, id);
	Init();
}

Enemy::Enemy(STATUS state, std::pair<Vector2D, float> eArea)
{
	TRACE("エネミー生成\n");
	_goalArea = eArea;
	Obj::Init(state);
	Init();
}


Enemy::~Enemy()
{
	TRACE("エネミー削除\n");
}

void Enemy::Draw(void)
{
	DrawRotaGraph(_state.pos.x + _state.divSize.x / 2, _state.pos.y + _state.divSize.y / 2,
		1.0, PI / 2,
		IMAGE_ID(_state.imageName)[_state.id], true);
}

void Enemy::Update(void)
{
	if (DestroyProc())
	{
		return; 
	}

	(this->*_actTbl[static_cast<int>(_actMode)])();
	
	/*if (rand() % 1200 == 0)
	{
		_alive = false;
		animKey(ANIM::BLAST);
	}*/
	
}

UNIT_ID Enemy::GetUnitType(void)
{
	return UNIT_ID::ENEMY;
}

int Enemy::Idle(void)
{
	return 0;
}

int Enemy::Move(void)
{
	//直線移動の実装
	//ゴール地点から現在地点までの方向を正規化してあげて
	//posにスピード*方向を加算すればその方向に向かう
	/*_state.mov = Normalize(Vector2(_goalArea.first - _state.pos));

	_state.pos += _state.mov * _state.speed;

	if (sqrt(pow(_state.pos.x - _goalArea.first.x,2) + pow(_state.pos.y - _goalArea.first.y,2)) <= _goalArea.second)
	{
		_state.pos = _goalArea.first;
		_actMode = ENE_ACT::IDLE;
	}*/

	float _y = Sigmoid(count);
	
	return 0;
}

float Enemy::Sigmoid(float x)
{
	count += 1.0f;
	float _y = 1 / (1 + exp(-(count - 1)));
	Vector2D til = {count , _y};
	til.Normalized();
	_state.pos +=  til * _state.speed;
	
	return true;
}

bool Enemy::Sigmoid(Vector2 start, Vector2 end, float til)		//till(0.0f < til < 1.0f)
{
	/*f(x) = 1(上下の範囲の最大値(引数でもらって来るか、元々の固定値まで)) / (1 + exp(-ax));	シグモイド曲線(a > 0)*/
	/*f'(x) =  f(x)(1 - f(x));							シグモイド曲線の微分*/	

	Vector2 center;
	center = start + (end - start) / 2;
	_state.pos.x += _state.speed;

	return true;
}

bool Enemy::Init(void)
{
	AnimVector data;
	data.reserve(2);
	//data.push_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	//data.emplace_back(std::make_pair(IMAGE_ID("キャラ")[0], 30));
	data.emplace_back(IMAGE_ID("kyara")[_state.id], 30);
	data.emplace_back(IMAGE_ID("kyara")[_state.id + 1], 60);
	SetAnim(ANIM::NORMAL, data);
	//data.clear();
	
	data.reserve(6);
	for (int i = 0; i < 5; ++i)
	{
		data.emplace_back(IMAGE_ID("enblast")[i], 30 * (i + 1));
	}
	data.emplace_back(-1, 180);
	SetAnim(ANIM::BLAST, data);

	_actTbl[static_cast<int>(ENE_ACT::IDLE)] = &Enemy::Idle;
	_actTbl[static_cast<int>(ENE_ACT::MOVE)] = &Enemy::Move;

	_actMode = ENE_ACT::MOVE;
	return true;
}
