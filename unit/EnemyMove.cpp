#include "EnemyMove.h"



EnemyMove::EnemyMove()
{
}


EnemyMove::~EnemyMove()
{
}

void EnemyMove::Update(void)
{
}

//float EnemyMove::Sigmoid(float x, float a)
//{
//	float f1 = ((1 - exp(-a * (2 * x - 1))) / (1 + exp(-a * (2 * x - 1))));
//	float f2 = ((1 + exp(-a)) / (1 - exp(-a)));
//
//	return (1.0f / 2.0f) * (1 + (f1 * f2));
//}
//
//bool EnemyMove::Sigmoid(Vector2D start, Vector2D end, float til)
//{
//	/*f(x) = 1�@/ (1 + exp(-ax));	�V�O���C�h�Ȑ�(a > 0)*/
//	/*�X�����`���Đ��K�����ꂽ�ړ��ʂ����Ă����邩�ocos��sin�Ɓp�����邩tan�Ƃ̒l�𕪉����邩*/
//	Vector2D _til = { 0.1f / 3, (Sigmoid(count + 0.1f / 3, til) - Sigmoid(count, til)) };
//	count += (0.1f / 3);
//	//_til.Normalized();
//	_state.pos.x += _til.x * (end.x - start.x);
//	_state.pos.y += _til.y * (end.y - start.y);
//
//	if (count >= 1.0f)
//	{
//		_actMode = ENE_ACT::IDLE;
//	}
//
//	return true;
//}
//
//bool EnemyMove::Cyclone(Vector2D start, Vector2D end, double & rad)
//{
//	Vector2D vec = { start.x - end.x, start.y - end.y };
//	double theta = atan2(vec.y, vec.x);
//
//	theta -= (10.0 * PI / 180);
//	_state.pos.x = end.x + rad * cos(theta);
//	_state.pos.y = end.y + rad * sin(theta);
//
//	if (rad <= 0)
//	{
//		_actMode = ENE_ACT::IDLE;
//	}
//	rad -= 2.0;
//
//	return true;
//}

bool EnemyMove::Line(Vector2D start, std::pair<Vector2D, float> end)
{
	/*_state.mov = Normalize(Vector2D(end.first - start));

	_state.pos += _state.mov * _state.speed;

	if (sqrt(pow(start.x - end.first.x, 2) + pow(start.y - end.first.y, 2)) <= end.second)
	{
		_state.pos = end.first;
		_actMode = ENE_ACT::IDLE;
	}*/
	return true;
}
