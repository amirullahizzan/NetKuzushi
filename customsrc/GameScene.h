#pragma once

#include <vector>

#include "../customcommon/SceneBase.h"
#include "../customcommon/GameTime.h"
#include "../customcommon/Sprite.h"
#include "../customcommon/Hitbox.h"
#include "../customsrc/Ball.h"
#include "Player.h"
#include "../customsrc/BlockConstructor.h"
#include "../customsrc/LoseWall.h"

struct GameScene : public SceneBase
{
	GameScene(SceneManager* sceneManager);

	Player* player = nullptr;
	PlayerSkill* skill = nullptr;
	PlayerController* control = nullptr;
	LoseWall* loseWall = nullptr;
	int score = 0;
	void Update() override;
	void Render() override;
	Cooldown returnToMainMenuCooldown = { 1.2f };

	void CreateBorderWalls();

	std::vector<Ball> balls;
	std::vector<NewBox> borderWallsSide;
	std::vector<NewBox> borderWallsTop;

private:

	Sprite ballSprite = { std::string("data/pic/smallnode.png") };
	Sprite redBallSprite = { std::string("data/pic/smallnodered.png") };
	Sprite stackSprite = { std::string("data/pic/stackicon.png") };
	Sprite skillIcon = { std::string("data/pic/greenlock.png") };

	Sprite ControllerCrossSprite = { std::string("data/pic/Cross.png") };
	Sprite ControllerSquareSprite = { std::string("data/pic/Square.png") };
	Sprite ControllerLTSprite = { std::string("data/pic/LT.png") };

	Vector2 playerSpawnPos = { WINDOW_W_HALF,WINDOW_H * 0.80f };

	BallSpawner ballSpawner = { balls, ballSprite.handle, redBallSprite.handle };
	BlockSpawner blockSpawner = { &ballSpawner };

	Box backgroundBox = { 0.0f, 0.0f, WINDOW_W, WINDOW_H, BLACK };

	const Vector2 UPPER_BORDER = { 50,200 };
	const Vector2 BORDER_OFFSET = { 50,100 };

	void ProcessGameOver();
};