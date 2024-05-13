#include "LineDeflect.h"
#include "../src/WinMain.h"
#include "../customcommon/GameTime.h"
#include "../customcommon/Math.h"
#include <cmath>

extern GameTime gameTime;

LineDeflect::LineDeflect(PlayerSkill* _playerSkill, Vector2* currentPlayerPos, bool _isDeflectRight) :
	playerSkill(_playerSkill), startPos(currentPlayerPos), isDeflectRight(_isDeflectRight)
{
	circle2.pointPos = *currentPlayerPos; // initialized wrong, teleports

	if (isDeflectRight)
	{
		degree = 180;
	}
	else
	{
		degree = 0;
	}
}

LineDeflect::~LineDeflect()
{
}

void LineDeflect::Update()
{
	if (IsFlaggedDestroy())return;

	//rb.Update();
	//box1.Update();
	//box2.Update();
	const float lineLength = 100.0f;
	float deltaTime = gameTime.GetDeltaTime();
	const float speed = 550.0f;
	const float angularSpeed = speed;

	if (isDeflectRight)
	{
		degree += deltaTime * angularSpeed;

		endPos.x = startPos->x + lineLength * (float)std::cos(ToRadian(degree));  // Cosine for horizontal component
		endPos.y = startPos->y + lineLength * (float)std::sin(ToRadian(degree));  // Sine for vertical component
		circle1.pointPos.x = startPos->x + 0.75 * (endPos.x - startPos->x);
		circle1.pointPos.y = startPos->y + 0.75 * (endPos.y - startPos->y);

		const int maxDegree = 360 - 15;
		if (int(degree) > maxDegree)
		{
			SetDestroy();
		}
	}
	else
	{
		degree -= deltaTime * angularSpeed;
		endPos.x = startPos->x + lineLength * (float)std::cos(ToRadian(degree));  // Cosine for horizontal component
		endPos.y = startPos->y + lineLength * (float)std::sin(ToRadian(degree));  // Sine for vertical component
		circle1.pointPos.x = startPos->x + 0.75 * (endPos.x - startPos->x);
		circle1.pointPos.y = startPos->y + 0.75 * (endPos.y - startPos->y);

		const int maxDegree = -180 + 15;
		if (int(degree) < maxDegree)
		{
			SetDestroy();
		}
	}
}

void LineDeflect::Render()
{
	DrawLineAA(startPos->x, startPos->y, endPos.x, endPos.y, GREEN, 3);
}

void LineDeflect::HandleCollision(GameObject& _other)
{
	if (_other.tag == "Ball")
	{

		printf("\nReversing\n");
		playerSkill->deflectCooldown.ResetCooldown();
		SetDestroy(); // is not cleaned immediately
	}
}