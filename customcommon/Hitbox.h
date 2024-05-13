#pragma once

#include "Pos.h"
#include "Primitive.h"
#include "Collider2D.h"
#include <memory>

bool HitboxCircleCircle(const Circle& circle1, const Circle& circle2);

bool HitboxBoxCircle(const Vector2& _pos1, const Vector2& _pos2, const Vector2& _circlepos, float _radius = 0);

bool IsMouseHitBox(const Vector2& _boxPos1, const Vector2& _boxPos2, Vector2& _mousePos);

bool CheckCollision(const std::shared_ptr<BaseCollider2D>& collider1, const std::shared_ptr<BaseCollider2D>& collider2);

