#include "LoseWall.h"

#include "../customcommon/Rigidbody2D.h"

LoseWall::LoseWall()
{
	tag = "BallDestroyer";
}

void LoseWall::Update()
{
	
}

void LoseWall::Render()
{
	box.Render();
}

void LoseWall::HandleCollision(GameObject& _other)
{

}


