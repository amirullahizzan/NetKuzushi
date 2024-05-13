#include "GameManager.h"


GameManager::GameManager()
{
}

void GameManager::Init()
{
	sceneManager.Init();
}

void GameManager::Update()
{
	gameTime.Update();
	sceneManager.Update();
}

void GameManager::Draw()
{
	sceneManager.Render();
}
