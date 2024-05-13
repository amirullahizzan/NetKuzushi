#pragma once

#include "../customcommon/GameObject.h"
#include "../customcommon/Sprite.h"
#include "../customcommon/Rigidbody2D.h"
#include "../customcommon/Primitive.h"

struct Ball : GameObject
{
	Ball();
	Ball(Vector2 _spawnPos, int _sprite);
	double angle;
	int sprite;
	Circle circle;
	int type = 0;

	void Update() override;
	void Render() override;
	void ReverseDirX();
	void ReverseDirY();
	void ReverseDir();
	void AddSpeed();
	void SetSpeed(float _newSpeed);
	void RestoreSpeed();
	float speed = 1.00f;
	bool isColliding = false;

	protected:
	void LaunchDownRandom();
private:
	int savedSpeed = 0;
	Vector2 dir;
	float vx = 0;
	float vy = 0;
};

struct RedBall : Ball
{
	RedBall(Vector2 _spawnPos, int _sprite) : Ball(_spawnPos, _sprite)
	{
		speed = 1.75f;
		type = 1;
		LaunchDownRandom();
	}
};