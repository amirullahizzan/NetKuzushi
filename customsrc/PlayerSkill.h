#pragma once

#include "../customcommon/Cooldown.h"
#include "../customsrc/Ball.h"
#include "../customsrc/LoseWall.h"

struct Player;

struct PlayerSkill
{
	PlayerSkill(Player* _player, std::vector<Ball>& _balls, LoseWall* loseWall);
	Player* player = nullptr;
	std::vector<Ball>& balls;
	LoseWall* loseWall = nullptr;

	Cooldown skillCooldown = { 10.0f };
	Cooldown slowDur = { 2.0f };
	Cooldown immuneDur = { 1.4f };
	
	Cooldown deflectCooldown = { 0.8f }; //ONdevelopment
	//std::vector<LineDeflect>(this, player->pos,) lines;

	void DeflectRight();
	void DeflectLeft();
	void SpeedBoost();
	void DisableLoseWalls();
	void RestoreLoseWalls();
	void SlowBalls();

	void RestoreBalls();

	void Update();
	void Render();

	void CreateLineDeflect(bool _isDeflectRight);
	void CreateBalls();

private:
	bool isSlowMo = false;
};
