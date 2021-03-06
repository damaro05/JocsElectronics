#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "entity.h"

class Controller
{
public:
	Entity* target;
	const Uint8* keystate;
	SDL_Joystick* pad;
	Camera* camera;
	bool active;

	Controller();
	virtual ~Controller();
	virtual void update(float dt);

	void setTarget(Entity* entity);

	Camera* getCamera();
};


class ControllerIA : public Controller
{
public:
	std::vector<Vector3> s_checkpoints;

	int checkpoint;
	bool dynamic_controller;
	bool attack;
	ControllerIA();
	~ControllerIA();

	void update(float dt);

};

#endif
