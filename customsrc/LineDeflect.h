#pragma once
#include "../customcommon/GameObject.h"
#include "../customcommon/Pos.h"
#include "../customcommon/Rigidbody2D.h"
#include "../customsrc/PlayerSkill.h"
#include "../customcommon/Primitive.h"

struct PlayerSkill;

struct LineDeflect : GameObject
{
	LineDeflect(PlayerSkill* _playerSkill, Vector2* currentPlayerPos, bool _isDeflectRight);
	~LineDeflect();

	PlayerSkill* playerSkill;

	void Update() override;
	void Render() override;

	void HandleCollision(GameObject& _other);

private:

	Vector2* startPos;
	Vector2 endPos;

	Vector2 hitBoxSize = { 18.0f,18.0f };
	Circle circle1;
	Circle circle2;

	//Box box1;
	//Box box2;
	//BoxCollider2D boxColl1 = { box1 };
	//BoxCollider2D boxColl2 = { box2 };

	double degree;
	bool isDeflectRight = true;

};
