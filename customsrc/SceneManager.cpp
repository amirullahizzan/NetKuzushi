#include "SceneManager.h"
#include "../customsrc/MainMenuScene.h"
#include "../customsrc/GameScene.h"
#include "../customsrc/EndScene.h"


SceneManager::SceneManager()
{
	UpdateSceneChange();
}

void SceneManager::Init()
{
	if (bgm == -1)
	{
		bgm = LoadMusicMem("data/music/SUNO - Byte by Byte.mp3");
		PlayMusicMem(bgm, DX_PLAYTYPE_LOOP);
		//LoadSoundMem();
		//PlaySoundMem();
	}
}

void SceneManager::Update()
{
	if(currentScene)currentScene->Update();
	fadeBox.Update();
}

void SceneManager::Render()
{
	currentScene->Render();
	fadeBox.Render();
}

void SceneManager::NextScene()
{
	sceneIndex++;
	UpdateSceneChange();
}

void SceneManager::SetScene(EList _sceneIndex)
{
	sceneIndex = _sceneIndex;
	UpdateSceneChange();
}

void SceneManager::UpdateSceneChange()
{
	//if (currentScene != nullptr)
	//{
	//	delete currentScene;
	//	currentScene = nullptr;
	//}

	switch (sceneIndex)
	{
	case MainMenu:
		currentScene = new MainMenuScene(this); //Memory leak
		break;
	case Game:
		currentScene = new GameScene(this);
		break;
	case End:
		currentScene = new EndScene(this);
		break;
	}
}



