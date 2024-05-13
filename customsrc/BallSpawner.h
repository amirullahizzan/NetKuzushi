#pragma once

#include "../customcommon/Pos.h"
#include "../customsrc/Ball.h"

struct BallSpawner
{
	BallSpawner(std::vector<Ball>& _balls, int _ballHandler, int _redBallHandler) : 
		ballHandler(_ballHandler), redBallHandler(_redBallHandler), balls(_balls) {}
	std::vector<Ball>& balls;
	int ballHandler = -1;
	int redBallHandler = -1;

	int greenBall = 0;
	int MAX_GREEN_BALL = 5;
	void SpawnNewBall(Vector2 _ballSpawnPos)
	{
		int randomizer = GetRand(4);
		if (randomizer == 3 || greenBall >= MAX_GREEN_BALL)
		{
			RedBall redBall(_ballSpawnPos, redBallHandler);
			balls.push_back(redBall);
		}
		else
		{
			greenBall++;
			Ball ball(_ballSpawnPos, ballHandler);
			balls.push_back(ball);
		}

	}
};