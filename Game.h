#pragma once
#include "Define.h"

class Game
{
public:
	Game();
	~Game();

public:
	void	Init();
	void	Update();
	void	Render();
	void	Release();

public:
	bool	GetGameRunning() { return m_gameRunning; }

public:
	void	SetGameRunning(bool gameRunning) { m_gameRunning = gameRunning; }

private:
	bool	m_gameRunning;

};

