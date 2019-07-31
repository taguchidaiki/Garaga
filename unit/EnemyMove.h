#pragma once
#include <common/VECTOR2.h>
#include <utility>
#include <memory>
#include "Obj.h"

enum class MOV_PTN
{
	LINE,
	SIGMOID,
	CYCLONE,
	MAX
};

class EnemyMove
{
public:
	EnemyMove(std::vector<MoveInfo> moveMap);
	~EnemyMove();

	Vector2D Update(const TRNS& trns/*なんの動きをするかの情報も引数に追加する*/);
	
private:
	//xとyの範囲を0~1に正規化済みのシグモイド曲線の値を返す
	float Sigmoid(float x, float a);
	//(スタート位置、ゴール位置、移動の曲線のなだらかさ、移動情報)
	Vector2D Sigmoid(Vector2D start, Vector2D end, float til, const TRNS& trns);

	//(現在位置、円の中心、半径、移動情報)
	Vector2D Cyclone(Vector2D start, Vector2D end, double& rad, const TRNS& trns);

	//(スタート位置、ゴール位置とゴール範囲、移動情報)
	Vector2D Line(Vector2D start, Vector2D end, const TRNS& trns);

	Vector2D Sigmoid(const TRNS& trns);
	Vector2D Cyclone(const TRNS& trns);
	Vector2D Line(const TRNS& trns);

	std::vector<MoveInfo> *_moveMap;
	float count;
};

