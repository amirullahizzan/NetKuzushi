#include "Player.h"

Player::Player(Vector2 _spawnPoint)
{
	circle.radius = 25.0f;
	circle.pointPos = _spawnPoint; 
	pos = &circle.pointPos;
	pad = { *pos, padSize };
}

Player::~Player()
{
}

void Player::Update()
{
	if (isDestroyed)
	{
		return;
	}
	pad.pointPos = circle.pointPos;
	pad.pointPos.y -= 20.0f;
	pad.RecalculateBox();
}

void Player::Render()
{
	if (isDestroyed) return;
	sprite.Render(pos->x, pos->y, 1, 0, true);
	pad.Render();
}

void Player::HandleCollision(GameObject& _other)
{
}

void Player::Destroy()
{
	isDestroyed = true;
	
	SpawnEffects();
}

void Player::SpawnEffects()
{

}
