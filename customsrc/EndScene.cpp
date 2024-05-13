#include "EndScene.h"

//#ENDGAMESCENE
void EndScene::Update()
{
	if(GetKeyDown(KEY_INPUT_RETURN) || IsPadOn(PS_CIRCLE) || IsPadOn(PS_CROSS))
	{
		scene->sceneIndex = SceneManager::MainMenu;
		scene->UpdateSceneChange();
	}
}

void EndScene::Render()
{
	DrawStringF(WINDOW_W_HALF - 150.0f, WINDOW_H_HALF-50.0f, "YOU WIN!!!", GREEN);
}

