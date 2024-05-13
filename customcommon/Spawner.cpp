#include "Spawner.h"

Spawner::Spawner(float _spawnMaxCooldown)
{
	cooldown.SetMaxCooldown(_spawnMaxCooldown);
}
