#include "MainMenuScene.h"

//#MAINMENUSCENE

MainMenuScene::MainMenuScene(SceneManager* _sceneManager) : SceneBase(_sceneManager)
{
	SetFontSize(FONTSIZE_LARGE);
	selectionCursor.color = YELLOW;
}

void MainMenuScene::Update()
{
	MenuControl();
}

void MainMenuScene::Render()
{
	RenderTitle();
	RenderMenuText();
	selectionCursor.Render();
	logoSprite.Render(WINDOW_W - 200.0f, WINDOW_H_HALF , 1,0,1);
}

void MainMenuScene::MenuControl()
{
	if (selectionIndex == -999 && scene->fadeBox.IsStandby())
	{
		scene->fadeBox.SetFadeIn(220.0f);
		scene->NextScene();
	}
	if (selectionIndex == -999) return;

	if (GetKeyDown(KEY_INPUT_UP) || IsPadOn(PAD_UP))
	{
		selectionIndex = 0;
		selectionCursor.pointPos.y = WINDOW_H / 2;
	}
	else if (GetKeyDown(KEY_INPUT_DOWN) || IsPadOn(PAD_DOWN))
	{
		selectionIndex = 1;
		selectionCursor.pointPos.y = WINDOW_H/2 + 150;
	}
	selectionCursor.pointPos.x = WINDOW_W/2 - 200.0f;

	if (GetKeyDown(KEY_INPUT_RETURN) || IsPadOn(PS_CIRCLE) || IsPadOn(PS_CROSS) || IsPadOn(PS_SQUARE))
	{
		switch (selectionIndex)
		{
		case 0:
			selectionIndex = -999;
			scene->fadeBox.SetFadeOut(420.0f);
			break;
		case 1:
			exit(0);
			break;
		}
	}
}

void MainMenuScene::RenderTitle()
{
	int originalFontSize = GetFontSize();
	SetFontSize(FONTSIZE_TITLE);
	std::string gameTitle = "NET Kuzushi";
	const int perCharTimer = 5;
	int textLength = GetTextSize(gameTitle);
	DrawString(WINDOW_W_HALF - textLength, WINDOW_H_HALF - 200,
		GetTimedCharacter(gameTitle, perCharTimer, textTickBuffer, charIndexBuffer).c_str(),
		YELLOW);

	SetFontSize(FONTSIZE_SMALL);
	std::string credit = "アミルラ イザン";
	textLength = GetTextSize(credit);
	DrawString(WINDOW_W_HALF - textLength, WINDOW_H - 50,
		GetTimedCharacter(credit, perCharTimer, textTickBuffer, charIndexBuffer).c_str(),
		YELLOW);

	SetFontSize(originalFontSize);
}

void MainMenuScene::RenderMenuText()
{
	std::string text[2] = { "Start" , "Exit" };

	SetFontSize(FONTSIZE_LARGE);

	int fontSize = GetFontSize(); //get height


	for (int i = 0; i < buttonBox.size(); i++)
	{
		buttonBox[i] = { (float)WINDOW_W_HALF, (float)WINDOW_H_HALF + (buttonUIOffset * i), WINDOW_W,40,GRAY, true };
		buttonBox[i].Render();

		const int perCharTimer = 50;
		//DrawCircleAA(buttonBox[i].pointPos_.x_, buttonBox[i].pointPos_.y_,64,64,RED,1,1);
		int textLength = GetTextSize((text[i])); //get width
		DrawStringF(buttonBox[i].pointPos->x - textLength, buttonBox[i].pointPos->y - fontSize * 0.5f,
			GetTimedCharacter(text[i], perCharTimer, textTickBuffer, charIndexBuffer).c_str(),
			WHITE);
	}
}
