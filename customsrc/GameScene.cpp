#include "GameScene.h"
#include "../customcommon/GameObject.h"
#include "../customsrc/LineDeflect.h"

//#GAMESCENE
GameScene::GameScene(SceneManager* sceneManager) : SceneBase(sceneManager)
{
	player = new Player(playerSpawnPos);
	loseWall = new LoseWall();
	skill = new PlayerSkill(player, balls, loseWall);
	control = new PlayerController(player, skill);

	Vector2 ballSpawnPos = { WINDOW_W / 2, WINDOW_H / 2 + 150 };
	Ball ball(ballSpawnPos, ballSprite.GetHandle());
	balls.push_back(ball);

	blockSpawner.GenerateBlockies();
	CreateBorderWalls();
}


void GameScene::Update()
{
	player->Update();
	skill->Update();
	control->Update();
	loseWall->Update();
	for (auto& ball : balls)
	{
		ball.Update();

		//LOSE WALL
		if (HitboxBoxCircle(loseWall->box.GetPos1(), loseWall->box.GetPos2(),
			ball.circle.pointPos, ball.circle.radius))
		{
			if (!loseWall->isImmune)
			{
				if (ball.type == 0)
				{
					player->Destroy();
					returnToMainMenuCooldown.StartCooldown();
				}
			}
			else
			{
				ball.ReverseDirY();
			}
		}

		// WALLS SIDE
		for (auto& wall : borderWallsSide)
		{
			if (HitboxBoxCircle(wall.pos1, wall.pos2,
				ball.circle.pointPos, ball.circle.radius))
			{
				ball.ReverseDirX();
			}

		}
		//WALLS TOP
		for (auto& wall : borderWallsTop)
		{
			if (HitboxBoxCircle(wall.pos1, wall.pos2,
				ball.circle.pointPos, ball.circle.radius))
			{
				ball.ReverseDirY();
			}
		}

		//PAD
		if (HitboxBoxCircle(player->pad.pos1, player->pad.pos2,
			ball.circle.pointPos, ball.circle.radius))
		{
			if (!ball.isColliding)
			{
				ball.isColliding = true;
				if (ball.type == 0)
				{
					ball.ReverseDirX();
					ball.ReverseDirY();
				}
				else
				{
					player->Destroy();
					returnToMainMenuCooldown.StartCooldown();
				}
			}
		}
		else
		{
			ball.isColliding = false;
		}

	}

	//////////////////////////////

	// BLOCKY
	for (auto& ball : balls)
	{
		for (int i = 0; i < blockSpawner.blockies.size(); i++)
		{
			auto& blocky = blockSpawner.blockies[i];
			if (HitboxBoxCircle(blocky.pos1, blocky.pos2,
				ball.circle.pointPos, ball.circle.radius))
			{
				ball.ReverseDirY();
				if (ball.type == 1) continue;
				blocky.ReduceHP();
				if (blocky.IsHPZero())
				{
					score++;
					blockSpawner.totalBlocky--;
					blockSpawner.TrySpawnBall(blocky.pointPos);
					blockSpawner.vfx.SpawnEffects(blocky.pointPos);
					blockSpawner.blockies.erase(blockSpawner.blockies.begin() + i);
				}
			}
		}
	}


	if (player->isDestroyed)
	{
		ProcessGameOver();
	}

	blockSpawner.Update();
	if (blockSpawner.totalBlocky <= 0) { scene->NextScene(); }
}

void GameScene::ProcessGameOver()
{
	if (!returnToMainMenuCooldown.IsCooldown())
	{
		scene->SetScene(scene->EList::MainMenu);
	}
}

void GameScene::Render()
{
	backgroundBox.Render();
	//////////////////////////
	player->Render();
	skill->Render();
	loseWall->Render();
	blockSpawner.Render();
	for (auto& ball : balls)
	{
		ball.Render();
	}

	for (auto& wall : borderWallsSide)
	{
		wall.Render();
	}

	if (!skill->skillCooldown.IsCooldown())
	{
		ControllerSquareSprite.Render(WINDOW_W - 500, 35.0f, 0.4f, 0, 1);
		ControllerCrossSprite.Render(WINDOW_W - 455, 35.0f, 0.4f, 0, 1);
	}

	ControllerLTSprite.Render(WINDOW_W - 80.0f, WINDOW_H - 120, 0.8f, 0, 1);
	stackSprite.Render(50.0f, WINDOW_H - 105, 0.8f, 0, 1);
	DxLib::SetFontSize(FONTSIZE_SMALL);
	DrawFormatStringF(80.0f, WINDOW_H - 120, WHITE, "Score : %d", score);
}

void GameScene::CreateBorderWalls()
{
	NewBox wallUp = { {WINDOW_W / 2,0},{WINDOW_W,25.0f} };
	NewBox wallLeft = { {0,WINDOW_H / 2}, {25.0f,WINDOW_H} };
	NewBox wallRight = { {WINDOW_W,WINDOW_H / 2}, {25.0f,WINDOW_H} };

	borderWallsTop.push_back(wallUp);
	borderWallsSide.push_back(wallLeft);
	borderWallsSide.push_back(wallRight);
}

struct Text {
	std::string text;
	int x;
	int y;
};

std::vector<Text> texts;

//void AddRandomText() {
//	Text newText;
//	newText.text = "main.cpp";
//	newText.x = -TEXT_SIZE;
//	newText.y = rand() % (WINDOW_H - TEXT_SIZE);
//	texts.push_back(newText);
//}

//void UpdateTexts() {
//	for (auto& text : texts) {
//		text.x += TEXT_SPEED;
//		if (text.x > WINDOW_W) {
//			text.x = -TEXT_SIZE;
//		}
//	}
//}
//
//void RenderTexts() 
//{
//	for (auto& text : texts) 
//	{
//		DrawString(text.x, text.y, text.text.c_str(), GetColor(0, 255, 0));
//	}
//}