#pragma once
#include "Rigidbody2D.h"
#include <vector>
#include <string>
#include <memory>

struct GameObject
{
	GameObject();
	GameObject(float _destroyTime);

	virtual ~GameObject() = default;

	virtual void Update() = 0;
	virtual void Render() = 0;

	float maxDestroyTime = 0.6f;
	float destroyTime;
	int layer = 0;
	std::string tag = "";
	std::string name = "";

	void SetDestroy();
	const bool IsTimeToDestroy();
	const bool IsFlaggedDestroy();

	virtual void HandleCollision(GameObject& _other);

	bool hasProcessedCollision = false;
private:
	bool isFlaggedDestroy = false;
	
};
