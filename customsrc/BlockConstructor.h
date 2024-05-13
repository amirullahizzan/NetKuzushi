#pragma once

#include "../src/WinMain.h"
#include "../customcommon/Pos.h"
#include "../customcommon/Primitive.h"
#include "../customsrc/BallSpawner.h"
#include "../customcommon/Cooldown.h"
#include "../customcommon/Math.h"
#include "../customcommon/GameTime.h"

extern GameTime gameTime;

struct Particle : Circle
{
	using Circle::Circle;
	Cooldown particleLifetimeCooldown;
	Particle() : particleLifetimeCooldown(5.0f)
	{
	}

};

struct VFXManager
{
	std::vector<Particle> particles;

	void SpawnEffects(Vector2 _pointPos)
	{
		for (int i = 0; i < 18; i++)
		{
			Particle particle = {_pointPos,5.0f};
			particle.color = GREEN;
			_pointPos = particle.pointPos;
			particle.particleLifetimeCooldown.StartCooldown();
			particles.push_back(particle);
		}
	}

	void Update()
	{
		for (int i = 0; i < particles.size(); i++)
		{
			float angle = GetRandF(2.0f,PI,100) * i;

			float speed = 12.0f;

			Vector2 velocity(speed * cos(angle), speed * sin(angle));

			particles[i].pointPos += velocity;
		}

		GarbageCollector();
		printf("%f", gameTime.GetTime());
	}

	void Render()
	{
		for(auto& particle : particles)
		{
			particle.Render();
		}
	}

	void GarbageCollector()
	{
		for (int i = 0; i < particles.size(); i++)
		{
			if (!particles[i].particleLifetimeCooldown.IsCooldown())
			{
				particles.erase(particles.begin() + i);
				break;
			}
		}
	}
};

struct Blocky : NewBox
{
	using NewBox::NewBox;
	Blocky() : NewBox() {}
	void ReduceHP()
	{
		hp--;
		color = RED;
	}
	bool IsHPZero()
	{
		return hp <= 0;
	}
private:
	int hp = 2;
};

struct BlockSpawner
{
	BlockSpawner(BallSpawner* _ballSpawner) : ballSpawner(_ballSpawner) {}
	BallSpawner* ballSpawner = nullptr;
	Vector2 blockySize = { 60.0f, 30.0f };
	Vector2 blockySpawnPoint = { 120, 100 };
	VFXManager vfx;

	std::vector<Blocky> blockies;
	int totalBlocky = 0;
	void GenerateBlockies(); //TODO timed spawn anim
	void Update(); //TODO timed spawn anim
	void TrySpawnBall(Vector2 blockDestroyedPos);
	void Render(); //TODO timed spawn anim
	
// {
//     
//
// }
//
// int totalBlocky = 0;
// public bool IsAllBlockyDestroyed()
// {
//     return totalBlocky <= 0;
// }
//
// enum EColorPalette
// {
//     Red = 0,
//     Orange,
//     Yellow,
//     Green,
// }
// EColorPalette currentColorPalette = EColorPalette.Red;
//
// Color GetColorPalette(EColorPalette colorSeq)
// {
//     switch (colorSeq)
//     {
//     case EColorPalette.Red:
//         return Color.red;
//
//     case EColorPalette.Orange:
//         Color orange = new Color(1, 0.38f, 0);
//         return orange;
//
//     case EColorPalette.Yellow:
//         return Color.green;
//
//     case EColorPalette.Green:
//         return Color.yellow;
//
//     default:
//         return Color.white;
//     }
// }
//
// void ChangeColorBasedOnPalette(GameObject blockyGO)
// {
//     SpriteRenderer instantiatedBlockyRenderer = blockyGO.GetComponent<SpriteRenderer>();
//     instantiatedBlockyRenderer.color = GetColorPalette(currentColorPalette);
// }
//
// void NextColorVariant()
// {
//     currentColorPalette++;
// }

};