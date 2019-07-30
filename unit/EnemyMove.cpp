#include "EnemyMove.h"

EnemyMove::EnemyMove()
{
	count = 0.0f;
}

EnemyMove::~EnemyMove()
{
}

Vector2D EnemyMove::Update(const TRNS & trns)
{
	Vector2D mov;
	mov = Sigmoid({ 500,358 }, {0,0},4.5f,trns);
	return mov;
}

float EnemyMove::Sigmoid(float x, float a)
{
	float f1 = ((1 - exp(-a * (2 * x - 1))) / (1 + exp(-a * (2 * x - 1))));
	float f2 = ((1 + exp(-a)) / (1 - exp(-a)));

	return (1.0f / 2.0f) * (1 + (f1 * f2));
}

Vector2D EnemyMove::Sigmoid(Vector2D start, Vector2D end, float til, const TRNS& trns)
{
	Vector2D mov;
	/*f(x) = 1　/ (1 + exp(-ax));	シグモイド曲線(a > 0)*/
	/*傾きを定義して正規化された移動量を入れてあげるか｛cosθsinθ｝を入れるかtanθの値を分解するか*/
	Vector2D _til = { 0.1f / 3, (Sigmoid(count + 0.1f / 3, til) - Sigmoid(count, til)) };
	count += (0.1f / 3);
	//_til.Normalized();
	mov.x = _til.x * (end.x - start.x);
	mov.y = _til.y * (end.y - start.y);
	/*_state.pos.x += _til.x * (end.x - start.x);
	_state.pos.y += _til.y * (end.y - start.y);*/

	if (count >= 1.0f)
	{
		mov = { 0,0 };
		//_actMode = ENE_ACT::IDLE;
	}

	return mov;
}

Vector2D EnemyMove::Cyclone(Vector2D start, Vector2D end, double & rad, const TRNS& trns)
{
	Vector2D mov;
	Vector2D vec = { start.x - end.x, start.y - end.y };
	double theta = atan2(vec.y, vec.x);

	theta -= (10.0 * PI / 180);

	Vector2D nextPos;
	 nextPos.x = end.x + rad * cos(theta);
	 nextPos.y = end.y + rad * sin(theta);

	 mov = nextPos - start;

	if (rad <= 0)
	{
		mov = { 0,0 };
	}
	rad -= 2.0;

	return mov;
}

Vector2D EnemyMove::Line(Vector2D start, std::pair<Vector2D, float> end, const TRNS& trns)
{
	Vector2D mov;

	mov = Normalize(Vector2D(end.first - start)) * trns.speed;

	if (sqrt(pow(trns.pos.x - end.first.x, 2) + pow(trns.pos.y - end.first.y, 2)) <= end.second)
	{
		mov = Normalize(Vector2D(end.first - trns.pos));
		//Enemyの行動表のカウントを１進める（次の行動に移る）処理
	}

	return mov;
}
