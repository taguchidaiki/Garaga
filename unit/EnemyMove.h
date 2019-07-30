#pragma once
#include <common/VECTOR2.h>
#include <utility>
#include <memory>
#include <unit/Obj.h>

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
	EnemyMove();
	~EnemyMove();

	Vector2D Update(const TRNS& trns/*�Ȃ�̓��������邩�̏��������ɒǉ�����*/);
	
private:
	//x��y�͈̔͂�0~1�ɐ��K���ς݂̃V�O���C�h�Ȑ��̒l��Ԃ�
	float Sigmoid(float x, float a);
	//(�X�^�[�g�ʒu�A�S�[���ʒu�A�ړ��̋Ȑ��̂Ȃ��炩���A�ړ����)
	Vector2D Sigmoid(Vector2D start, Vector2D end, float til, const TRNS& trns);

	//(���݈ʒu�A�~�̒��S�A���a�A�ړ����)
	Vector2D Cyclone(Vector2D start, Vector2D end, double& rad, const TRNS& trns);

	//(�X�^�[�g�ʒu�A�S�[���ʒu�ƃS�[���͈́A�ړ����)
	Vector2D Line(Vector2D start, std::pair<Vector2D, float> end, const TRNS& trns);

	float count;
};

