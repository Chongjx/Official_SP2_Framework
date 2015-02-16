#include "3D_HitBox.h"

#include "2D_HitBox.h"

threeD_HitBox::threeD_HitBox(void)
{
    Position.Set(0, 0);
    unitVecX.Set(0, 0);
    unitVecY.Set(0, 0);
    HalfWidth = -1.f;
    HalfHeight = -1.f;
}

threeD_HitBox::~threeD_HitBox(void)
{

}

void threeD_HitBox::Set(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4, Vector3 v5, Vector3 v6, Vector3 v7, Vector3 v8)
{
    Position = calCenter(v1, v2, v3, v4, v5, v6, v7, v8);
    unitVecX = (v2 - v3).Normalized();
    unitVecY = (v4 - v5).Normalize();
    unitVecZ = (v1 - v2).Normalized();
    HalfWidth = calLength(v3, v2);
    HalfHeight = calLength(v5, v6);
    HalfDepth = calLength(v1, v2);
}

Vector3 threeD_HitBox::calCenter(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4, Vector3 v5, Vector3 v6, Vector3 v7, Vector3 v8)
{
    Vector3 v;
    v.Set((v1.x + v3.x)/2, (v2.y + v4.y)/2, (v5.z + v7.z)/2);
    return v;
}

float threeD_HitBox::calLength(Vector3 v1, Vector3 v2)
{
    return (v2 - v1).Length() / 2;
}