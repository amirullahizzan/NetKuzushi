#pragma once

template <typename T> const T& clamp(const T& value, const T& min, const T& max)
{
    return (value < min) ? min : (value > max) ? max : value;
}

double ToRadian(double _degree);
double ToDegree(double _radian);
void CapDegree(double& _degree);
void CapRadian(double& _radian);

float GetRandF(float minInclusion, float maxExclusion, int precision = 1);
