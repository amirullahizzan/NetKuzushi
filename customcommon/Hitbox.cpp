#include "Hitbox.h"
#include "Math.h"
#include <cmath>
#include "Collider2D.h"

bool HitboxCircleCircle(const Circle& circle1, const Circle& circle2) {
    // Calculate the distance between the centers of the two circles
    float distance = (float)std::sqrt(std::pow(circle2.pointPos.x - circle1.pointPos.x, 2) + std::pow(circle2.pointPos.y - circle1.pointPos.y, 2));

    // Check if the distance is less than the sum of the radii
    return distance <= (circle1.radius + circle2.radius);
}

bool HitboxBoxCircle(const Vector2& _pos1, const Vector2& _pos2, const Vector2& _circlepos, float _radius)
{
    float closestX = clamp(_circlepos.x, _pos1.x, _pos2.x);
    float closestY = clamp(_circlepos.y, _pos1.y, _pos2.y);

    float deltaX = _circlepos.x - closestX;
    float deltaY = _circlepos.y - closestY;

    return (deltaX * deltaX + deltaY * deltaY) <= (_radius * _radius);
}

bool HitboxBoxCircle(const Box& box, const Circle& circle) {
    // Calculate the closest point to the circle center within the box
    float closestX = clamp(circle.pointPos.x, box.pos->x, box.pos->x + box.pos2->x);
    float closestY = clamp(circle.pointPos.y, box.pos->y, box.pos->y + box.pos2->y);

    // Calculate the distance between the closest point and the circle center
    float distanceX = circle.pointPos.x - closestX;
    float distanceY = circle.pointPos.y - closestY;
    float distanceSquared = distanceX * distanceX + distanceY * distanceY;

    // Check if the distance is less than or equal to the square of the circle's radius
    return distanceSquared <= (circle.radius * circle.radius);
}

bool HitboxCircleBox(const Circle& circle, const Box& box) {
    // Calculate the closest point to the circle center within the box
    float closestX = clamp(circle.pointPos.x, box.pos->x, box.pos->x + box.pos2->x);
    float closestY = clamp(circle.pointPos.y, box.pos->y, box.pos->y + box.pos2->y);

    // Calculate the distance between the closest point and the circle center
    float distanceX = circle.pointPos.x - closestX;
    float distanceY = circle.pointPos.y - closestY;
    float distanceSquared = distanceX * distanceX + distanceY * distanceY;

    // Check if the distance is less than or equal to the square of the circle's radius
    return distanceSquared <= (circle.radius * circle.radius);
}


bool IsMouseHitBox(const Vector2& _boxPos1, const Vector2& _boxPos2, Vector2& _mousePos)
{
    return HitboxBoxCircle(_boxPos1, _boxPos2, _mousePos);
}


bool HitboxBoxBox(const Box& box1, const Box& box2) {
    // Check for overlap on the x-axis
    bool xOverlap = (box1.pos->x + box1.size.x >= box2.pos->x) && (box2.pos->x + box2.size.x >= box1.pos->x);

    // Check for overlap on the y-axis
    bool yOverlap = (box1.pos->y + box1.size.y>= box2.pos->y) && (box2.pos->y + box2.size.y >= box1.pos->y);

    // If both x-axis and y-axis overlap, there is an intersection
    return xOverlap && yOverlap;
}


bool CheckCollision(const std::shared_ptr<BaseCollider2D>& collider1, 
    const std::shared_ptr<BaseCollider2D>& collider2)
{
    if (!collider1 || !collider2) 
    {
        // One or both colliders are invalid
        return false;
    }

    //printf("colliders : %s , %s\n" , collider1->name.c_str(), collider2->name.c_str());

    auto boxCollider1 = std::dynamic_pointer_cast<BoxCollider2D>(collider1);
    auto boxCollider2 = std::dynamic_pointer_cast<BoxCollider2D>(collider2);
    if (boxCollider1 && boxCollider2) 
    {
        // Both colliders are BoxCollider2D, perform AABB collision detection
        return HitboxBoxBox(boxCollider1->box, boxCollider2->box);
    }
    auto circleCollider1 = std::dynamic_pointer_cast<CircleCollision2D>(collider1);
    auto circleCollider2 = std::dynamic_pointer_cast<CircleCollision2D>(collider2);

    if (circleCollider1 && circleCollider2) {
        // Both colliders are CircleCollision2D, perform circle-circle collision detection
        return HitboxCircleCircle(circleCollider1->circle, circleCollider2->circle);
    }

    if (boxCollider1 && circleCollider2) {
        // Perform circle-box collision detection
        return HitboxBoxCircle(boxCollider1->box,circleCollider2->circle);
    }

    if (circleCollider1 && boxCollider2) {
        // Perform circle-box collision detection
        return HitboxCircleBox(circleCollider1->circle, boxCollider2->box);
    }

    return false;
}
