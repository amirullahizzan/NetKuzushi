#pragma once

#include "../src/WinMain.h"

struct Sprite
{
	Sprite(const std::string& filePath);
	//void Load(const std::string& filePath);
	const int GetHandle();
	void Render(float _posX, float _posY, double _scale = 1, double _rot = 0, bool _transp = false);

	int handle = -1;

private:
};