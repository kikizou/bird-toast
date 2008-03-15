#include <math.h>
#include "physics.h"

// ----------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------
Vector::Vector()
{
	x = y = 0;
}

Vector::Vector( float x, float y )
{
	this->x = x;
	this->y = y;
}

// ----------------------------------------------------------------------------
// Assignment operators
// ----------------------------------------------------------------------------
Vector& Vector::operator =( const Vector &r )
{
	// Check for self-assignment
	if( this == &r )
		return *this;
	else
	{
		x = r.x;
		y = r.y;
		return *this;
	}
}


Vector& Vector::operator +=( const Vector &r )
{
	x += r.x;
	y += r.y;
	return *this;
}

Vector& Vector::operator -=( const Vector &r )
{
	x -= r.x;
	y -= r.y;
	return *this;
}

Vector& Vector::operator *=( const float s )
{
	x *= s;
	y *= s;
	return *this;
}

Vector& Vector::operator /=( const float s )
{
	x /= s;
	y /= s;
	return *this;
}


// ----------------------------------------------------------------------------
// Binary Operators
// ----------------------------------------------------------------------------
const Vector operator +( const Vector &l, const Vector &r )
{
	Vector result;
	result.x = l.x + r.x;
	result.y = l.y + r.y;
	return result;
}

const Vector operator -( const Vector &l, const Vector &r )
{
	Vector result;
	result.x = l.x - r.x;
	result.y = l.y - r.y;
	return result;
}

const Vector operator *( const Vector &l, const float s )
{
	Vector result;
	result.x = l.x * s;
	result.y = l.y * s;
	return result;
}

/*
 * Dot product
 */
const float operator *( const Vector &l, const Vector &r )
{
	return (l.x * r.x + l.y * r.y);
}

const Vector operator /( const Vector &l, const float s )
{
	Vector result;
	result.x = l.x / s;
	result.y = l.y / s;
	return result;
}


/*
 * Magnitude
 */
const float Vector::length()
{
	return sqrt(x * x + y * y);
}


/*
* Projection of u onto v
*/
const Vector proj( Vector &u, Vector &v )
{
	return v * ((u * v) / v.length());
}
