#include "../customsrc/Player.h"
#include "PlayerSkill.h"
#include "Ball.h"
#include "../customcommon/Pos.h"
#include "../customcommon/Cooldown.h"
#include "../customcommon/GameObject.h"
#include "../customcommon/Rigidbody2D.h"
#include "../customsrc/LineDeflect.h"

PlayerSkill::PlayerSkill(Player* _player, std::vector<Ball>& _balls, LoseWall* _loseWall) : player(_player), balls(_balls), loseWall(_loseWall)
{

}


void PlayerSkill::DisableLoseWalls()
{
	loseWall->SetImmune();
	immuneDur.StartCooldown();
}

void PlayerSkill::RestoreLoseWalls()
{
	loseWall->RestoreImmune();
}

void PlayerSkill::SlowBalls()
{
	if (!slowDur.IsCooldown())
	{
		for (auto& ball : balls)
		{
			ball.SetSpeed(ball.speed * 0.2f);
		}
		isSlowMo = true;
		slowDur.StartCooldown();
	}
}

void PlayerSkill::RestoreBalls()
{
	for (auto& ball : balls)
	{
		ball.RestoreSpeed();
	}
}

void PlayerSkill::DeflectLeft()
{
	if (!deflectCooldown.IsCooldown())
	{
		CreateLineDeflect(false);
		deflectCooldown.StartCooldown();
	}
}

void PlayerSkill::SpeedBoost()
{
	player->speedMult = player->SPEED_BOOST;
}

void PlayerSkill::DeflectRight()
{
	if (!deflectCooldown.IsCooldown())
	{
		CreateLineDeflect(true);
		//CreateBalls();
		deflectCooldown.StartCooldown();
	}
}




void PlayerSkill::Update()
{
	if (!slowDur.IsCooldown() && isSlowMo)
	{
		RestoreBalls();
		isSlowMo = false;
		slowDur.StartCooldown();
	}
	if (!immuneDur.IsCooldown() && loseWall->isImmune)
	{
		isSlowMo = false;
		RestoreLoseWalls();
		immuneDur.StartCooldown();
	}
}

void PlayerSkill::Render()
{

	DxLib::SetFontSize(FONTSIZE_SMALL);
	if (skillCooldown.GetCurrentCooldownForDisplay() > 0)
	{
		float skillCooldownTimer = skillCooldown.GetCurrentCooldownForDisplay();
		DrawFormatStringF(WINDOW_W - 440, 22.0f, YELLOW, " Injection cooldown %.1f", skillCooldownTimer);
	}
	else
	{
		DrawStringF(WINDOW_W - 440, 22.0f, " Injection READY ", GREEN);
	}
}

void PlayerSkill::CreateLineDeflect(bool _isDeflectRight)
{
	//objectManager.Instantiate(std::make_unique<LineDeflect>(this,player->pos, _isDeflectRight));
}

void PlayerSkill::CreateBalls()
{
	//objectManager.Instantiate(std::make_shared<Ball>()); // Do I create the ball?
}

