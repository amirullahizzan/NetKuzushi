#pragma once

#include "Pos.h"
#include "Cooldown.h"

struct Spawner
{
	Spawner(float _spawnMaxCooldown);
	Vector2 pos;
	Cooldown cooldown = {0.0f};
};