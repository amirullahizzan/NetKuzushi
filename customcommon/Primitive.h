#pragma once

#include "../src/WinMain.h"
#include "Pos.h"

struct Shape
{
	~Shape();
	Vector2* pointPos = &pointPos_;


	Vector2 GetPointPos() const;
	void SetPointPos(Vector2& pointpos_);

	virtual void Update() = 0;
	virtual void Render() = 0;

	int color = WHITE;

private :
	Vector2 pointPos_ = { WINDOW_W_HALF,WINDOW_H_HALF };
};

struct Box : public Shape
{
	Box();
	Box(float _xPoint, float _yPoint, float _sizeX, float _sizeY, unsigned int = WHITE, bool _hasShadow = false);
	Box(Vector2* position, Vector2 _size, unsigned int color = WHITE, bool hasShadow = false);
	Box(Vector2 position, Vector2 _size, unsigned int color = WHITE, bool hasShadow = false);
	Vector2* pos = &pos_;
	Vector2* pos2 = &pos2_;
	Vector2 size;

	void Update();
	void Render();

	Vector2 GetPos1() const;
	Vector2 GetPos2() const;


private:
	Vector2 pos_;
	Vector2 pos2_;
	bool hasShadow_ = false;

	void RenderBox(Vector2& _pos, Vector2& _pos2);
	void RenderShadow(Vector2& _pos, Vector2& _pos2);
};

struct Circle
{
	Circle()
	{
	};
	Circle(Vector2& _pointPos, float _radius)
	{
		pointPos = _pointPos;
		radius = _radius;
	};
	Vector2 pointPos;
	float radius = 0;
	int color = WHITE;

	float ToPixelUnit()
	{
		return radius * 0.05f;
	}


	void Render()
	{
		DrawCircleAA(pointPos.x, pointPos.y, radius, 64, color, 1);
	}
};

struct NewBox
{
	NewBox()
	{

	}
	NewBox(Vector2& _pos1, Vector2& _pos2, Vector2 _size)
	{
		size = _size;
		pos2.x = pos1.x + size.x;
		pos2.y = pos1.y + size.y;

		UpdatePointPos();
	}
	// Method to update pointPos
	void UpdatePointPos()
	{
		pointPos.x = pos1.x + size.x / 2;
		pointPos.y = pos1.y + size.y / 2;
	}
	NewBox(const Vector2& _pointPos, Vector2 _size)
	{
		pointPos = _pointPos;
		size = _size;
		RecalculateBox();
	}

	void RecalculateBox()
	{
		pos1.x = pointPos.x - size.x / 2;
		pos1.y = pointPos.y - size.y / 2;
		pos2.x = pointPos.x + size.x / 2;
		pos2.y = pointPos.y + size.y / 2;
	}
	// Method to move the box by updating pointPos
	void Move(const Vector2& delta)
	{
		// Update the pointPos
		pointPos.x += delta.x;
		pointPos.y += delta.y;

		RecalculateBox();
	}


	Vector2 pointPos;
	Vector2 pos1;
	Vector2 pos2;
	Vector2 size;

	void Render();

	int color = WHITE;
private:
};