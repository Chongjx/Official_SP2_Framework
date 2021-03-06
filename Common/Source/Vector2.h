#ifndef VECTOR_2_H
#define VECTOR_2_H

#include "MyMath.h"
#include <iostream>

#pragma warning( disable: 4290 ) //for throw(DivideByZero)

struct Vector2 {
    float x, y;

    Vector2(float a = 0, float b = 0);  //default constructor
    Vector2(const Vector2&rhs);         //copy constructor
    ~Vector2();

    void Set(float a, float b);         //Set all data

    Vector2 operator+(const Vector2& rhs) const;    //Vector addition
    Vector2& operator+=( const Vector2& rhs ); 

    Vector2 operator-(const Vector2& rhs) const;    //Vector subtraction
    Vector2 operator-(void) const;                  //Unary negation

    Vector2 operator*(float scalar) const;          //Scalar multiplication
    Vector2 operator*( const Vector2& rhs ) const; //Vector multiplication

    float Length(void) const;           //get magnitude
    float Dot(const Vector2& rhs) const;            //dot product
    Vector2 Normalized(void) const throw( DivideByZero );           //return copy of this vector, normalized

    friend std::ostream& operator<<( std::ostream& os, Vector2& rhs); //print to ostream
    friend Vector2 operator*( float scalar, const Vector2& rhs ); //what is this for?
};

#endif