#include "WinMain.h"
#include "../customsrc/GameManager.h"

GameManager* gameManager = nullptr;

void GameInit()
{
	gameManager = new GameManager();
	gameManager->Init();
}

void GameUpdate()
{
	gameManager->Update();
}

void GameDraw()
{
	gameManager->Draw();
}

void GameExit()
{
}