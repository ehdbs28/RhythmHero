#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	virtual ~TitleScene();

public:
	void	Init() override;
	void	Update() override;
	void	Render() override;
	void	Release() override;

private:
	void	DrawAsciiTitle();

};

