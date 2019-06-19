#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	//‘ã“ü‰‰ŽZŽq
	Vector2& operator=(const Vector2& vec);

	//“Y‚¦Žš‰‰ŽZŽq
	//int& operator[](const int i);

	//”äŠr‰‰ŽZŽq
	bool operator==(const Vector2& vec)const;
	bool operator!=(const Vector2& vec)const;
	bool operator>=(const Vector2& vec)const;
	bool operator<=(const Vector2& vec)const;
	bool operator>(const Vector2& vec)const;
	bool operator<(const Vector2& vec)const;

	//’P€‰‰ŽZŽq
	Vector2& operator+=(const Vector2& vec);
	Vector2& operator-=(const Vector2& vec);
	Vector2& operator*=(const float k);
	Vector2& operator/=(const float k);
	Vector2 operator+()const;
	Vector2 operator-()const;

	//À•Wî•ñ
	float x;
	float y;
};

//VECTOR2‚Æfloat‚Ì’P€‰‰ŽZŽq
Vector2 operator+(const Vector2& vec, const float i);
Vector2 operator-(const Vector2& vec, const float i);
Vector2 operator*(const Vector2& vec, const float i);
Vector2 operator*(const float i, const Vector2& vec);
Vector2 operator/(const Vector2& vec, const float i);
//Vector2 operator%(const Vector2& vec, const int i);


//VECTOR2“¯Žm‚Ì’P€‰‰ŽZŽq
Vector2 operator+(const Vector2& vec, const Vector2& vec2);
Vector2 operator-(const Vector2& vec, const Vector2& vec2);

//VECTOR2‚Ì“àÏ‚ð•Ô‚·
float Dot(const Vector2& vec, const Vector2& vec2);

//VECTOR2‚ÌŠOÏ‚ð•Ô‚·
float Cross(const Vector2& vec, const Vector2& vec2);