#include "Collider2D.h"
#include "Primitive.h"
#include "Hitbox.h"

void BaseCollider2D::Update()
{
}

void BaseCollider2D::Render()
{
}


BoxCollider2D::BoxCollider2D
(Box& _box) : box(_box)
{
	name = "BoxColl";
	isTrigger = false;
}

void BoxCollider2D::Update()
{
	//hitbox
}

void BoxCollider2D::Render()
{
	if (!isDebugMode)return;
	box.Render();
}


CircleCollision2D::CircleCollision2D(Circle& _circle) : circle(_circle)
{
}

void CircleCollision2D::Update()
{

}

void CircleCollision2D::Render()
{
	if (!isDebugMode)return;
	circle.Render();
}

