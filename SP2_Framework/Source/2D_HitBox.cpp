#include "2D_HitBox.h"

twoD_HitBox::twoD_HitBox(void)
{
    Position.Set(0, 0);
    unitVecX.Set(0, 0);
    unitVecY.Set(0, 0);
    HalfWidth = -1.f;
    HalfHeight = -1.f;
}

twoD_HitBox::twoD_HitBox(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4)
{
    Position = calCenter(v1, v2, v3, v4);
    unitVecX = (v2 - v3).Normalized();
    unitVecY = (v1 - v2).Normalized();
    HalfWidth = calLength(v1, v2);
    HalfHeight = calLength(v2, v3);
}

twoD_HitBox::~twoD_HitBox(void)
{

}

void twoD_HitBox::Set(Vector2 &v1, Vector2 &v2, Vector2 &v3, Vector2 &v4)
{
    Position = calCenter(v1, v2, v3, v4);
    unitVecX = (v2 - v3).Normalized();
    unitVecY = (v2 - v1).Normalized();
    HalfWidth = calLength(v1, v2);
    HalfHeight = calLength(v3, v2);
}

Vector2 twoD_HitBox::calCenter(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4)
{
    Vector2 v;
    v.Set((v1.x + v3.x)/2, (v2.y + v4.y)/2);
    return v;
}

float twoD_HitBox::calLength(Vector2 v1, Vector2 v2)
{
    return (v2 - v1).Length() / 2;
}