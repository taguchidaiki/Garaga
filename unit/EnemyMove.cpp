#include "EnemyMove.h"

EnemyMove::EnemyMove(std::vector<MoveInfo> moveMap)
{
	_moveMap = &moveMap;
	count = 0.0f;
}

EnemyMove::~EnemyMove()
{
}

Vector2D EnemyMove::Update(const TRNS & trns)
{
	Vector2D mov = { 0,0 };
	
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
	/*f(x) = 1�@/ (1 + exp(-ax));	�V�O���C�h�Ȑ�(a > 0)*/
	/*�X�����`���Đ��K�����ꂽ�ړ��ʂ����Ă����邩�ocos��sin�Ɓp�����邩tan�Ƃ̒l�𕪉����邩*/
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

Vector2D EnemyMove::Line(Vector2D start, Vector2D end, const TRNS& trns)
{
	Vector2D mov;
	Vector2D nextPos;

	mov = Normalize(Vector2D(end - start)) * trns.speed;
	nextPos = trns.pos + mov;

	double L1 = sqrt(pow(end.x - trns.pos.x, 2) + pow(end.y - trns.pos.y, 2));
	double L2 = sqrt(pow(nextPos.x - trns.pos.x, 2) + pow(nextPos.y - trns.pos.y, 2));
	double vSize = ((end.x - trns.pos.x) * (nextPos.x - trns.pos.x) + (end.y - trns.pos.y) * (nextPos.y - trns.pos.y));
	double L3 = (L1 * L2);
	double L4 = fabs(vSize - L3) -1.0;
	
	if (((fabs(vSize - L3)- 1.0) < 0.00001) && (L2 >= L1))
	{
		mov = Vector2D(end - trns.pos);
		//Enemy�̍s���\�̃J�E���g���P�i�߂�i���̍s���Ɉڂ�j����
	}

	return mov;
}

Vector2D EnemyMove::Sigmoid(const TRNS & trns)
{
	Vector2D mov;
	Vector2D start = std::get<0>(_moveMap);
	Vector2D end = std::get<1>(_moveMap);
	/*f(x) = 1�@/ (1 + exp(-ax));	�V�O���C�h�Ȑ�(a > 0)*/
	/*�X�����`���Đ��K�����ꂽ�ړ��ʂ����Ă����邩�ocos��sin�Ɓp�����邩tan�Ƃ̒l�𕪉����邩*/
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

Vector2D EnemyMove::Cyclone(const TRNS & trns)
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

Vector2D EnemyMove::Line(const TRNS & trns)
{
	Vector2D mov;
	Vector2D nextPos;

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
		//Enemy�̍s���\�̃J�E���g���P�i�߂�i���̍s���Ɉڂ�j����
	}

	return mov;
}