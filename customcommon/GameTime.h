#pragma once
#include <chrono>

struct GameTime
{
public:
	void Update();

	const float GetTime()		 const { return time; }
	const float GetDeltaTime()	 const { return deltaTime; }
	const float GetDeltaTimeMS() const { return deltaTime_ms; }


private:
	float time;
	float deltaTime;
	float deltaTime_ms;

	void UpdateDeltaTime();
	void UpdateTime();
};

