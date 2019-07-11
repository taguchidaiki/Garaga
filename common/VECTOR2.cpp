#include "VECTOR2.h"
#include <math.h>



Vector2::Vector2():x(0),y(0)
{
}

Vector2::Vector2(float x, float y):x(x), y(y)
{
}


Vector2::~Vector2()
{
}

Vector2 & Vector2::operator=(const Vector2 & vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
}

//int & Vector2::operator[](const int i)
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

bool Vector2::operator==(const Vector2 & vec) const
{
	return  ((x == vec.x) && (y == vec.y));
}

bool Vector2::operator!=(const Vector2 & vec) const
{
	return !((x == vec.x) && (y == vec.y));
}

bool Vector2::operator>=(const Vector2 & vec) const
{
	return ((x >= vec.x) && (y >= vec.y));
}

bool Vector2::operator<=(const Vector2 & vec) const
{
	return ((x <= vec.x) && (y <= vec.y));
}

bool Vector2::operator>(const Vector2 & vec) const
{
	return ((x > vec.x) && (y > vec.y));
}

bool Vector2::operator<(const Vector2 & vec) const
{
	return ((x < vec.x) && (y < vec.y));
}

Vector2 & Vector2::operator+=(const Vector2 & vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

Vector2 & Vector2::operator*=(const float k)
{
	x *= k;
	y *= k;
	return *this;
}

Vector2 & Vector2::operator/=(const float k)
{
	x /= k;
	y /= k;
	return *this;
}

Vector2 Vector2::operator+() const
{
	return *this;
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

bool Vector2::Normalized(void)
{
	
	return true;
}

float Vector2::magnitude(void)
{
	return sqrt(x * x + y * y);
}

//VECTOR2‚Æfloat‚Ì’P€‰‰ŽZŽq
Vector2 operator+(const Vector2 & vec, const float i)
{
	return Vector2(vec.x + i, vec.y + i);
}

Vector2 operator-(const Vector2 & vec, const float i)
{
	return Vector2(vec.x - i, vec.y - i);
}

Vector2 operator*(const Vector2 & vec, const float i)
{
	return Vector2(vec.x * i, vec.y * i);
}

Vector2 operator*(const float i, const Vector2 & vec)
{
	return Vector2(vec.x * i, vec.y * i);
}

Vector2 operator/(const Vector2 & vec, const float i)
{
	return Vector2(vec.x / i, vec.y / i);
}

//Vector2 operator%(const Vector2 & vec, const int i)
//{
//	return Vector2(vec.x % i , vec.y % i);
//}

//VECTOR2“¯Žm‚Ì’P€‰‰ŽZŽq
Vector2 operator+(const Vector2 & vec, const Vector2 & vec2)
{
	return Vector2(vec.x + vec2.x, vec.y + vec2.y);
}

Vector2 operator-(const Vector2 & vec, const Vector2 & vec2)
{
	return Vector2(vec.x - vec2.x, vec.y - vec2.y);
}


float Dot(const Vector2 & vec, const Vector2 & vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y);
}

float Cross(const Vector2 & vec, const Vector2 & vec2)
{
	return (vec.x * vec2.y - vec.y * vec2.x);
}

Vector2 Normalize(Vector2  vec)
{
	float mag = vec.magnitude();
	return Vector2(vec.x / mag, vec.y / mag);
}
