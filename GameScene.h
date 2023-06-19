#pragma once
#include "Scene.h"

class GameLine;
class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();
	
public:
	void	Init() override;
	void	Update() override;
	void	Render() override;
	void	Release() override;

private:
	shared_ptr<GameLine>	m_gameLine;

};

