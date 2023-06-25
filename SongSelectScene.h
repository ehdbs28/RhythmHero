#pragma once
#include "Scene.h"

class SongSelectScene : public Scene
{
public:
	SongSelectScene();
	virtual ~SongSelectScene();

public:
	void	Init() override;
	void	Update(float dt) override;
	void	Render() override;
	void	Release() override;

private:
	int		m_currentSelect;

};

