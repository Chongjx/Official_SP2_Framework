/******************************************************************************/
/*!
\file	3D_PhysicAndCollision.h
\author Chuk Yih Jou
\brief
Class to build ...
*/
/******************************************************************************/

#ifndef THREED_PHYSICANDCOLLISION_H
#define THREED_PHYSICANDCOLLISION_H

#include "Scene.h"
#include "FirstPersonCamera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Material.h"
#include "Light.h"
#include "3D_Collision_Detection.h"

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
using std::to_string;

/******************************************************************************/
/*!
Class Scene_SuperMarket:
\brief	Provide methods to build a Scene_SuperMarket for SP2
*/
/******************************************************************************/
class threeD_scene : public Scene
{
    enum UNIFORM_TYPE
    {
        U_MVP = 0,
        U_SCENEVIEW,
        U_SCENEVIEW_INVERSE_TRANSPOSE,
        U_MATERIAL_AMBIENT,
        U_MATERIAL_DIFFUSE,
        U_MATERIAL_SPECULAR,
        U_MATERIAL_SHININESS,
        U_LIGHT0_POSITION,
        U_LIGHT0_COLOR,
        U_LIGHT0_POWER,
        U_LIGHT0_KC,
        U_LIGHT0_KL,
        U_LIGHT0_KQ,
        U_LIGHTENABLED,		
        U_LIGHT0_TYPE,
        U_LIGHT0_SPOTDIRECTION,
        U_LIGHT0_COSCUTOFF,
        U_LIGHT0_COSINNER,
        U_LIGHT0_EXPONENT,
        U_NUMLIGHTS,
        U_COLOR_TEXTURE_ENABLED,
        U_COLOR_TEXTURE,
        U_TEXT_ENABLED,
        U_TEXT_COLOR,
        U_TOTAL,
    };

    enum GEOMETRY_TYPE
    {
        GEO_QUAD,
        GEO_AXES,
        GEO_TEXT,
        GEO_CUBE,
        NUM_GEOMETRY,
    };
public:
    threeD_scene();
    ~threeD_scene();
    MS sceneStack, viewStack, projectionStack;
    void Init();
    void Update(double dt);
    void Render();
    void Exit();

private:
    Mesh* meshList[NUM_GEOMETRY];
    unsigned m_vertexArrayID;
    unsigned m_programID;
    unsigned m_parameters[U_TOTAL];

    FPSCamera camera;
    Light light[1];

    float deltaTime;

    threeD_HitBox hb1;

    float translateX, translateY, translateZ, tx, ty;
    float scale, s;
    float rotate, r;
    float velocity;

    bool collide;

    void RenderMesh(Mesh *mesh, bool enableLight);
    void RenderText(Mesh* mesh, std::string text, Color color);
    void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
};

#endif