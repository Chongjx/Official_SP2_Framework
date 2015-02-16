#include <cmath>
#include "Vector2.h"

Vector2::Vector2(float a, float b) : x(a), y(b)
{
}

Vector2::Vector2(const Vector2 &rhs) : x(rhs.x), y(rhs.y)
{
}

Vector2::~Vector2()
{
}

void Vector2::Set( float a, float b)
{
	x = a;
	y = b;
}

Vector2 Vector2::operator+( const Vector2& rhs ) const
{
    return Vector2(x + rhs.x, y + rhs.y);
}

/******************************************************************************/
/*!
\brief
operator+= overload for vector addition and assignment

\param rhs
	Vector2 to add with
\return 
	Resulting vector
*/
/******************************************************************************/
Vector2& Vector2::operator+=( const Vector2& rhs )
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2 Vector2::operator-( const Vector2& rhs ) const
{
    return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator-( void ) const
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator*( float scalar ) const
{
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator*( const Vector2& rhs ) const
{
	return Vector2(x * rhs.x, y * rhs.y);
}


float Vector2::Length( void ) const
{
  return sqrt(x * x + y * y);
}

float Vector2::Dot( const Vector2& rhs ) const
{
	return ((x * rhs.x) + (y * rhs.y));
}

Vector2 Vector2::Normalized( void ) const throw( DivideByZero )
{
	float d = Length(); 
    if(d <= Math::EPSILON && -d <= Math::EPSILON)
	  throw DivideByZero();
	return Vector2(x / d, y / d);
}

std::ostream& operator<< (std::ostream& os, Vector2& rhs)
{
	os << "[ " << rhs.x << ", " << rhs.y << " ]";
	return os;
}

Vector2 operator*( float scalar, const Vector2& rhs )
{
	return rhs * scalar;
}
