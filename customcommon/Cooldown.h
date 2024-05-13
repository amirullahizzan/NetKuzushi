#pragma once

#include "GameTime.h"

extern GameTime gameTime;

struct Cooldown
{
	Cooldown(float _setMaxCooldown = 2.0f);

	void SetMaxCooldown(float _newMaxCooldown);
	void StartCooldown();
	void ResetCooldown();
	bool IsCooldown();
	void SetCurrentCooldown(float _customCooldown);
	float GetCurrentCooldown();
	float GetCurrentCooldownForDisplay();

private:
	float maxCooldown = 2.0f;
	float currentCooldownTick = 0.0f;
};