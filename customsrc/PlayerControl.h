#pragma once

#include "../src/WinMain.h"

#include "Player.h"

struct Player;

struct PlayerController
{
	PlayerController(Player* _player, PlayerSkill* _skill);
	Player* player;
	PlayerSkill* skill;

	bool isDisabled = false;
	void Update();


private:

	void UpdateJoystickDPad();
	void UpdateJoystickActions();
	void UpdateJoystickChords();
};


