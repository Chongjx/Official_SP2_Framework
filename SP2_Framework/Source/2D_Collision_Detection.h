/******************************************************************************/
/*!
\file	2D_Collision_Detection.h
\author Chuk Yih Jou
\brief
Class to check 2D objects collide or not
*/
/******************************************************************************/
#ifndef TwoD_COLLISIONDETECTION_H
#define TwoD_COLLISIONDETECTION_H

#include "2D_HitBox.h"
/******************************************************************************/
/*!
Class twoD_Collision_Detection:
\brief	check for collsion detection
*/
/******************************************************************************/

class twoD_Collision_Detection
{
public:
    twoD_Collision_Detection(void);
    ~twoD_Collision_Detection(void);

    void SATCheckCollision(twoD_HitBox &BoxA, twoD_HitBox &BoxB, bool &collide);
    float abs(float value);     // absolute value

    Vector2 T;
    Vector2 L;

    bool c1, c2, c3, c4;
};

#endif