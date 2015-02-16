/******************************************************************************/
/*!
\file	2D_PhysicAndCollision.h
\author Chuk Yih Jou
\brief
Class to build 2D scene
*/
/******************************************************************************/
#ifndef TwoD_PHYSICANDCOLLISION_H
#define TwoD_PHYSICANDCOLLISION_H

#include "Scene.h"
#include "Vector2.h"
#include "MatrixStack.h"
#include "FirstPersonCamera.h"
#include "MeshBuilder.h"
#include "2D_Collision_Detection.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using std::string;
/******************************************************************************/
/*!
Class twoD_scene:
\brief	build 2D scenes, use this check for collision and implement physic
*/
/******************************************************************************/
class twoD_scene : public Scene
{
    enum UNIFORM_TYPE
    {
        U_MVP = 0,
        U_COLOR_TEXTURE_ENABLED,
        U_COLOR_TEXTURE,
        U_TEXT_ENABLED,
        U_TEXT_COLOR,
        U_TOTAL,
    };

    enum GEOMETRY_TYPE
    {
        GEO_QUAD,
        GEO_TEXT,
        GEO_LINE,
        GEO_LINE2,
        NUM_GEOMETRY,
    };
private:
    Mesh* meshList[NUM_GEOMETRY];
    unsigned m_vertexArrayID;
    unsigned m_programID;
    unsigned m_parameters[U_TOTAL];

    void RenderMesh(Mesh *mesh, bool enableLight);
    void RenderText(Mesh* mesh, std::string text, Color color);
    void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);

public:
    twoD_HitBox hb1;
    twoD_HitBox hb2;

    twoD_Collision_Detection check;

    float translateX, translateY, tx, ty;
    float scale, s;
    float rotate, r;
    float velocity;

    bool collide;

    twoD_scene();
    ~twoD_scene();
    MS sceneStack, viewStack, projectionStack;
    void Init();
    void Update(double dt);
    void Render();
    void Exit();

    double t;
};

#endif
