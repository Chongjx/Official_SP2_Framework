#ifndef OBJECTS_H
#define OBJECTS_H

#include "MatrixStack.h"
#include "Mesh.h"
#include "MeshBuilder.h"
#include <iostream>

enum OBJECT_TYPES
{
	OBJ_ANIMALS = 0,
	OBJ_HUMAN,
	OBJ_BALLOON,
	OBJ_SHELF,
	OBJ_MISCE,
	MAX_OBJ,
	// OBJ_...
};

struct properties
{
	Mtx44 modelProperties;

	properties()
	{
		modelProperties.SetToIdentity();
	}
};

class Objects
{
private:
	Mesh* mesh;
	Vector3 pos;
	properties TRS;
	bool render;
	bool reflectLight;
	OBJECT_TYPES obj;
	Objects *parentObj;
public:
	Objects(void);
	~Objects(void);

	void setAll(Mesh* _mesh, Vector3 _pos, properties _TRS, bool _render, bool _reflectLight, OBJECT_TYPES _obj, Objects *_parentObj);

	void setMesh(Mesh* _mesh);
	Mesh* getMesh(void) const;

	void setPos(Vector3 _pos);
	Vector3 getPos(void) const;

	void setProperties(properties _TRS);
	properties getProperties(void) const;

	void setRender(bool _render);
	bool getRender(void) const;

	void setReflectLight(bool _reflectLight);
	bool getReflectLight(void) const;

	void setOBJ(OBJECT_TYPES _obj);
	OBJECT_TYPES getOBJ(void) const;

	void setParent(Objects *_parentObj);
	Objects* getParentObj(void) const;
};

#endif