#ifndef ENEMY_H
#define ENEMY_H

#include "Vector2D.h"
#include "gl2d.h"
#include "Aabb.h"

class Enemy{
public:
	Enemy(){
		wasHurt=false;
	}

	virtual ~Enemy();


	virtual bool update(float time);
	virtual bool render(float time)=0;
	virtual void init();
	virtual void cleanUp();
	virtual bool collides(Vector2D<float> pos,Vector2D<float> size);
	virtual void loadTextures()=0;

	virtual void hurt();

	Vector2D<float> pos;
	Vector2D<float> dir;
	float angle;

	int life;

	int loops;

	AABB	Aabb;

	bool isAlive;

	float radius;

	int energy;

	bool wasHurt;
	float hurtTimer;



};

#endif