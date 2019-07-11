#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	//γόZq
	Vector2& operator=(const Vector2& vec);

	//Y¦Zq
	//int& operator[](const int i);

	//δrZq
	bool operator==(const Vector2& vec)const;
	bool operator!=(const Vector2& vec)const;
	bool operator>=(const Vector2& vec)const;
	bool operator<=(const Vector2& vec)const;
	bool operator>(const Vector2& vec)const;
	bool operator<(const Vector2& vec)const;

	//PZq
	Vector2& operator+=(const Vector2& vec);
	Vector2& operator-=(const Vector2& vec);
	Vector2& operator*=(const float k);
	Vector2& operator/=(const float k);
	Vector2 operator+()const;
	Vector2 operator-()const;

	//³K»
	bool Normalized(void);

	//xNgΜε«³ζΎ
	float magnitude(void);

	//ΐWξρ
	float x;
	float y;
};

//VECTOR2ΖfloatΜPZq
Vector2 operator+(const Vector2& vec, const float i);
Vector2 operator-(const Vector2& vec, const float i);
Vector2 operator*(const Vector2& vec, const float i);
Vector2 operator*(const float i, const Vector2& vec);
Vector2 operator/(const Vector2& vec, const float i);
//Vector2 operator%(const Vector2& vec, const int i);


//VECTOR2―mΜPZq
Vector2 operator+(const Vector2& vec, const Vector2& vec2);
Vector2 operator-(const Vector2& vec, const Vector2& vec2);

//VECTOR2ΜΰΟπΤ·
float Dot(const Vector2& vec, const Vector2& vec2);

//VECTOR2ΜOΟπΤ·
float Cross(const Vector2& vec, const Vector2& vec2);

Vector2 Normalize(Vector2 vec);