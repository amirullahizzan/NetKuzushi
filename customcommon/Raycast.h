#pragma once
#include "Pos.h"
#include "GameObject.h"

class Raycast {
public:
    Vector2 origin;
    Vector2 direction;
    float length;

    Raycast(const Vector2& origin, const Vector2& direction, float length)
        : origin(origin), direction(direction.normalize()), length(length) {}
    
    bool intersectsCircle(const Vector2& circleCenter, float circleRadius) const {
        Vector2 toCircle = circleCenter - origin;
        float t = toCircle.dot(direction); // Project vector to circle onto ray direction
        if (t < 0 || t > length) { // Check if the intersection point is on the ray segment
            return false;
        }
        Vector2 closestPoint = origin + direction * t;
        Vector2 distanceVec = circleCenter - closestPoint;
        float distanceSq = distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y;
        return distanceSq <= (circleRadius * circleRadius);
    }
};
