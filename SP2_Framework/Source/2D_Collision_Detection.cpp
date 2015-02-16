#include "2D_Collision_Detection.h"

twoD_Collision_Detection::twoD_Collision_Detection(void)
{
    c1 = c2 = c3 = c4 = true;
}

twoD_Collision_Detection::~twoD_Collision_Detection(void)
{

}

void twoD_Collision_Detection::SATCheckCollision(twoD_HitBox &BoxA, twoD_HitBox &BoxB, bool &collide)
{
    T = BoxB.Position - BoxA.Position;
    
    // case 1
    L = BoxA.unitVecX;
    if (abs(T.Dot(L)) > abs((BoxA.unitVecX * BoxA.HalfWidth).Dot(L)) + 
                        abs((BoxA.unitVecY * BoxA.HalfHeight).Dot(L)) +
                        abs((BoxB.unitVecX * BoxB.HalfWidth).Dot(L)) +
                        abs((BoxB.unitVecY * BoxB.HalfHeight).Dot(L)))
    {
        c1 = true;
    }

    else
    {
        c1 = false;
    }

    // case 2
    L = BoxA.unitVecY;
    if (abs(T.Dot(L)) > abs((BoxA.unitVecX * BoxA.HalfWidth).Dot(L)) + 
                        abs((BoxA.unitVecY * BoxA.HalfHeight).Dot(L)) +
                        abs((BoxB.unitVecX * BoxB.HalfWidth).Dot(L)) +
                        abs((BoxB.unitVecY * BoxB.HalfHeight).Dot(L)))
    {
        c2= true;
    }

    else
    {
        c2 = false;
    }

    // case 3
    L = BoxB.unitVecX;
    if (abs(T.Dot(L)) > abs((BoxA.unitVecX * BoxA.HalfWidth).Dot(L)) + 
                        abs((BoxA.unitVecY * BoxA.HalfHeight).Dot(L)) +
                        abs((BoxB.unitVecX * BoxB.HalfWidth).Dot(L)) +
                        abs((BoxB.unitVecY * BoxB.HalfHeight).Dot(L)))
    {
        c3 = true;
    }

    else
    {
        c3 = false;
    }

    // case 3
    L = BoxB.unitVecY;
    if (abs(T.Dot(L)) > abs((BoxA.unitVecX * BoxA.HalfWidth).Dot(L)) + 
                        abs((BoxA.unitVecY * BoxA.HalfHeight).Dot(L)) +
                        abs((BoxB.unitVecX * BoxB.HalfWidth).Dot(L)) +
                        abs((BoxB.unitVecY * BoxB.HalfHeight).Dot(L)))
    {
        c4 = true;
    }

    else
    {
        c4 = false;
    }


    if (c1 == false && c2 == false && c3 == false && c4 == false)
    {
        collide = true;
    }

    else
    {
        collide = false;
    }

}

float twoD_Collision_Detection::abs(float value)
{
    if (value < 0)
    {
        return value * (-1);
    }

    else
    {
        return value;
    }
}