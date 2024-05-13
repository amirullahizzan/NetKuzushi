#include "FadeBox.h"

void FadeBox::Update()
{
	if (fadeMode == FadeOut) //Inc to MAX
	{
		if (blendparam_ >= DX_MAX_ALPHA)
		{
			blendparam_ = DX_MAX_ALPHA;
			fadeMode = Standby;
		}
		else
		{
			blendparam_ += gameTime.GetDeltaTime() * fadeSpeed_;
		}
	}
	else if (fadeMode == FadeIn) //Dec to NO
	{
		if (blendparam_ <= DX_NO_ALPHA)
		{
			blendparam_ = DX_NO_ALPHA;
			fadeMode = Standby;
		}
		else
		{
			blendparam_ -= gameTime.GetDeltaTime() * fadeSpeed_;
		}
	}
}

void FadeBox::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(blendparam_));
	DrawBoxAA(pos_.x, pos_.y, pos2_.x, pos2_.y, BLACK, 1, 1);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 1);
}

void FadeBox::SetFadeOut(float _fadeSpeed)
{
	fadeSpeed_ = _fadeSpeed;
	fadeMode = FadeOut;
}

bool FadeBox::IsStandby()
{
	return fadeMode == Standby;
}

void FadeBox::SetFadeIn(float _fadeSpeed)
{
	fadeSpeed_ = _fadeSpeed;
	fadeMode = FadeIn;
}

