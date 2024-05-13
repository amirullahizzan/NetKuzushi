#include "Math.h"
#include "../src/WinMain.h"
#include <cmath>

double ToRadian(double _degree)
{
	return _degree * PI / 180;
}

double ToDegree(double _radian)
{
	return _radian * 180 / PI;
}

void CapDegree(double& _degree)
{
	if (_degree >= 360)
	{
		_degree -= 360;
	}
	else if (_degree < 0)
	{
		_degree += 360;
	}
}

void CapRadian(double& _radian)
{
	if (_radian >= 2 * PI)
	{
		_radian -= 2 * PI;
	}
	else if (_radian < 0)
	{
		_radian += 2 * PI;
	}
}

float GetRandF(float minInclusion, float maxExclusion, int precision) {
	// Determine the range for the random integer (scaled by precision)
	float range = (maxExclusion - minInclusion) * precision;

	// Generate a random integer between 0 and range
	int rand_int = GetRand(static_cast<int>(std::round(range)));

	// Scale and shift the random integer to fit within the range [minInclusion, maxExclusion)
	return minInclusion + static_cast<float>(rand_int) / precision;
}