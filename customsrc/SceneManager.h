#pragma once

//#include "../customcommon/Primitive.h"
//#include "../customcommon/TextEffect.h"
//#include "../customcommon/Pos.h"
//#include "../customcommon/DebugTools.h"
//#include <random>

//#include "../customsrc/EndScene.h"
//#include "../customcommon/ObjectManager.h"
//#include "../customcommon/GameObject.h"

#include "../customcommon/Pos.h"
#include "../customcommon/FadeBox.h"

struct SceneManager
{
public:
	FadeBox fadeBox;

	enum EList
	{

		MainMenu,
		Game,
		End,
	};

	SceneManager();

	void Init();
	void Update();
	void Render();
	void NextScene();
	void UpdateSceneChange();
	void SetScene(EList _sceneIndex);

	int sceneIndex = MainMenu;
	//ObjectManager<GameObject> objectManager;
protected:

private:
	int bgm = -1;

	struct SceneBase* currentScene = nullptr;

};
