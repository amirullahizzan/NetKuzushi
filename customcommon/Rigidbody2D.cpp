#include "../src/WinMain.h"
#include "Rigidbody2D.h"
#include "GameTime.h"

extern GameTime gameTime;

Rigidbody2D::Rigidbody2D()
{
	printf("Constructed times");
}

Rigidbody2D::Rigidbody2D(Vector2* _objectPos) : objectPos(_objectPos)
{
	printf("Constructed times");
}

void Rigidbody2D::Update()
{
	//if (forceMagnitude > 0) forceMagnitude -= friction;
	//if (forceMagnitude < 0) forceMagnitude = 0;

	force += forceDir * GetVelocityMagnitude();
	velocity = force;

	if (isGravityEnabled) { GravityUpdate(); }

	*objectPos += velocity * gameTime.GetDeltaTime();
}

void Rigidbody2D::AddForce(Vector2 _forceVector2)
{
	//if(isGravityEnabled) force += S_GetGravity(); //*mass
	force += _forceVector2; //*mass
	velocity += force;
}

void Rigidbody2D::AttachToPos(Vector2& _pos)
{
	objectPos = &_pos;
}

void Rigidbody2D::ReverseAngle()
{
	velocity = -velocity;
	forceDir = -forceDir;
	force = -force; //Todo config these
}

void Rigidbody2D::ReverseAngle(Vector2 _appliedForce)
{
	velocity = -velocity;
	forceDir = -forceDir;
	force = -force; //Todo config these
	force += _appliedForce;
}

float Rigidbody2D::GetForceMagnitude()
{
	return (float)sqrt(force.x * force.x + force.y * force.y);
}

float Rigidbody2D::GetVelocityMagnitude()
{
	return (float)sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
}

void Rigidbody2D::GravityUpdate()
{
	//In dev
	Vector2 grav = S_GetGravity(); //*mass
	velocity += S_GetGravity();
}

Vector2& Rigidbody2D::S_GetGravity()
{
	static Vector2 gravity = Vector2::down * 7.9f;
	return gravity;
}

void Rigidbody2D::S_ModifyGravity(float _x, float _y)
{
	Vector2& newGravity = S_GetGravity();
	newGravity.x = _x;
	newGravity.y = _y;
}

