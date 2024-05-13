#include "Primitive.h"

Shape::~Shape()
{
}

Vector2 Shape::GetPointPos() const
{
	return *pointPos;
}

void Shape::SetPointPos(Vector2& _pointPos)
{
	pointPos = &_pointPos;
}

Box::Box()
{
	hasShadow_ = false;
	Update();
}

Box::Box(float _xPoint, float _yPoint, float _sizeX, float _sizeY, unsigned int _color, bool _hasShadow)
{
	pointPos->x = _xPoint;
	pointPos->y = _yPoint;
	size.x = _sizeX;
	size.y = _sizeY;
	hasShadow_ = _hasShadow;
	color = _color;
	Update();
}

Box::Box(Vector2* position, Vector2 _size, unsigned int color, bool hasShadow)
{
	pointPos = position;
	size = _size;
}

Box::Box(Vector2 position, Vector2 _size, unsigned int color, bool hasShadow)
{
	*pointPos = position;
	size = _size;
}

void Box::Update()
{
	*pos = { (pointPos->x - size.x), (pointPos->y - size.y) };
	*pos2 = { (pointPos->x + size.x), (pointPos->y + size.y) };
}

void Box::Render()
{
	if (hasShadow_)
	{
		RenderShadow(*pos, *pos2);
	}
	RenderBox(*pos, *pos2);
}

Vector2 Box::GetPos1() const
{
	return *pos;
}
Vector2 Box::GetPos2() const
{
	return *pos2;
}


void Box::RenderBox(Vector2& _pos, Vector2& _pos2)
{
	DrawBoxAA(_pos.x, _pos.y, _pos2.x, _pos2.y, color, 1);
}


void Box::RenderShadow(Vector2& _pos, Vector2& _pos2)
{
	const float shadowOffset = 5.0f;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
	DrawBoxAA(_pos.x - shadowOffset, _pos.y, _pos2.x, _pos2.y + shadowOffset, BLACK, 1);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 120);
}
