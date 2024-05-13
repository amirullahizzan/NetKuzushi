#include "BlockConstructor.h"

void BlockSpawner::GenerateBlockies()
{
	Vector2 generatedPosition;
	const int BLOCKIES_IN_ONE_ROW = 14;
	const int BLOCKIES_COLUMNS = 6;
	//
	Vector2 positionGap = { 15.15f, 25.15f };
	//
	for (int j = 0; j < BLOCKIES_COLUMNS + 1; j++)
	{
		//if (j % 2 == 0 && j != 0)
		//{
		//    NextColorVariant();
		//}
		generatedPosition.y = blockySpawnPoint.y;
		generatedPosition.y += j * (positionGap.y + blockySize.y);

		for (int i = 0; i < BLOCKIES_IN_ONE_ROW + 1; i++)
		{
			generatedPosition.x = i * (positionGap.x + blockySize.x);
			generatedPosition.x += blockySpawnPoint.x; //Going right
			//Vector3 generatedPositionVec3 = new Vector3(generatedPosition.x, generatedPosition.y, 0);
			Blocky blocky = { generatedPosition, blockySize };
			blockies.push_back(blocky);
			//ChangeColorBasedOnPalette(instantiatedBlocky);
			totalBlocky++;
		}
	}
}

void BlockSpawner::Update()
{

	vfx.Update();
}

void BlockSpawner::TrySpawnBall(Vector2 blockDestroyedPos)
{
	if (totalBlocky % 6 == 0 && totalBlocky != 0)
	{
		ballSpawner->SpawnNewBall(blockDestroyedPos);
	}
}

void BlockSpawner::Render()
{
	for (auto& blocky : blockies)
	{
		blocky.Render();
	}

	vfx.Render();

}


void NewBox::Render()
{
	DrawBoxAA(pos1.x, pos1.y, pos2.x, pos2.y, color, 1);
}
