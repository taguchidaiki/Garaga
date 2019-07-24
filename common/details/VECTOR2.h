#pragma once
#include "../VECTOR2.h"
#include <math.h>


template<class T>
Vector2Temple<T>::Vector2Temple():x(0),y(0)
{
}

template<class T>
Vector2Temple<T>::Vector2Temple(T x, T y):x(x), y(y)
{
}

template<class T>
Vector2Temple<T>::~Vector2Temple()
{
}

template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator=(const Vector2Temple & vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
}

//template<class T>
//int & Vector2Temple<T>::operator[](const int i)
//{
//	if (i == 0)
//	{
//		return x;
//	}
//	else if (i == 1)
//	{
//		return y;
//	}
//
//	return x;
//}

template<class T>
bool Vector2Temple<T>::operator==(const Vector2Temple & vec) const
{
	return  ((x == vec.x) && (y == vec.y));
}

template<class T>
bool Vector2Temple<T>::operator!=(const Vector2Temple & vec) const
{
	return !((x == vec.x) && (y == vec.y));
}

template<class T>
bool Vector2Temple<T>::operator>=(const Vector2Temple & vec) const
{
	return ((x >= vec.x) && (y >= vec.y));
}

template<class T>
bool Vector2Temple<T>::operator<=(const Vector2Temple & vec) const
{
	return ((x <= vec.x) && (y <= vec.y));
}

template<class T>
bool Vector2Temple<T>::operator>(const Vector2Temple & vec) const
{
	return ((x > vec.x) && (y > vec.y));
}

template<class T>
bool Vector2Temple<T>::operator<(const Vector2Temple & vec) const
{
	return ((x < vec.x) && (y < vec.y));
}

template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator+=(const Vector2Temple & vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator-=(const Vector2Temple & vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator*=(const T k)
{
	x *= k;
	y *= k;
	return *this;
}

template<class T>
Vector2Temple<T> & Vector2Temple<T>::operator/=(const T k)
{
	x /= k;
	y /= k;
	return *this;
}

template<class T>
Vector2Temple<T> Vector2Temple<T>::operator+() const
{
	return *this;
}

template<class T>
Vector2Temple<T> Vector2Temple<T>::operator-() const
{
	return Vector2Temple(-x, -y);
}

template<class T>
bool Vector2Temple<T>::Normalized(void)
{
	float mag = magnitude();
	x = x / mag;
	y = y / mag;
	return true;
}

template<class T>
float Vector2Temple<T>::magnitude(void)
{
	return sqrt(x * x + y * y);
}

//Vector2TempleÇ∆floatÇÃíPçÄââéZéq
template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T> & vec, const T i)
{
	return Vector2Temple<T>(vec.x + i, vec.y + i);
}

template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T> & vec, const T i)
{
	return Vector2Temple<T>(vec.x - i, vec.y - i);
}

template<class T>
Vector2Temple<T> operator*(const Vector2Temple<T> & vec, const T i)
{
	return Vector2Temple<T>(vec.x * i, vec.y * i);
}

template<class T>
Vector2Temple<T> operator*(const T i, const Vector2Temple<T> & vec)
{
	return Vector2Temple<T>(vec.x * i, vec.y * i);
}

template<class T>
Vector2Temple<T> operator/(const Vector2Temple<T> & vec, const float i)
{
	return Vector2Temple<T>(vec.x / i, vec.y / i);
}

template<class T>
Vector2Temple<T> operator%(const Vector2Temple<T> & vec, const T i)
{
	return Vector2Temple<T>(vec.x % i , vec.y % i);
}

template<class T>
inline Vector2Temple<T> operator*(const Vector2Temple<T>& vec, const float i)
{
	return Vector2Temple<T>(vec.x * i, vec.y * i);
}

//Vector2TempleìØémÇÃíPçÄââéZéq
template<class T>
Vector2Temple<T> operator+(const Vector2Temple<T> & vec, const Vector2Temple<T> & vec2)
{
	return Vector2Temple<T>(vec.x + vec2.x, vec.y + vec2.y);
}

template<class T>
Vector2Temple<T> operator-(const Vector2Temple<T> & vec, const Vector2Temple<T> & vec2)
{
	return Vector2Temple<T>(vec.x - vec2.x, vec.y - vec2.y);
}

template<class T>
float Dot(const Vector2Temple<T> & vec, const Vector2Temple<T> & vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y);
}

template<class T>
float Cross(const Vector2Temple<T> & vec, const Vector2Temple<T> & vec2)
{
	return (vec.x * vec2.y - vec.y * vec2.x);
}

template<class T>
Vector2Temple<T> Normalize(Vector2Temple<T>  vec)
{
	float mag = vec.magnitude();
	return Vector2Temple<T>(vec.x / mag, vec.y / mag);
}
