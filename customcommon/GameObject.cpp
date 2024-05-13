#include "GameTime.h"
#include "GameObject.h"

extern GameTime gameTime;

GameObject::GameObject()
{
	destroyTime = 0.0f;
	tag = "default";
	name = "GameObject";
}

GameObject::GameObject(float _destroyTime) : destroyTime(_destroyTime)
{
	destroyTime = gameTime.GetTime() + maxDestroyTime;
}

void GameObject::SetDestroy()
{
	isFlaggedDestroy = true;
}

const bool GameObject::IsTimeToDestroy()
{
	return gameTime.GetTime() > destroyTime;
}

const bool GameObject::IsFlaggedDestroy()
{
	return isFlaggedDestroy;
}

void GameObject::HandleCollision(GameObject& _other)
{
}

