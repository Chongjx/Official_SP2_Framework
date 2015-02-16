/******************************************************************************/
/*!
\file	3D_HitBox.h
\author Chuk Yih Jou
\brief
Class to build 3D hitbox
*/
/******************************************************************************/
#ifndef ThreeD_HITBOX_H
#define ThreeD_HITBOX_H

#include "Vector3.h"
/******************************************************************************/
/*!
Class threeD_HitBox:
\brief	build 3D hitbox for collsion detection
*/
/******************************************************************************/

class threeD_HitBox
{
public:
    threeD_HitBox(void);
    ~threeD_HitBox(void);

    void Set(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4, Vector3 v5, Vector3 v6, Vector3 v7, Vector3 v8);
    Vector3 calCenter(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4, Vector3 v5, Vector3 v6, Vector3 v7, Vector3 v8);
    float calLength(Vector3 v1, Vector3 v2);

    Vector3 Position;

    Vector3 unitVecX;
    Vector3 unitVecY;
    Vector3 unitVecZ;

    float HalfWidth;
    float HalfHeight;
    float HalfDepth;
};

#endif