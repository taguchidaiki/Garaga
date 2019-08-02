#include "EnemyMove.h"

EnemyMove::EnemyMove()
{
	count = 0.0f;
	func[static_cast<int>(MOV_PTN::LINE)] = &EnemyMove::Line;
	func[static_cast<int>(MOV_PTN::SIGMOID)] = &EnemyMove::Sigmoid;
	func[static_cast<int>(MOV_PTN::CYCLONE)] = &EnemyMove::Cyclone;
	func[static_cast<int>(MOV_PTN::LATERAL)] = &EnemyMove::Lateral;
}

EnemyMove::~EnemyMove()
{
}

Vector2D EnemyMove::Update(const TRNS & trns, MoveOrder& order)
{
	Vector2D mov = { 0,0 };
	
	mov = (this->*func[static_cast<int>(std::get<0>(order.first))])(trns,order);

	return mov;
}

float EnemyMove::Sigmoid(float x, float a)
{
	float f1 = ((1 - exp(-a * (2 * x - 1))) / (1 + exp(-a * (2 * x - 1))));
	float f2 = ((1 + exp(-a)) / (1 - exp(-a)));

	return (1.0f / 2.0f) * (1 + (f1 * f2));
}

//Vector2D EnemyMove::Sigmoid(Vector2D start, Vector2D end, float til, const TRNS& trns)
//{
//	Vector2D mov;
//	/*f(x) = 1　/ (1 + exp(-ax));	シグモイド曲線(a > 0)*/
//	/*傾きを定義して正規化された移動量を入れてあげるか｛cosθsinθ｝を入れるかtanθの値を分解するか*/
//	Vector2D _til = { 0.1f / 3, (Sigmoid(count + 0.1f / 3, til) - Sigmoid(count, til)) };
//	count += (0.1f / 3);
//	//_til.Normalized();
//	mov.x = _til.x * (end.x - start.x);
//	mov.y = _til.y * (end.y - start.y);
//	/*_state.pos.x += _til.x * (end.x - start.x);
//	_state.pos.y += _til.y * (end.y - start.y);*/
//
//	if (count >= 1.0f)
//	{
//		mov = { 0,0 };
//		//_actMode = ENE_ACT::IDLE;
//	}
//
//	return mov;
//}
//
//Vector2D EnemyMove::Cyclone(Vector2D start, Vector2D end, double & rad, const TRNS& trns)
//{
//	Vector2D mov;
//	Vector2D vec = { start.x - end.x, start.y - end.y };
//	double theta = atan2(vec.y, vec.x);
//
//	theta -= (10.0 * PI / 180);
//
//	Vector2D nextPos;
//	 nextPos.x = end.x + rad * cos(theta);
//	 nextPos.y = end.y + rad * sin(theta);
//
//	 mov = nextPos - start;
//
//	if (rad <= 0)
//	{
//		mov = { 0,0 };
//	}
//	rad -= 2.0;
//
//	return mov;
//}
//
//Vector2D EnemyMove::Line(Vector2D start, Vector2D end, const TRNS& trns)
//{
//	Vector2D mov;
//	Vector2D nextPos;
//
//	mov = Normalize(Vector2D(end - start)) * trns.speed;
//	nextPos = trns.pos + mov;
//
//	double L1 = sqrt(pow(end.x - trns.pos.x, 2) + pow(end.y - trns.pos.y, 2));
//	double L2 = sqrt(pow(nextPos.x - trns.pos.x, 2) + pow(nextPos.y - trns.pos.y, 2));
//	double vSize = ((end.x - trns.pos.x) * (nextPos.x - trns.pos.x) + (end.y - trns.pos.y) * (nextPos.y - trns.pos.y));
//	double L3 = (L1 * L2);
//	double L4 = fabs(vSize - L3) -1.0;
//	
//	if (((fabs(vSize - L3)- 1.0) < 0.00001) && (L2 >= L1))
//	{
//		mov = Vector2D(end - trns.pos);
//		//Enemyの行動表のカウントを１進める（次の行動に移る）処理
//	}
//
//	return mov;
//}

Vector2D EnemyMove::Sigmoid(const TRNS & trns, MoveOrder& order)
{
	Vector2D mov;
	Vector2D start = std::get <1>(order.first);
	Vector2D end = std::get<2>(order.first);
	double til = std::get<3>(order.first);
	float speed = 10 - trns.speed;

	/*f(x) = 1　/ (1 + exp(-ax));	シグモイド曲線(a > 0)*/
	/*傾きを定義して正規化された移動量を入れてあげるか｛cosθsinθ｝を入れるかtanθの値を分解するか*/
	Vector2D _til = { 0.1f / speed, (Sigmoid(count + 0.1f / speed, til) - Sigmoid(count, til)) };
	count += (0.1f / speed);
	
	mov.x = _til.x * (end.x - start.x);
	mov.y = _til.y * (end.y - start.y);
	/*_state.pos.x += _til.x * (end.x - start.x);
	_state.pos.y += _til.y * (end.y - start.y);*/

	if (count >= 1.0f)
	{
		mov = Vector2D(end - trns.pos);
		count = 0.0f;
		order.second++;
	}

	return mov;
}

Vector2D EnemyMove::Cyclone(const TRNS & trns, MoveOrder& order)
{
	Vector2D mov;
	Vector2D start = trns.pos;
	Vector2D end = std::get<2>(order.first);
	double rad = Magnitude(start - end) - 2.5;

	if (rad <= 0)
	{
		mov = Vector2D(end - trns.pos);
		order.second++;
		return mov;
	}

	Vector2D vec = { start.x - end.x, start.y - end.y };
	double theta = atan2(vec.y, vec.x);

	theta += std::get<3>(order.first) * (10.0 * PI / 180);

	Vector2D nextPos;
	nextPos.x = end.x + rad * cos(theta);
	nextPos.y = end.y + rad * sin(theta);

	mov = nextPos - start;

	return mov;
}

Vector2D EnemyMove::Line(const TRNS & trns, MoveOrder& order)
{
	Vector2D mov;
	Vector2D nextPos;
	Vector2D start = std::get <1>(order.first);
	Vector2D end = std::get<2>(order.first);

	mov = Normalize(Vector2D(end - start)) * trns.speed;
	nextPos = trns.pos + mov;

	double L1 = sqrt(pow(end.x - trns.pos.x, 2) + pow(end.y - trns.pos.y, 2));
	double L2 = sqrt(pow(nextPos.x - trns.pos.x, 2) + pow(nextPos.y - trns.pos.y, 2));
	double vSize = ((end.x - trns.pos.x) * (nextPos.x - trns.pos.x) + (end.y - trns.pos.y) * (nextPos.y - trns.pos.y));
	double L3 = (L1 * L2);
	double L4 = fabs(vSize - L3) - 1.0;

	if (((fabs(vSize - L3) - 1.0) < 0.00001) && (L2 >= L1))
	{
		mov = Vector2D(end - trns.pos);
		order.second++;
	}

	return mov;
}

Vector2D EnemyMove::Lateral(const TRNS & trns, MoveOrder & order)
{
	Vector2D dir = {1,0};
	count++;

	if ((trns.pos.x <= std::get<1>(order.first).x) || (trns.pos.x >= std::get<2>(order.first).x))
	{
		dir * -1.0;
	}

	if (((int)count % 30) != 0)
	{
		return { 0,0 };	
	}

	return (dir * trns.speed);
}
