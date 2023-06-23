#pragma once
#include "Define.h"
#include "Console.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Init() abstract;
	virtual void Update(float dt) abstract;
	virtual void Render() abstract;
	virtual void Release() abstract;

};

