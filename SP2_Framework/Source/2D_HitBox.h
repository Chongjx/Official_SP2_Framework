/******************************************************************************/
/*!
\file	2D_HitBox.h
\author Chuk Yih Jou
\brief
Class to build 2D hitbox
*/
/******************************************************************************/
#ifndef TwoD_HITBOX_H
#define TwoD_HITBOX_H

#include "Vector2.h"
/******************************************************************************/
/*!
Class twoD_HitBox:
\brief	build 2D hitbox for collsion detection
*/
/******************************************************************************/

class twoD_HitBox
{
public:
    twoD_HitBox(void);
    twoD_HitBox(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
    ~twoD_HitBox(void);

    void Set(Vector2 &v1, Vector2 &v2, Vector2 &v3, Vector2 &v4);
    Vector2 calCenter(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
    float calLength(Vector2 v1, Vector2 v2);

    Vector2 Position;
    Vector2 unitVecX;
    Vector2 unitVecY;

    float HalfWidth;
    float HalfHeight;
};

#endif