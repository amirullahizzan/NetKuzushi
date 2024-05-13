#pragma once

#include "../customcommon/SceneBase.h"
#include "../customcommon/TextEffect.h"
#include "../customcommon/Primitive.h"
#include "../customcommon/Sprite.h"


struct MainMenuScene : public SceneBase
{
	MainMenuScene(SceneManager* _sceneManager);
	~MainMenuScene() = default;

	void Update() override;
	void Render() override;

private:
	std::array<Box, 2> buttonBox = {};
	Circle selectionCursor = { *buttonBox[0].pointPos,25.0f };

	int selectionIndex = 0;

	int textTickBuffer = 0;
	int charIndexBuffer = 0;

	Sprite logoSprite = { std::string("data/pic/ghostZeroMediumTransparent.png") };


	void MenuControl();
	void RenderTitle();
	void RenderMenuText();
	int fontSize = GetFontSize(); //get height
	const int buttonUIOffset = 140 + fontSize;
};