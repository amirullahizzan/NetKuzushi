#pragma once

#include "../customcommon/GameObject.h"
#include "../customcommon/Sprite.h"
#include "../customcommon/Pos.h"
#include "../customcommon/Collider2D.h"

#include  "PlayerSkill.h"
#include "PlayerControl.h"

struct Player : GameObject
{
	Player(Vector2 _spawnPoint);
	~Player();
	
	
	Vector2* pos = nullptr;

	Sprite sprite = {std::string("data/pic/player.png")};
	
	const float SPEED_BOOST = 750.0f;
	const float SPEED_NORMAL = 150.0f;
	float speedMult = SPEED_NORMAL;

	void Update() override;
	void Render() override;
	void HandleCollision(GameObject& _other) override;
	void Destroy();

	NewBox pad;
	bool isDestroyed = false;
private:
	void SpawnEffects();

	Circle circle;
	Vector2 padSize = { 55.0f,5.0f };
};