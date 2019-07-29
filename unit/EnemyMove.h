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
	//xとyの範囲を0~1に正規化済みのシグモイド曲線の値を返す
	/*float Sigmoid(float x, float a);
	bool Sigmoid(Vector2D start, Vector2D end, float til);

	bool Cyclone(Vector2D start, Vector2D end, double& rad);*/

	bool Line(Vector2D start, std::pair<Vector2D, float> end);
};

