#pragma once
#include <common/VECTOR2.h>
#include <utility>

class EnemyMove
{
public:
	EnemyMove();
	~EnemyMove();

	void Update(void);
	
private:
	//x��y�͈̔͂�0~1�ɐ��K���ς݂̃V�O���C�h�Ȑ��̒l��Ԃ�
	/*float Sigmoid(float x, float a);
	bool Sigmoid(Vector2D start, Vector2D end, float til);

	bool Cyclone(Vector2D start, Vector2D end, double& rad);*/

	bool Line(Vector2D start, std::pair<Vector2D, float> end);
};

