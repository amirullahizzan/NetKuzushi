#include "Cooldown.h"

Cooldown::Cooldown(float _setMaxCooldown)
{
	maxCooldown = _setMaxCooldown;
}

void Cooldown::SetMaxCooldown(float _newMaxCooldown)
{
	maxCooldown = _newMaxCooldown;
}

void Cooldown::StartCooldown()
{
	currentCooldownTick = gameTime.GetTime() + maxCooldown;
}

void Cooldown::ResetCooldown()
{
	currentCooldownTick = gameTime.GetTime();
}

bool Cooldown::IsCooldown()
{
	return currentCooldownTick > gameTime.GetTime();
}

void Cooldown::SetCurrentCooldown(float _customCooldown)
{
	currentCooldownTick = gameTime.GetTime() + _customCooldown;
}

float Cooldown::GetCurrentCooldown()
{
	return currentCooldownTick;
}

float Cooldown::GetCurrentCooldownForDisplay()
{
	return  currentCooldownTick - gameTime.GetTime();
}
