#pragma once

#include "Pos.h"

struct Rigidbody2D
{
	Rigidbody2D();
	Rigidbody2D(Vector2* _objectPos);

	bool isGravityEnabled = false;
	Vector2* objectPos = nullptr;
	Vector2 velocity;
	Vector2 forceDir; //MAX 1, MIN 0
	Vector2 force;

	float forceMagnitude = 0.0f;
	float bounciness = 1.0f;
	float friction = 0.0f;

	void Update();
	void AddForce(Vector2 _forceVector2);
	void AttachToPos(Vector2& pos);
	void ReverseAngle();
	void ReverseAngle(Vector2 _appliedForce);
	float GetForceMagnitude();
	float GetVelocityMagnitude();

	static Vector2& S_GetGravity();
	static void S_ModifyGravity(float _x, float _y);

private:
	void GravityUpdate();

};

