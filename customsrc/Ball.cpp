#include "Ball.h"
#include <cmath>
#include "../customcommon/Math.h"

Ball::Ball()
{
	//circle = { , 25.0f };
	tag = "Ball";
	LaunchDownRandom();
}

Ball::Ball(Vector2 _spawnPos, int _sprite) : sprite(_sprite)
{
	circle = { _spawnPos, 15.0f };
	tag = "Ball";
	LaunchDownRandom();
}

void Ball::Update()
{
	if (speed <= 0.1f) speed = 0.2f;
	circle.pointPos.x += vx * speed;
	circle.pointPos.y += vy * speed;
}

void Ball::SetSpeed(float _newSpeed)
{
	 savedSpeed = speed;
	 speed  = _newSpeed;
}
void Ball::RestoreSpeed()
{
	speed = savedSpeed;
}

void Ball::Render()
{
	DrawRotaGraphF(circle.pointPos.x, circle.pointPos.y, circle.ToPixelUnit(), 0, sprite, true);
}

void Ball::LaunchDownRandom()
{
	
	dir.x = { (float)GetRandF(-0.75f,0.75f,100) };
	dir.y = 1.0f;

	vx = dir.x * speed;
	vy = dir.y * speed;
}

void Ball::ReverseDirY()
{
	vy = -vy; 
	AddSpeed();
}

void Ball::ReverseDir()
{
	vx = -vx;
	vy = -vy;
	AddSpeed();
}

void Ball::ReverseDirX()
{
	vx = -vx; 
	AddSpeed();
}

void Ball::AddSpeed()
{
	speed += 0.2f;
	if (speed > 1.7f) speed = 1.7f;
}

