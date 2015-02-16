/******************************************************************************/
/*!
\file	2D_Collision_Detection.h
\author Chuk Yih Jou
\brief
Class to check 3D objects collide or not
*/
/******************************************************************************/
#ifndef threeD_COLLISIONDETECTION_H
#define threeD_COLLISIONDETECTION_H

#include "3D_HitBox.h"
/******************************************************************************/
/*!
Class twoD_Collision_Detection:
\brief	check for collsion detection
*/
/******************************************************************************/

class threeD_Collision_Detection
{
public:
    threeD_Collision_Detection(void);
    ~threeD_Collision_Detection(void);

    void SATCheckCollision_3D(threeD_HitBox &BoxA, threeD_HitBox &BoxB, bool &collide);
    float abs(float value);     // absolute value
    

    Vector3 T;
    Vector3 L;

    bool c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15;
};

#endif