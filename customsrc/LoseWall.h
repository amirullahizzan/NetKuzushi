#pragma once

#include "../customcommon/GameObject.h"
#include "../customcommon/Primitive.h"
#include "../customcommon/Collider2D.h"
#include "../customcommon/Pos.h"

struct LoseWall : GameObject
{
	LoseWall();

	Vector2 pointPos = { WINDOW_W * 0.5f,WINDOW_H };
	Vector2 size = { WINDOW_W * 0.5f,25.0f };
	Box box = { pointPos.x,pointPos.y, size.x,size.y, RED }; // THIS IS NOT CORRECT
	int* color = &box.color;

	void Update() override;
	void Render() override;
	bool isImmune = false;
	void SetImmune()
	{
		*color = GREEN;
		isImmune = true;
	}
	void RestoreImmune()
	{
		*color = RED;
		isImmune = false;
	}
	void HandleCollision(GameObject& _other) override;
};