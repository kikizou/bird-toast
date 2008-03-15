#ifndef BT_PHYSICS_H
#define BT_PHYSICS_H


// ----------------------------------------------------------------------------
// struct Vector
// ----------------------------------------------------------------------------
class Vector
{
public:
	Vector();
	Vector( float x, float y );

	// Assignment operators
	Vector& operator =( const Vector &r );

	// Compound operators
	Vector& operator +=( const Vector &r );
	Vector& operator -=( const Vector &r );
	Vector& operator *=( const float s );
	Vector& operator /=( const float s );

	// Binary operators
	friend const Vector operator +( const Vector &l, const Vector &r );
	friend const Vector operator -( const Vector &l, const Vector &r );
	friend const Vector operator *( const Vector &l, const float s );
	friend const float operator *( const Vector &l, const Vector &r );
	friend const Vector operator /( const Vector &l, const float s );

	const float length();	// magnitude

	/*
	 * Projection of u onto v
	 */
	friend const Vector proj( Vector &u, Vector &v );

	float x;
	float y;
};


#endif
