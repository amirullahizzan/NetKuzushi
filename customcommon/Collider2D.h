#pragma once

#include "Primitive.h"

struct BaseCollider2D
{
	std::string name = "BaseColl";
	bool isTrigger = false;
	virtual void Update();
	virtual void Render();
	bool isDebugMode = false;
};

struct BoxCollider2D : BaseCollider2D
{
	//BoxCollider2D(float _xPoint, float _yPoint ,float _sizeX, float sizeY, bool _isTrigger);
	//BoxCollider2D();
	BoxCollider2D(Box& _box);
	Box& box;

	void Update() override;
	void Render() override;

};

struct CircleCollision2D : BaseCollider2D
{
	CircleCollision2D(Circle& _circle);
	Circle& circle;

	void Update() override;
	void Render() override;
};