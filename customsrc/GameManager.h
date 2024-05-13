#pragma once

#include "../customcommon/GameTime.h"
#include "../customcommon/GameObject.h"
#include "SceneManager.h"

extern GameTime gameTime;

class GameManager
{

public:
	GameManager();
	void Init();

	void Update();

	void Draw();

private:

	SceneManager sceneManager;
};