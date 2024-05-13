#include "Sprite.h"

Sprite::Sprite(const std::string& filePath)
{
 	handle = LoadGraph(filePath.c_str()); 
}

const int Sprite::GetHandle()
{
	return handle;
}

void Sprite::Render(float _posX,float _posY, double _scale, double _rot, bool _transp)
{
	DrawRotaGraphF(_posX, _posY, _scale, _rot, GetHandle(), _transp, 0, 0);
}
