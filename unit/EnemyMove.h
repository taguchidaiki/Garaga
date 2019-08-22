#pragma once
#include <common/VECTOR2.h>
#include <utility>
#include <memory>
#include "Enemy.h"

enum class MOV_PTN
{
	STANDBY,
	LINE,
	SIGMOID,
	CYCLONE,
	LATERAL,
	MAX
};

class EnemyMove
{
public:
	EnemyMove();
	~EnemyMove();

	Vector2D Update(const TRNS& trns, MoveOrder& order);
	
private:
	//xとyの範囲を0~1に正規化済みのシグモイド曲線の値を返す
	float Sigmoid(float x, float a);
	////(スタート位置、ゴール位置、移動の曲線のなだらかさ、移動情報)
	//Vector2D Sigmoid(Vector2D start, Vector2D end, float til, const TRNS& trns);

	////(現在位置、円の中心、半径、移動情報)
	//Vector2D Cyclone(Vector2D start, Vector2D end, double& rad, const TRNS& trns);

	////(スタート位置、ゴール位置とゴール範囲、移動情報)
	//Vector2D Line(Vector2D start, Vector2D end, const TRNS& trns);

	Vector2D StandBy(const TRNS& trns, MoveOrder& order);
	Vector2D Sigmoid(const TRNS& trns, MoveOrder& order);
	Vector2D Cyclone(const TRNS& trns, MoveOrder& order);
	Vector2D Line(const TRNS& trns, MoveOrder& order);
	Vector2D Lateral(const TRNS& trns, MoveOrder& order);

	Vector2D (EnemyMove::*func[static_cast<int>(MOV_PTN::MAX)])(const TRNS& trns, MoveOrder& order);

	float count;
};

