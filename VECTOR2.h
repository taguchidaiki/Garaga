#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	//������Z�q
	Vector2& operator=(const Vector2& vec);

	//�Y�������Z�q
	//int& operator[](const int i);

	//��r���Z�q
	bool operator==(const Vector2& vec)const;
	bool operator!=(const Vector2& vec)const;
	bool operator>=(const Vector2& vec)const;
	bool operator<=(const Vector2& vec)const;
	bool operator>(const Vector2& vec)const;
	bool operator<(const Vector2& vec)const;

	//�P�����Z�q
	Vector2& operator+=(const Vector2& vec);
	Vector2& operator-=(const Vector2& vec);
	Vector2& operator*=(const float k);
	Vector2& operator/=(const float k);
	Vector2 operator+()const;
	Vector2 operator-()const;

	//���W���
	float x;
	float y;
};

//VECTOR2��float�̒P�����Z�q
Vector2 operator+(const Vector2& vec, const float i);
Vector2 operator-(const Vector2& vec, const float i);
Vector2 operator*(const Vector2& vec, const float i);
Vector2 operator*(const float i, const Vector2& vec);
Vector2 operator/(const Vector2& vec, const float i);
//Vector2 operator%(const Vector2& vec, const int i);


//VECTOR2���m�̒P�����Z�q
Vector2 operator+(const Vector2& vec, const Vector2& vec2);
Vector2 operator-(const Vector2& vec, const Vector2& vec2);

//VECTOR2�̓��ς�Ԃ�
float Dot(const Vector2& vec, const Vector2& vec2);

//VECTOR2�̊O�ς�Ԃ�
float Cross(const Vector2& vec, const Vector2& vec2);