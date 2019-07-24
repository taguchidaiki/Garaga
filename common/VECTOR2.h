#pragma once

template<class T>
class Vector2Temple
{
public:
	Vector2Temple();
	Vector2Temple(T x, T y);
	~Vector2Temple();

	//‘ã“ü‰‰Zq
	Vector2Temple<T>& operator=(const Vector2Temple<T>& vec);

	//“Y‚¦š‰‰Zq
	//int& operator[](const int i);

	//”äŠr‰‰Zq
	bool operator==(const Vector2Temple& vec)const;
	bool operator!=(const Vector2Temple& vec)const;
	bool operator>=(const Vector2Temple& vec)const;
	bool operator<=(const Vector2Temple& vec)const;
	bool operator>(const Vector2Temple& vec)const;
	bool operator<(const Vector2Temple& vec)const;

	//’P€‰‰Zq
	Vector2Temple& operator+=(const Vector2Temple& vec);
	Vector2Temple& operator-=(const Vector2Temple& vec);
	Vector2Temple<T>& operator*=(const T k);
	Vector2Temple<T>& operator/=(const T k);
	Vector2Temple operator+()const;
	Vector2Temple operator-()const;

	//³‹K‰»
	bool Normalized(void);

	//ƒxƒNƒgƒ‹‚Ì‘å‚«‚³æ“¾
	float magnitude(void);

	//À•Wî•ñ
	T x;
	T y;
};

//Vector2Temple‚Æfloat‚Ì’P€‰‰Zq
template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T>& vec, const T i);
template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T>& vec, const T i);
template<class T>
Vector2Temple<T> operator*(const Vector2Temple<T>& vec, const T i);
template<class T>
Vector2Temple<T> operator*(const T i, const Vector2Temple<T>& vec);
template<class T>
Vector2Temple<T> operator/(const Vector2Temple<T>& vec, const float i);
template<class T>
Vector2Temple<T> operator%(const Vector2Temple<T>& vec, const T i);

template<class T>
Vector2Temple<T> operator*(const Vector2Temple<T>& vec, const float i);



//Vector2Temple“¯m‚Ì’P€‰‰Zq
template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T>& vec, const Vector2Temple<T>& vec2);
template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T>& vec, const Vector2Temple<T>& vec2);

//Vector2Temple‚Ì“àÏ‚ğ•Ô‚·
template<class T>
float Dot(const Vector2Temple<T>& vec, const Vector2Temple<T>& vec2);

//Vector2Temple‚ÌŠOÏ‚ğ•Ô‚·
template<class T>
float Cross(const Vector2Temple<T>& vec, const Vector2Temple<T>& vec2);

template<class T>
Vector2Temple<T> Normalize(Vector2Temple<T> vec);

using Vector2 = Vector2Temple<int>;
using Vector2F = Vector2Temple<float>;
using Vector2D = Vector2Temple<double>;

#include "./details/VECTOR2.h"