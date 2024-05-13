#pragma once

#include "../src/WinMain.h"
#include "Pos.h"
#include "GameTime.h"

extern GameTime gameTime;

struct FadeBox
{

	void SetFadeOut(float _fadeSpeed = 50.0f);
	void SetFadeIn(float _fadeSpeed  = 50.0f);
	bool IsStandby();

	void Update();
	void Render();

private:

	enum EMode
	{
		Standby,
		FadeIn,
		FadeOut,
	};

	int fadeMode = Standby;

	Vector2 pos_ = { 0,0 };
	Vector2 pos2_ = { WINDOW_W,WINDOW_H };

	float fadeSpeed_ = 80.0f;
	float blendparam_ = 0.0f;

};