#pragma once

#include "../customcommon/Primitive.h"
#include "../customcommon/TextEffect.h"
#include "../customsrc/SceneManager.h"

struct SceneBase
{
public:
	SceneBase(SceneManager* _sceneManager);
	~SceneBase() = default;

	virtual void Update() = 0;
	virtual void Render() = 0;

	SceneManager* scene = nullptr;

protected:
};
