#ifndef ENTITY_H
#define ENTITY_H


#include "framework.h"
#include "utils.h"

class Camera;
class Mesh;
class Texture;

class Entity
{
public:
	unsigned int uid;
	std::string name;
	Matrix44 local_matrix;
	Matrix44 global_matrix;
	std::vector<Entity*> children;
	Entity* parent;

	Entity();
	~Entity();

	virtual void render( Camera* camera );
	virtual void update(float dt);

	void addChildren(Entity* entity);

	Matrix44 getGlobalMatrix() {
		if (parent)
			global_matrix = local_matrix * parent->getGlobalMatrix();
		else
			global_matrix = local_matrix;
		return global_matrix;
			
	}

};

class EntityMesh : public Entity
{
public:
	Mesh* mesh;
	Mesh* lod_mesh;
	Texture* texture;

	EntityMesh();
	//~EntityMesh();
	
	void render( Camera* camera );

};

#endif