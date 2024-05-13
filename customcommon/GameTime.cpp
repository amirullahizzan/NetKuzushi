#include "GameTime.h"
#include "../src/WinMain.h"

GameTime gameTime;

void GameTime::Update()
{
	UpdateTime();
	UpdateDeltaTime();
}

void GameTime::UpdateDeltaTime()
{
	static const float MaxDeltaTime = 0.1f;
	// Get the current time
	static auto lastTime = std::chrono::high_resolution_clock::now();
	auto currentTime = std::chrono::high_resolution_clock::now();

	// Calculate the time 
	// difference between frames
	std::chrono::duration<float> duration = currentTime - lastTime;
	deltaTime = duration.count();
	deltaTime = (deltaTime < MaxDeltaTime) ? deltaTime : MaxDeltaTime;
	deltaTime_ms = deltaTime * 1000.0f;

	// Update the last time for the next frame
	lastTime = currentTime;

}

void GameTime::UpdateTime()
{
	time += deltaTime;
}

