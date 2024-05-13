#pragma once

#include "../customcommon/SceneBase.h"

struct EndScene : public SceneBase
{
	EndScene(SceneManager* sceneManager) : SceneBase(sceneManager) 
	{
		DxLib::SetFontSize(FONTSIZE_LARGE);
	};
	void Update() override;
	void Render() override;
};

