#include "Player.h"
#include "PlayerControl.h"
#include "Ball.h"

extern GameTime gameTime;

PlayerController::PlayerController(Player* _player, PlayerSkill* _skill) : player(_player), skill(_skill)
{
}

void PlayerController::Update()
{
	if (!player->isDestroyed)
	{
		UpdateJoystickDPad();
		UpdateJoystickActions();
		UpdateJoystickChords();
	}
}

void PlayerController::UpdateJoystickDPad()
{
	if (IsPadRepeat(PAD_LEFT, PAD_NO1) || GetKeyDown(KEY_INPUT_LEFT))
	{
		player->pos->x -= gameTime.GetDeltaTime() * player->speedMult;
	}
	if (IsPadRepeat(PAD_RIGHT, PAD_NO1) || GetKeyDown(KEY_INPUT_RIGHT))
	{
		player->pos->x += gameTime.GetDeltaTime() * player->speedMult;
	}
	if (IsPadRepeat(PAD_UP, PAD_NO1))
	{
		//player->pos->y -= gameTime.GetDeltaTime() * player->speedMult;
	}
	if (IsPadRepeat(PAD_DOWN, PAD_NO1))
	{
		//player->pos->y += gameTime.GetDeltaTime() * player->speedMult;
	}
}

void PlayerController::UpdateJoystickActions()
{

	if (IsPadOn(PS_SQUARE, PAD_NO1))
	{
		if (!skill->skillCooldown.IsCooldown() && !skill->slowDur.IsCooldown())
		{
			skill->SlowBalls();
			skill->skillCooldown.SetCurrentCooldown(1.8f);
		}
	}
	if (IsPadOn(PS_CROSS, PAD_NO1))
	{
		if (!skill->skillCooldown.IsCooldown())
		{
			skill->DisableLoseWalls();
			skill->skillCooldown.SetCurrentCooldown(4.2f);
		}
	}
	if (IsPadOn(PS_CIRCLE, PAD_NO1))
	{
		//skillCooldown.StartCooldown();

	}
	if (IsPadOn(PS_TRIANGLE, PAD_NO1))
	{
		//skillCooldown.StartCooldown();

	}

}

void PlayerController::UpdateJoystickChords()
{
	if (IsPadRepeat(PS_L1, PAD_NO1))
	{
		skill->SpeedBoost();
	}
	else
	{
		player->speedMult = player->SPEED_NORMAL;
	}

	if (IsPadOn(PS_R1, PAD_NO1))
	{
	}
	else if (IsPadOn(PS_L2, PAD_NO1))
	{
		skill->DeflectLeft();
	}
	else if (IsPadOn(PS_R2, PAD_NO1))
	{
		skill->DeflectRight();
	}
}
